/*
    ChibiOS - Copyright (C) 2006..2018 Giovanni Di Sirio
    ChibiOS - Copyright (C) 2022 Artery Technology
    ChibiOS - Copyright (C) 2022 HorrorTroll

    Licensed under the Apache License, Version 2.0 (the "License");
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at

        http://www.apache.org/licenses/LICENSE-2.0

    Unless required by applicable law or agreed to in writing, software
    distributed under the License is distributed on an "AS IS" BASIS,
    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
    See the License for the specific language governing permissions and
    limitations under the License.
*/

/**
 * @file    AT32F40xx/hal_lld.c
 * @brief   AT32F40xx HAL subsystem low level driver source.
 *
 * @addtogroup HAL
 * @{
 */

#include "hal.h"

/*===========================================================================*/
/* Driver local definitions.                                                 */
/*===========================================================================*/

/*===========================================================================*/
/* Driver exported variables.                                                */
/*===========================================================================*/

/**
 * @brief   CMSIS system core clock variable.
 * @note    It is declared in system_at32f40xx.h.
 */
uint32_t SystemCoreClock = AT32_HCLK;

/*===========================================================================*/
/* Driver local variables and types.                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Driver local functions.                                                   */
/*===========================================================================*/

/**
 * @brief   Initializes the battery powered domain.
 * @note    WARNING! Changing clock source impossible without resetting
 *          of the whole BPR domain.
 */
static void hal_lld_battery_powered_domain_init(void) {

  /* Battery powered domain access enabled and left open.*/
  PWC->CTRL |= PWC_CTRL_BPWEN;

#if HAL_USE_RTC
  /* Reset BPR domain if different clock source selected.*/
  if ((CRM->BPDC & AT32_RTCSEL_MASK) != AT32_RTCSEL) {
    /* Battery powered domain reset.*/
    CRM->BPDC = CRM_BPDC_BPDRST;
    CRM->BPDC = 0;
  }

  /* If enabled then the LEXT is started.*/
#if AT32_LEXT_ENABLED
#if defined(AT32_LEXT_BYPASS)
  /* LEXT Bypass.*/
  CRM->BPDC |= CRM_BPDC_LEXTEN | CRM_BPDC_LEXTBYPS;
#else
  /* No LEXT Bypass.*/
  CRM->BPDC |= CRM_BPDC_LEXTEN;
#endif
  while ((CRM->BPDC & CRM_BPDC_LEXTSTBL) == 0)
    ;                                     /* Waits until LEXT is stable.   */
#endif /* AT32_LEXT_ENABLED */

#if AT32_RTCSEL != AT32_RTCSEL_NOCLOCK
  /* If the battery powered domain hasn't been initialized yet then proceed with
     initialization.*/
  if ((CRM->BPDC & CRM_BPDC_RTCEN) == 0) {
    /* Selects clock source.*/
    CRM->BPDC |= AT32_RTCSEL;

    /* Prescaler value loaded in registers.*/
    rtc_lld_set_prescaler();

    /* RTC clock enabled.*/
    CRM->BPDC |= CRM_BPDC_RTCEN;
  }
#endif /* AT32_RTCSEL != AT32_RTCSEL_NOCLOCK */
#endif /* HAL_USE_RTC */
}

/*===========================================================================*/
/* Driver interrupt handlers.                                                */
/*===========================================================================*/

#if defined(AT32_DMA_REQUIRED) || defined(__DOXYGEN__)
#if defined(AT32_DMA2_CH45_HANDLER) || defined(__DOXYGEN__)
/**
 * @brief   DMA2 streams 4 and 5 shared ISR.
 *
 * @isr
 */
OSAL_IRQ_HANDLER(AT32_DMA2_CH45_HANDLER) {

  OSAL_IRQ_PROLOGUE();

  /* Check on channel 4 of DMA2.*/
  dmaServeInterrupt(AT32_DMA2_STREAM4);

  /* Check on channel 5 of DMA2.*/
  dmaServeInterrupt(AT32_DMA2_STREAM5);

  OSAL_IRQ_EPILOGUE();
}
#endif /* defined(AT32_DMA2_CH45_HANDLER) */
#endif /* defined(AT32_DMA_REQUIRED) */

/*===========================================================================*/
/* Driver exported functions.                                                */
/*===========================================================================*/

/**
 * @brief   Low level HAL driver initialization.
 *
 * @notapi
 */
