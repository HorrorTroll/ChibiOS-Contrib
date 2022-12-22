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
 * @defgroup AT32F403A_F407_HAL AT32F403A/F407 HAL Support
 * @details HAL support for AT32 New Performance Line and Connectivity Line sub-families.
 *
 * @ingroup HAL
 */

/**
 * @file    AT32F40xx/hal_lld_f403a_f407.h
 * @brief   AT32F403A/F407 HAL subsystem low level driver header.
 *
 * @addtogroup AT32F403A_F407_HAL
 * @{
 */

#ifndef _HAL_LLD_F403A_F407_H_
#define _HAL_LLD_F403A_F407_H_

/*===========================================================================*/
/* Driver constants.                                                         */
/*===========================================================================*/

/**
 * @name    Absolute Maximum Ratings
 * @{
 */
/**
 * @brief   Maximum system clock frequency.
 */
#define AT32_SYSCLK_MAX         240000000

/**
 * @brief   Maximum HEXT clock frequency.
 */
#define AT32_HEXTCLK_MAX        25000000

/**
 * @brief   Minimum HEXT clock frequency.
 */
#define AT32_HEXTCLK_MIN        4000000

/**
 * @brief   Maximum LEXT clock frequency.
 */
#define AT32_LEXTCLK_MAX        1000000

/**
 * @brief   Minimum LEXT clock frequency.
 */
#define AT32_LEXTCLK_MIN        32768

/**
 * @brief   Maximum PLLs input clock frequency.
 */
#define AT32_PLLIN_MAX          16000000

/**
 * @brief   Minimum PLLs input clock frequency.
 */
#define AT32_PLLIN_MIN          2000000

/**
 * @brief   Maximum PLL output clock frequency.
 */
#define AT32_PLLOUT_MAX         240000000

/**
 * @brief   Minimum PLL output clock frequency.
 */
#define AT32_PLLOUT_MIN         16000000

/**
 * @brief   Maximum APB1 clock frequency.
 */
#define AT32_PCLK1_MAX          120000000

/**
 * @brief   Maximum APB2 clock frequency.
 */
#define AT32_PCLK2_MAX          120000000

/**
 * @brief   Maximum ADC clock frequency.
 */
#define AT32_ADCCLK_MAX         28000000
/** @} */

/**
 * @name    CRM_CFG register bits definitions
 * @{
 */
#define AT32_SCLKSEL_HICK       (0 << 0)                /**< SCLK source is HICK. */
#define AT32_SCLKSEL_HEXT       (1 << 0)                /**< SCLK source is HEXT. */
#define AT32_SCLKSEL_PLL        (2 << 0)                /**< SCLK source is PLL. */

#define AT32_AHBDIV_DIV1        (0 << 4)                /**< SCLK divided by 1. */
#define AT32_AHBDIV_DIV2        (8 << 4)                /**< SCLK divided by 2. */
#define AT32_AHBDIV_DIV4        (9 << 4)                /**< SCLK divided by 4. */
#define AT32_AHBDIV_DIV8        (10 << 4)               /**< SCLK divided by 8. */
#define AT32_AHBDIV_DIV16       (11 << 4)               /**< SCLK divided by 16. */
#define AT32_AHBDIV_DIV64       (12 << 4)               /**< SCLK divided by 64. */
#define AT32_AHBDIV_DIV128      (13 << 4)               /**< SCLK divided by 128. */
#define AT32_AHBDIV_DIV256      (14 << 4)               /**< SCLK divided by 256. */
#define AT32_AHBDIV_DIV512      (15 << 4)               /**< SCLK divided by 512. */

#define AT32_APB1DIV_DIV1       (0 << 8)                /**< HCLK divided by 1. */
#define AT32_APB1DIV_DIV2       (4 << 8)                /**< HCLK divided by 2. */
#define AT32_APB1DIV_DIV4       (5 << 8)                /**< HCLK divided by 4. */
#define AT32_APB1DIV_DIV8       (6 << 8)                /**< HCLK divided by 8. */
#define AT32_APB1DIV_DIV16      (7 << 8)                /**< HCLK divided by 16. */

