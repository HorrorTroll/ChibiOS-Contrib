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
 * @file    AT32F40xx/at32_crm.h
 * @brief   CRM helper driver header.
 * @note    This file requires definitions from the AT header file
 *          @p at32f40xx.h.
 *
 * @addtogroup AT32F40xx_CRM
 * @{
 */

#ifndef AT32_CRM_H
#define AT32_CRM_H

/*===========================================================================*/
/* Driver constants.                                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Driver pre-compile time settings.                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Derived constants and error checks.                                       */
/*===========================================================================*/

/*===========================================================================*/
/* Driver data structures and types.                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Driver macros.                                                            */
/*===========================================================================*/

/**
 * @name    Generic CRM operations
 * @{
 */
/**
 * @brief   Enables the clock of one or more peripheral on the APB1 bus.
 * @note    The @p lp parameter is ignored in this family.
 *
 * @param[in] mask      APB1 peripherals mask
 * @param[in] lp        low power enable flag
 *
 * @api
 */
#define crmEnableAPB1(mask, lp) {                                           \
  CRM->APB1EN |= (mask);                                                   \
  (void)CRM->APB1EN;                                                       \
}

/**
 * @brief   Disables the clock of one or more peripheral on the APB1 bus.
 * @note    The @p lp parameter is ignored in this family.
 *
 * @param[in] mask      APB1 peripherals mask
 *
 * @api
 */
#define crmDisableAPB1(mask) {                                              \
  CRM->APB1EN &= ~(mask);                                                  \
  (void)CRM->APB1EN;                                                       \
}

/**
 * @brief   Resets one or more peripheral on the APB1 bus.
 *
 * @param[in] mask      APB1 peripherals mask
 *
 * @api
 */
#define crmResetAPB1(mask) {                                                \
  CRM->APB1RST |= (mask);                                                  \
  CRM->APB1RST &= ~(mask);                                                 \
  (void)CRM->APB1RST;                                                      \
}

/**
 * @brief   Enables the clock of one or more peripheral on the APB2 bus.
 * @note    The @p lp parameter is ignored in this family.
 *
 * @param[in] mask      APB2 peripherals mask
 * @param[in] lp        low power enable flag
 *
 * @api
 */
#define crmEnableAPB2(mask, lp) {                                           \
  CRM->APB2EN |= (mask);                                                   \
  (void)CRM->APB2EN;                                                       \
}

/**
 * @brief   Disables the clock of one or more peripheral on the APB2 bus.
 * @note    The @p lp parameter is ignored in this family.
 *
 * @param[in] mask      APB2 peripherals mask
 *
 * @api
 */
#define crmDisableAPB2(mask) {                                              \
  CRM->APB2EN &= ~(mask);                                                  \
  (void)CRM->APB2EN;                                                       \
}

/**
 * @brief   Resets one or more peripheral on the APB2 bus.
 *
 * @param[in] mask      APB2 peripherals mask
 *
 * @api
 */
#define crmResetAPB2(mask) {                                                \
  CRM->APB2RST |= (mask);                                                  \
  CRM->APB2RST &= ~(mask);                                                 \
  (void)CRM->APB2RST;                                                      \
}

/**
 * @brief   Enables the clock of one or more peripheral on the AHB bus.
 * @note    The @p lp parameter is ignored in this family.
 *
 * @param[in] mask      AHB peripherals mask
 * @param[in] lp        low power enable flag
 *
 * @api
 */
#define crmEnableAHB(mask, lp) {                                            \
  CRM->AHBEN |= (mask);                                                    \
  (void)CRM->AHBEN;                                                        \
}

/**
 * @brief   Disables the clock of one or more peripheral on the AHB bus.
 * @note    The @p lp parameter is ignored in this family.
 *
 * @param[in] mask      AHB peripherals mask
 *
 * @api
 */
#define crmDisableAHB(mask) {                                               \
  CRM->AHBEN &= ~(mask);                                                   \
  (void)CRM->AHBEN;                                                        \
}

/**
 * @brief   Resets one or more peripheral on the AHB bus.
 *
 * @param[in] mask      AHB peripherals mask
 *
 * @api
 */
#define crmResetAHB(mask) {                                                 \
  CRM->AHBRST |= (mask);                                                   \
  CRM->AHBRST &= ~(mask);                                                  \
  (void)CRM->AHBRST;                                                       \
}
/** @} */

