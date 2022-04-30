/*
    ChibiOS - Copyright (C) 2006..2018 Giovanni Di Sirio

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
 * @file    CT/hal_pwm_lld.c
 * @brief   SN32 PWM subsystem low level driver header.
 *
 * @addtogroup PWM
 * @{
 */

#include "hal.h"

#if HAL_USE_PWM || defined(__DOXYGEN__)

/*===========================================================================*/
/* Driver local definitions.                                                 */
/*===========================================================================*/

/*===========================================================================*/
/* Driver exported variables.                                                */
/*===========================================================================*/

/**
 * @brief   PWMD1 driver identifier.
 * @note    The driver PWMD1 allocates the complex timer CT16B0 when enabled.
 */
#if SN32_PWM_USE_CT16B0 || defined(__DOXYGEN__)
PWMDriver PWMD1;
#endif

/**
 * @brief   PWMD2 driver identifier.
 * @note    The driver PWMD2 allocates the complex timer CT16B1 when enabled.
 */
#if SN32_PWM_USE_CT16B1 || defined(__DOXYGEN__)
PWMDriver PWMD2;
#endif

/**
 * @brief   PWMD3 driver identifier.
 * @note    The driver PWMD3 allocates the complex timer CT16B2 when enabled.
 */
#if SN32_PWM_USE_CT16B2 || defined(__DOXYGEN__)
PWMDriver PWMD3;
#endif

/**
 * @brief   PWMD4 driver identifier.
 * @note    The driver PWMD4 allocates the complex timer CT32B0 when enabled.
 */
#if SN32_PWM_USE_CT32B0 || defined(__DOXYGEN__)
PWMDriver PWMD4;
#endif

/**
 * @brief   PWMD5 driver identifier.
 * @note    The driver PWMD5 allocates the complex timer CT32B1 when enabled.
 */
#if SN32_PWM_USE_CT32B1 || defined(__DOXYGEN__)
PWMDriver PWMD5;
#endif

/**
 * @brief   PWMD6 driver identifier.
 * @note    The driver PWMD6 allocates the complex timer CT32B2 when enabled.
 */
#if SN32_PWM_USE_CT32B2 || defined(__DOXYGEN__)
PWMDriver PWMD6;
#endif

/*===========================================================================*/
/* Driver local variables and types.                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Driver local functions.                                                   */
/*===========================================================================*/

/*===========================================================================*/
/* Driver interrupt handlers.                                                */
/*===========================================================================*/

#if SN32_PWM_USE_CT16B0 || defined(__DOXYGEN__)
#if !defined(SN32_CT16B0_SUPPRESS_ISR)
#if !defined(SN32_CT16B0_HANDLER)
#error "SN32_CT16B0_HANDLER not defined"
#endif
/**
 * @brief   CT16B0 interrupt handler.
 *
 * @isr
 */
OSAL_IRQ_HANDLER(SN32_CT16B0_HANDLER) {

  OSAL_IRQ_PROLOGUE();

  pwm_lld_serve_interrupt(&PWMD1);

  OSAL_IRQ_EPILOGUE();
}
#endif /* !defined(SN32_CT16B0_SUPPRESS_ISR) */
#endif /* SN32_PWM_USE_CT16B0 */

/*===========================================================================*/
/* Driver exported functions.                                                */
/*===========================================================================*/

/**
 * @brief   Low level PWM driver initialization.
 *
 * @notapi
 */
void pwm_lld_init(void) {

#if SN32_PWM_USE_CT16B0
  /* Driver initialization.*/
  pwmObjectInit(&PWMD1);
  PWMD1.channels = SN32_CT16B0_CHANNELS;
  PWMD1.ct16 = SN32_CT16B0;
#endif

#if SN32_PWM_USE_CT16B1
  /* Driver initialization.*/
  pwmObjectInit(&PWMD2);
  PWMD2.channels = SN32_CT16B1_CHANNELS;
  PWMD2.ct16 = SN32_CT16B1;
#endif

#if SN32_PWM_USE_CT16B2
  /* Driver initialization.*/
  pwmObjectInit(&PWMD3);
  PWMD3.channels = SN32_CT16B2_CHANNELS;
  PWMD3.ct16 = SN32_CT16B2;
#endif

#if SN32_PWM_USE_CT32B0
  /* Driver initialization.*/
  pwmObjectInit(&PWMD4);
  PWMD4.channels = SN32_CT32B0_CHANNELS;
  PWMD4.ct32 = SN32_CT32B0;
#endif

#if SN32_PWM_USE_CT32B1
  /* Driver initialization.*/
  pwmObjectInit(&PWMD5);
  PWMD5.channels = SN32_CT32B1_CHANNELS;
  PWMD5.ct32 = SN32_CT32B1;
#endif

#if SN32_PWM_USE_CT32B2
  /* Driver initialization.*/
  pwmObjectInit(&PWMD6);
  PWMD6.channels = SN32_CT32B2_CHANNELS;
  PWMD6.ct32 = SN32_CT32B2;
#endif
}

/**
 * @brief   Configures and activates the PWM peripheral.
 * @note    Starting a driver that is already in the @p PWM_READY state
 *          disables all the active channels.
 *
 * @param[in] pwmp      pointer to a @p PWMDriver object
 *
 * @notapi
 */