void hal_lld_init(void) {

  /* Reset of all peripherals.*/
  crmResetAPB1(0xFFFFFFFF);
  crmResetAPB2(0xFFFFFFFF);

  /* PWC and BPD clocks enabled.*/
  crmEnablePWCInterface(true);
  crmEnableBPRInterface(true);

  /* Initializes the backup domain.*/
  hal_lld_battery_powered_domain_init();

  /* DMA subsystems initialization.*/
#if defined(AT32_DMA_REQUIRED)
  dmaInit();
#endif

  /* IRQ subsystem initialization.*/
  irqInit();

  /* Power voltage monitoring enable.*/
#if AT32_PVM_ENABLE
  PWC->CTRL |= PWC_CTRL_PVMEN | (AT32_PVMSEL & AT32_PVMSEL_MASK);
#endif /* AT32_PVM_ENABLE */
}

/**
 * @brief   AT32 clocks and PLL initialization.
 * @note    All the involved constants come from the file @p board.h.
 * @note    This function should be invoked just after the system reset.
 *
 * @special
 */
#if defined(AT32F403XX_OL) || defined(AT32F403AXX_NL) ||                    \
    defined(AT32F407XX_CL) || defined(__DOXYGEN__)
/*
 * Clocks initialization for all series.
 */
void at32_clock_init(void) {

#if !AT32_NO_INIT
  /* HICK setup, it enforces the reset situation in order to handle possible
     problems with JTAG probes and re-initializations.*/
  CRM->CTRL |= CRM_CTRL_HICKEN;            /* Make sure HICK is ON.         */
  while (!(CRM->CTRL & CRM_CTRL_HICKSTBL))
    ;                                      /* Wait until HICK is stable.    */
  CRM->CTRL &= CRM_CTRL_HICKTRIM | CRM_CTRL_HICKEN; /* CTRL Reset value.    */
  CRM->CFG = 0;                            /* CFG reset value.              */
  while ((CRM->CFG & CRM_CFG_SCLKSTS) != CRM_CFG_SCLKSTS_HICK)
    ;                                      /* Waits until HICK is selected. */

#if AT32_HEXT_ENABLED
#if defined(AT32_HEXT_BYPASS)
  /* HEXT Bypass.*/
  CRM->CTRL |= CRM_CTRL_HEXTEN | CRM_CTRL_HEXTBYPS;
#endif
  /* HEXT activation.*/
  CRM->CTRL |= CRM_CTRL_HEXTEN;
  while (!(CRM->CTRL & CRM_CTRL_HEXTSTBL))
    ;                                       /* Waits until HEXT is stable.  */
#endif

#if AT32_LICK_ENABLED
  /* LICK activation.*/
  CRM->CTRLSTS |= CRM_CTRLSTS_LICKEN;
  while ((CRM->CTRLSTS & CRM_CTRLSTS_LICKSTBL) == 0)
    ;                                       /* Waits until LICK is stable.  */
#endif

#if AT32_ACTIVATE_PLL
  /* PLL activation.*/
  CRM->CFG  |= AT32_PLLMULT | AT32_PLLHEXTDIV | AT32_PLLRCS;
  CRM->CTRL |= CRM_CTRL_PLLEN;
  while (!(CRM->CTRL & CRM_CTRL_PLLSTBL))
    ;                                       /* Waits until PLL is stable.   */
#endif

  /* Clock settings.*/
#if AT32_HAS_USB
  CRM->CFG = AT32_CLKOUT_SEL | AT32_USBDIV | AT32_PLLMULT | AT32_PLLHEXTDIV |
             AT32_PLLRCS     | AT32_ADCDIV | AT32_APB2DIV | AT32_APB1DIV    |
             AT32_AHBDIV;
#else
  CRM->CFG = AT32_CLKOUT_SEL |               AT32_PLLMULT | AT32_PLLHEXTDIV |
             AT32_PLLRCS     | AT32_ADCDIV | AT32_APB2DIV | AT32_APB1DIV    |
             AT32_AHBDIV;
#endif

  /* Switching to the configured clock source if it is different from HICK.*/
#if (AT32_SCLKSEL != AT32_SCLKSEL_HICK)
  /* Switches clock source.*/
  CRM->CFG |= AT32_SCLKSEL;
  while ((CRM->CFG & CRM_CFG_SCLKSTS) != (AT32_SCLKSEL << 2))
    ;                                       /* Waits selection complete.    */
#endif

#if !AT32_HICK_ENABLED
  CRM->CTRL &= ~CRM_CTRL_HICKEN;
#endif
#endif /* !AT32_NO_INIT */
}
#else
void at32_clock_init(void) {}
#endif

/** @} */
