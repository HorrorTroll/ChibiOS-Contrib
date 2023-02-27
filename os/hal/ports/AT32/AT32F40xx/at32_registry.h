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
 * @file    AT32F40xx/at32_registry.h
 * @brief   AT32F40xx capabilities registry.
 *
 * @addtogroup HAL
 * @{
 */

#ifndef AT32_REGISTRY_H
#define AT32_REGISTRY_H

#if defined(AT32F403xx)
#define AT32F403XX_OL

#elif defined(AT32F403Axx)
#define AT32F403AXX_NL

#elif defined(AT32F407xx)
#define AT32F407XX_CL

#else
#error "unsupported or unrecognized AT32F40xx member"
#endif

/*===========================================================================*/
/* Platform capabilities.                                                    */
/*===========================================================================*/

#if defined(AT32F403AXX_NL) || defined(__DOXYGEN__)
/**
 * @name    AT32F403A NL capabilities
 * @{
 */
/* ADC attributes.*/
#define AT32_HAS_ADC1                      TRUE
#define AT32_HAS_ADC2                      TRUE
#define AT32_HAS_ADC3                      TRUE

/* CAN attributes.*/
#define AT32_HAS_CAN1                      TRUE
#define AT32_HAS_CAN2                      TRUE
#define AT32_CAN_MAX_FILTERS               28

/* DAC attributes.*/
#define AT32_HAS_DAC1_CH1                  TRUE
#define AT32_DAC_DAC1_CH1_DMA_STREAM       AT32_DMA_STREAM_ID(2, 3)

#define AT32_HAS_DAC1_CH2                  TRUE
#define AT32_DAC_DAC1_CH2_DMA_STREAM       AT32_DMA_STREAM_ID(2, 4)

#define AT32_HAS_DAC2_CH1                  FALSE
#define AT32_HAS_DAC2_CH2                  FALSE

/* DMA attributes.*/
#define AT32_ADVANCED_DMA                  FALSE
#define AT32_DMA_SUPPORTS_DMAMUX           FALSE
#define AT32_DMA_SUPPORTS_CSELR            FALSE

#define AT32_DMA1_NUM_CHANNELS             7
#define AT32_DMA1_CH1_HANDLER              Vector6C
#define AT32_DMA1_CH2_HANDLER              Vector70
#define AT32_DMA1_CH3_HANDLER              Vector74
#define AT32_DMA1_CH4_HANDLER              Vector78
#define AT32_DMA1_CH5_HANDLER              Vector7C
#define AT32_DMA1_CH6_HANDLER              Vector80
#define AT32_DMA1_CH7_HANDLER              Vector84
#define AT32_DMA1_CH1_NUMBER               11
#define AT32_DMA1_CH2_NUMBER               12
#define AT32_DMA1_CH3_NUMBER               13
#define AT32_DMA1_CH4_NUMBER               14
#define AT32_DMA1_CH5_NUMBER               15
#define AT32_DMA1_CH6_NUMBER               16
#define AT32_DMA1_CH7_NUMBER               17

#define AT32_DMA2_NUM_CHANNELS             7
#define AT32_DMA2_CH1_HANDLER              Vector120
#define AT32_DMA2_CH2_HANDLER              Vector124
#define AT32_DMA2_CH3_HANDLER              Vector128
#define AT32_DMA2_CH4_5_HANDLER            Vector12C
#define AT32_DMA2_CH6_7_HANDLER            Vector16C
#define AT32_DMA2_CH1_NUMBER               56
#define AT32_DMA2_CH2_NUMBER               57
#define AT32_DMA2_CH3_NUMBER               58
#define AT32_DMA2_CH4_5_NUMBER             59
#define AT32_DMA2_CH6_7_NUMBER             75

/* EMAC attributes.*/
#define AT32_HAS_EMAC                      FALSE

/* EXINT attributes.*/
#define AT32_EXINT_NUM_LINES               19
#define AT32_EXINT_IMR_MASK                0x00000000U

/* FLASH attributes.*/
#define AT32_FLASH_NUMBER_OF_BANKS         2
#define AT32_FLASH_SECTOR_SIZE             2048U
#if !defined(AT32_FLASH_SECTORS_PER_BANK) || defined(__DOXYGEN__)
#define AT32_FLASH_SECTORS_PER_BANK        256 /* Maximum, can be redefined.*/
#endif

/* GPIO attributes.*/
#define AT32_HAS_GPIOA                     TRUE
#define AT32_HAS_GPIOB                     TRUE
#define AT32_HAS_GPIOC                     TRUE
#define AT32_HAS_GPIOD                     TRUE
#define AT32_HAS_GPIOE                     TRUE

/* I2C attributes.*/
#define AT32_HAS_I2C1                      TRUE
#define AT32_I2C_I2C1_RX_DMA_STREAM        AT32_DMA_STREAM_ID(1, 7)
#define AT32_I2C_I2C1_TX_DMA_STREAM        AT32_DMA_STREAM_ID(1, 6)

#define AT32_HAS_I2C2                      TRUE
#define AT32_I2C_I2C2_RX_DMA_STREAM        AT32_DMA_STREAM_ID(1, 5)
#define AT32_I2C_I2C2_TX_DMA_STREAM        AT32_DMA_STREAM_ID(1, 4)

#define AT32_HAS_I2C3                      TRUE
#define AT32_I2C_I2C3_RX_DMA_STREAM        AT32_DMA_STREAM_ID(1, 3)
#define AT32_I2C_I2C3_TX_DMA_STREAM        AT32_DMA_STREAM_ID(1, 2)

/* RTC attributes.*/
#define AT32_HAS_RTC                       TRUE
#define AT32_RTC_HAS_SUBSECONDS            TRUE
#define AT32_RTC_IS_CALENDAR               FALSE

/* SDIO attributes.*/
#define AT32_HAS_SDIO1                     TRUE
#define AT32_SDC_SDIO1_DMA_STREAM          AT32_DMA_STREAM_ID(2, 4)

#define AT32_HAS_SDIO2                     TRUE
#define AT32_SDC_SDIO2_DMA_STREAM          AT32_DMA_STREAM_ID(2, 5)

/* SPI attributes.*/
#define AT32_HAS_SPI1                      TRUE
#define AT32_SPI1_SUPPORTS_I2S             TRUE
#define AT32_SPI_SPI1_RX_DMA_STREAM        AT32_DMA_STREAM_ID(1, 2)
#define AT32_SPI_SPI1_TX_DMA_STREAM        AT32_DMA_STREAM_ID(1, 3)

#define AT32_HAS_SPI2                      TRUE
#define AT32_SPI2_SUPPORTS_I2S             TRUE
#define AT32_SPI2_I2S_FULLDUPLEX           TRUE
#define AT32_SPI_SPI2_RX_DMA_STREAM        AT32_DMA_STREAM_ID(1, 4)
#define AT32_SPI_SPI2_TX_DMA_STREAM        AT32_DMA_STREAM_ID(1, 5)

#define AT32_HAS_SPI3                      TRUE
#define AT32_SPI3_SUPPORTS_I2S             TRUE
#define AT32_SPI3_I2S_FULLDUPLEX           TRUE
#define AT32_SPI_SPI3_RX_DMA_STREAM        AT32_DMA_STREAM_ID(2, 1)
#define AT32_SPI_SPI3_TX_DMA_STREAM        AT32_DMA_STREAM_ID(2, 2)

#define AT32_HAS_SPI4                      TRUE
#define AT32_SPI2_SUPPORTS_I2S             TRUE
#define AT32_SPI_SPI4_RX_DMA_STREAM        AT32_DMA_STREAM_ID(2, 3)
#define AT32_SPI_SPI4_TX_DMA_STREAM        AT32_DMA_STREAM_ID(2, 4)

/* TMR attributes.*/
#define AT32_TMR_MAX_CHANNELS              4

#define AT32_HAS_TMR1                      TRUE
#define AT32_TMR1_IS_32BITS                FALSE
#define AT32_TMR1_CHANNELS                 4

#define AT32_HAS_TMR2                      TRUE
#define AT32_TMR2_IS_32BITS                TRUE
#define AT32_TMR2_CHANNELS                 4

#define AT32_HAS_TMR3                      TRUE
#define AT32_TMR3_IS_32BITS                FALSE
#define AT32_TMR3_CHANNELS                 4

#define AT32_HAS_TMR4                      TRUE
#define AT32_TMR4_IS_32BITS                FALSE
#define AT32_TMR4_CHANNELS                 4

#define AT32_HAS_TMR5                      TRUE
#define AT32_TMR5_IS_32BITS                TRUE
#define AT32_TMR5_CHANNELS                 4

#define AT32_HAS_TMR6                      TRUE
#define AT32_TMR6_IS_32BITS                FALSE
#define AT32_TMR6_CHANNELS                 0

#define AT32_HAS_TMR7                      TRUE
#define AT32_TMR7_IS_32BITS                FALSE
#define AT32_TMR7_CHANNELS                 0

#define AT32_HAS_TMR8                      TRUE
#define AT32_TMR8_IS_32BITS                FALSE
#define AT32_TMR8_CHANNELS                 4

#define AT32_HAS_TMR9                      TRUE
#define AT32_TMR9_IS_32BITS                FALSE
#define AT32_TMR9_CHANNELS                 2

#define AT32_HAS_TMR10                     TRUE
#define AT32_TMR10_IS_32BITS               FALSE
#define AT32_TMR10_CHANNELS                1

#define AT32_HAS_TMR11                     TRUE
#define AT32_TMR11_IS_32BITS               FALSE
#define AT32_TMR11_CHANNELS                1

#define AT32_HAS_TMR12                     TRUE
#define AT32_TMR12_IS_32BITS               FALSE
#define AT32_TMR12_CHANNELS                2

#define AT32_HAS_TMR13                     TRUE
#define AT32_TMR13_IS_32BITS               FALSE
#define AT32_TMR13_CHANNELS                1

#define AT32_HAS_TMR14                     TRUE
#define AT32_TMR14_IS_32BITS               FALSE
#define AT32_TMR14_CHANNELS                1

/* USART attributes.*/
#define AT32_HAS_USART1                    TRUE
#define AT32_UART_USART1_RX_DMA_STREAM     AT32_DMA_STREAM_ID(1, 5)
#define AT32_UART_USART1_TX_DMA_STREAM     AT32_DMA_STREAM_ID(1, 4)

#define AT32_HAS_USART2                    TRUE
#define AT32_UART_USART2_RX_DMA_STREAM     AT32_DMA_STREAM_ID(1, 6)
#define AT32_UART_USART2_TX_DMA_STREAM     AT32_DMA_STREAM_ID(1, 7)

#define AT32_HAS_USART3                    TRUE
#define AT32_UART_USART3_RX_DMA_STREAM     AT32_DMA_STREAM_ID(1, 3)
#define AT32_UART_USART3_TX_DMA_STREAM     AT32_DMA_STREAM_ID(1, 2)

#define AT32_HAS_UART4                     TRUE
#define AT32_UART_UART4_RX_DMA_STREAM      AT32_DMA_STREAM_ID(2, 3)
#define AT32_UART_UART4_TX_DMA_STREAM      AT32_DMA_STREAM_ID(2, 5)

#define AT32_HAS_UART5                     TRUE
#define AT32_HAS_USART6                    TRUE
#define AT32_HAS_UART7                     TRUE
#define AT32_HAS_UART8                     TRUE

/* USB attributes.*/
#define AT32_HAS_USB                       TRUE
#define AT32_USB_ACCESS_SCHEME_2x16        FALSE
#define AT32_USB_UCFO_SIZE                 512

/* WDT attributes.*/
#define AT32_HAS_WDT                       TRUE
#define AT32_WDT_IS_WINDOWED               FALSE

/* XMC attributes.*/
#define AT32_HAS_XMC                       TRUE
#define AT32_XMC_IS_FMC                    FALSE
#define AT32_XMC_HANDLER                   Vector100
#define AT32_XMC_NUMBER                    48

/* CRC attributes.*/
#define AT32_HAS_CRC                       TRUE
#define AT32_CRC_PROGRAMMABLE              FALSE
/** @} */
#endif /* defined(AT32F403AXX_NL) */

#endif /* AT32_REGISTRY_H */

/** @} */