#define AT32_APB2DIV_DIV1       (0 << 11)               /**< HCLK divided by 1. */
#define AT32_APB2DIV_DIV2       (4 << 11)               /**< HCLK divided by 2. */
#define AT32_APB2DIV_DIV4       (5 << 11)               /**< HCLK divided by 4. */
#define AT32_APB2DIV_DIV8       (6 << 11)               /**< HCLK divided by 8. */
#define AT32_APB2DIV_DIV16      (7 << 11)               /**< HCLK divided by 16. */

#define AT32_ADCDIV_DIV2        (0 << 14)               /**< PCLK divided by 2. */
#define AT32_ADCDIV_DIV4        (1 << 14)               /**< PCLK divided by 4. */
#define AT32_ADCDIV_DIV6        (2 << 14)               /**< PCLK divided by 6. */
#define AT32_ADCDIV_DIV8        (3 << 14)               /**< PCLK divided by 8. */
#define AT32_ADCDIV_DIV12       ((1 << 28) | (1 << 14)) /**< PCLK divided by 12. */
#define AT32_ADCDIV_DIV16       ((1 << 28) | (3 << 14)) /**< PCLK divided by 16. */

#define AT32_PLLRCS_HICK        (0 << 16)               /**< PLL clock source is HICK. */
#define AT32_PLLRCS_HEXT        (1 << 16)               /**< PLL clock source is HEXT. */

#define AT32_PLLHEXTDIV_DIV1    (0 << 17)               /**< HEXT divided by 1. */
#define AT32_PLLHEXTDIV_DIVX    (1 << 17)               /**< HEXT divided by AT32_HEXTDIV_DIVx */

#define AT32_USBDIV_DIV1_5      (0 << 22)               /**< PLLOUT divided by 1.5. */
#define AT32_USBDIV_DIV1        (1 << 22)               /**< PLLOUT divided by 1. */
#define AT32_USBDIV_DIV2_5      (2 << 22)               /**< PLLOUT divided by 2.5. */
#define AT32_USBDIV_DIV2        (3 << 22)               /**< PLLOUT divided by 2. */
#define AT32_USBDIV_DIV3_5      ((1 << 27) | (0 << 22)) /**< PLLOUT divided by 3.5. */
#define AT32_USBDIV_DIV3        ((1 << 27) | (1 << 22)) /**< PLLOUT divided by 3. */
#define AT32_USBDIV_DIV4        ((1 << 27) | (2 << 22)) /**< PLLOUT divided by 4. */

#define AT32_CLKOUT_SEL_NOCLOCK (0 << 24)               /**< No clock on CLKOUT_SEL pin. */
#define AT32_CLKOUT_SEL_LICK    (2 << 24)               /**< LICK clockon CLKOUT_SEL pin. */
#define AT32_CLKOUT_SEL_LEXT    (3 << 24)               /**< LEXT clock on CLKOUT_SEL pin. */
#define AT32_CLKOUT_SEL_SCLK    (4 << 24)               /**< SCLK on CLKOUT_SEL pin. */
#define AT32_CLKOUT_SEL_HICK    (5 << 24)               /**< HICK clock on CLKOUT_SEL pin. */
#define AT32_CLKOUT_SEL_HEXT    (6 << 24)               /**< HEXT clock on CLKOUT_SEL pin. */
#define AT32_CLKOUT_SEL_PLLDIV2 (7 << 24)               /**< PLL/2 clock on CLKOUT_SEL pin. */
/** @} */

/**
 * @name    CRM_BPDC register bits definitions
 * @{
 */
#define AT32_RTCSEL_MASK        (3 << 8) /**< RTC clock source mask.                 */
#define AT32_RTCSEL_NOCLOCK     (0 << 8) /**< No clock.                              */
#define AT32_RTCSEL_LEXT        (1 << 8) /**< LEXT used as RTC clock.                */
#define AT32_RTCSEL_LICK        (2 << 8) /**< LICK used as RTC clock.                */
#define AT32_RTCSEL_HEXTDIV     (3 << 8) /**< HEXT divided by 128 used as RTC clock. */
/** @} */

/**
 * @name    CRM_MISC1 Additional Register
 * @{
 */
#define AT32_HICKDIV_DIV6       (0 << 25)               /**< HICK/6 enable 8 MHz. */
#define AT32_HICKDIV_DIV1       (1 << 25)               /**< HICK outputs clock 48 MHz. */
                                                        /**< sets HEXT_DIV_EN = 1. */