/**
 * @name    ADC peripherals specific CRM operations
 * @{
 */
/**
 * @brief   Enables the ADC1 peripheral clock.
 * @note    The @p lp parameter is ignored in this family.
 *
 * @param[in] lp        low power enable flag
 *
 * @api
 */
#define crmEnableADC1(lp) crmEnableAPB2(CRM_APB2EN_ADC1EN, lp)

/**
 * @brief   Disables the ADC1 peripheral clock.
 *
 * @api
 */
#define crmDisableADC1() crmDisableAPB2(CRM_APB2EN_ADC1EN)

/**
 * @brief   Resets the ADC1 peripheral.
 *
 * @api
 */
#define crmResetADC1() crmResetAPB2(CRM_APB2RST_ADC1RST)
/** @} */

/**
 * @name    DAC peripheral specific CRM operations
 * @{
 */
/**
 * @brief   Enables the DAC1 peripheral clock.
 *
 * @param[in] lp        low power enable flag
 *
 * @api
 */
#define crmEnableDAC1(lp) crmEnableAPB1(CRM_APB1EN_DACEN, lp)

/**
 * @brief   Disables the DAC1 peripheral clock.
 *
 * @api
 */
#define crmDisableDAC1() crmDisableAPB1(CRM_APB1EN_DACEN)

/**
 * @brief   Resets the DAC1 peripheral.
 *
 * @api
 */
#define crmResetDAC1() crmResetAPB1(CRM_APB1RST_DACRST)
/** @} */

/**
 * @name    Battery powered interface specific CRM operations
 * @{
 */
/**
 * @brief   Enables the BPR interface clock.
 * @note    The @p lp parameter is ignored in this family.
 *
 * @param[in] lp        low power enable flag
 *
 * @api
 */
#define crmEnableBPRInterface(lp) crmEnableAPB1((CRM_APB1EN_BPREN), lp)

/**
 * @brief   Disables BPR interface clock.
 *
 * @api
 */
#define crmDisableBPRInterface() crmDisableAPB1(CRM_APB1EN_BPREN)

/**
 * @brief   Resets the Battery Powered interface.
 *
 * @api
 */
#define crmResetBPRInterface() crmResetAPB1(CRM_APB1RST_BPRRST)

/**
 * @brief   Resets the entire Battery Powered.
 *
 * @api
 */
#define crmResetBPR() (CRM->BPDC |= CRM_BPDC_BPDRST)
/** @} */

/**
 * @name    PWC interface specific CRM operations
 * @{
 */
/**
 * @brief   Enables the PWC interface clock.
 * @note    The @p lp parameter is ignored in this family.
 *
 * @param[in] lp        low power enable flag
 *
 * @api
 */
#define crmEnablePWCInterface(lp) crmEnableAPB1(CRM_APB1EN_PWCEN, lp)

/**
 * @brief   Disables PWC interface clock.
 *
 * @api
 */
#define crmDisablePWCInterface() crmDisableAPB1(CRM_APB1EN_PWCEN)

/**
 * @brief   Resets the PWC interface.
 *
 * @api
 */
#define crmResetPWCInterface() crmResetAPB1(CRM_APB1RST_PWCRST)
/** @} */

/**
 * @name    CAN peripherals specific CRM operations
 * @{
 */
/**
 * @brief   Enables the CAN1 peripheral clock.
 * @note    The @p lp parameter is ignored in this family.
 *
 * @param[in] lp        low power enable flag
 *
 * @api
 */
#define crmEnableCAN1(lp) crmEnableAPB1(CRM_APB1EN_CAN1EN, lp)

/**
 * @brief   Disables the CAN1 peripheral clock.
 *
 * @api
 */
#define crmDisableCAN1() crmDisableAPB1(CRM_APB1EN_CAN1EN)

/**
 * @brief   Resets the CAN1 peripheral.
 *
 * @api
 */
#define crmResetCAN1() crmResetAPB1(CRM_APB1RST_CAN1RST)

/**
 * @brief   Enables the CAN2 peripheral clock.
 *
 * @param[in] lp        low power enable flag
 *
 * @api
 */
#define crmEnableCAN2(lp) crmEnableAPB1(CRM_APB1EN_CAN2EN, lp)

/**
 * @brief   Disables the CAN2 peripheral clock.
 *
 * @api
 */
