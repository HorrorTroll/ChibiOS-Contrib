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
 * @file    AT32F40xx/at32_isr.h
 * @brief   AT32F40xx ISR handler header.
 *
 * @addtogroup AT32F40xx_ISR
 * @{
 */

#ifndef AT32_ISR_H
#define AT32_ISR_H

/*===========================================================================*/
/* Driver constants.                                                         */
/*===========================================================================*/

/**
 * @name    ISR names and numbers remapping
 * @{
 */
/*
 * CAN units.
 */
#define AT32_CAN1_TX_HANDLER       Vector8C
#define AT32_CAN1_RX0_HANDLER      Vector90
#define AT32_CAN1_RX1_HANDLER      Vector94
#define AT32_CAN1_SE_HANDLER       Vector98
#define AT32_CAN1_TX_NUMBER        19
#define AT32_CAN1_RX0_NUMBER       20
#define AT32_CAN1_RX1_NUMBER       21
#define AT32_CAN1_SE_NUMBER        22

#define AT32_CAN2_TX_HANDLER       Vector150
#define AT32_CAN2_RX0_HANDLER      Vector154
#define AT32_CAN2_RX1_HANDLER      Vector158
#define AT32_CAN2_SE_HANDLER       Vector15C
#define AT32_CAN2_TX_NUMBER        68
#define AT32_CAN2_RX0_NUMBER       69
#define AT32_CAN2_RX1_NUMBER       70
#define AT32_CAN2_SE_NUMBER        71

/*
 * I2C units.
 */
#define AT32_I2C1_EVENT_HANDLER    VectorBC
#define AT32_I2C1_ERROR_HANDLER    VectorC0
#define AT32_I2C1_EVENT_NUMBER     31
#define AT32_I2C1_ERROR_NUMBER     32

#define AT32_I2C2_EVENT_HANDLER    VectorC4
#define AT32_I2C2_ERROR_HANDLER    VectorC8
#define AT32_I2C2_EVENT_NUMBER     33
#define AT32_I2C2_ERROR_NUMBER     34

#define AT32_I2C3_EVENT_HANDLER    Vector134
#define AT32_I2C3_ERROR_HANDLER    Vector138
#define AT32_I2C3_EVENT_NUMBER     61
#define AT32_I2C3_ERROR_NUMBER     62

/*
 * SDIO unit.
 */
#define AT32_SDIO1_HANDLER         Vector104
#define AT32_SDIO1_NUMBER          49

#define AT32_SDIO2_HANDLER         Vector130
#define AT32_SDIO2_NUMBER          60

/*
 * TMR units.
 */
#define AT32_TMR1_OVF_HANDLER      VectorA4
#define AT32_TMR1_CH_HANDLER       VectorAC
#define AT32_TMR2_HANDLER          VectorB0
#define AT32_TMR3_HANDLER          VectorB4
#define AT32_TMR4_HANDLER          VectorB8
#define AT32_TMR5_HANDLER          Vector108
#define AT32_TMR6_HANDLER          Vector118
#define AT32_TMR7_HANDLER          Vector11C
#define AT32_TMR8_OVF_HANDLER      VectorF0
#define AT32_TMR8_CH_HANDLER       VectorF8
#define AT32_TMR9_HANDLER          VectorA0 /* Note: same as AT32_TMR1_BRK */
#define AT32_TMR10_HANDLER         VectorA4 /* Note: same as AT32_TMR1_OVF */
#define AT32_TMR11_HANDLER         VectorA8 /* Note: same as AT32_TMR1_TRG_HALL */
#define AT32_TMR12_HANDLER         VectorEC /* Note: same as AT32_TMR8_BRK */
#define AT32_TMR13_HANDLER         VectorF0 /* Note: same as AT32_TMR8_OVF */
#define AT32_TMR14_HANDLER         VectorF4 /* Note: same as AT32_TMR8_TRG_HALL */

#define AT32_TMR1_OVF_NUMBER       25
#define AT32_TMR1_CH_NUMBER        27
#define AT32_TMR2_NUMBER           28
#define AT32_TMR3_NUMBER           29
#define AT32_TMR4_NUMBER           30
#define AT32_TMR5_NUMBER           50
#define AT32_TMR6_NUMBER           54
#define AT32_TMR7_NUMBER           55
#define AT32_TMR8_OVF_NUMBER       44
#define AT32_TMR8_CH_NUMBER        46
#define AT32_TMR9_NUMBER           24 /* Note: same as AT32_TMR1_BRK */
#define AT32_TMR10_NUMBER          25 /* Note: same as AT32_TMR1_OVF */
#define AT32_TMR11_NUMBER          26 /* Note: same as AT32_TMR1_TRG_HALL */
#define AT32_TMR12_NUMBER          43 /* Note: same as AT32_TMR8_BRK */
#define AT32_TMR13_NUMBER          44 /* Note: same as AT32_TMR8_OVF */
#define AT32_TMR14_NUMBER          45 /* Note: same as AT32_TMR8_TRG_HALL */

/*
 * USART units.
 */
#define AT32_USART1_HANDLER        VectorD4
#define AT32_USART2_HANDLER        VectorD8
#define AT32_USART3_HANDLER        VectorDC
#define AT32_UART4_HANDLER         Vector110
#define AT32_UART5_HANDLER         Vector114
#define AT32_USART6_HANDLER        Vector170
#define AT32_UART7_HANDLER         Vector174
#define AT32_UART8_HANDLER         Vector178

#define AT32_USART1_NUMBER         37
#define AT32_USART2_NUMBER         38
#define AT32_USART3_NUMBER         39
#define AT32_UART4_NUMBER          52
#define AT32_UART5_NUMBER          53
#define AT32_USART6_NUMBER         76
#define AT32_UART7_NUMBER          77
#define AT32_UART8_NUMBER          78

/*
 * USB units.
 */
#define AT32_USB1_H_HANDLER        Vector8C
#define AT32_USB1_L_HANDLER        Vector90

#define AT32_USB1_H_NUMBER         19
#define AT32_USB1_L_NUMBER         20

/*
 * RTC unit
 */
#define AT32_RTC1_HANDLER          Vector4C

#define AT32_RTC1_NUMBER           3
/** @} */

/*===========================================================================*/
/* Driver pre-compile time settings.                                         */
/*===========================================================================*/

/**
 * @name    Configuration options
 * @{
 */
/**
 * @brief   EXINT0 interrupt priority level setting.
 */
#if !defined(AT32_IRQ_EXINT0_PRIORITY) || defined(__DOXYGEN__)
#define AT32_IRQ_EXINT0_PRIORITY            6
#endif

/**
 * @brief   EXINT1 interrupt priority level setting.
 */
#if !defined(AT32_IRQ_EXINT1_PRIORITY) || defined(__DOXYGEN__)
#define AT32_IRQ_EXINT1_PRIORITY            6
#endif

/**
 * @brief   EXINT2 interrupt priority level setting.
 */
#if !defined(AT32_IRQ_EXINT2_PRIORITY) || defined(__DOXYGEN__)
#define AT32_IRQ_EXINT2_PRIORITY            6
#endif

/**
 * @brief   EXINT3 interrupt priority level setting.
 */
#if !defined(AT32_IRQ_EXINT3_PRIORITY) || defined(__DOXYGEN__)
#define AT32_IRQ_EXINT3_PRIORITY            6
#endif

/**
 * @brief   EXINT4 interrupt priority level setting.
 */
#if !defined(AT32_IRQ_EXINT4_PRIORITY) || defined(__DOXYGEN__)
#define AT32_IRQ_EXINT4_PRIORITY            6
#endif

/**
 * @brief   EXINT9..5 interrupt priority level setting.
 */
#if !defined(AT32_IRQ_EXINT5_9_PRIORITY) || defined(__DOXYGEN__)
#define AT32_IRQ_EXINT5_9_PRIORITY          6
#endif

/**
 * @brief   EXINT15..10 interrupt priority level setting.
 */
#if !defined(AT32_IRQ_EXINT10_15_PRIORITY) || defined(__DOXYGEN__)
#define AT32_IRQ_EXINT10_15_PRIORITY        6
#endif
/** @} */

/*===========================================================================*/
/* Derived constants and error checks.                                       */
/*===========================================================================*/

/*===========================================================================*/
/* Driver data structures and types.                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Driver macros.                                                            */
/*===========================================================================*/

/*===========================================================================*/
/* External declarations.                                                    */
/*===========================================================================*/

#ifdef __cplusplus
extern "C" {
#endif
  void irqInit(void);
  void irqDeinit(void);
#ifdef __cplusplus
}
#endif

#endif /* AT32_ISR_H */

/** @} */
