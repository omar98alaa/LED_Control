/******************************************************************************
 *  FILE DESCRIPTION
 *  ---------------------------------------------------------------------------
 *         FILE:   Port.h  
 *       MODULE:   Port
 * 
 *  DESCRIPTION:  
 * 
 *****************************************************************************/
#ifndef PORT_H
#define PORT_H

/******************************************************************************
 *  INCLUDES
 *****************************************************************************/
#include "Port_Types.h"

/******************************************************************************
 *  GLOBAL CONSTANT MACROS
 *****************************************************************************/


/******************************************************************************
 *  GLOBAL FUNCTION MACROS
 *****************************************************************************/


/******************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *****************************************************************************/


/******************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *****************************************************************************/


/******************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *****************************************************************************/


/******************************************************************************
 * \syntax          : void Port_Init(void)
 * \Description     : Configures GPIO pins functionalities
 * \Sync\Async      : Synchronos
 * \Reentrancy      : Non-Reentrant
 * \parameters (in) : None
 * \parameters (out): None
 * \Return value    : None
 *****************************************************************************/
void Port_Init(void);

/******************************************************************************
 * \syntax          : void GPIOA_Handler(void)
 * \Description     : Port A interrupt handler
 * \Sync\Async      : Sync
 * \Reentrancy      : Non-Reentrant
 * \parameters (in) : None
 * \parameters (out): None
 * \Return value    : None
 *****************************************************************************/
void GPIOA_Handler(void);

/******************************************************************************
 * \syntax          : void GPIOB_Handler(void)
 * \Description     : Port B interrupt handler
 * \Sync\Async      : Sync
 * \Reentrancy      : Non-Reentrant
 * \parameters (in) : None
 * \parameters (out): None
 * \Return value    : None
 *****************************************************************************/
void GPIOB_Handler(void);

/******************************************************************************
 * \syntax          : void GPIOC_Handler(void)
 * \Description     : Port C interrupt handler
 * \Sync\Async      : Sync
 * \Reentrancy      : Non-Reentrant
 * \parameters (in) : None
 * \parameters (out): None
 * \Return value    : None
 *****************************************************************************/
void GPIOC_Handler(void);

/******************************************************************************
 * \syntax          : void GPIOD_Handler(void)
 * \Description     : Port D interrupt handler
 * \Sync\Async      : Sync
 * \Reentrancy      : Non-Reentrant
 * \parameters (in) : None
 * \parameters (out): None
 * \Return value    : None
 *****************************************************************************/
void GPIOD_Handler(void);

/******************************************************************************
 * \syntax          : void GPIOE_Handler(void)
 * \Description     : Port E interrupt handler
 * \Sync\Async      : Sync
 * \Reentrancy      : Non-Reentrant
 * \parameters (in) : None
 * \parameters (out): None
 * \Return value    : None
 *****************************************************************************/
void GPIOE_Handler(void);

/******************************************************************************
 * \syntax          : void GPIOF_Handler(void)
 * \Description     : Port F interrupt handler
 * \Sync\Async      : Sync
 * \Reentrancy      : Non-Reentrant
 * \parameters (in) : None
 * \parameters (out): None
 * \Return value    : None
 *****************************************************************************/
void GPIOF_Handler(void);

/******************************************************************************
 * \syntax          : void Port_SetCallBack(Port_PinType Pin, 
 *                                          Port_IntHandlerType (*CallBack)())
 * \Description     : Sets the corresponding callback function
 * \Sync\Async      : Sync
 * \Reentrancy      : Non-Reentrant
 * \parameters (in) : Port_PinType Pin
 *                    Port_IntHandlerType (*CallBack)
 * \parameters (out): None
 * \Return value    : None
 *****************************************************************************/
void Port_SetCallBack(Port_PinType Pin, Port_IntHandlerType (*CallBack)());

#endif  /* PORT_H */

/******************************************************************************
 *  END OF FILE:    Port.h  
 *****************************************************************************/
