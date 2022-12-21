/**
  ******************************************************************************
  * @file    at32f40xx.h
  * @author  Artery Technology & HorrorTroll
  * @brief   CMSIS AT32F40xx Device Peripheral Access Layer Header File. 
  *
  *          The file is the unique include file that the application programmer
  *          is using in the C source code, usually in main.c. This file contains:
  *            - Configuration section that allows to select:
  *              - The AT32F40xx device used in the target application
  *              - To use or not the peripheral’s drivers in application code(i.e. 
  *                code will be based on direct access to peripheral’s registers 
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

/** @addtogroup at32f40xx
  * @{
  */
    
#ifndef __AT32F40XX_H
#define __AT32F40XX_H

#ifdef __cplusplus
 extern "C" {
#endif /* __cplusplus */
  
/** @addtogroup Library_configuration_section
  * @{
  */

/**
  * @brief AT32 Family
  */
#if !defined (AT32F40)
#define AT32F40
#endif /* AT32F40 */

/* Uncomment the line below according to the target AT32 device used in your
   application 
  */

#if !defined (AT32F403xx) && !defined (AT32F403Axx) && \
    !defined (AT32F407xx)
   /* #define AT32F403xx  */    /*!< AT32F403CC, AT32F403CE, AT32F403CG, AT32F403RC, AT32F403RE, AT32F403RG, AT32F403VC, AT32F403VE, AT32F403VG, AT32F403ZC, AT32F403ZE, and AT32F403ZG */
   /* #define AT32F403Axx */    /*!< AT32F403ACC, AT32F403ACE, AT32F403ACG, AT32F403ARC, AT32F403ARE, AT32F403ARG, AT32F403AVC, AT32F403AVE and AT32F403AVG */
   /* #define AT32F407xx  */    /*!< AT32F407RC, AT32F407RE, AT32F407RG, AT32F407VC, AT32F407VE, AT32F407VG, AT32F407AVC and AT32F407AVG */
#endif

/*  Tip: To avoid modifying this file each time you need to switch between these
        devices, you can define the device in your toolchain compiler preprocessor.
  */
  
#if !defined  (USE_HAL_DRIVER)
/**
 * @brief Comment the line below if you will not use the peripherals drivers.
   In this case, these drivers will not be included and the application code will 
   be based on direct access to peripherals registers 
   */
   /* #define USE_HAL_DRIVER */
#endif /* USE_HAL_DRIVER */

/**
  * @}
  */

/** @addtogroup Device_Included
  * @{
  */

#if defined(AT32F403xx)
   #include "at32f403xx.h"
#elif defined(AT32F403Axx)
   #include "at32f403axx.h"
#elif defined(AT32F407xx)
   #include "at32f407xx.h"
#else
   #error "Please select first the target AT32F40xx device used in your application (in at32f40xx.h file)"
#endif

/**
  * @}
  */

/** @addtogroup Exported_types
  * @{
  */  
typedef enum 
{
  RESET = 0, 
  SET = !RESET
} FlagStatus, ITStatus;

typedef enum 
{
  DISABLE = 0, 
  ENABLE = !DISABLE
} FunctionalState;

#define IS_FUNCTIONAL_STATE(STATE) (((STATE) == DISABLE) || ((STATE) == ENABLE))

typedef enum 
{
  ERROR = 0, 
  SUCCESS = !ERROR
} ErrorStatus;

/**
  * @}
  */


/** @addtogroup Exported_macros
  * @{
  */

#define SET_BIT(REG, BIT)     ((REG) |= (BIT))

#define CLEAR_BIT(REG, BIT)   ((REG) &= ~(BIT))

#define READ_BIT(REG, BIT)    ((REG) & (BIT))

#define CLEAR_REG(REG)        ((REG) = (0x0))

#define WRITE_REG(REG, VAL)   ((REG) = (VAL))

#define READ_REG(REG)         ((REG))

#define MODIFY_REG(REG, CLEARMASK, SETMASK)  WRITE_REG((REG), (((READ_REG(REG)) & (~(CLEARMASK))) | (SETMASK)))

#define POSITION_VAL(VAL)     (__CLZ(__RBIT(VAL))) 

/**
  * @}
  */

#if defined (USE_HAL_DRIVER)
   #include "at32f40xx_hal.h"
#endif /* USE_HAL_DRIVER */

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __AT32F40XX_H */

/**
  * @}
  */

/**
  * @}
  */

/*********************** (C) COPYRIGHT Artery Technologies *****END OF FILE****/
