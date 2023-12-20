#ifndef __SN32F2XX_CT32B2_H
#define __SN32F2XX_CT32B2_H

/*_____ I N C L U D E S ____________________________________________________*/
#include <stdint.h>
#include <SN32F200_Def.h>

/*_____ D E F I N I T I O N S ______________________________________________*/
#define	CT32B2_IRQ INTERRUPT_METHOD         //INTERRUPT_METHOD: Enable CT32B2 timer and interrupt.
                                            //POLLING_METHOD: Enable CT32B2 timer only.

/*_____ D E C L A R A T I O N S ____________________________________________*/
extern volatile uint32_t iwCT32B2_IrqEvent; //The bitmask usage of iwCT32Bn_IrqEvent is the same with CT32Bn_RIS.

extern void CT32B2_Init(void);
extern void CT32B2_ResetTimer(void);
extern void CT32B2_NvicEnable(void);
extern void CT32B2_NvicDisable(void);
extern void CT32B2_IRQHandler(void);
#endif /*__SN32F2XX_CT32B2_H*/