void pwm_lld_start(PWMDriver *pwmp) {
  uint32_t pwmctrl_ct16;
  uint32_t pwmctrl_ct32;

  if (pwmp->state == PWM_STOP) {
    /* Clock activation and timer reset.*/
#if SN32_PWM_USE_CT16B0
    if (&PWMD1 == pwmp) {
      CT16B0_Init();
      CT16B0_ResetTimer();
#if !defined(SN32_CT16B0_SUPPRESS_ISR)
      nvicEnableVector(SN32_CT16B0_NUMBER, SN32_PWM_CT16B0_IRQ_PRIORITY);
#endif
      pwmp->clock = SystemCoreClock;
    }
#endif

#if SN32_PWM_USE_CT16B1
    if (&PWMD2 == pwmp) {
      CT16B1_Init();
      CT16B1_ResetTimer();
      pwmp->clock = SystemCoreClock;
    }
#endif

#if SN32_PWM_USE_CT16B2
    if (&PWMD3 == pwmp) {
      CT16B2_Init();
      CT16B2_ResetTimer();
      pwmp->clock = SystemCoreClock;
    }
#endif

#if SN32_PWM_USE_CT32B0
    if (&PWMD4 == pwmp) {
      CT32B0_Init();
      CT32B0_ResetTimer();
      pwmp->clock = SystemCoreClock;
    }
#endif

#if SN32_PWM_USE_CT32B1
    if (&PWMD5 == pwmp) {
      CT32B1_Init();
      CT32B1_ResetTimer();
      pwmp->clock = SystemCoreClock;
    }
#endif

#if SN32_PWM_USE_CT32B2
    if (&PWMD6 == pwmp) {
      CT32B2_Init();
      CT32B2_ResetTimer();
      pwmp->clock = SystemCoreClock;
    }
#endif

#if defined(SN32F240)
  /* PFPA Timer Mapping
    ┌─────┬────────────────┬────────────────┬───────────────┬────────────────┬────────────────┬────────────────┐
    │     │ CT16B0         │ CT16B1         │ CT16B2        │ CT32B0         │ CT32B1         │ CT32B2         │
    │PWM0 │ P0.0  (Col 0)  │ P1.15 (Col 20) │ P0.2 (Col 2)  │ P0.4  (Col 4)  │ P1.13 (Col 18) │ P1.1  (Col 11) │
    │PWM1 │ P0.1  (Col 1)  │ P1.3  (Col 13) │ P1.4 (Col 14) │ P1.11 (Col 16) │ P1.10 (Col 15) │ P0.14 (Col 8)  │
    │PWM2 │ P1.12 (Col 17) │ P0.15 (Col 9)  │ P1.0 (Col 10) │ P1.14 (Col 19) │ P0.5  (Col 5)  │ P0.3  (Col 3)  │
    │PWM3 │                │                │               │ P1.2  (Col 12) │ P0.7  (Col 7)  │ P0.6  (Col 6)  │
    └─────┴────────────────┴────────────────┴───────────────┴────────────────┴────────────────┴────────────────┘ 
  */

  SN_PFPA->CT16B0 = 0x00000;
  SN_PFPA->CT16B1 = 0x02330;
  SN_PFPA->CT16B2 = 0x02010;
  SN_PFPA->CT32B0 = 0x00410;
  SN_PFPA->CT32B1 = 0x21300;
  SN_PFPA->CT32B2 = 0x00030;
#endif

  /* Channel PWM mode selection and polarities setup.*/
  pwmctrl_ct16 = 0;
  pwmctrl_ct32 = 0;
  switch (pwmp->config->channels[0].mode & PWM_OUTPUT_MASK) {
  case PWM_OUTPUT_ACTIVE_LOW:
    pwmctrl_ct16 |= mskCT16_PWM0MODE_1;
    pwmctrl_ct16 |= mskCT16_PWM0EN_EN;
    pwmctrl_ct16 |= mskCT16_PWM0IOEN_EN;
    break;
  case PWM_OUTPUT_ACTIVE_HIGH:
    pwmctrl_ct16 |= mskCT16_PWM0MODE_2;
    pwmctrl_ct16 |= mskCT16_PWM0EN_EN;
    pwmctrl_ct16 |= mskCT16_PWM0IOEN_EN;
    break;
  }
  switch (pwmp->config->channels[1].mode & PWM_OUTPUT_MASK) {
  case PWM_OUTPUT_ACTIVE_LOW:
    pwmctrl_ct16 |= mskCT16_PWM1MODE_1;
    pwmctrl_ct16 |= mskCT16_PWM1EN_EN;
    pwmctrl_ct16 |= mskCT16_PWM1IOEN_EN;
    break;
  case PWM_OUTPUT_ACTIVE_HIGH:
    pwmctrl_ct16 |= mskCT16_PWM1MODE_2;
    pwmctrl_ct16 |= mskCT16_PWM1EN_EN;
    pwmctrl_ct16 |= mskCT16_PWM1IOEN_EN;
    break;
  }
  switch (pwmp->config->channels[2].mode & PWM_OUTPUT_MASK) {
  case PWM_OUTPUT_ACTIVE_LOW:
    pwmctrl_ct16 |= mskCT16_PWM0MODE_1;
    pwmctrl_ct16 |= mskCT16_PWM0EN_EN;
    pwmctrl_ct16 |= mskCT16_PWM0IOEN_EN;
    break;
  case PWM_OUTPUT_ACTIVE_HIGH:
    pwmctrl_ct16 |= mskCT16_PWM0MODE_2;
    pwmctrl_ct16 |= mskCT16_PWM0EN_EN;
    pwmctrl_ct16 |= mskCT16_PWM0IOEN_EN;
    break;
  }
  switch (pwmp->config->channels[3].mode & PWM_OUTPUT_MASK) {
  case PWM_OUTPUT_ACTIVE_LOW:
    pwmctrl_ct32 |= mskCT32_PWM2MODE_1;
    pwmctrl_ct32 |= mskCT32_PWM2EN_EN;
    pwmctrl_ct32 |= mskCT32_PWM2IOEN_EN;
    break;
  case PWM_OUTPUT_ACTIVE_HIGH:
    pwmctrl_ct32 |= mskCT32_PWM2MODE_2;
    pwmctrl_ct32 |= mskCT32_PWM2EN_EN;
    pwmctrl_ct32 |= mskCT32_PWM2IOEN_EN;
    break;
  }
  switch (pwmp->config->channels[4].mode & PWM_OUTPUT_MASK) {
  case PWM_OUTPUT_ACTIVE_LOW:
    pwmctrl_ct32 |= mskCT32_PWM0MODE_1;
    pwmctrl_ct32 |= mskCT32_PWM0EN_EN;
    pwmctrl_ct32 |= mskCT32_PWM0IOEN_EN;
    break;
  case PWM_OUTPUT_ACTIVE_HIGH:
    pwmctrl_ct32 |= mskCT32_PWM0MODE_2;
    pwmctrl_ct32 |= mskCT32_PWM0EN_EN;
    pwmctrl_ct32 |= mskCT32_PWM0IOEN_EN;
    break;
  }
  switch (pwmp->config->channels[5].mode & PWM_OUTPUT_MASK) {
  case PWM_OUTPUT_ACTIVE_LOW:
    pwmctrl_ct32 |= mskCT32_PWM2MODE_1;
    pwmctrl_ct32 |= mskCT32_PWM2EN_EN;
    pwmctrl_ct32 |= mskCT32_PWM2IOEN_EN;
    break;
  case PWM_OUTPUT_ACTIVE_HIGH:
    pwmctrl_ct32 |= mskCT32_PWM2MODE_2;
    pwmctrl_ct32 |= mskCT32_PWM2EN_EN;
    pwmctrl_ct32 |= mskCT32_PWM2IOEN_EN;
    break;
  }
  switch (pwmp->config->channels[6].mode & PWM_OUTPUT_MASK) {
  case PWM_OUTPUT_ACTIVE_LOW:
    pwmctrl_ct32 |= mskCT32_PWM3MODE_1;
    pwmctrl_ct32 |= mskCT32_PWM3EN_EN;
    pwmctrl_ct32 |= mskCT32_PWM3IOEN_EN;
    break;
  case PWM_OUTPUT_ACTIVE_HIGH:
    pwmctrl_ct32 |= mskCT32_PWM3MODE_2;
    pwmctrl_ct32 |= mskCT32_PWM3EN_EN;
    pwmctrl_ct32 |= mskCT32_PWM3IOEN_EN;
    break;
  }
  switch (pwmp->config->channels[7].mode & PWM_OUTPUT_MASK) {
  case PWM_OUTPUT_ACTIVE_LOW:
    pwmctrl_ct32 |= mskCT32_PWM3MODE_1;
    pwmctrl_ct32 |= mskCT32_PWM3EN_EN;
    pwmctrl_ct32 |= mskCT32_PWM3IOEN_EN;
    break;
  case PWM_OUTPUT_ACTIVE_HIGH:
    pwmctrl_ct32 |= mskCT32_PWM3MODE_2;
    pwmctrl_ct32 |= mskCT32_PWM3EN_EN;
    pwmctrl_ct32 |= mskCT32_PWM3IOEN_EN;
    break;
  }
  switch (pwmp->config->channels[8].mode & PWM_OUTPUT_MASK) {
  case PWM_OUTPUT_ACTIVE_LOW:
    pwmctrl_ct32 |= mskCT32_PWM1MODE_1;
    pwmctrl_ct32 |= mskCT32_PWM1EN_EN;
    pwmctrl_ct32 |= mskCT32_PWM1IOEN_EN;
    break;
  case PWM_OUTPUT_ACTIVE_HIGH:
    pwmctrl_ct32 |= mskCT32_PWM1MODE_2;
    pwmctrl_ct32 |= mskCT32_PWM1EN_EN;
    pwmctrl_ct32 |= mskCT32_PWM1IOEN_EN;
    break;
  }
  switch (pwmp->config->channels[9].mode & PWM_OUTPUT_MASK) {
  case PWM_OUTPUT_ACTIVE_LOW:
    pwmctrl_ct16 |= mskCT16_PWM2MODE_1;
    pwmctrl_ct16 |= mskCT16_PWM2EN_EN;
    pwmctrl_ct16 |= mskCT16_PWM2IOEN_EN;
    break;
  case PWM_OUTPUT_ACTIVE_HIGH:
    pwmctrl_ct16 |= mskCT16_PWM2MODE_2;
    pwmctrl_ct16 |= mskCT16_PWM2EN_EN;
    pwmctrl_ct16 |= mskCT16_PWM2IOEN_EN;
    break;
  }
  switch (pwmp->config->channels[10].mode & PWM_OUTPUT_MASK) {
  case PWM_OUTPUT_ACTIVE_LOW:
    pwmctrl_ct16 |= mskCT16_PWM2MODE_1;
    pwmctrl_ct16 |= mskCT16_PWM2EN_EN;
    pwmctrl_ct16 |= mskCT16_PWM2IOEN_EN;
    break;
  case PWM_OUTPUT_ACTIVE_HIGH:
    pwmctrl_ct16 |= mskCT16_PWM2MODE_2;
    pwmctrl_ct16 |= mskCT16_PWM2EN_EN;
    pwmctrl_ct16 |= mskCT16_PWM2IOEN_EN;
    break;
  }
  switch (pwmp->config->channels[11].mode & PWM_OUTPUT_MASK) {
  case PWM_OUTPUT_ACTIVE_LOW:
    pwmctrl_ct32 |= mskCT32_PWM0MODE_1;
    pwmctrl_ct32 |= mskCT32_PWM0EN_EN;
    pwmctrl_ct32 |= mskCT32_PWM0IOEN_EN;
    break;
  case PWM_OUTPUT_ACTIVE_HIGH:
    pwmctrl_ct32 |= mskCT32_PWM0MODE_2;
    pwmctrl_ct32 |= mskCT32_PWM0EN_EN;
    pwmctrl_ct32 |= mskCT32_PWM0IOEN_EN;
    break;
  }
  switch (pwmp->config->channels[12].mode & PWM_OUTPUT_MASK) {
  case PWM_OUTPUT_ACTIVE_LOW:
    pwmctrl_ct32 |= mskCT32_PWM3MODE_1;
    pwmctrl_ct32 |= mskCT32_PWM3EN_EN;
    pwmctrl_ct32 |= mskCT32_PWM3IOEN_EN;
    break;
  case PWM_OUTPUT_ACTIVE_HIGH:
    pwmctrl_ct32 |= mskCT32_PWM3MODE_2;
    pwmctrl_ct32 |= mskCT32_PWM3EN_EN;
    pwmctrl_ct32 |= mskCT32_PWM3IOEN_EN;
    break;
  }
  switch (pwmp->config->channels[13].mode & PWM_OUTPUT_MASK) {
  case PWM_OUTPUT_ACTIVE_LOW:
    pwmctrl_ct16 |= mskCT16_PWM1MODE_1;
    pwmctrl_ct16 |= mskCT16_PWM1EN_EN;
    pwmctrl_ct16 |= mskCT16_PWM1IOEN_EN;
    break;
  case PWM_OUTPUT_ACTIVE_HIGH:
    pwmctrl_ct16 |= mskCT16_PWM1MODE_2;
    pwmctrl_ct16 |= mskCT16_PWM1EN_EN;
    pwmctrl_ct16 |= mskCT16_PWM1IOEN_EN;
    break;
  }
  switch (pwmp->config->channels[14].mode & PWM_OUTPUT_MASK) {
  case PWM_OUTPUT_ACTIVE_LOW:
    pwmctrl_ct16 |= mskCT16_PWM1MODE_1;
    pwmctrl_ct16 |= mskCT16_PWM1EN_EN;
    pwmctrl_ct16 |= mskCT16_PWM1IOEN_EN;
    break;
  case PWM_OUTPUT_ACTIVE_HIGH:
    pwmctrl_ct16 |= mskCT16_PWM1MODE_2;
    pwmctrl_ct16 |= mskCT16_PWM1EN_EN;
    pwmctrl_ct16 |= mskCT16_PWM1IOEN_EN;
    break;
  }
  switch (pwmp->config->channels[15].mode & PWM_OUTPUT_MASK) {
  case PWM_OUTPUT_ACTIVE_LOW:
    pwmctrl_ct32 |= mskCT32_PWM1MODE_1;
    pwmctrl_ct32 |= mskCT32_PWM1EN_EN;
    pwmctrl_ct32 |= mskCT32_PWM1IOEN_EN;
    break;
  case PWM_OUTPUT_ACTIVE_HIGH:
    pwmctrl_ct32 |= mskCT32_PWM1MODE_2;
    pwmctrl_ct32 |= mskCT32_PWM1EN_EN;
    pwmctrl_ct32 |= mskCT32_PWM1IOEN_EN;
    break;
  }
  switch (pwmp->config->channels[16].mode & PWM_OUTPUT_MASK) {
  case PWM_OUTPUT_ACTIVE_LOW:
    pwmctrl_ct32 |= mskCT32_PWM1MODE_1;
    pwmctrl_ct32 |= mskCT32_PWM1EN_EN;
    pwmctrl_ct32 |= mskCT32_PWM1IOEN_EN;
    break;
  case PWM_OUTPUT_ACTIVE_HIGH:
    pwmctrl_ct32 |= mskCT32_PWM1MODE_2;
    pwmctrl_ct32 |= mskCT32_PWM1EN_EN;
    pwmctrl_ct32 |= mskCT32_PWM1IOEN_EN;
    break;
  }
  switch (pwmp->config->channels[17].mode & PWM_OUTPUT_MASK) {
  case PWM_OUTPUT_ACTIVE_LOW:
    pwmctrl_ct16 |= mskCT16_PWM2MODE_1;
    pwmctrl_ct16 |= mskCT16_PWM2EN_EN;
    pwmctrl_ct16 |= mskCT16_PWM2IOEN_EN;
    break;
  case PWM_OUTPUT_ACTIVE_HIGH:
    pwmctrl_ct16 |= mskCT16_PWM2MODE_2;
    pwmctrl_ct16 |= mskCT16_PWM2EN_EN;
    pwmctrl_ct16 |= mskCT16_PWM2IOEN_EN;
    break;
  }
  switch (pwmp->config->channels[18].mode & PWM_OUTPUT_MASK) {
  case PWM_OUTPUT_ACTIVE_LOW:
    pwmctrl_ct32 |= mskCT32_PWM0MODE_1;
    pwmctrl_ct32 |= mskCT32_PWM0EN_EN;
    pwmctrl_ct32 |= mskCT32_PWM0IOEN_EN;
    break;
  case PWM_OUTPUT_ACTIVE_HIGH:
    pwmctrl_ct32 |= mskCT32_PWM0MODE_2;
    pwmctrl_ct32 |= mskCT32_PWM0EN_EN;
    pwmctrl_ct32 |= mskCT32_PWM0IOEN_EN;
    break;
  }
  switch (pwmp->config->channels[19].mode & PWM_OUTPUT_MASK) {
  case PWM_OUTPUT_ACTIVE_LOW:
    pwmctrl_ct32 |= mskCT32_PWM2MODE_1;
    pwmctrl_ct32 |= mskCT32_PWM2EN_EN;
    pwmctrl_ct32 |= mskCT32_PWM2IOEN_EN;
    break;
  case PWM_OUTPUT_ACTIVE_HIGH:
    pwmctrl_ct32 |= mskCT32_PWM2MODE_2;
    pwmctrl_ct32 |= mskCT32_PWM2EN_EN;
    pwmctrl_ct32 |= mskCT32_PWM2IOEN_EN;
    break;
  }
  switch (pwmp->config->channels[20].mode & PWM_OUTPUT_MASK) {
  case PWM_OUTPUT_ACTIVE_LOW:
    pwmctrl_ct16 |= mskCT16_PWM0MODE_1;
    pwmctrl_ct16 |= mskCT16_PWM0EN_EN;
    pwmctrl_ct16 |= mskCT16_PWM0IOEN_EN;
    break;
  case PWM_OUTPUT_ACTIVE_HIGH:
    pwmctrl_ct16 |= mskCT16_PWM0MODE_2;
    pwmctrl_ct16 |= mskCT16_PWM0EN_EN;
    pwmctrl_ct16 |= mskCT16_PWM0IOEN_EN;
    break;
  }

  pwmp->ct16->PWMCTRL = pwmctrl_ct16;
  pwmp->ct32->PWMCTRL = pwmctrl_ct32;
  }
  else {
    /* Driver re-configuration scenario, it must be stopped first.*/
    pwmp->ct16->TMRCTRL = CT16_CEN_DIS;       /* Timer disabled.              */
    pwmp->ct32->TMRCTRL = CT32_CEN_DIS;       /* Timer disabled.              */
    CT16B0_ResetTimer();                      /* Counter reset to zero.       */
    CT16B1_ResetTimer();                      /* Counter reset to zero.       */
    CT16B2_ResetTimer();                      /* Counter reset to zero.       */
    CT32B0_ResetTimer();                      /* Counter reset to zero.       */
    CT32B1_ResetTimer();                      /* Counter reset to zero.       */
    CT32B2_ResetTimer();                      /* Counter reset to zero.       */
  }

  /* Timer configuration.*/
  pwmp->ct16->PRE = 0x30;
  pwmp->ct32->PRE = 0x30;
  pwmp->ct16->MR3 = pwmp->period - 1;

#if SN32_PWM_USE_ONESHOT || defined(__DOXYGEN__)
  pwmp->ct16->MCTRL |= mskCT16_MR3STOP_EN;
#elif !defined(SN32_PWM_NO_RESET)
  pwmp->ct16->MCTRL |= mskCT16_MR3RST_EN;
#endif

  pwmp->ct16->IC &= 0x1FFFFFF;           /* Clear pending IRQs.          */
  pwmp->ct32->IC &= 0x1FFFFFF;           /* Clear pending IRQs.          */

  /* Timer configured and started.*/
  pwmp->ct16->TMRCTRL |= mskCT16_CEN_EN;
  pwmp->ct32->TMRCTRL |= mskCT32_CEN_EN;
}