#define crmDisableCAN2() crmDisableAPB1(CRM_APB1EN_CAN2EN)

/**
 * @brief   Resets the CAN2 peripheral.
 *
 * @api
 */
#define crmResetCAN2() crmResetAPB1(CRM_APB1RST_CAN2RST)
/** @} */

/**
 * @name    DMA peripherals specific CRM operations
 * @{
 */
/**
 * @brief   Enables the DMA1 peripheral clock.
 * @note    The @p lp parameter is ignored in this family.
 *
 * @param[in] lp        low power enable flag
 *
 * @api
 */
#define crmEnableDMA1(lp) crmEnableAHB(CRM_AHBEN_DMA1EN, lp)

/**
 * @brief   Disables the DMA1 peripheral clock.
 *
 * @api
 */
#define crmDisableDMA1() crmDisableAHB(CRM_AHBEN_DMA1EN)

/**
 * @brief   Resets the DMA1 peripheral.
 * @note    Not supported in this family, does nothing.
 *
 * @api
 */
#define crmResetDMA1()

/**
 * @brief   Enables the DMA2 peripheral clock.
 * @note    The @p lp parameter is ignored in this family.
 *
 * @param[in] lp        low power enable flag
 *
 * @api
 */
#define crmEnableDMA2(lp) crmEnableAHB(CRM_AHBEN_DMA2EN, lp)

/**
 * @brief   Disables the DMA2 peripheral clock.
 *
 * @api
 */
#define crmDisableDMA2() crmDisableAHB(CRM_AHBEN_DMA2EN)

/**
 * @brief   Resets the DMA1 peripheral.
 * @note    Not supported in this family, does nothing.
 *
 * @api
 */
#define crmResetDMA2()
/** @} */

/**
 * @name    ETH peripheral specific CRM operations
 * @{
 */
/**
 * @brief   Enables the ETH peripheral clock.
 * @note    The @p lp parameter is ignored in this family.
 *
 * @param[in] lp        low power enable flag
 *
 * @api
 */
#define crmEnableETH(lp) crmEnableAHB(CRM_AHBEN_EMACEN |                   \
                                      CRM_AHBEN_EMACTXEN |                 \
                                      CRM_AHBEN_EMACRXEN |                 \
                                      CRM_AHBEN_EMACPTPEN, lp)

/**
 * @brief   Disables the ETH peripheral clock.
 * @note    The @p lp parameter is ignored in this family.
 *
 * @param[in] lp        low power enable flag
 *
 * @api
 */
#define crmDisableETH() crmDisableAHB(CRM_AHBEN_EMACEN |                   \
                                      CRM_AHBEN_EMACTXEN |                 \
                                      CRM_AHBEN_EMACRXEN |                 \
                                      CRM_AHBEN_EMACPTPEN)

/**
 * @brief   Resets the ETH peripheral.
 *
 * @api
 */
#define crmResetETH() crmResetAHB(CRM_AHBRST_EMACRST)
/** @} */

/**
 * @name    I2C peripherals specific CRM operations
 * @{
 */
/**
 * @brief   Enables the I2C1 peripheral clock.
 * @note    The @p lp parameter is ignored in this family.
 *
 * @param[in] lp        low power enable flag
 *
 * @api
 */
#define crmEnableI2C1(lp) crmEnableAPB1(CRM_APB1EN_I2C1EN, lp)

/**
 * @brief   Disables the I2C1 peripheral clock.
 *
 * @api
 */
#define crmDisableI2C1() crmDisableAPB1(CRM_APB1EN_I2C1EN)

/**
 * @brief   Resets the I2C1 peripheral.
 *
 * @api
 */
#define crmResetI2C1() crmResetAPB1(CRM_APB1RST_I2C1RST)

/**
 * @brief   Enables the I2C2 peripheral clock.
 * @note    The @p lp parameter is ignored in this family.
 *
 * @param[in] lp        low power enable flag
 *
 * @api
 */
#define crmEnableI2C2(lp) crmEnableAPB1(CRM_APB1EN_I2C2EN, lp)

/**
 * @brief   Disables the I2C2 peripheral clock.
 *
 * @api
 */
#define crmDisableI2C2() crmDisableAPB1(CRM_APB1EN_I2C2EN)

/**
 * @brief   Resets the I2C2 peripheral.
 *
 * @api
 */
