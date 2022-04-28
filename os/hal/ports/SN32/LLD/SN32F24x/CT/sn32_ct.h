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
 * @file    CT/sn32_ct.h
 * @brief   SN32 CT units common header.
 * @note    This file requires definitions from the SN32 header file.
 *
 * @{
 */

#ifndef SN32_CT_H
#define SN32_CT_H

#include "CT16.h"
#include "CT32.h"

/*===========================================================================*/
/* Driver constants.                                                         */
/*===========================================================================*/

/**
 * @name    CT units references
 * @{
 */
#define SN32_CT16B0       ((sn32_ct16_t *)SN_CT16B0_BASE)
#define SN32_CT16B1       ((sn32_ct16_t *)SN_CT16B1_BASE)
#define SN32_CT16B2       ((sn32_ct16_t *)SN_CT16B2_BASE)
#define SN32_CT32B0       ((sn32_ct32_t *)SN_CT32B0_BASE)
#define SN32_CT32B1       ((sn32_ct32_t *)SN_CT32B1_BASE)
#define SN32_CT32B2       ((sn32_ct32_t *)SN_CT32B2_BASE)

#if defined(SN32F240)
#define SN32_CT_MAX_CHANNELS        21

#define SN32_CT16B0_CHANNELS        3
#define SN32_CT16B1_CHANNELS        3
#define SN32_CT16B2_CHANNELS        3

#define SN32_CT32B0_CHANNELS        4
#define SN32_CT32B1_CHANNELS        4
#define SN32_CT32B2_CHANNELS        4
#else
#error "CT not supported in the selected device"
#endif

/** @} */

/*===========================================================================*/
/* Driver pre-compile time settings.                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Derived constants and error checks.                                       */
/*===========================================================================*/

/*===========================================================================*/
/* Driver data structures and types.                                         */
/*===========================================================================*/

/**
 * @brief   SN32 CT16 registers block.
 * @note    This is the most general known form, not all timers have
 *          necessarily all registers and bits.
 */
typedef struct {                                   /*!< (@ 0x40000000) SN_CT16Bn Structure                                        */
    volatile uint32_t TMRCTRL;                     /*!< (@ 0x00000000) Offset:0x00 CT16Bn Timer Control Register                  */
    volatile uint32_t TC;                          /*!< (@ 0x00000004) Offset:0x04 CT16Bn Timer Counter Register                  */
    volatile uint32_t PRE;                         /*!< (@ 0x00000008) Offset:0x08 CT16Bn Prescale Register                       */
    volatile uint32_t PC;                          /*!< (@ 0x0000000C) Offset:0x0C CT16Bn Prescale Counter Register               */
    volatile uint32_t CNTCTRL;                     /*!< (@ 0x00000010) Offset:0x10 CT16Bn Counter Control Register                */
    volatile uint32_t MCTRL;                       /*!< (@ 0x00000014) Offset:0x14 CT16Bn Match Control Register                  */
    volatile uint32_t MR0;                         /*!< (@ 0x00000018) Offset:0x18 CT16Bn MR0 Register                            */
    volatile uint32_t MR1;                         /*!< (@ 0x0000001C) Offset:0x1C CT16Bn MR1 Register                            */
    volatile uint32_t MR2;                         /*!< (@ 0x00000020) Offset:0x20 CT16Bn MR2 Register                            */
    volatile uint32_t MR3;                         /*!< (@ 0x00000024) Offset:0x24 CT16Bn MR3 Register                            */
    volatile uint32_t CAPCTRL;                     /*!< (@ 0x00000028) Offset:0x28 CT16Bn Capture Control Register                */
    volatile uint32_t CAP0;                        /*!< (@ 0x0000002C) Offset:0x2C CT16Bn CAP0 Register                           */
    volatile uint32_t EM;                          /*!< (@ 0x00000030) Offset:0x30 CT16Bn External Match Register                 */
    volatile uint32_t PWMCTRL;                     /*!< (@ 0x00000034) Offset:0x34 CT16Bn PWM Control Register                    */
    volatile uint32_t RIS;                         /*!< (@ 0x00000038) Offset:0x38 CT16Bn Raw Interrupt Status Register           */
    volatile uint32_t IC;                          /*!< (@ 0x0000003C) Offset:0x3C CT16Bn Interrupt Clear Register                */
} sn32_ct16_t;                                     /*!< Size = 64 (0x40)                                                          */

/**
 * @brief   SN32 CT32 registers block.
 * @note    This is the most general known form, not all timers have
 *          necessarily all registers and bits.
 */
typedef struct {                                   /*!< (@ 0x40006000) SN_CT32Bn Structure                                        */
    volatile uint32_t TMRCTRL;                     /*!< (@ 0x00000000) Offset:0x00 CT32Bn Timer Control Register                  */
    volatile uint32_t TC;                          /*!< (@ 0x00000004) Offset:0x04 CT32Bn Timer Counter Register                  */
    volatile uint32_t PRE;                         /*!< (@ 0x00000008) Offset:0x08 CT32Bn Prescale Register                       */
    volatile uint32_t PC;                          /*!< (@ 0x0000000C) Offset:0x0C CT32Bn Prescale Counter Register               */
    volatile uint32_t CNTCTRL;                     /*!< (@ 0x00000010) Offset:0x10 CT32Bn Counter Control Register                */
    volatile uint32_t MCTRL;                       /*!< (@ 0x00000014) Offset:0x14 CT32Bn Match Control Register                  */
    volatile uint32_t MR0;                         /*!< (@ 0x00000018) Offset:0x18 CT32Bn MR0 Register                            */
    volatile uint32_t MR1;                         /*!< (@ 0x0000001C) Offset:0x1C CT32Bn MR1 Register                            */
    volatile uint32_t MR2;                         /*!< (@ 0x00000020) Offset:0x20 CT32Bn MR2 Register                            */
    volatile uint32_t MR3;                         /*!< (@ 0x00000024) Offset:0x24 CT32Bn MR3 Register                            */
    volatile uint32_t CAPCTRL;                     /*!< (@ 0x00000028) Offset:0x28 CT32Bn Capture Control Register                */
    volatile uint32_t CAP0;                        /*!< (@ 0x0000002C) Offset:0x2C CT32Bn CAP0 Register                           */
    volatile uint32_t EM;                          /*!< (@ 0x00000030) Offset:0x30 CT32Bn External Match Register                 */
    volatile uint32_t PWMCTRL;                     /*!< (@ 0x00000034) Offset:0x34 CT32Bn PWM Control Register                    */
    volatile uint32_t RIS;                         /*!< (@ 0x00000038) Offset:0x38 CT32Bn Raw Interrupt Status Register           */
    volatile uint32_t IC;                          /*!< (@ 0x0000003C) Offset:0x3C CT32Bn Interrupt Clear Register                */
} sn32_ct32_t;                                     /*!< Size = 64 (0x40)                                                          */

/*===========================================================================*/
/* Driver macros.                                                            */
/*===========================================================================*/

/*===========================================================================*/
/* External declarations.                                                    */
/*===========================================================================*/

#endif /* SN32_CT_H */

/** @} */