/**
 * @brief   Deactivates the PWM peripheral.
 *
 * @param[in] pwmp      pointer to a @p PWMDriver object
 *
 * @notapi
 */
void pwm_lld_stop(PWMDriver *pwmp) {

  /* If in ready state then disables the PWM clock.*/
  if (pwmp->state == PWM_READY) {
    pwmp->ct16->TMRCTRL = CT16_CEN_DIS;       /* Timer disabled.              */
    pwmp->ct32->TMRCTRL = CT32_CEN_DIS;       /* Timer disabled.              */
    pwmp->ct16->IC &= 0x1FFFFFF;              /* Clear pending IRQs.          */
    pwmp->ct32->IC &= 0x1FFFFFF;              /* Clear pending IRQs.          */

#if SN32_PWM_USE_CT16B0
    if (&PWMD1 == pwmp) {
#if !defined(SN32_CT16B0_SUPPRESS_ISR)
      nvicDisableVector(SN32_CT16B0_NUMBER);
#endif
      SN_SYS1->AHBCLKEN_b.CT16B0CLKEN = DISABLE;
    }
#endif

#if SN32_PWM_USE_CT16B1
    if (&PWMD2 == pwmp) {
      SN_SYS1->AHBCLKEN_b.CT16B1CLKEN = DISABLE;
    }
#endif

#if SN32_PWM_USE_CT16B2
    if (&PWMD3 == pwmp) {
      SN_SYS1->AHBCLKEN_b.CT16B2CLKEN = DISABLE;
    }
#endif

#if SN32_PWM_USE_CT32B0
    if (&PWMD4 == pwmp) {
      SN_SYS1->AHBCLKEN_b.CT32B0CLKEN = DISABLE;
    }
#endif

#if SN32_PWM_USE_CT32B1
    if (&PWMD5 == pwmp) {
      SN_SYS1->AHBCLKEN_b.CT32B1CLKEN = DISABLE;
    }
#endif

#if SN32_PWM_USE_CT32B2
    if (&PWMD6 == pwmp) {
      SN_SYS1->AHBCLKEN_b.CT32B2CLKEN = DISABLE;
    }
#endif
  }
}