#define crmResetI2C2() crmResetAPB1(CRM_APB1RST_I2C2RST)

/**
 * @brief   Enables the I2C3 peripheral clock.
 * @note    The @p lp parameter is ignored in this family.
 *
 * @param[in] lp        low power enable flag
 *
 * @api
 */
#define crmEnableI2C3(lp) crmEnableAPB1(CRM_APB2EN_I2C3EN, lp)

/**
 * @brief   Disables the I2C3 peripheral clock.
 *
 * @api
 */
#define crmDisableI2C3() crmDisableAPB1(CRM_APB2EN_I2C3EN)

/**
 * @brief   Resets the I2C3 peripheral.
 *
 * @api
 */
#define crmResetI2C3() crmResetAPB1(CRM_APB2RST_I2C3RST)
/** @} */

/**
 * @name    SDIO1 peripheral specific CRM operations
 * @{
 */
/**
 * @brief   Enables the SDIO1 peripheral clock.
 * @note    The @p lp parameter is ignored in this family.
 *
 * @param[in] lp        low power enable flag
 *
 * @api
 */
#define crmEnableSDIO1(lp) crmEnableAHB(CRM_AHBEN_SDIO1EN, lp)

/**
 * @brief   Disables the SDIO1 peripheral clock.
 *
 * @api
 */
#define crmDisableSDIO1() crmDisableAHB(CRM_AHBEN_SDIO1EN)

/**
 * @brief   Resets the SDIO1 peripheral.
 * @note    Not supported in this family, does nothing.
 *
 * @api
 */
#define crmResetSDIO1()

/**
 * @brief   Enables the SDIO2 peripheral clock.
 * @note    The @p lp parameter is ignored in this family.
 *
 * @param[in] lp        low power enable flag
 *
 * @api
 */
#define crmEnableSDIO2(lp) crmEnableAHB(CRM_AHBEN_SDIO2EN, lp)

/**
 * @brief   Disables the SDIO2 peripheral clock.
 *
 * @api
 */
#define crmDisableSDIO2() crmDisableAHB(CRM_AHBEN_SDIO2EN)

/**
 * @brief   Resets the SDIO2 peripheral.
 * @note    Not supported in this family, does nothing.
 *
 * @api
 */
#define crmResetSDIO2()
/** @} */

/**
 * @name    SPI peripherals specific CRM operations
 * @{
 */
/**
 * @brief   Enables the SPI1 peripheral clock.
 * @note    The @p lp parameter is ignored in this family.
 *
 * @param[in] lp        low power enable flag
 *
 * @api
 */
#define crmEnableSPI1(lp) crmEnableAPB2(CRM_APB2EN_SPI1EN, lp)

/**
 * @brief   Disables the SPI1 peripheral clock.
 *
 * @api
 */
#define crmDisableSPI1() crmDisableAPB2(CRM_APB2EN_SPI1EN)

/**
 * @brief   Resets the SPI1 peripheral.
 *
 * @api
 */
#define crmResetSPI1() crmResetAPB2(CRM_APB2RST_SPI1RST)

/**
 * @brief   Enables the SPI2 peripheral clock.
 * @note    The @p lp parameter is ignored in this family.
 *
 * @param[in] lp        low power enable flag
 *
 * @api
 */
#define crmEnableSPI2(lp) crmEnableAPB1(CRM_APB1EN_SPI2EN, lp)

/**
 * @brief   Disables the SPI2 peripheral clock.
 *
 * @api
 */
#define crmDisableSPI2() crmDisableAPB1(CRM_APB1EN_SPI2EN)

/**
 * @brief   Resets the SPI2 peripheral.
 *
 * @api
 */
#define crmResetSPI2() crmResetAPB1(CRM_APB1RST_SPI2RST)

/**
 * @brief   Enables the SPI3 peripheral clock.
 * @note    The @p lp parameter is ignored in this family.
 *
 * @param[in] lp        low power enable flag
 *
 * @api
 */
#define crmEnableSPI3(lp) crmEnableAPB1(CRM_APB1EN_SPI3EN, lp)

/**
 * @brief   Disables the SPI3 peripheral clock.
 *
 * @api
 */
#define crmDisableSPI3() crmDisableAPB1(CRM_APB1EN_SPI3EN)

/**
 * @brief   Resets the SPI3 peripheral.
 *
 * @api
 */
#define crmResetSPI3() crmResetAPB1(CRM_APB1RST_SPI3RST)

