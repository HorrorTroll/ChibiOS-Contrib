/*
    ChibiOS - Copyright (C) 2006..2018 Giovanni Di Sirio
    ChibiOS - Copyright (C) 2023 Artery Technology
    ChibiOS - Copyright (C) 2023 HorrorTroll

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

#ifndef _BOARD_H_
#define _BOARD_H_

/*
 * Setup for a AT-START-F403A board.
 */

/*
 * Board identifier.
 */
#define BOARD_AT_START_F403A
#define BOARD_NAME                  "Artery AT-START-F403A"

/*
 * Board frequencies.
 */
#define AT32_LEXTCLK                32768
#define AT32_HEXTCLK                8000000

/*
 * MCU type, supported types are defined in ./os/hal/platforms/hal_lld.h.
 */
#define AT32F403AxC

/*
 * IO pins assignments.
 */
#define GPIOA_ARD_A0                0U
#define GPIOA_ADC123_IN0            0U
#define GPIOA_ARD_A1                1U
#define GPIOA_ADC123_IN1            1U
#define GPIOA_ARD_D1                2U
#define GPIOA_USART2_TX             2U
#define GPIOA_ARD_D0                3U
#define GPIOA_USART2_RX             3U
#define GPIOA_ARD_A2                4U
#define GPIOA_ADC12_IN4             4U
#define GPIOA_ARD_D13               5U
#define GPIOA_ARD_D12               6U
#define GPIOA_ARD_D11               7U
#define GPIOA_ARD_D7                8U
#define GPIOA_ARD_D8                9U
#define GPIOA_ARD_D2                10U
#define GPIOA_PIN11                 11U
#define GPIOA_PIN12                 12U
#define GPIOA_SWDIO                 13U
#define GPIOA_SWCLK                 14U
#define GPIOA_ARD_D10               15U

#define GPIOB_ARD_A3                0U
#define GPIOB_ADC12_IN8             0U
#define GPIOB_PIN1                  1U
#define GPIOB_PIN2                  2U
#define GPIOB_ARD_D3                3U
#define GPIOB_SWO                   3U
#define GPIOB_ARD_D5                4U
#define GPIOB_ARD_D4                5U
#define GPIOB_PIN6                  6U
#define GPIOB_PIN7                  7U
#define GPIOB_ARD_SCL               8U
#define GPIOB_ARD_SDA               9U
#define GPIOB_ARD_D6                10U
#define GPIOB_PIN10                 10U
#define GPIOB_ARD_PB11              11U
#define GPIOB_PIN11                 11U
#define GPIOB_ARD_NSS               12U
#define GPIOB_PIN12                 12U
#define GPIOB_ARD_SCK               13U
#define GPIOB_ARD_MISO              14U
#define GPIOB_ARD_MOSI              15U

#define GPIOC_ARD_A5                0U
#define GPIOC_ADC123_IN10           0U
#define GPIOC_ARD_A4                1U
#define GPIOC_ADC123_IN11           1U
#define GPIOC_PIN2                  2U
#define GPIOC_PIN3                  3U
#define GPIOC_PIN4                  4U
#define GPIOC_PIN5                  5U
#define GPIOC_PIN6                  6U
#define GPIOC_ARD_D9                7U
#define GPIOC_PIN8                  8U
#define GPIOC_PIN9                  9U
#define GPIOC_PIN10                 10U
#define GPIOC_PIN11                 11U
#define GPIOC_PIN12                 12U
#define GPIOC_BUTTON                13U
#define GPIOC_PIN14                 14U
#define GPIOC_PIN15                 15U

#define GPIOD_PIN0                  0U
#define GPIOD_PIN1                  1U
#define GPIOD_PIN2                  2U
#define GPIOD_PIN3                  3U
#define GPIOD_PIN4                  4U
#define GPIOD_PIN5                  5U
#define GPIOD_PIN6                  6U
#define GPIOD_PIN7                  7U
#define GPIOD_PIN8                  8U
#define GPIOD_PIN9                  9U
#define GPIOD_PIN10                 10U
#define GPIOD_PIN11                 11U
#define GPIOD_PIN12                 12U
#define GPIOD_LED_RED               13U
#define GPIOD_LED_YELLOW            14U
#define GPIOD_LED_GREEN             15U