/**
 * @brief   Enables a PWM channel.
 * @pre     The PWM unit must have been activated using @p pwmStart().
 * @post    The channel is active using the specified configuration.
 * @note    The function has effect at the next cycle start.
 * @note    Channel notification is not enabled.
 *
 * @param[in] pwmp      pointer to a @p PWMDriver object
 * @param[in] channel   PWM channel identifier (0...channels-1)
 * @param[in] width     PWM pulse width as clock pulses number
 *
 * @notapi
 */
void pwm_lld_enable_channel(PWMDriver *pwmp,
                            pwmchannel_t channel,
                            pwmcnt_t width) {

  /* Changing channel duty cycle on the fly.*/
  switch(channel){
    case 0:
      SN_CT16B0->MR0 = width;
      SN_CT16B0->PWMCTRL |= mskCT16_PWM0IOEN_EN;
      break;
    case 1:
      SN_CT16B0->MR1 = width;
      SN_CT16B0->PWMCTRL |= mskCT16_PWM1IOEN_EN;
      break;
    case 2:
      SN_CT16B2->MR0 = width;
      SN_CT16B2->PWMCTRL |= mskCT16_PWM0IOEN_EN;
      break;
    case 3:
      SN_CT32B2->MR2 = width;
      SN_CT32B2->PWMCTRL |= mskCT32_PWM2IOEN_EN;
      break;
    case 4:
      SN_CT32B0->MR0 = width;
      SN_CT32B0->PWMCTRL |= mskCT32_PWM0IOEN_EN;
      break;
    case 5:
      SN_CT32B1->MR2 = width;
      SN_CT32B1->PWMCTRL |= mskCT32_PWM2IOEN_EN;
      break;
    case 6:
      SN_CT32B2->MR3 = width;
      SN_CT32B2->PWMCTRL |= mskCT32_PWM3IOEN_EN;
      break;
    case 7:
      SN_CT32B1->MR3 = width;
      SN_CT32B1->PWMCTRL |= mskCT32_PWM3IOEN_EN;
      break;
    case 8:
      SN_CT32B2->MR1 = width;
      SN_CT32B2->PWMCTRL |= mskCT32_PWM1IOEN_EN;
      break;
    case 9:
      SN_CT16B1->MR2 = width;
      SN_CT16B1->PWMCTRL |= mskCT16_PWM2IOEN_EN;
      break;
    case 10:
      SN_CT16B2->MR2 = width;
      SN_CT16B2->PWMCTRL |= mskCT16_PWM2IOEN_EN;
      break;
    case 11:
      SN_CT32B2->MR0 = width;
      SN_CT32B2->PWMCTRL |= mskCT32_PWM0IOEN_EN;
      break;
    case 12:
      SN_CT32B0->MR3 = width;
      SN_CT32B0->PWMCTRL |= mskCT32_PWM3IOEN_EN;
      break;
    case 13:
      SN_CT16B1->MR1 = width;
      SN_CT16B1->PWMCTRL |= mskCT16_PWM1IOEN_EN;
      break;
    case 14:
      SN_CT16B2->MR1 = width;
      SN_CT16B2->PWMCTRL |= mskCT16_PWM1IOEN_EN;
      break;
    case 15:
      SN_CT32B1->MR1 = width;
      SN_CT32B1->PWMCTRL |= mskCT32_PWM1IOEN_EN;
      break;
    case 16:
      SN_CT32B0->MR1 = width;
      SN_CT32B0->PWMCTRL |= mskCT32_PWM1IOEN_EN;
      break;
    case 17:
      SN_CT16B0->MR2 = width;
      SN_CT16B0->PWMCTRL |= mskCT16_PWM2IOEN_EN;
      break;
    case 18:
      SN_CT32B1->MR0 = width;
      SN_CT32B1->PWMCTRL |= mskCT32_PWM0IOEN_EN;
      break;
    case 19:
      SN_CT32B0->MR2 = width;
      SN_CT32B0->PWMCTRL |= mskCT32_PWM2IOEN_EN;
      break;
    case 20:
      SN_CT16B1->MR0 = width;
      SN_CT16B1->PWMCTRL |= mskCT16_PWM0IOEN_EN;
      break;
    default:
      ;
  }
}

