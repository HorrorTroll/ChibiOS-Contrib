/**
  ******************************************************************************
  * @file    system_at32f40xx.h
  * @author  Artery Technology & HorrorTroll
  * @brief   CMSIS AT32F40xx Device Peripheral Access Layer Header File.
  *
  *          The file is the unique include file that the application programmer
  *          is using in the C source code, usually in main.c. This file contains:
  *            - Configuration section that allows to select:
  *              - The AT32F40xx device used in the target application
  *              - To use or not the peripheral drivers in application code(i.e.
  *                code will be based on direct access to peripheral registers
  *                rather than drivers API), this option is controlled by
  *                "#define USE_HAL_DRIVER"
  *
  ******************************************************************************
  *                       Copyright notice & Disclaimer
  *
  * The software Board Support Package (BSP) that is made available to
  * download from Artery official website is the copyrighted work of Artery.
  * Artery authorizes customers to use, copy, and distribute the BSP
  * software and its related documentation for the purpose of design and
  * development in conjunction with Artery microcontrollers. Use of the
  * software is governed by this copyright notice and the following disclaimer.
  *
  * THIS SOFTWARE IS PROVIDED ON "AS IS" BASIS WITHOUT WARRANTIES,
  * GUARANTEES OR REPRESENTATIONS OF ANY KIND. ARTERY EXPRESSLY DISCLAIMS,
  * TO THE FULLEST EXTENT PERMITTED BY LAW, ALL EXPRESS, IMPLIED OR
  * STATUTORY OR OTHER WARRANTIES, GUARANTEES OR REPRESENTATIONS,
  * INCLUDING BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY,
  * FITNESS FOR A PARTICULAR PURPOSE, OR NON-INFRINGEMENT.
  *
  **************************************************************************
  */

/** @addtogroup CMSIS
  * @{
  */

/** @addtogroup at32f40xx_system
  * @{
  */  

/**
  * @brief Define to prevent recursive inclusion
  */

#ifndef __SYSTEM_AT32F40XX_H
#define __SYSTEM_AT32F40XX_H

#ifdef __cplusplus
 extern "C" {
#endif 

/** @addtogroup AT32F40xx_System_Includes
  * @{
  */

/** @defgroup AT32F40xx_System_Clock_Stable_Definition
  * @{
  */

#define HEXT_STABLE_DELAY                 (5000u)
#define PLL_STABLE_DELAY                  (500u)

/** @addtogroup AT32F40xx_System_Exported_types
  * @{
  */

extern uint32_t SystemCoreClock;          /*!< System Clock Frequency (Core Clock) */

/**
  * @}
  */

/** @addtogroup AT32F40xx_System_Exported_Constants
  * @{
  */

/**
  * @}
  */

/** @addtogroup AT32F40xx_System_Exported_Macros
  * @{
  */

/**
  * @}
  */

/** @addtogroup AT32F40xx_System_Exported_Functions
  * @{
  */

extern void SystemInit(void);
extern void SystemCoreClockUpdate(void);

/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /*__SYSTEM_AT32F40XX_H */

/**
  * @}
  */

/**
  * @}
  */

/*********************** (C) COPYRIGHT Artery Technologies *****END OF FILE****/