#define AT32_CLKOUT_SEL_PLLDIV4 ((1 << 16) | (4 << 24)) /*!< PLL/4 clock on CLKOUT_SEL pin. */
#define AT32_CLKOUT_SEL_USB     ((1 << 16) | (5 << 22)) /*!< USB clock on CLKOUT_SEL pin. */
#define AT32_CLKOUT_SEL_ADC     ((1 << 16) | (6 << 22)) /*!< ADC clock on CLKOUT_SEL pin. */
/** @} */

/**
 * @name    CRM_MISC3 Additional Register
 * @{
 */
#define AT32_HICK_TO_USB_PLL    (0 << 8) /**< USB clock source is PLL or divider. */
#define AT32_HICK_TO_USB_HICK   (1 << 8) /**< USB clock source is HICK or HICK/6. */
                                         /**< sets HEXT_DIV_EN = 1. */

#define AT32_HICK_TO_SCLK_SEL0  (0 << 9) /**< Fixed 8MHz */
#define AT32_HICK_TO_SCLK_SEL1  (1 << 9) /**< 48MHz or 8MHz */
                                         /**< sets HEXT_DIV_EN = 1. */

#define AT32_HEXTDIV_DIV2       (0 << 12) /**< HEXT clock divide by 2. */
#define AT32_HEXTDIV_DIV3       (1 << 12) /**< HEXT clock divide by 3. */
#define AT32_HEXTDIV_DIV4       (2 << 12) /**< HEXT clock divide by 4. */
#define AT32_HEXTDIV_DIV5       (3 << 12) /**< HEXT clock divide by 5. */
                                          /**< HEXT_DIV_CTRL. */
/** @} */

/*===========================================================================*/
/* Driver pre-compile time settings.                                         */
/*===========================================================================*/

/**
 * @name    Configuration options
 * @{
 */
/**
 * @brief   Main clock source selection.
 * @note    If the selected clock source is not the PLL then the PLL is not
 *          initialized and started.
 * @note    The default value is calculated for a 240MHz system clock from
 *          a 48MHz crystal using the PLL.
 */
#if !defined(AT32_SCLKSEL) || defined(__DOXYGEN__)
#define AT32_SCLKSEL                AT32_SCLKSEL_PLL
#endif

/**
 * @brief   Clock source for the PLL.
 * @note    This setting has only effect if the PLL is selected as the
 *          system clock source.
 * @note    The default value is calculated for a 240MHz system clock from
 *          a 48MHz crystal using the PLL.
 */
#if !defined(AT32_PLLRCS) || defined(__DOXYGEN__)
#define AT32_PLLRCS                 AT32_PLLRCS_HEXT
#endif

/**
 * @brief   Clock source to control HICK TO SCLK
 * @note    The default value is calculated for a 240MHz system clock from
 *          a 48MHz HICK crystal using the PLL.
 */
#if !defined(AT32_HICK_TO_SCLK) || defined(__DOXYGEN__)
#define AT32_HICK_TO_SCLK           AT32_HICK_TO_SCLK_SEL1
#endif

/**
 * @brief   Clock source to control HICK DIV EN
 * @note    The default value is calculated for a 240MHz system clock from
 *          a 48MHz HICK crystal using the PLL.
 */
#if !defined(AT32_HICKDIV) || defined(__DOXYGEN__)
#define AT32_HICKDIV                AT32_HICKDIV_DIV1
#endif

/**
 * @brief   Clock source to control USB Clock Source
 * @note    The default value is calculated for a 240MHz system clock from
 *          a 48MHz HICK crystal using the PLL.
 */
#if !defined(AT32_HICK_TO_USB) || defined(__DOXYGEN__)
#define AT32_HICK_TO_USB            AT32_HICK_TO_USB_HICK
#endif

/**
 * @brief   HEXT Crystal divider
 * @note    This setting has only effect if the HEXT is enabled
 * @note    The default value is calculated for a 240MHz system clock from
 *          a 48MHz HSI crystal using the PLL.
 */
#if !defined(AT32_HEXT_DIV) || defined(__DOXYGEN__)
#define AT32_HEXT_DIV               AT32_HEXTDIV_DIV2
#endif

