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
 * @file    USBv1/at32_usb.h
 * @brief   AT32 USB registers layout header.
 * @note    This file requires definitions from the Artery AT32 header files
 *          at32f40xx.h.
 *
 * @addtogroup USB
 * @{
 */

#ifndef AT32_USB_H
#define AT32_USB_H

/**
 * @brief   Number of the available endpoints.
 * @details This value does not include the endpoint 0 which is always present.
 */
#define USB_ENDPOINTS_NUMBER            7

/**
 * @brief   Width of USB packet memory accesses.
 */
#if AT32_USB_ACCESS_SCHEME_2x16
typedef uint16_t at32_usb_ucfo_t;
#else
typedef uint32_t at32_usb_ucfo_t;
#endif

/**
 * @brief   USB registers block.
 */
typedef struct {
  /**
   * @brief   Endpoint registers.
   */
  volatile uint32_t             EPT[USB_ENDPOINTS_NUMBER + 1];
  /*
   * @brief   Reserved space.
   */
  volatile uint32_t             _r20[8];
  /*
   * @brief   Control Register.
   */
  volatile uint32_t             CTRL;
  /*
   * @brief   Interrupt Status Register.
   */
  volatile uint32_t             INTSTS;
  /*
   * @brief   Frame Number Register.
   */
  volatile uint32_t             SOFRNUM;
  /*
   * @brief   Device Address Register.
   */
  volatile uint32_t             DEVADDR;
  /*
   * @brief   Buffer Table Address.
   */
  volatile uint32_t             BUFTBL;
  /*
   * @brief   LPM Control and Status Register.
   */
  volatile uint32_t             LPMCSR;
#if AT32_USB_HAS_BCDR
  /*
   * @brief   Battery Charging Detector
   */
  volatile uint32_t             BCDR;
#endif
} at32_usb_t;

/**
 * @brief   USB descriptor registers block.
 */
typedef struct {
  /**
   * @brief   TX buffer offset register.
   */
  volatile at32_usb_ucfo_t      TXADDR0;
  /**
   * @brief   TX counter register 0.
   */
  volatile at32_usb_ucfo_t      TXCOUNT0;
  /**
   * @brief   RX buffer offset register.
   */
  volatile at32_usb_ucfo_t      RXADDR0;
  /**
   * @brief   RX counter register 0.
   */
  volatile at32_usb_ucfo_t      RXCOUNT0;
} at32_usb_descriptor_t;

/**
 * @name    Register aliases
 * @{
 */
#define RXCOUNT1                TXCOUNT0
#define TXCOUNT1                RXCOUNT0
#define RXADDR1                 TXADDR0
#define TXADDR1                 RXADDR0
/** @} */

/**
 * @brief USB registers block numeric address.
 */
#if defined(USB1_BASE) || defined(__DOXYGEN__)
  #define AT32_USB_BASE         USB1_BASE
#elif defined(USB_BASE)
  #define AT32_USB_BASE         USB_BASE
#else
  #define AT32_USB_BASE         (APB1PERIPH_BASE + 0x5C00)
#endif

/**
 * @brief USB RAM numeric address.
 */
#if defined(USB1_UCFOADDR) || defined(__DOXYGEN__)
  #define AT32_USBRAM_BASE      USB1_UCFOADDR
#elif defined(USB_UCFOADDR)
  #define AT32_USBRAM_BASE      USB_UCFOADDR
#elif defined(USB_DRD_UCFOADDR)
#define AT32_USBRAM_BASE        USB_DRD_UCFOADDR
#else
  #define AT32_USBRAM_BASE      (APB1PERIPH_BASE + 0x6000)
#endif

/**
 * @brief Pointer to the USB registers block.
 */
#define AT32_USB                ((at32_usb_t *)AT32_USB_BASE)

/**
 * @brief   Pointer to the USB RAM.
 */
#define AT32_USBRAM             ((at32_usb_ucfo_t *)AT32_USBRAM_BASE)

/**
 * @brief   Mask of all the toggling bits in the EPT register.
 */
#define EPT_TOGGLE_MASK         (EPT_TXSTS_MASK | EPT_TXDTS |               \
                                 EPT_RXSTS_MASK | EPT_RXDTS |               \
                                 EPT_SETUPTC)