/**
 * @brief   Disables a PWM channel and its notification.
 * @pre     The PWM unit must have been activated using @p pwmStart().
 * @post    The channel is disabled and its output line returned to the
 *          idle state.
 * @note    The function has effect at the next cycle start.
 *
 * @param[in] pwmp      pointer to a @p PWMDriver object
 * @param[in] channel   PWM channel identifier (0...channels-1)
 *
 * @notapi
 */
void pwm_lld_disable_channel(PWMDriver *pwmp, pwmchannel_t channel) {

  /* Changing channel duty cycle on the fly.*/
  switch(channel){
    case 0:
      SN_CT16B0->IC |= mskCT16_MR0IC;
      SN_CT16B0->PWMCTRL &= ~mskCT16_PWM0IOEN_EN;
      break;
    case 1:
      SN_CT16B0->IC |= mskCT16_MR1IC;
      SN_CT16B0->PWMCTRL &= ~mskCT16_PWM1IOEN_EN;
      break;
    case 2:
      SN_CT16B2->IC |= mskCT16_MR0IC;
      SN_CT16B2->PWMCTRL &= ~mskCT16_PWM0IOEN_EN;
      break;
    case 3:
      SN_CT32B2->IC |= mskCT32_MR2IC;
      SN_CT32B2->PWMCTRL &= ~mskCT32_PWM2IOEN_EN;
      break;
    case 4:
      SN_CT32B0->IC |= mskCT32_MR0IC;
      SN_CT32B0->PWMCTRL &= ~mskCT32_PWM0IOEN_EN;
      break;
    case 5:
      SN_CT32B1->IC |= mskCT32_MR2IC;
      SN_CT32B1->PWMCTRL &= ~mskCT32_PWM2IOEN_EN;
      break;
    case 6:
      SN_CT32B2->IC |= mskCT32_MR3IC;
      SN_CT32B2->PWMCTRL &= ~mskCT32_PWM3IOEN_EN;
      break;
    case 7:
      SN_CT32B1->IC |= mskCT32_MR3IC;
      SN_CT32B1->PWMCTRL &= ~mskCT32_PWM3IOEN_EN;
      break;
    case 8:
      SN_CT32B2->IC |= mskCT32_MR1IC;
      SN_CT32B2->PWMCTRL &= ~mskCT32_PWM1IOEN_EN;
      break;
    case 9:
      SN_CT16B1->IC |= mskCT16_MR2IC;
      SN_CT16B1->PWMCTRL &= ~mskCT16_PWM2IOEN_EN;
      break;
    case 10:
      SN_CT16B2->IC |= mskCT16_MR2IC;
      SN_CT16B2->PWMCTRL &= ~mskCT16_PWM2IOEN_EN;
      break;
    case 11:
      SN_CT32B2->IC |= mskCT32_MR0IC;
      SN_CT32B2->PWMCTRL &= ~mskCT32_PWM0IOEN_EN;
      break;
    case 12:
      SN_CT32B0->IC |= mskCT32_MR3IC;
      SN_CT32B0->PWMCTRL &= ~mskCT32_PWM3IOEN_EN;
      break;
    case 13:
      SN_CT16B1->IC |= mskCT16_MR1IC;
      SN_CT16B1->PWMCTRL &= ~mskCT16_PWM1IOEN_EN;
      break;
    case 14:
      SN_CT16B2->IC |= mskCT16_MR1IC;
      SN_CT16B2->PWMCTRL &= ~mskCT16_PWM1IOEN_EN;
      break;
    case 15:
      SN_CT32B1->IC |= mskCT32_MR1IC;
      SN_CT32B1->PWMCTRL &= ~mskCT32_PWM1IOEN_EN;
      break;
    case 16:
      SN_CT32B0->IC |= mskCT32_MR1IC;
      SN_CT32B0->PWMCTRL &= ~mskCT32_PWM1IOEN_EN;
      break;
    case 17:
      SN_CT16B0->IC |= mskCT32_MR2IC;
      SN_CT16B0->PWMCTRL &= ~mskCT16_PWM2IOEN_EN;
      break;
    case 18:
      SN_CT32B1->IC |= mskCT32_MR0IC;
      SN_CT32B1->PWMCTRL &= ~mskCT32_PWM0IOEN_EN;
      break;
    case 19:
      SN_CT32B0->IC |= mskCT32_MR2IC;
      SN_CT32B0->PWMCTRL &= ~mskCT32_PWM2IOEN_EN;
      break;
    case 20:
      SN_CT16B1->IC |= mskCT16_MR0IC;
      SN_CT16B1->PWMCTRL &= ~mskCT16_PWM0IOEN_EN;
      break;
    default:
      ;
  }
}