/**
 * @brief   Crystal PLL pre-divider.
 * @note    This setting has only effect if the PLL is selected as the
 *          system clock source.
 * @note    The default value is calculated for a 240MHz system clock from
 *          a 48MHz crystal using the PLL.
 */
#if !defined(AT32_PLLHEXTDIV) || defined(__DOXYGEN__)
#define AT32_PLLHEXTDIV             AT32_PLLHEXTDIV_DIV1
#endif

/**
 * @brief   PLL multiplier value.
 * @note    The allowed range is 2...64.
 * @note    The default value is calculated for a 240MHz system clock from
 *          a 48MHz crystal using the PLL.
 */
#if !defined(AT32_PLLMULT_VALUE) || defined(__DOXYGEN__)
#define AT32_PLLMULT_VALUE          15
#endif

/**
 * @brief   AHB prescaler value.
 * @note    The default value is calculated for a 240MHz system clock from
 *          a 48MHz crystal using the PLL.
 */
#if !defined(AT32_AHBDIV) || defined(__DOXYGEN__)
#define AT32_AHBDIV                 AT32_AHBDIV_DIV1
#endif

/**
 * @brief   APB1 prescaler value.
 */
#if !defined(AT32_APB1DIV) || defined(__DOXYGEN__)
#define AT32_APB1DIV                AT32_APB1DIV_DIV2
#endif

/**
 * @brief   APB2 prescaler value.
 */
#if !defined(AT32_APB2DIV) || defined(__DOXYGEN__)
#define AT32_APB2DIV                AT32_APB2DIV_DIV2
#endif

/**
 * @brief   ADC prescaler value.
 */
#if !defined(AT32_ADCDIV) || defined(__DOXYGEN__)
#define AT32_ADCDIV                 AT32_ADCDIV_DIV4
#endif

/**
 * @brief   USB clock setting.
 */
#if !defined(AT32_USB_CLOCK_REQUIRED) || defined(__DOXYGEN__)
#define AT32_USB_CLOCK_REQUIRED     TRUE
#endif

/**
 * @brief   USB prescaler initialization.
 */
#if !defined(AT32_USBDIV) || defined(__DOXYGEN__)
#define AT32_USBDIV                 AT32_USBDIV_DIV2_5
#endif

/**
 * @brief   CLKOUT_SEL pin setting.
 */
#if !defined(AT32_CLKOUT_SEL) || defined(__DOXYGEN__)
#define AT32_CLKOUT_SEL             AT32_CLKOUT_SEL_NOCLOCK
#endif

/**
 * @brief   RTC clock source.
 */
#if !defined(AT32_RTCSEL) || defined(__DOXYGEN__)
#define AT32_RTCSEL                 AT32_RTCSEL_HEXTDIV
#endif
/** @} */

/*===========================================================================*/
/* Derived constants and error checks.                                       */
/*===========================================================================*/

/*
 * Configuration-related checks.
 */
#if !defined(AT32F403A_MCUCONF)
#error "Using a wrong mcuconf.h file, AT32F403A_MCUCONF not defined"
#endif

/*
 * HICK related checks.
 */
#if AT32_HICK_ENABLED
#else /* !AT32_HICK_ENABLED */

#if AT32_SCLKSEL == AT32_SCLKSEL_HICK
#error "HICK not enabled, required by AT32_SCLKSEL"
#endif

#if (AT32_SCLKSEL == AT32_SCLKSEL_PLL) && (AT32_PLLRCS == AT32_PLLRCS_HICK)
#error "HICK not enabled, required by AT32_SCLKSEL and AT32_PLLRCS"
#endif

#if (AT32_CLKOUT_SEL == AT32_CLKOUT_SEL_HICK) ||                            \
    ((AT32_CLKOUT_SEL == AT32_CLKOUT_SEL_PLLDIV2) &&                        \
     (AT32_PLLRCS == AT32_PLLRCS_HICK))
#error "HICK not enabled, required by AT32_CLKOUT_SEL"
#endif

#endif /* !AT32_HICK_ENABLED */

/*
 * HEXT related checks.
 */
#if AT32_HEXT_ENABLED

