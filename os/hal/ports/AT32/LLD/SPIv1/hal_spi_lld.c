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
 * @file    SPIv1/hal_spi_lld.c
 * @brief   AT32 SPI subsystem low level driver source.
 *
 * @addtogroup SPI
 * @{
 */

#include "hal.h"

#if HAL_USE_SPI || defined(__DOXYGEN__)

/*===========================================================================*/
/* Driver local definitions.                                                 */
/*===========================================================================*/

/*===========================================================================*/
/* Driver exported variables.                                                */
/*===========================================================================*/

/** @brief SPI1 driver identifier.*/
#if AT32_SPI_USE_SPI1 || defined(__DOXYGEN__)
SPIDriver SPID1;
#endif

/** @brief SPI2 driver identifier.*/
#if AT32_SPI_USE_SPI2 || defined(__DOXYGEN__)
SPIDriver SPID2;
#endif

/** @brief SPI3 driver identifier.*/
#if AT32_SPI_USE_SPI3 || defined(__DOXYGEN__)
SPIDriver SPID3;
#endif

/** @brief SPI4 driver identifier.*/
#if AT32_SPI_USE_SPI4 || defined(__DOXYGEN__)
SPIDriver SPID4;
#endif

/*===========================================================================*/
/* Driver local variables and types.                                         */
/*===========================================================================*/

static const uint16_t dummytx = 0xFFFFU;
static uint16_t dummyrx;

/*===========================================================================*/
/* Driver local functions.                                                   */
/*===========================================================================*/

/**
 * @brief   Shared end-of-rx service routine.
 *
 * @param[in] spip      pointer to the @p SPIDriver object
 * @param[in] flags     pre-shifted content of the STS register
 */
static void spi_lld_serve_rx_interrupt(SPIDriver *spip, uint32_t flags) {

  /* DMA errors handling.*/
#if defined(AT32_SPI_DMA_ERROR_HOOK)
  if ((flags & AT32_DMA_STS_DTERRF) != 0) {
    AT32_SPI_DMA_ERROR_HOOK(spip);
  }
#else
  (void)flags;
#endif

  if (spip->config->circular) {
    if ((flags & AT32_DMA_STS_HDTF) != 0U) {
      /* Half buffer interrupt.*/
      _spi_sts_half_code(spip);
    }
    if ((flags & AT32_DMA_STS_FDTF) != 0U) {
      /* End buffer interrupt.*/
      _spi_sts_full_code(spip);
    }
  }
  else {
    /* Stopping DMAs.*/
    dmaStreamDisable(spip->dmatx);
    dmaStreamDisable(spip->dmarx);

    /* Portable SPI STS code defined in the high level driver, note, it is
       a macro.*/
    _spi_sts_code(spip);
  }
}

/**
 * @brief   Shared end-of-tx service routine.
 *
 * @param[in] spip      pointer to the @p SPIDriver object
 * @param[in] flags     pre-shifted content of the STS register
 */
static void spi_lld_serve_tx_interrupt(SPIDriver *spip, uint32_t flags) {

  /* DMA errors handling.*/
#if defined(AT32_SPI_DMA_ERROR_HOOK)
  (void)spip;
  if ((flags & AT32_DMA_STS_DTERRF) != 0) {
    AT32_SPI_DMA_ERROR_HOOK(spip);
  }
#else
  (void)spip;
  (void)flags;
#endif
}

/*===========================================================================*/
/* Driver interrupt handlers.                                                */
/*===========================================================================*/

/*===========================================================================*/
/* Driver exported functions.                                                */
/*===========================================================================*/

/**
 * @brief   Low level SPI driver initialization.
 *
 * @notapi
 */
void spi_lld_init(void) {

#if AT32_SPI_USE_SPI1
  spiObjectInit(&SPID1);
  SPID1.spi       = SPI1;
  SPID1.dmarx     = NULL;
  SPID1.dmatx     = NULL;
  SPID1.rxdmamode = AT32_DMA_CTRL_CHPL(AT32_SPI_SPI1_DMA_PRIORITY) |
                    AT32_DMA_CTRL_DTD_P2M |
                    AT32_DMA_CTRL_FDTIEN |
                    AT32_DMA_CTRL_DTERRIEN;
  SPID1.txdmamode = AT32_DMA_CTRL_CHPL(AT32_SPI_SPI1_DMA_PRIORITY) |
                    AT32_DMA_CTRL_DTD_M2P |
                    AT32_DMA_CTRL_DTERRIEN;
#endif

#if AT32_SPI_USE_SPI2
  spiObjectInit(&SPID2);
  SPID2.spi       = SPI2;
  SPID2.dmarx     = NULL;
  SPID2.dmatx     = NULL;
  SPID2.rxdmamode = AT32_DMA_CTRL_CHPL(AT32_SPI_SPI2_DMA_PRIORITY) |
                    AT32_DMA_CTRL_DTD_P2M |
                    AT32_DMA_CTRL_FDTIEN |
                    AT32_DMA_CTRL_DTERRIEN;
  SPID2.txdmamode = AT32_DMA_CTRL_CHPL(AT32_SPI_SPI2_DMA_PRIORITY) |
                    AT32_DMA_CTRL_DTD_M2P |
                    AT32_DMA_CTRL_DTERRIEN;
#endif

#if AT32_SPI_USE_SPI3
  spiObjectInit(&SPID3);
  SPID3.spi       = SPI3;
  SPID3.dmarx     = NULL;
  SPID3.dmatx     = NULL;
  SPID3.rxdmamode = AT32_DMA_CTRL_CHPL(AT32_SPI_SPI3_DMA_PRIORITY) |
                    AT32_DMA_CTRL_DTD_P2M |
                    AT32_DMA_CTRL_FDTIEN |
                    AT32_DMA_CTRL_DTERRIEN;
  SPID3.txdmamode = AT32_DMA_CTRL_CHPL(AT32_SPI_SPI3_DMA_PRIORITY) |
                    AT32_DMA_CTRL_DTD_M2P |
                    AT32_DMA_CTRL_DTERRIEN;
#endif

#if AT32_SPI_USE_SPI4
  spiObjectInit(&SPID4);
  SPID4.spi       = SPI4;
  SPID4.dmarx     = NULL;
  SPID4.dmatx     = NULL;
  SPID4.rxdmamode = AT32_DMA_CTRL_CHPL(AT32_SPI_SPI4_DMA_PRIORITY) |
                    AT32_DMA_CTRL_DTD_P2M |
                    AT32_DMA_CTRL_FDTIEN |
                    AT32_DMA_CTRL_DTERRIEN;
  SPID4.txdmamode = AT32_DMA_CTRL_CHPL(AT32_SPI_SPI4_DMA_PRIORITY) |
                    AT32_DMA_CTRL_DTD_M2P |
                    AT32_DMA_CTRL_DTERRIEN;
#endif
}

/**
 * @brief   Configures and activates the SPI peripheral.
 *
 * @param[in] spip      pointer to the @p SPIDriver object
 *
 * @notapi
 */
void spi_lld_start(SPIDriver *spip) {

  /* If in stopped state then enables the SPI and DMA clocks.*/
  if (spip->state == SPI_STOP) {
#if AT32_SPI_USE_SPI1
    if (&SPID1 == spip) {
      spip->dmarx = dmaStreamAllocI(AT32_SPI_SPI1_RX_DMA_STREAM,
                                    AT32_SPI_SPI1_IRQ_PRIORITY,
                                    (at32_dmasts_t)spi_lld_serve_rx_interrupt,
                                    (void *)spip);
      osalDbgAssert(spip->dmarx != NULL, "unable to allocate stream");
      spip->dmatx = dmaStreamAllocI(AT32_SPI_SPI1_TX_DMA_STREAM,
                                    AT32_SPI_SPI1_IRQ_PRIORITY,
                                    (at32_dmasts_t)spi_lld_serve_tx_interrupt,
                                    (void *)spip);
      osalDbgAssert(spip->dmatx != NULL, "unable to allocate stream");
      crmEnableSPI1(true);
    }
#endif
#if AT32_SPI_USE_SPI2
    if (&SPID2 == spip) {
      spip->dmarx = dmaStreamAllocI(AT32_SPI_SPI2_RX_DMA_STREAM,
                                    AT32_SPI_SPI2_IRQ_PRIORITY,
                                    (at32_dmasts_t)spi_lld_serve_rx_interrupt,
                                    (void *)spip);
      osalDbgAssert(spip->dmarx != NULL, "unable to allocate stream");
      spip->dmatx = dmaStreamAllocI(AT32_SPI_SPI2_TX_DMA_STREAM,
                                    AT32_SPI_SPI2_IRQ_PRIORITY,
                                    (at32_dmasts_t)spi_lld_serve_tx_interrupt,
                                    (void *)spip);
      osalDbgAssert(spip->dmatx != NULL, "unable to allocate stream");
      crmEnableSPI2(true);
    }
#endif
#if AT32_SPI_USE_SPI3
    if (&SPID3 == spip) {
      spip->dmarx = dmaStreamAllocI(AT32_SPI_SPI3_RX_DMA_STREAM,
                                    AT32_SPI_SPI3_IRQ_PRIORITY,
                                    (at32_dmasts_t)spi_lld_serve_rx_interrupt,
                                    (void *)spip);
      osalDbgAssert(spip->dmarx != NULL, "unable to allocate stream");
      spip->dmatx = dmaStreamAllocI(AT32_SPI_SPI3_TX_DMA_STREAM,
                                    AT32_SPI_SPI3_IRQ_PRIORITY,
                                    (at32_dmasts_t)spi_lld_serve_tx_interrupt,
                                    (void *)spip);
      osalDbgAssert(spip->dmatx != NULL, "unable to allocate stream");
      crmEnableSPI3(true);
    }
#endif
#if AT32_SPI_USE_SPI4
    if (&SPID4 == spip) {
      spip->dmarx = dmaStreamAllocI(AT32_SPI_SPI4_RX_DMA_STREAM,
                                    AT32_SPI_SPI4_IRQ_PRIORITY,
                                    (at32_dmasts_t)spi_lld_serve_rx_interrupt,
                                    (void *)spip);
      osalDbgAssert(spip->dmarx != NULL, "unable to allocate stream");
      spip->dmatx = dmaStreamAllocI(AT32_SPI_SPI4_TX_DMA_STREAM,
                                    AT32_SPI_SPI4_IRQ_PRIORITY,
                                    (at32_dmasts_t)spi_lld_serve_tx_interrupt,
                                    (void *)spip);
      osalDbgAssert(spip->dmatx != NULL, "unable to allocate stream");
      crmEnableSPI4(true);
    }
#endif

    /* DMA setup.*/
    dmaStreamSetPeripheral(spip->dmarx, &spip->spi->DT);
    dmaStreamSetPeripheral(spip->dmatx, &spip->spi->DT);
  }

  /* Configuration-specific DMA setup.*/
  if ((spip->config->ctrl1 & SPI_CTRL1_FBN) == 0) {
    /* Frame width is 8 bits or smaller.*/
    spip->rxdmamode = (spip->rxdmamode & ~AT32_DMA_CTRL_SIZE_MASK) |
                      AT32_DMA_CTRL_PWIDTH_BYTE | AT32_DMA_CTRL_MWIDTH_BYTE;
    spip->txdmamode = (spip->txdmamode & ~AT32_DMA_CTRL_SIZE_MASK) |
                      AT32_DMA_CTRL_PWIDTH_BYTE | AT32_DMA_CTRL_MWIDTH_BYTE;
  }
  else {
    /* Frame width is larger than 8 bits.*/
    spip->rxdmamode = (spip->rxdmamode & ~AT32_DMA_CTRL_SIZE_MASK) |
                      AT32_DMA_CTRL_PWIDTH_HWORD | AT32_DMA_CTRL_MWIDTH_HWORD;
    spip->txdmamode = (spip->txdmamode & ~AT32_DMA_CTRL_SIZE_MASK) |
                      AT32_DMA_CTRL_PWIDTH_HWORD | AT32_DMA_CTRL_MWIDTH_HWORD;
  }

  if (spip->config->circular) {
    spip->rxdmamode |= (AT32_DMA_CTRL_LM | AT32_DMA_CTRL_HDTIEN);
    spip->txdmamode |= (AT32_DMA_CTRL_LM | AT32_DMA_CTRL_HDTIEN);
  }
  else {
    spip->rxdmamode &= ~(AT32_DMA_CTRL_LM | AT32_DMA_CTRL_HDTIEN);
    spip->txdmamode &= ~(AT32_DMA_CTRL_LM | AT32_DMA_CTRL_HDTIEN);
  }

  /* SPI setup and enable.*/
  spip->spi->CTRL1 &= ~SPI_CTRL1_SPIEN;
  spip->spi->CTRL1  = spip->config->ctrl1 | SPI_CTRL1_MSTEN | SPI_CTRL1_SWCSEN |
                      SPI_CTRL1_SWCSIL;
  spip->spi->CTRL2  = spip->config->ctrl2 | SPI_CTRL2_HWCSOE | SPI_CTRL2_DMAREN |
                      SPI_CTRL2_DMATEN;
  spip->spi->CTRL1 |= SPI_CTRL1_SPIEN;
}

/**
 * @brief   Deactivates the SPI peripheral.
 *
 * @param[in] spip      pointer to the @p SPIDriver object
 *
 * @notapi
 */
void spi_lld_stop(SPIDriver *spip) {

  /* If in ready state then disables the SPI clock.*/
  if (spip->state == SPI_READY) {

    /* SPI disable.*/
    spip->spi->CTRL1 &= ~SPI_CTRL1_SPIEN;
    spip->spi->CTRL1  = 0;
    spip->spi->CTRL2  = 0;
    dmaStreamFreeI(spip->dmarx);
    dmaStreamFreeI(spip->dmatx);
    spip->dmarx = NULL;
    spip->dmatx = NULL;

#if AT32_SPI_USE_SPI1
    if (&SPID1 == spip)
      crmDisableSPI1();
#endif
#if AT32_SPI_USE_SPI2
    if (&SPID2 == spip)
      crmDisableSPI2();
#endif
#if AT32_SPI_USE_SPI3
    if (&SPID3 == spip)
      crmDisableSPI3();
#endif
#if AT32_SPI_USE_SPI4
    if (&SPID4 == spip)
      crmDisableSPI4();
#endif
  }
}

#if (SPI_SELECT_MODE == SPI_SELECT_MODE_LLD) || defined(__DOXYGEN__)
/**
 * @brief   Asserts the slave select signal and prepares for transfers.
 *
 * @param[in] spip      pointer to the @p SPIDriver object
 *
 * @notapi
 */
void spi_lld_select(SPIDriver *spip) {

  /* No implementation on AT32.*/
}

/**
 * @brief   Deasserts the slave select signal.
 * @details The previously selected peripheral is unselected.
 *
 * @param[in] spip      pointer to the @p SPIDriver object
 *
 * @notapi
 */
void spi_lld_unselect(SPIDriver *spip) {

  /* No implementation on AT32.*/
}
#endif

/**
 * @brief   Ignores data on the SPI bus.
 * @details This asynchronous function starts the transmission of a series of
 *          idle words on the SPI bus and ignores the received data.
 * @post    At the end of the operation the configured callback is invoked.
 *
 * @param[in] spip      pointer to the @p SPIDriver object
 * @param[in] n         number of words to be ignored
 *
 * @notapi
 */
void spi_lld_ignore(SPIDriver *spip, size_t n) {

  osalDbgAssert(n <= AT32_DMA_MAX_TRANSFER, "unsupported DMA transfer size");

  dmaStreamSetMemory0(spip->dmarx, &dummyrx);
  dmaStreamSetTransactionSize(spip->dmarx, n);
  dmaStreamSetMode(spip->dmarx, spip->rxdmamode);

  dmaStreamSetMemory0(spip->dmatx, &dummytx);
  dmaStreamSetTransactionSize(spip->dmatx, n);
  dmaStreamSetMode(spip->dmatx, spip->txdmamode);

  dmaStreamEnable(spip->dmarx);
  dmaStreamEnable(spip->dmatx);
}

/**
 * @brief   Exchanges data on the SPI bus.
 * @details This asynchronous function starts a simultaneous transmit/receive
 *          operation.
 * @post    At the end of the operation the configured callback is invoked.
 * @note    The buffers are organized as uint8_t arrays for data sizes below or
 *          equal to 8 bits else it is organized as uint16_t arrays.
 *
 * @param[in] spip      pointer to the @p SPIDriver object
 * @param[in] n         number of words to be exchanged
 * @param[in] txbuf     the pointer to the transmit buffer
 * @param[out] rxbuf    the pointer to the receive buffer
 *
 * @notapi
 */
void spi_lld_exchange(SPIDriver *spip, size_t n,
                      const void *txbuf, void *rxbuf) {

  osalDbgAssert(n <= AT32_DMA_MAX_TRANSFER, "unsupported DMA transfer size");

  dmaStreamSetMemory0(spip->dmarx, rxbuf);
  dmaStreamSetTransactionSize(spip->dmarx, n);
  dmaStreamSetMode(spip->dmarx, spip->rxdmamode| AT32_DMA_CTRL_MINCM);

  dmaStreamSetMemory0(spip->dmatx, txbuf);
  dmaStreamSetTransactionSize(spip->dmatx, n);
  dmaStreamSetMode(spip->dmatx, spip->txdmamode | AT32_DMA_CTRL_MINCM);

  dmaStreamEnable(spip->dmarx);
  dmaStreamEnable(spip->dmatx);
}

/**
 * @brief   Sends data over the SPI bus.
 * @details This asynchronous function starts a transmit operation.
 * @post    At the end of the operation the configured callback is invoked.
 * @note    The buffers are organized as uint8_t arrays for data sizes below or
 *          equal to 8 bits else it is organized as uint16_t arrays.
 *
 * @param[in] spip      pointer to the @p SPIDriver object
 * @param[in] n         number of words to send
 * @param[in] txbuf     the pointer to the transmit buffer
 *
 * @notapi
 */
void spi_lld_send(SPIDriver *spip, size_t n, const void *txbuf) {

  osalDbgAssert(n <= AT32_DMA_MAX_TRANSFER, "unsupported DMA transfer size");

  dmaStreamSetMemory0(spip->dmarx, &dummyrx);
  dmaStreamSetTransactionSize(spip->dmarx, n);
  dmaStreamSetMode(spip->dmarx, spip->rxdmamode);

  dmaStreamSetMemory0(spip->dmatx, txbuf);
  dmaStreamSetTransactionSize(spip->dmatx, n);
  dmaStreamSetMode(spip->dmatx, spip->txdmamode | AT32_DMA_CTRL_MINCM);

  dmaStreamEnable(spip->dmarx);
  dmaStreamEnable(spip->dmatx);
}

/**
 * @brief   Receives data from the SPI bus.
 * @details This asynchronous function starts a receive operation.
 * @post    At the end of the operation the configured callback is invoked.
 * @note    The buffers are organized as uint8_t arrays for data sizes below or
 *          equal to 8 bits else it is organized as uint16_t arrays.
 *
 * @param[in] spip      pointer to the @p SPIDriver object
 * @param[in] n         number of words to receive
 * @param[out] rxbuf    the pointer to the receive buffer
 *
 * @notapi
 */
void spi_lld_receive(SPIDriver *spip, size_t n, void *rxbuf) {

  osalDbgAssert(n <= AT32_DMA_MAX_TRANSFER, "unsupported DMA transfer size");

  dmaStreamSetMemory0(spip->dmarx, rxbuf);
  dmaStreamSetTransactionSize(spip->dmarx, n);
  dmaStreamSetMode(spip->dmarx, spip->rxdmamode | AT32_DMA_CTRL_MINCM);

  dmaStreamSetMemory0(spip->dmatx, &dummytx);
  dmaStreamSetTransactionSize(spip->dmatx, n);
  dmaStreamSetMode(spip->dmatx, spip->txdmamode);

  dmaStreamEnable(spip->dmarx);
  dmaStreamEnable(spip->dmatx);
}

#if (SPI_SUPPORTS_CIRCULAR == TRUE) || defined(__DOXYGEN__)
/**
 * @brief   Aborts the ongoing SPI operation, if any.
 *
 * @param[in] spip      pointer to the @p SPIDriver object
 *
 * @notapi
 */
void spi_lld_abort(SPIDriver *spip) {

  /* Stopping DMAs.*/
  dmaStreamDisable(spip->dmatx);
  dmaStreamDisable(spip->dmarx);
}
#endif /* SPI_SUPPORTS_CIRCULAR == TRUE */

/**
 * @brief   Exchanges one frame using a polled wait.
 * @details This synchronous function exchanges one frame using a polled
 *          synchronization method. This function is useful when exchanging
 *          small amount of data on high speed channels, usually in this
 *          situation is much more efficient just wait for completion using
 *          polling than suspending the thread waiting for an interrupt.
 *
 * @param[in] spip      pointer to the @p SPIDriver object
 * @param[in] frame     the data frame to send over the SPI bus
 * @return              The received data frame from the SPI bus.
 */
uint16_t spi_lld_polled_exchange(SPIDriver *spip, uint16_t frame) {

  spip->spi->DT = frame;
  while ((spip->spi->STS & SPI_STS_RDBF) == 0)
    ;
  return spip->spi->DT;
}

#endif /* HAL_USE_SPI */

/** @} */