/**
 * @brief   Enables the periodic activation edge notification.
 * @pre     The PWM unit must have been activated using @p pwmStart().
 * @note    If the notification is already enabled then the call has no effect.
 *
 * @param[in] pwmp      pointer to a @p PWMDriver object
 *
 * @notapi
 */
void pwm_lld_enable_periodic_notification(PWMDriver *pwmp) {
  pwmp->ct16->MCTRL |= mskCT16_MR3IE_EN;
}

/**
 * @brief   Disables the periodic activation edge notification.
 * @pre     The PWM unit must have been activated using @p pwmStart().
 * @note    If the notification is already disabled then the call has no effect.
 *
 * @param[in] pwmp      pointer to a @p PWMDriver object
 *
 * @notapi
 */
void pwm_lld_disable_periodic_notification(PWMDriver *pwmp) {
  pwmp->ct16->IC |= mskCT16_MR3IC;
  pwmp->ct16->MCTRL &= ~mskCT16_MR3IE_EN;
}

/**
 * @brief   Enables a channel de-activation edge notification.
 * @pre     The PWM unit must have been activated using @p pwmStart().
 * @pre     The channel must have been activated using @p pwmEnableChannel().
 * @note    If the notification is already enabled then the call has no effect.
 *
 * @param[in] pwmp      pointer to a @p PWMDriver object
 * @param[in] channel   PWM channel identifier (0...channels-1)
 *
 * @notapi
 */