#if AT32_HEXTCLK == 0
#error "HEXT frequency not defined"
#elif (AT32_HEXTCLK < AT32_HEXTCLK_MIN) || (AT32_HEXTCLK > AT32_HEXTCLK_MAX)
#error "AT32_HEXTCLK outside acceptable range (AT32_HEXTCLK_MIN...AT32_HEXTCLK_MAX)"
#endif

#else /* !AT32_HEXT_ENABLED */

#if AT32_SCLKSEL == AT32_SCLKSEL_HEXT
#error "HEXT not enabled, required by AT32_SCLKSEL"
#endif

#if (AT32_SCLKSEL == AT32_SCLKSEL_PLL) && (AT32_PLLRCS == AT32_PLLRCS_HEXT)
#error "HEXT not enabled, required by AT32_SCLKSEL and AT32_PLLRCS"
#endif

#if (AT32_CLKOUT_SEL == AT32_CLKOUT_SEL_HEXT) ||                            \
    ((AT32_CLKOUT_SEL == AT32_CLKOUT_SEL_PLLDIV2) &&                        \
     (AT32_PLLRCS == AT32_PLLRCS_HEXT))
#error "HEXT not enabled, required by AT32_CLKOUT_SEL"
#endif

#if AT32_RTCSEL == AT32_RTCSEL_HEXTDIV
#error "HEXT not enabled, required by AT32_RTCSEL"
#endif

#endif /* !AT32_HEXT_ENABLED */

/*
 * LICK related checks.
 */
#if AT32_LICK_ENABLED
#else /* !AT32_LICK_ENABLED */

#if HAL_USE_RTC && (AT32_RTCSEL == AT32_RTCSEL_LICK)
#error "LICK not enabled, required by AT32_RTCSEL"
#endif

#endif /* !AT32_LICK_ENABLED */

/*
 * LEXT related checks.
 */
#if AT32_LEXT_ENABLED

#if (AT32_LEXTCLK == 0)
#error "LEXT frequency not defined"
#endif

#if (AT32_LEXTCLK < AT32_LEXTCLK_MIN) || (AT32_LEXTCLK > AT32_LEXTCLK_MAX)
#error "AT32_LEXTCLK outside acceptable range (AT32_LEXTCLK_MIN...AT32_LEXTCLK_MAX)"
#endif

#else /* !AT32_LEXT_ENABLED */

#if AT32_RTCSEL == AT32_RTCSEL_LEXT
#error "LEXT not enabled, required by AT32_RTCSEL"
#endif

#endif /* !AT32_LEXT_ENABLED */

/* PLL activation conditions.*/
#if AT32_USB_CLOCK_REQUIRED ||                                              \
    (AT32_SCLKSEL == AT32_SCLKSEL_PLL) ||                                   \
    (AT32_CLKOUT_SEL == AT32_CLKOUT_SEL_PLLDIV2) ||                         \
    defined(__DOXYGEN__)
/**
 * @brief   PLL activation flag.
 */
#define AT32_ACTIVATE_PLL           TRUE
#else
#define AT32_ACTIVATE_PLL           FALSE
#endif

/* HEXT divider setting check.*/
#if (AT32_HEXT_DIV != AT32_HEXTDIV_DIV2) &&                                 \
    (AT32_HEXT_DIV != AT32_HEXTDIV_DIV3) &&                                 \
    (AT32_HEXT_DIV != AT32_HEXTDIV_DIV4) &&                                 \
    (AT32_HEXT_DIV != AT32_HEXTDIV_DIV5)
#error "invalid AT32_HEXT_DIV value specified"
#endif

/* HEXT prescaler setting check.*/
#if (AT32_PLLHEXTDIV != AT32_PLLHEXTDIV_DIV1) &&                            \
    (AT32_PLLHEXTDIV != AT32_PLLHEXTDIV_DIVX)
#error "invalid AT32_PLLHEXTDIV value specified"
#endif

/**
 * @brief   PLLMULT field.
 */
#if ((AT32_PLLMULT_VALUE >= 2) && (AT32_PLLMULT_VALUE <= 16)) ||            \
    defined(__DOXYGEN__)
#define AT32_PLLMULT                ((AT32_PLLMULT_VALUE - 2) << 18)
#else
#error "invalid AT32_PLLMULT_VALUE value specified"
#endif

/**
 * @brief   PLL input clock frequency.
 */