/**
 * @brief   Enables the SPI4 peripheral clock.
 * @note    The @p lp parameter is ignored in this family.
 *
 * @param[in] lp        low power enable flag
 *
 * @api
 */
#define crmEnableSPI4(lp) crmEnableAPB1(CRM_APB1EN_SPI4EN, lp)

/**
 * @brief   Disables the SPI4 peripheral clock.
 *
 * @api
 */
#define crmDisableSPI4() crmDisableAPB1(CRM_APB1EN_SPI4EN)

/**
 * @brief   Resets the SPI4 peripheral.
 *
 * @api
 */
#define crmResetSPI4() crmResetAPB1(CRM_APB1RST_SPI4RST)
/** @} */

/**
 * @name    TMR peripherals specific CRM operations
 * @{
 */
/**
 * @brief   Enables the TMR1 peripheral clock.
 * @note    The @p lp parameter is ignored in this family.
 *
 * @param[in] lp        low power enable flag
 *
 * @api
 */
#define crmEnableTMR1(lp) crmEnableAPB2(CRM_APB2EN_TMR1EN, lp)

/**
 * @brief   Disables the TMR1 peripheral clock.
 *
 * @api
 */
#define crmDisableTMR1() crmDisableAPB2(CRM_APB2EN_TMR1EN)

/**
 * @brief   Resets the TMR1 peripheral.
 *
 * @api
 */
#define crmResetTMR1() crmResetAPB2(CRM_APB2RST_TMR1RST)

/**
 * @brief   Enables the TMR2 peripheral clock.
 * @note    The @p lp parameter is ignored in this family.
 *
 * @param[in] lp        low power enable flag
 *
 * @api
 */
#define crmEnableTMR2(lp) crmEnableAPB1(CRM_APB1EN_TMR2EN, lp)

/**
 * @brief   Disables the TMR2 peripheral clock.
 *
 * @api
 */
#define crmDisableTMR2() crmDisableAPB1(CRM_APB1EN_TMR2EN)

/**
 * @brief   Resets the TMR2 peripheral.
 *
 * @api
 */
#define crmResetTMR2() crmResetAPB1(CRM_APB1RST_TMR2RST)

/**
 * @brief   Enables the TMR3 peripheral clock.
 * @note    The @p lp parameter is ignored in this family.
 *
 * @param[in] lp        low power enable flag
 *
 * @api
 */
#define crmEnableTMR3(lp) crmEnableAPB1(CRM_APB1EN_TMR3EN, lp)

/**
 * @brief   Disables the TMR3 peripheral clock.
 *
 * @api
 */
#define crmDisableTMR3() crmDisableAPB1(CRM_APB1EN_TMR3EN)

/**
 * @brief   Resets the TMR3 peripheral.
 *
 * @api
 */
#define crmResetTMR3() crmResetAPB1(CRM_APB1RST_TMR3RST)

/**
 * @brief   Enables the TMR4 peripheral clock.
 * @note    The @p lp parameter is ignored in this family.
 *
 * @param[in] lp        low power enable flag
 *
 * @api
 */
#define crmEnableTMR4(lp) crmEnableAPB1(CRM_APB1EN_TMR4EN, lp)

/**
 * @brief   Disables the TMR4 peripheral clock.
 *
 * @api
 */
#define crmDisableTMR4() crmDisableAPB1(CRM_APB1EN_TMR4EN)

/**
 * @brief   Resets the TMR4 peripheral.
 *
 * @api
 */
#define crmResetTMR4() crmResetAPB1(CRM_APB1RST_TMR4RST)

/**
 * @brief   Enables the TMR5 peripheral clock.
 * @note    The @p lp parameter is ignored in this family.
 *
 * @param[in] lp        low power enable flag
 *
 * @api
 */
#define crmEnableTMR5(lp) crmEnableAPB1(CRM_APB1EN_TMR5EN, lp)

/**
 * @brief   Disables the TMR5 peripheral clock.
 *
 * @api
 */
#define crmDisableTMR5() crmDisableAPB1(CRM_APB1EN_TMR5EN)

/**
 * @brief   Resets the TMR5 peripheral.
 *
 * @api
 */
#define crmResetTMR5() crmResetAPB1(CRM_APB1RST_TMR5RST)