void pwm_lld_enable_channel_notification(PWMDriver *pwmp,
                                         pwmchannel_t channel) {
  switch(channel){
    case 0:
      pwmp->ct16->MCTRL |= mskCT16_MR0IE_EN;
      break;
    case 1:
      pwmp->ct16->MCTRL |= mskCT16_MR1IE_EN;
      break;
    case 2:
      pwmp->ct16->MCTRL |= mskCT16_MR0IE_EN;
      break;
    case 3:
      pwmp->ct32->MCTRL |= mskCT32_MR2IE_EN;
      break;
    case 4:
      pwmp->ct32->MCTRL |= mskCT32_MR0IE_EN;
      break;
    case 5:
      pwmp->ct32->MCTRL |= mskCT32_MR2IE_EN;
      break;
    case 6:
      pwmp->ct32->MCTRL |= mskCT32_MR3IE_EN;
      break;
    case 7:
      pwmp->ct32->MCTRL |= mskCT32_MR3IE_EN;
      break;
    case 8:
      pwmp->ct32->MCTRL |= mskCT32_MR1IE_EN;
      break;
    case 9:
      pwmp->ct16->MCTRL |= mskCT16_MR2IE_EN;
      break;
    case 10:
      pwmp->ct16->MCTRL |= mskCT16_MR2IE_EN;
      break;
    case 11:
      pwmp->ct32->MCTRL |= mskCT32_MR0IE_EN;
      break;
    case 12:
      pwmp->ct32->MCTRL |= mskCT32_MR3IE_EN;
      break;
    case 13:
      pwmp->ct16->MCTRL |= mskCT16_MR1IE_EN;
      break;
    case 14:
      pwmp->ct16->MCTRL |= mskCT16_MR1IE_EN;
      break;
    case 15:
      pwmp->ct32->MCTRL |= mskCT32_MR1IE_EN;
      break;
    case 16:
      pwmp->ct32->MCTRL |= mskCT32_MR1IE_EN;
      break;
    case 17:
      pwmp->ct16->MCTRL |= mskCT16_MR2IE_EN;
      break;
    case 18:
      pwmp->ct32->MCTRL |= mskCT32_MR0IE_EN;
      break;
    case 19:
      pwmp->ct32->MCTRL |= mskCT32_MR2IE_EN;
      break;
    case 20:
      pwmp->ct16->MCTRL |= mskCT16_MR0IE_EN;
      break;
    default:
      ;
  }
}

/**
 * @brief   Disables a channel de-activation edge notification.
 * @pre     The PWM unit must have been activated using @p pwmStart().
 * @pre     The channel must have been activated using @p pwmEnableChannel().
 * @note    If the notification is already disabled then the call has no effect.
 *
 * @param[in] pwmp      pointer to a @p PWMDriver object
 * @param[in] channel   PWM channel identifier (0...channels-1)
 *
 * @notapi
 */