#if (AT32_PLLRCS == AT32_PLLRCS_HEXT) || defined(__DOXYGEN__)
#if AT32_PLLHEXTDIV == AT32_PLLHEXTDIV_DIV1
#define AT32_PLLCLKIN               (AT32_HEXTCLK / 1)
#elif (AT32_PLLHEXTDIV == AT32_PLLHEXTDIV_DIVX) && (AT32_HEXT_DIV == AT32_HEXTDIV_DIV2)
#define AT32_PLLCLKIN               (AT32_HEXTCLK / 2)
#elif (AT32_PLLHEXTDIV == AT32_PLLHEXTDIV_DIVX) && (AT32_HEXT_DIV == AT32_HEXTDIV_DIV3)
#define AT32_PLLCLKIN               (AT32_HEXTCLK / 3)
#elif (AT32_PLLHEXTDIV == AT32_PLLHEXTDIV_DIVX) && (AT32_HEXT_DIV == AT32_HEXTDIV_DIV4)
#define AT32_PLLCLKIN               (AT32_HEXTCLK / 4)
#elif (AT32_PLLHEXTDIV == AT32_PLLHEXTDIV_DIVX) && (AT32_HEXT_DIV == AT32_HEXTDIV_DIV5)
#define AT32_PLLCLKIN               (AT32_HEXTCLK / 5)
#else
#error "invalid AT32_HEXT_DIV value specified"
#endif
#elif AT32_PLLRCS == AT32_PLLRCS_HICK
#define AT32_PLLCLKIN               (AT32_HICKCLK / 12)
#else
#error "invalid AT32_PLLRCS value specified"
#endif

/* PLL input frequency range check.*/
#if (AT32_PLLCLKIN < AT32_PLLIN_MIN) || (AT32_PLLCLKIN > AT32_PLLIN_MAX)
#error "AT32_PLLCLKIN outside acceptable range (AT32_PLLIN_MIN...AT32_PLLIN_MAX)"
#endif

/**
 * @brief   PLL output clock frequency.
 */
#define AT32_PLLCLKOUT              (AT32_PLLCLKIN * AT32_PLLMULT_VALUE)

/* PLL output frequency range check.*/
#if (AT32_PLLCLKOUT < AT32_PLLOUT_MIN) || (AT32_PLLCLKOUT > AT32_PLLOUT_MAX)
#error "AT32_PLLCLKOUT outside acceptable range (AT32_PLLOUT_MIN...AT32_PLLOUT_MAX)"
#endif

/**
 * @brief   HSI clock source out to Sys Clock
 * @note    Controlled by HSI_DIV_EN and HSI_SYS_CTRL
 */
#if (AT32_HICK_TO_SCLK == AT32_HICK_TO_SCLK_SEL1)
#if (AT32_HICKDIV == AT32_HICKDIV_DIV1)
#define AT32_HICK_SCLK              AT32_HICKCLK
#elif (AT32_HICKDIV == AT32_HICKDIV_DIV6)
#define AT32_HICK_SCLK              (AT32_HICKCLK / 6)
#else
#error "invalid AT32_HICKDIV value specified"
#endif
#elif (AT32_HICK_TO_SCLK == AT32_HICK_TO_SCLK_SEL0)
#define AT32_HICK_SCLK              (AT32_HICKCLK / 6)
#else 
#error "invalid AT32_HICK_TO_SCLK value specified"
#endif

/**
 * @brief   System clock source.
 */
#if (AT32_SCLKSEL == AT32_SCLKSEL_PLL) || defined(__DOXYGEN__)
#define AT32_SYSCLK                 AT32_PLLCLKOUT
#elif (AT32_SCLKSEL == AT32_SCLKSEL_HICK)
#define AT32_SYSCLK                 AT32_HICK_SCLK
#elif (AT32_SCLKSEL == AT32_SCLKSEL_HEXT)
#define AT32_SYSCLK                 AT32_HEXTCLK
#else
#error "invalid AT32_SCLKSEL value specified"
#endif

/* Check on the system clock.*/
#if AT32_SYSCLK > AT32_SYSCLK_MAX
#error "AT32_SYSCLK above maximum rated frequency (AT32_SYSCLK_MAX)"
#endif

/**
 * @brief   AHB frequency.
 */