/**
 * @brief   Enables the TMR6 peripheral clock.
 *
 * @param[in] lp        low power enable flag
 *
 * @api
 */
#define crmEnableTMR6(lp) crmEnableAPB1(CRM_APB1EN_TMR6EN, lp)

/**
 * @brief   Disables the TMR6 peripheral clock.
 *
 * @api
 */
#define crmDisableTMR6() crmDisableAPB1(CRM_APB1EN_TMR6EN)

/**
 * @brief   Resets the TMR6 peripheral.
 *
 * @api
 */
#define crmResetTMR6() crmResetAPB1(CRM_APB1RST_TMR6RST)

/**
 * @brief   Enables the TMR7 peripheral clock.
 *
 * @param[in] lp        low power enable flag
 *
 * @api
 */
#define crmEnableTMR7(lp) crmEnableAPB1(CRM_APB1EN_TMR7EN, lp)

/**
 * @brief   Disables the TMR7 peripheral clock.
 *
 * @api
 */
#define crmDisableTMR7() crmDisableAPB1(CRM_APB1EN_TMR7EN)

/**
 * @brief   Resets the TMR7 peripheral.
 *
 * @api
 */
#define crmResetTMR7() crmResetAPB1(CRM_APB1RST_TMR7RST)

/**
 * @brief   Enables the TMR8 peripheral clock.
 * @note    The @p lp parameter is ignored in this family.
 *
 * @param[in] lp        low power enable flag
 *
 * @api
 */
#define crmEnableTMR8(lp) crmEnableAPB2(CRM_APB2EN_TMR8EN, lp)

/**
 * @brief   Disables the TMR8 peripheral clock.
 *
 * @api
 */
#define crmDisableTMR8() crmDisableAPB2(CRM_APB2EN_TMR8EN)

/**
 * @brief   Resets the TMR8 peripheral.
 *
 * @api
 */
#define crmResetTMR8() crmResetAPB2(CRM_APB2RST_TMR8RST)

/**

 * @brief   Enables the TMR9 peripheral clock.

 * @note    The @p lp parameter is ignored in this family.

 *
 * @param[in] lp        low power enable flag
 *
 * @api
 */
#define crmEnableTMR9(lp) crmEnableAPB2(CRM_APB2EN_TMR9EN, lp)

/**
 * @brief   Disables the TMR9 peripheral clock.
 *
 * @api
 */
#define crmDisableTMR9() crmDisableAPB2(CRM_APB2EN_TMR9EN)

/**
 * @brief   Resets the TMR9 peripheral.
 *
 * @api
 */
#define crmResetTMR9() crmResetAPB2(CRM_APB2RST_TMR9RST)

/**
 * @brief   Enables the TMR10 peripheral clock.
 * @note    The @p lp parameter is ignored in this family.
 *
 * @param[in] lp        low power enable flag
 *
 * @api
 */
#define crmEnableTMR10(lp) crmEnableAPB2(CRM_APB2EN_TMR10EN, lp)

/**
 * @brief   Disables the TMR10 peripheral clock.
 *
 * @api
 */
#define crmDisableTMR10() crmDisableAPB2(CRM_APB2EN_TMR10EN)

/**
 * @brief   Resets the TMR10 peripheral.
 *
 * @api
 */
#define crmResetTMR10() crmResetAPB2(CRM_APB2RST_TMR10RST)

/**
 * @brief   Enables the TMR11 peripheral clock.
 * @note    The @p lp parameter is ignored in this family.
 *
 * @param[in] lp        low power enable flag
 *
 * @api
 */
#define crmEnableTMR11(lp) crmEnableAPB2(CRM_APB2EN_TMR11EN, lp)

/**
 * @brief   Disables the TMR11 peripheral clock.
 *
 * @api
 */
#define crmDisableTMR11() crmDisableAPB2(CRM_APB2EN_TMR11EN)

/**
 * @brief   Resets the TMR11 peripheral.
 *
 * @api
 */
#define crmResetTMR11() crmResetAPB2(CRM_APB2RST_TMR11RST)

/**
 * @brief   Enables the TMR12 peripheral clock.
 * @note    The @p lp parameter is ignored in this family.
 *
 * @param[in] lp        low power enable flag
 *
 * @api
 */
#define crmEnableTMR12(lp) crmEnableAPB1(CRM_APB1EN_TMR12EN, lp)

/**
 * @brief   Disables the TMR12 peripheral clock.
 *
 * @api
 */