void pwm_lld_disable_channel_notification(PWMDriver *pwmp,
                                          pwmchannel_t channel) {
  switch(channel){
    case 0:
      pwmp->ct16->MCTRL &= ~mskCT16_MR0IE_EN;
      break;
    case 1:
      pwmp->ct16->MCTRL &= ~mskCT16_MR1IE_EN;
      break;
    case 2:
      pwmp->ct16->MCTRL &= ~mskCT16_MR0IE_EN;
      break;
    case 3:
      pwmp->ct32->MCTRL &= ~mskCT32_MR2IE_EN;
      break;
    case 4:
      pwmp->ct32->MCTRL &= ~mskCT32_MR0IE_EN;
      break;
    case 5:
      pwmp->ct32->MCTRL &= ~mskCT32_MR2IE_EN;
      break;
    case 6:
      pwmp->ct32->MCTRL &= ~mskCT32_MR3IE_EN;
      break;
    case 7:
      pwmp->ct32->MCTRL &= ~mskCT32_MR3IE_EN;
      break;
    case 8:
      pwmp->ct32->MCTRL &= ~mskCT32_MR1IE_EN;
      break;
    case 9:
      pwmp->ct16->MCTRL &= ~mskCT16_MR2IE_EN;
      break;
    case 10:
      pwmp->ct16->MCTRL &= ~mskCT16_MR2IE_EN;
      break;
    case 11:
      pwmp->ct32->MCTRL &= ~mskCT32_MR0IE_EN;
      break;
    case 12:
      pwmp->ct32->MCTRL &= ~mskCT32_MR3IE_EN;
      break;
    case 13:
      pwmp->ct16->MCTRL &= ~mskCT16_MR1IE_EN;
      break;
    case 14:
      pwmp->ct16->MCTRL &= ~mskCT16_MR1IE_EN;
      break;
    case 15:
      pwmp->ct32->MCTRL &= ~mskCT32_MR1IE_EN;
      break;
    case 16:
      pwmp->ct32->MCTRL &= ~mskCT32_MR1IE_EN;
      break;
    case 17:
      pwmp->ct16->MCTRL &= ~mskCT16_MR2IE_EN;
      break;
    case 18:
      pwmp->ct32->MCTRL &= ~mskCT32_MR0IE_EN;
      break;
    case 19:
      pwmp->ct32->MCTRL &= ~mskCT32_MR2IE_EN;
      break;
    case 20:
      pwmp->ct16->MCTRL &= ~mskCT16_MR0IE_EN;
      break;
    default:
      ;
  }
}

/**
 * @brief   Common CT IRQ handler.
 * @note    It is assumed that the various sources are only activated if the
 *          associated callback pointer is not equal to @p NULL in order to not
 *          perform an extra check in a potentially critical interrupt handler.
 *
 * @param[in] pwmp      pointer to a @p PWMDriver object
 *
 * @notapi
 */
void pwm_lld_serve_interrupt(PWMDriver *pwmp) {
  uint32_t ris_ct16;
  uint32_t ris_ct32;

  ris_ct16 = pwmp->ct16->RIS;
  ris_ct32 = pwmp->ct32->RIS;
  if (((ris_ct16 & mskCT16_MR0IF) != 0) &&
      (pwmp->config->channels[0].callback != NULL))
    pwmp->config->channels[0].callback(pwmp);
  if (((ris_ct16 & mskCT16_MR1IF) != 0) &&
      (pwmp->config->channels[1].callback != NULL))
    pwmp->config->channels[1].callback(pwmp);
  if (((ris_ct16 & mskCT16_MR0IF) != 0) &&
      (pwmp->config->channels[2].callback != NULL))
    pwmp->config->channels[2].callback(pwmp);
  if (((ris_ct32 & mskCT32_MR2IF) != 0) &&
      (pwmp->config->channels[3].callback != NULL))
    pwmp->config->channels[3].callback(pwmp);
  if (((ris_ct32 & mskCT32_MR0IF) != 0) &&
      (pwmp->config->channels[4].callback != NULL))
    pwmp->config->channels[4].callback(pwmp);
  if (((ris_ct32 & mskCT32_MR2IF) != 0) &&
      (pwmp->config->channels[5].callback != NULL))
    pwmp->config->channels[5].callback(pwmp);
  if (((ris_ct32 & mskCT32_MR3IF) != 0) &&
      (pwmp->config->channels[6].callback != NULL))
    pwmp->config->channels[6].callback(pwmp);
  if (((ris_ct32 & mskCT32_MR3IF) != 0) &&
      (pwmp->config->channels[7].callback != NULL))
    pwmp->config->channels[7].callback(pwmp);
  if (((ris_ct32 & mskCT32_MR1IF) != 0) &&
      (pwmp->config->channels[8].callback != NULL))
    pwmp->config->channels[8].callback(pwmp);
  if (((ris_ct16 & mskCT16_MR2IF) != 0) &&
      (pwmp->config->channels[9].callback != NULL))
    pwmp->config->channels[9].callback(pwmp);
  if (((ris_ct16 & mskCT16_MR2IF) != 0) &&
      (pwmp->config->channels[10].callback != NULL))
    pwmp->config->channels[10].callback(pwmp);
  if (((ris_ct32 & mskCT32_MR0IF) != 0) &&
      (pwmp->config->channels[11].callback != NULL))
    pwmp->config->channels[11].callback(pwmp);
  if (((ris_ct32 & mskCT32_MR3IF) != 0) &&
      (pwmp->config->channels[12].callback != NULL))
    pwmp->config->channels[12].callback(pwmp);
  if (((ris_ct16 & mskCT16_MR1IF) != 0) &&
      (pwmp->config->channels[13].callback != NULL))
    pwmp->config->channels[13].callback(pwmp);
  if (((ris_ct16 & mskCT16_MR1IF) != 0) &&
      (pwmp->config->channels[14].callback != NULL))
    pwmp->config->channels[14].callback(pwmp);
  if (((ris_ct32 & mskCT32_MR1IF) != 0) &&
      (pwmp->config->channels[15].callback != NULL))
    pwmp->config->channels[15].callback(pwmp);
  if (((ris_ct32 & mskCT32_MR1IF) != 0) &&
      (pwmp->config->channels[16].callback != NULL))
    pwmp->config->channels[16].callback(pwmp);
  if (((ris_ct16 & mskCT16_MR2IF) != 0) &&
      (pwmp->config->channels[17].callback != NULL))
    pwmp->config->channels[17].callback(pwmp);
  if (((ris_ct32 & mskCT32_MR0IF) != 0) &&
      (pwmp->config->channels[18].callback != NULL))
    pwmp->config->channels[18].callback(pwmp);
  if (((ris_ct32 & mskCT32_MR2IF) != 0) &&
      (pwmp->config->channels[19].callback != NULL))
    pwmp->config->channels[19].callback(pwmp);
  if (((ris_ct16 & mskCT16_MR0IF) != 0) &&
      (pwmp->config->channels[20].callback != NULL))
    pwmp->config->channels[20].callback(pwmp);
  if (((ris_ct16 & mskCT16_MR3IF) != 0) && (pwmp->config->callback != NULL))
    pwmp->config->callback(pwmp);
}

#endif /* HAL_USE_PWM */

/** @} */