#if (AT32_AHBDIV == AT32_AHBDIV_DIV1) || defined(__DOXYGEN__)
#define AT32_HCLK                   (AT32_SYSCLK / 1)
#elif AT32_AHBDIV == AT32_AHBDIV_DIV2
#define AT32_HCLK                   (AT32_SYSCLK / 2)
#elif AT32_AHBDIV == AT32_AHBDIV_DIV4
#define AT32_HCLK                   (AT32_SYSCLK / 4)
#elif AT32_AHBDIV == AT32_AHBDIV_DIV8
#define AT32_HCLK                   (AT32_SYSCLK / 8)
#elif AT32_AHBDIV == AT32_AHBDIV_DIV16
#define AT32_HCLK                   (AT32_SYSCLK / 16)
#elif AT32_AHBDIV == AT32_AHBDIV_DIV64
#define AT32_HCLK                   (AT32_SYSCLK / 64)
#elif AT32_AHBDIV == AT32_AHBDIV_DIV128
#define AT32_HCLK                   (AT32_SYSCLK / 128)
#elif AT32_AHBDIV == AT32_AHBDIV_DIV256
#define AT32_HCLK                   (AT32_SYSCLK / 256)
#elif AT32_AHBDIV == AT32_AHBDIV_DIV512
#define AT32_HCLK                   (AT32_SYSCLK / 512)
#else
#error "invalid AT32_AHBDIV value specified"
#endif

/* AHB frequency check.*/
#if AT32_HCLK > AT32_SYSCLK_MAX
#error "AT32_HCLK exceeding maximum frequency (AT32_SYSCLK_MAX)"
#endif

/**
 * @brief   APB1 frequency.
 */
#if (AT32_APB1DIV == AT32_APB1DIV_DIV1) || defined(__DOXYGEN__)
#define AT32_PCLK1                  (AT32_HCLK / 1)
#elif AT32_APB1DIV == AT32_APB1DIV_DIV2
#define AT32_PCLK1                  (AT32_HCLK / 2)
#elif AT32_APB1DIV == AT32_APB1DIV_DIV4
#define AT32_PCLK1                  (AT32_HCLK / 4)
#elif AT32_APB1DIV == AT32_APB1DIV_DIV8
#define AT32_PCLK1                  (AT32_HCLK / 8)
#elif AT32_APB1DIV == AT32_APB1DIV_DIV16
#define AT32_PCLK1                  (AT32_HCLK / 16)
#else
#error "invalid AT32_APB1DIV value specified"
#endif

/* APB1 frequency check.*/
#if AT32_PCLK1 > AT32_PCLK1_MAX
#error "AT32_PCLK1 exceeding maximum frequency (AT32_PCLK1_MAX)"
#endif

/**
 * @brief   APB2 frequency.
 */
#if (AT32_APB2DIV == AT32_APB2DIV_DIV1) || defined(__DOXYGEN__)
#define AT32_PCLK2                  (AT32_HCLK / 1)
#elif AT32_APB2DIV == AT32_APB2DIV_DIV2
#define AT32_PCLK2                  (AT32_HCLK / 2)
#elif AT32_APB2DIV == AT32_APB2DIV_DIV4
#define AT32_PCLK2                  (AT32_HCLK / 4)
#elif AT32_APB2DIV == AT32_APB2DIV_DIV8
#define AT32_PCLK2                  (AT32_HCLK / 8)
#elif AT32_APB2DIV == AT32_APB2DIV_DIV16
#define AT32_PCLK2                  (AT32_HCLK / 16)
#else
#error "invalid AT32_APB2DIV value specified"
#endif

/* APB2 frequency check.*/
#if AT32_PCLK2 > AT32_PCLK2_MAX
#error "AT32_PCLK2 exceeding maximum frequency (AT32_PCLK2_MAX)"
#endif

/**
 * @brief   RTC clock.
 */
#if (AT32_RTCSEL == AT32_RTCSEL_LEXT) || defined(__DOXYGEN__)
#define AT32_RTCCLK                 AT32_LEXTCLK
#elif AT32_RTCSEL == AT32_RTCSEL_LICK
#define AT32_RTCCLK                 AT32_LICKCLK
#elif AT32_RTCSEL == AT32_RTCSEL_HEXTDIV
#define AT32_RTCCLK                 (AT32_HEXTCLK / 128)
#elif AT32_RTCSEL == AT32_RTCSEL_NOCLOCK
#define AT32_RTCCLK                 0
#else
#error "invalid source selected for RTC clock"
#endif