#define crmDisableTMR12() crmDisableAPB1(CRM_APB1EN_TMR12EN)

/**
 * @brief   Resets the TMR12 peripheral.
 *
 * @api
 */
#define crmResetTMR12() crmResetAPB1(CRM_APB1RST_TMR12RST)

/**
 * @brief   Enables the TMR13 peripheral clock.
 * @note    The @p lp parameter is ignored in this family.
 *
 * @param[in] lp        low power enable flag
 *
 * @api
 */
#define crmEnableTMR13(lp) crmEnableAPB1(CRM_APB1EN_TMR13EN, lp)

/**
 * @brief   Disables the TMR13 peripheral clock.
 *
 * @api
 */
#define crmDisableTMR13() crmDisableAPB1(CRM_APB1EN_TMR13EN)

/**
 * @brief   Resets the TMR13 peripheral.
 *
 * @api
 */
#define crmResetTMR13() crmResetAPB1(CRM_APB1RST_TMR13RST)

/**
 * @brief   Enables the TMR14 peripheral clock.
 * @note    The @p lp parameter is ignored in this family.
 *
 * @param[in] lp        low power enable flag
 *
 * @api
 */
#define crmEnableTMR14(lp) crmEnableAPB1(CRM_APB1EN_TMR14EN, lp)

/**
 * @brief   Disables the TMR14 peripheral clock.
 *
 * @api
 */
#define crmDisableTMR14() crmDisableAPB1(CRM_APB1EN_TMR14EN)

/**
 * @brief   Resets the TMR14 peripheral.
 *
 * @api
 */
#define crmResetTMR14() crmResetAPB1(CRM_APB1RST_TMR14RST)
/** @} */

/**
 * @name    USART/UART peripherals specific CRM operations
 * @{
 */
/**
 * @brief   Enables the USART1 peripheral clock.
 * @note    The @p lp parameter is ignored in this family.
 *
 * @param[in] lp        low power enable flag
 *
 * @api
 */
#define crmEnableUSART1(lp) crmEnableAPB2(CRM_APB2EN_USART1EN, lp)

/**
 * @brief   Disables the USART1 peripheral clock.
 *
 * @api
 */
#define crmDisableUSART1() crmDisableAPB2(CRM_APB2EN_USART1EN)

/**
 * @brief   Resets the USART1 peripheral.
 *
 * @api
 */
#define crmResetUSART1() crmResetAPB2(CRM_APB2RST_USART1RST)

/**
 * @brief   Enables the USART2 peripheral clock.
 * @note    The @p lp parameter is ignored in this family.
 *
 * @param[in] lp        low power enable flag
 *
 * @api
 */
#define crmEnableUSART2(lp) crmEnableAPB1(CRM_APB1EN_USART2EN, lp)

/**
 * @brief   Disables the USART2 peripheral clock.
 *
 * @api
 */
#define crmDisableUSART2() crmDisableAPB1(CRM_APB1EN_USART2EN)

/**
 * @brief   Resets the USART2 peripheral.
 *
 * @api
 */
#define crmResetUSART2() crmResetAPB1(CRM_APB1RST_USART2RST)

/**
 * @brief   Enables the USART3 peripheral clock.
 * @note    The @p lp parameter is ignored in this family.
 *
 * @param[in] lp        low power enable flag
 *
 * @api
 */
#define crmEnableUSART3(lp) crmEnableAPB1(CRM_APB1EN_USART3EN, lp)

/**
 * @brief   Disables the USART3 peripheral clock.
 *
 * @api
 */
#define crmDisableUSART3() crmDisableAPB1(CRM_APB1EN_USART3EN)

/**
 * @brief   Resets the USART3 peripheral.
 *
 * @api
 */
#define crmResetUSART3() crmResetAPB1(CRM_APB1RST_USART3RST)

/**
 * @brief   Enables the UART4 peripheral clock.
 * @note    The @p lp parameter is ignored in this family.
 *
 * @param[in] lp        low power enable flag
 *
 * @api
 */
#define crmEnableUART4(lp) crmEnableAPB1(CRM_APB1EN_UART4EN, lp)

/**
 * @brief   Disables the UART4 peripheral clock.
 *
 * @api
 */
#define crmDisableUART4() crmDisableAPB1(CRM_APB1EN_UART4EN)