#define EPT_EPTADDR_MASK        0x000F
#define EPT_TXSTS_MASK          0x0030
#define EPT_TXSTS_DIS           0x0000
#define EPT_TXSTS_STALL         0x0010
#define EPT_TXSTS_NAK           0x0020
#define EPT_TXSTS_VALID         0x0030
#define EPT_TXDTS               0x0040
#define EPT_SWBUF_RX            EPT_TXDTS
#define EPT_TXTC                0x0080
#define EPT_EXF                 0x0100
#define EPT_EP_DBL_BUF          EPT_EXF
#define EPT_EP_STATUS_OUT       EPT_EXF
#define EPT_TRANS_TYPE_MASK     0x0600
#define EPT_TRANS_TYPE_BULK     0x0000
#define EPT_TRANS_TYPE_CTRL     0x0200
#define EPT_TRANS_TYPE_ISO      0x0400
#define EPT_TRANS_TYPE_INT      0x0600
#define EPT_SETUPTC             0x0800
#define EPT_RXSTS_MASK          0x3000
#define EPT_RXSTS_DIS           0x0000
#define EPT_RXSTS_STALL         0x1000
#define EPT_RXSTS_NAK           0x2000
#define EPT_RXSTS_VALID         0x3000
#define EPT_RXDTS               0x4000
#define EPT_SWBUF_TX            EPT_RXDTS
#define EPT_RXTC                0x8000

#define CTRL_CSRST              0x0001
#define CTRL_DISUSB             0x0002
#define CTRL_LPM                0x0004
#define CTRL_SSP                0x0008
#define CTRL_GRESUME            0x0010
#define CTRL_LSOFIEN            0x0100
#define CTRL_SOFIEN             0x0200
#define CTRL_RSTIEN             0x0400
#define CTRL_SPIEN              0x0800
#define CTRL_WKIEN              0x1000
#define CTRL_BEIEN              0x2000
#define CTRL_UCFORIEN           0x4000
#define CTRL_TCIEN              0x8000

#define INTSTS_EPT_NUM_MASK     0x000F
#define INTSTS_INOUT            0x0010
#define INTSTS_LSOF             0x0100
#define INTSTS_SOF              0x0200
#define INTSTS_RST              0x0400
#define INTSTS_SP               0x0800
#define INTSTS_WK               0x1000
#define INTSTS_BE               0x2000
#define INTSTS_UCFOR            0x4000
#define INTSTS_TC               0x8000

#define SOFRNUM_SOFNUM_MASK     0x07FF
#define SOFRNUM_LSOFNUM         0x1800
#define SOFRNUM_CLCK            0x2000
#define SOFRNUM_DMSTS           0x4000
#define SOFRNUM_DPSTS           0x8000

#define DEVADDR_ADDR_MASK       0x007F
#define DEVADDR_CEN             0x0080

#define RXCOUNT_COUNT_MASK      0x03FF
#define TXCOUNT_COUNT_MASK      0x03FF

#define EPT_TC_MASK            (EPT_TXTC | EPT_RXTC)

#define EPT_SET_RXSTS(ep, ept)                                              \
  AT32_USB->EPT[ep] = ((AT32_USB->EPT[ep] &                                 \
                       ~(EPT_TOGGLE_MASK & ~EPT_RXSTS_MASK)) ^              \
                      (ept)) | EPT_TC_MASK

#define EPT_SET_TXSTS(ep, ept)                                              \
  AT32_USB->EPT[ep] = ((AT32_USB->EPT[ep] &                                 \
                       ~(EPT_TOGGLE_MASK & ~EPT_TXSTS_MASK)) ^              \
                      (ept)) | EPT_TC_MASK

#define EPT_CLEAR_RXTC(ep)                                                  \
  AT32_USB->EPT[ep] = (AT32_USB->EPT[ep] & ~EPT_RXTC & ~EPT_TOGGLE_MASK)    \
                      | EPT_TXTC

#define EPT_CLEAR_TXTC(ep)                                                  \
  AT32_USB->EPT[ep] = (AT32_USB->EPT[ep] & ~EPT_TXTC & ~EPT_TOGGLE_MASK)    \
                      | EPT_RXTC

/**
 * @brief   Returns an endpoint descriptor pointer.
 */
#define USB_GET_DESCRIPTOR(ep)                                              \
  ((at32_usb_descriptor_t *)((uint32_t)AT32_USBRAM_BASE +                   \
                             (uint32_t)AT32_USB->BUFTBL +                   \
                             (uint32_t)(ep) *                               \
                             sizeof(at32_usb_descriptor_t)))

/**
 * @brief   Converts from a UCFO address to a physical address.
 */
#define USB_ADDR2PTR(addr)                                                  \
  ((at32_usb_ucfo_t *)((addr) *                                             \
                       (sizeof(at32_usb_ucfo_t) / 2) +                      \
                       AT32_USBRAM_BASE))

#endif /* AT32_USB_H */

/** @} */