#define GPIOE_PIN0                  0U
#define GPIOE_PIN1                  1U
#define GPIOE_PIN2                  2U
#define GPIOE_PIN3                  3U
#define GPIOE_PIN4                  4U
#define GPIOE_PIN5                  5U
#define GPIOE_PIN6                  6U
#define GPIOE_PIN7                  7U
#define GPIOE_PIN8                  8U
#define GPIOE_PIN9                  9U
#define GPIOE_PIN10                 10U
#define GPIOE_PIN11                 11U
#define GPIOE_PIN12                 12U
#define GPIOE_PIN13                 13U
#define GPIOE_PIN14                 14U
#define GPIOE_PIN15                 15U

/*
 * I/O ports initial setup, this configuration is established soon after reset
 * in the initialization code.
 *
 * The digits have the following meaning:
 *   0 - Analog input.
 *   1 - Push Pull output 10MHz.
 *   2 - Push Pull output 2MHz.
 *   3 - Push Pull output 50MHz.
 *   4 - Digital input.
 *   5 - Open Drain output 10MHz.
 *   6 - Open Drain output 2MHz.
 *   7 - Open Drain output 50MHz.
 *   8 - Digital input with Pull-Up or Pull-Down resistor depending on ODT.
 *   9 - Alternate Push Pull output 10MHz.
 *   A - Alternate Push Pull output 2MHz.
 *   B - Alternate Push Pull output 50MHz.
 *   C - Reserved.
 *   D - Alternate Open Drain output 10MHz.
 *   E - Alternate Open Drain output 2MHz.
 *   F - Alternate Open Drain output 50MHz.
 * Please refer to the AT32 Reference Manual for details.
 */

/*
 * Port A setup.
 * Everything input with pull-up except:
 * PA2  - Alternate output          (GPIOA_ARD_D1, GPIOA_USART2_TX)
 * PA3  - Normal input              (GPIOA_ARD_D0, GPIOA_USART2_RX)
 * PA13 - Pull-up input             (GPIOA_SWDIO)
 * PA14 - Pull-down input           (GPIOA_SWCLK)
 */
#define VAL_GPIOACFGLR          0x88884B88      /*  PA7...PA0 */
#define VAL_GPIOACFGHR          0x88888888      /* PA15...PA8 */
#define VAL_GPIOAODT            0xFFFFFFFF

/*
 * Port B setup.
 * Everything input with pull-up except:
 * PB3  - Pull-up input             (GPIOB_SWO)
 */
#define VAL_GPIOBCFGLR          0x88888888      /*  PB7...PB0 */
#define VAL_GPIOBCFGHR          0x88888888      /* PB15...PB8 */
#define VAL_GPIOBODT            0xFFFFFFFF

/*
 * Port C setup.
 * Everything input with pull-up except:
 * PC13 - Normal input              (GPIOC_BUTTON)
 */
#define VAL_GPIOCCFGLR          0x88888888      /*  PC7...PC0 */
#define VAL_GPIOCCFGHR          0x88488888      /* PC15...PC8 */
#define VAL_GPIOCODT            0xFFFFFFFF

/*
 * Port D setup.
 * Everything input with pull-up except:
 * PD13 - Push Pull output          (GPIOD_LED_RED)
 * PD14 - Push Pull output          (GPIOD_LED_YELLOW)
 * PD15 - Push Pull output          (GPIOD_LED_GREEN)
 */
#define VAL_GPIODCFGLR          0x88888888      /*  PD7...PD0 */
#define VAL_GPIODCFGHR          0x33388888      /* PD15...PD8 */
#define VAL_GPIODODT            0xFFFFFFFF

/*
 * Port E setup.
 */
#define VAL_GPIOECFGLR          0x88888888      /*  PE7...PE0 */
#define VAL_GPIOECFGHR          0x88888888      /* PE15...PE8 */
#define VAL_GPIOEODT            0xFFFFFFFF

/*
 * USB bus activation macro, required by the USB driver.
 */
#define usb_lld_connect_bus(usbp)

/*
 * USB bus de-activation macro, required by the USB driver.
 */
#define usb_lld_disconnect_bus(usbp)

#if !defined(_FROM_ASM_)
#ifdef __cplusplus
extern "C" {
#endif
  void boardInit(void);
#ifdef __cplusplus
}
#endif
#endif /* _FROM_ASM_ */

#endif /* _BOARD_H_ */