/**
 * @brief   Resets the UART4 peripheral.
 *
 * @api
 */
#define crmResetUART4() crmResetAPB1(CRM_APB1RST_UART4RST)

/**
 * @brief   Enables the UART5 peripheral clock.
 * @note    The @p lp parameter is ignored in this family.
 *
 * @param[in] lp        low power enable flag
 *
 * @api
 */
#define crmEnableUART5(lp) crmEnableAPB1(CRM_APB1EN_UART5EN, lp)

/**
 * @brief   Disables the UART5 peripheral clock.
 *
 * @api
 */
#define crmDisableUART5() crmDisableAPB1(CRM_APB1EN_UART5EN)

/**
 * @brief   Resets the UART5 peripheral.
 *
 * @api
 */
#define crmResetUART5() crmResetAPB1(CRM_APB1RST_UART5RST)

/**
 * @brief   Enables the USART6 peripheral clock.
 * @note    The @p lp parameter is ignored in this family.
 *
 * @param[in] lp        low power enable flag
 *
 * @api
 */
#define crmEnableUSART6(lp) crmEnableAPB2(CRM_APB2EN_USART6EN, lp)

/**
 * @brief   Disables the USART6 peripheral clock.
 *
 * @api
 */
#define crmDisableUSART6() crmDisableAPB2(CRM_APB2EN_USART6EN)

/**
 * @brief   Resets the USART6 peripheral.
 *
 * @api
 */
#define crmResetUSART6() crmResetAPB2(CRM_APB2RST_USART6RST)

/**
 * @brief   Enables the UART7 peripheral clock.
 * @note    The @p lp parameter is ignored in this family.
 *
 * @param[in] lp        low power enable flag
 *
 * @api
 */
#define crmEnableUART7(lp) crmEnableAPB2(CRM_APB2EN_UART7EN, lp)

/**
 * @brief   Disables the UART7 peripheral clock.
 *
 * @api
 */
#define crmDisableUART7() crmDisableAPB2(CRM_APB2EN_UART7EN)

/**
 * @brief   Resets the UART7 peripheral.
 *
 * @api
 */
#define crmResetUART7() crmResetAPB2(CRM_APB2RST_UART7RST)

/**
 * @brief   Enables the UART8 peripheral clock.
 * @note    The @p lp parameter is ignored in this family.
 *
 * @param[in] lp        low power enable flag
 *
 * @api
 */
#define crmEnableUART8(lp) crmEnableAPB2(CRM_APB2EN_UART8EN, lp)

/**
 * @brief   Disables the UART8 peripheral clock.
 *
 * @api
 */
#define crmDisableUART8() crmDisableAPB2(CRM_APB2EN_UART8EN)

/**
 * @brief   Resets the UART8 peripheral.
 *
 * @api
 */
#define crmResetUART8() crmResetAPB2(CRM_APB2RST_UART8RST)
/** @} */

/**
 * @name    USB peripheral specific CRM operations
 * @{
 */
/**
 * @brief   Enables the USB peripheral clock.
 * @note    The @p lp parameter is ignored in this family.
 *
 * @param[in] lp        low power enable flag
 *
 * @api
 */
#define crmEnableUSB(lp) crmEnableAPB1(CRM_APB1EN_USBEN, lp)

/**
 * @brief   Disables the USB peripheral clock
 *
 * @api
 */
#define crmDisableUSB() crmDisableAPB1(CRM_APB1EN_USBEN)

/**
 * @brief   Resets the USB peripheral.
 *
 * @api
 */
#define crmResetUSB() crmResetAPB1(CRM_APB1RST_USBRST)
/** @} */

/**
 * @name    XMC peripherals specific CRM operations
 * @{
 */
/**
 * @brief   Enables the XMC peripheral clock.
 *
 * @param[in] lp        low power enable flag
 *
 * @api
 */
#define crmEnableXMC(lp) crmEnableAHB(CRM_AHBEN_XMCEN, lp)

/**
 * @brief   Disables the XMC peripheral clock.
 *
 * @api
 */
#define crmDisableXMC() crmDisableAHB(CRM_AHBEN_XMCEN)
/** @} */

/*===========================================================================*/
/* External declarations.                                                    */
/*===========================================================================*/

#ifdef __cplusplus
extern "C" {
#endif
#ifdef __cplusplus
}
#endif

#endif /* AT32_CRM_H */

/** @} */