/**
 * @brief   ADC frequency.
 */
#if (AT32_ADCDIV == AT32_ADCDIV_DIV2) || defined(__DOXYGEN__)
#define AT32_ADCCLK                 (AT32_PCLK2 / 2)
#elif AT32_ADCDIV == AT32_ADCDIV_DIV4
#define AT32_ADCCLK                 (AT32_PCLK2 / 4)
#elif AT32_ADCDIV == AT32_ADCDIV_DIV6
#define AT32_ADCCLK                 (AT32_PCLK2 / 6)
#elif AT32_ADCDIV == AT32_ADCDIV_DIV8
#define AT32_ADCCLK                 (AT32_PCLK2 / 8)
#elif AT32_ADCDIV == AT32_ADCDIV_DIV12
#define AT32_ADCCLK                 (AT32_PCLK2 / 12)
#elif AT32_ADCDIV == AT32_ADCDIV_DIV16
#define AT32_ADCCLK                 (AT32_PCLK2 / 16)
#else
#error "invalid AT32_ADCDIV value specified"
#endif

/* ADC frequency check.*/
#if AT32_ADCCLK > AT32_ADCCLK_MAX
#error "AT32_ADCCLK exceeding maximum frequency (AT32_ADCCLK_MAX)"
#endif

/**
 * @brief   USB frequency.
 */
#if(AT32_HICK_TO_USB == AT32_HICK_TO_USB_HICK)
//checks
#if (AT32_HICKDIV != AT32_HICKDIV_DIV1)
#error "AT32_HICKDIV must equal AT32_HICKDIV_DIV1 if using HICK for HICK TO USB"
#else
#define AT32_USBCLK                AT32_HICKCLK
#endif
#elif (AT32_HICK_TO_USB == AT32_HICK_TO_USB_PLL)
#if (AT32_USBDIV == AT32_USBDIV_DIV1_5) || defined(__DOXYGEN__)
#define AT32_USBCLK                 ((AT32_PLLCLKOUT * 2) / 3)
#elif (AT32_USBDIV == AT32_USBDIV_DIV1)
#define AT32_USBCLK                 AT32_PLLCLKOUT
#elif (AT32_USBDIV == AT32_USBDIV_DIV2_5)
#define AT32_USBCLK                 ((AT32_PLLCLKOUT * 2) / 5)
#elif (AT32_USBDIV == AT32_USBDIV_DIV2)
#define AT32_USBCLK                 ((AT32_PLLCLKOUT * 2) / 4)
#elif (AT32_USBDIV == AT32_USBDIV_DIV3_5)
#define AT32_USBCLK                 ((AT32_PLLCLKOUT * 2) / 7)
#elif (AT32_USBDIV == AT32_USBDIV_DIV3)
#define AT32_USBCLK                 ((AT32_PLLCLKOUT * 2) / 6)
#elif (AT32_USBDIV == AT32_USBDIV_DIV4)
#define AT32_USBCLK                 ((AT32_PLLCLKOUT * 2) / 8)
#else
#error "invalid AT32_USBDIV value specified"
#endif
#else
#error "invalid AT32_HICK_TO_USB value specified"
#endif

/**
 * @brief   Timers 2, 3, 4, 5, 6, 7, 12, 13, 14 clock.
 */
#if (AT32_APB1DIV == AT32_APB1DIV_DIV1) || defined(__DOXYGEN__)
#define AT32_TMRCLK1                (AT32_PCLK1 * 1)
#else
#define AT32_TMRCLK1                (AT32_PCLK1 * 2)
#endif

/**
 * @brief   Timers 1, 8, 9, 10, 11 clock.
 */
#if (AT32_APB2DIV == AT32_APB2DIV_DIV1) || defined(__DOXYGEN__)
#define AT32_TMRCLK2                (AT32_PCLK2 * 1)
#else
#define AT32_TMRCLK2                (AT32_PCLK2 * 2)
#endif

#endif /* _HAL_LLD_F403A_F407_H_ */

/** @} */
