/*******************************************************************************
 *  FILE DESCRIPTION
 *  ----------------------------------------------------------------------------
 *         FILE:   SysTick.h  
 *       MODULE:   SysTick
 * 
 *  DESCRIPTION:  
 * 
 ******************************************************************************/
#ifndef SYSTICK_H
#define SYSTICK_H

/*******************************************************************************
 *  INCLUDES
 ******************************************************************************/
#include "SysTick_Types.h"

/*******************************************************************************
 *  GLOBAL CONSTANT MACROS
 ******************************************************************************/


/*******************************************************************************
 *  GLOBAL FUNCTION MACROS
 ******************************************************************************/


/*******************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 ******************************************************************************/


/*******************************************************************************
 *  GLOBAL DATA PROTOTYPES
 ******************************************************************************/


/*******************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 ******************************************************************************/


/*******************************************************************************
 * \syntax          : void SysTick_Init(SysTick_ConfigType *SysTick_Config)
 * \Description     : Initializes the SysTick timer module
 * \Sync\Async      : Sync
 * \Reentrancy      : Non-Reentrant
 * \parameters (in) : SysTick_ConfigType *SysTick_Config
 * \parameters (out): None
 * \Return value    : None
 ******************************************************************************/
void SysTick_Init(const SysTick_ConfigType *SysTick_Config);

/*******************************************************************************
 * \syntax          : void SysTick_Reload(SysTick_ValueType Value)
 * \Description     : Reloads the SysTick timer counter
 * \Sync\Async      : Sync
 * \Reentrancy      : Reentrant
 * \parameters (in) : SysTick_ValueType Value
 * \parameters (out): None
 * \Return value    : None
 ******************************************************************************/
void SysTick_Reload(SysTick_ValueType Value);

/*******************************************************************************
 * \syntax          : SysTick_ValueType SysTick_GetValue(void)
 * \Description     : Reads the current count of the SysTick timer
 * \Sync\Async      : Sync
 * \Reentrancy      : Reentrant
 * \parameters (in) : None
 * \parameters (out): SysTick_ValueType Value
 * \Return value    : 0 - 0xFFFFFF
 ******************************************************************************/
SysTick_ValueType SysTick_GetValue(void);

/*******************************************************************************
 * \syntax          : SysTick_FlagType SysTick_CheckFlag(void)
 * \Description     : Checks the current status of the count flag
 * \Sync\Async      : Sync
 * \Reentrancy      : Reentrant
 * \parameters (in) : None
 * \parameters (out): SysTick_FlagType Flag
 * \Return value    : 0-1
 ******************************************************************************/
SysTick_FlagType SysTick_CheckFlag(void);

/*******************************************************************************
 * \syntax          : void SysTick_Handler(void)
 * \Description     : Handler for the SysTick ISR
 * \Sync\Async      : Sync
 * \Reentrancy      : Non-Reentrant
 * \parameters (in) : None
 * \parameters (out): None
 * \Return value    : None
 ******************************************************************************/
void SysTick_Handler(void);

/*******************************************************************************
 * \syntax          : void SysTick_SetCallback(SysTick_IntHandlerType(*CallBck)())
 * \Description     : Sets the callback function to the SysTick ISR
 * \Sync\Async      : Sync
 * \Reentrancy      : Non-Reentrant
 * \parameters (in) : SysTick_IntHandlerType (*CallBck)
 * \parameters (out): None
 * \Return value    : None
 ******************************************************************************/
void SysTick_SetCallback(SysTick_IntHandlerType (*CallBck)());

/*******************************************************************************
 * \syntax          : void SysTick_EnNotification(void)
 * \Description     : Enables the SysTick interrupt
 * \Sync\Async      : Sync
 * \Reentrancy      : Non-Reentrant
 * \parameters (in) : None
 * \parameters (out): None
 * \Return value    : None
 ******************************************************************************/
void SysTick_EnNotification(void);

/*******************************************************************************
 * \syntax          : void SysTick_DisNotification(void)
 * \Description     : Disables the SysTick interrupt
 * \Sync\Async      : Sync
 * \Reentrancy      : Non-Reentrant
 * \parameters (in) : None
 * \parameters (out): None
 * \Return value    : None
 ******************************************************************************/
void SysTick_DisNotification(void);

/*******************************************************************************
 * \syntax          : void SysTick_StartTimer(void)
 * \Description     : Starts the SysTick Timer
 * \Sync\Async      : Sync
 * \Reentrancy      : Reentrant
 * \parameters (in) : None
 * \parameters (out): None
 * \Return value    : None
 ******************************************************************************/
void SysTick_StartTimer(void);

/*******************************************************************************
 * \syntax          : void SysTick_StopTimer(void)
 * \Description     : Stops the SysTick Timer
 * \Sync\Async      : Sync
 * \Reentrancy      : Reentrant
 * \parameters (in) : None
 * \parameters (out): None
 * \Return value    : None
 ******************************************************************************/
void SysTick_StopTimer(void);

#endif  /* SYSTICK_H */

/*******************************************************************************
 *  END OF FILE:    SysTick.h  
 ******************************************************************************/
