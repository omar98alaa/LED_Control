/*******************************************************************************
 *  FILE DESCRIPTION
 *  --------------------------------------------------------------------------*/
/**         \file   SysTick.c
 *         \brief   Driver for System Tick Timer module
 *         
 *       \details   -
 ******************************************************************************/

/*******************************************************************************
 *  INCLUDES
 ******************************************************************************/
#include "../LIBRARIES/Mcu_Hw.h"
#include "Inc/SysTick.h"

/*******************************************************************************
 *  LOCAL MACROS CONSTANT\FUNCTION
 ******************************************************************************/


/*******************************************************************************
 *  LOCAL DATA
 ******************************************************************************/
static SysTick_IntHandlerType (*Int_Handler)() = NULL;


/*******************************************************************************
 *  GLOBAL DATA
 ******************************************************************************/


/*******************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 ******************************************************************************/


/*******************************************************************************
 *  LOCAL FUNCTIONS
 ******************************************************************************/


/*******************************************************************************
 *  GLOBAL FUNCTIONS
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
void SysTick_Init(const SysTick_ConfigType *SysTick_Config){
    SysTick_StopTimer();

    switch(SysTick_Config->ClkSrc){
        case SYSTICK_PIOSC:
            RESET_BIT(REG(MCU_PERI_BASE, STCTRL), STCTRL_CLKSRC);
        break;
        
        default:
            SET_BIT(REG(MCU_PERI_BASE, STCTRL), STCTRL_CLKSRC);
        break;
    }

    SysTick_Reload(SysTick_Config->Value);

    if(SysTick_Config->CallBck){
        SysTick_SetCallback(SysTick_Config->CallBck);
    }

    if(SysTick_Config->Notification){
        SysTick_EnNotification();
    }
}

/*******************************************************************************
 * \syntax          : void SysTick_Reload(SysTick_ValueType Value)
 * \Description     : Reloads the SysTick timer counter
 * \Sync\Async      : Sync
 * \Reentrancy      : Reentrant
 * \parameters (in) : SysTick_ValueType Value
 * \parameters (out): None
 * \Return value    : None
 ******************************************************************************/
void SysTick_Reload(SysTick_ValueType Value){
    REG(MCU_PERI_BASE, STRELOAD)  = (Value & 0x00FFFFFFu);
    REG(MCU_PERI_BASE, STCURRENT) = 1;
}

/*******************************************************************************
 * \syntax          : SysTick_ValueType SysTick_GetValue(void)
 * \Description     : Reads the current count of the SysTick timer
 * \Sync\Async      : Sync
 * \Reentrancy      : Reentrant
 * \parameters (in) : None
 * \parameters (out): SysTick_ValueType Value
 * \Return value    : 0 - 0xFFFFFF
 ******************************************************************************/
SysTick_ValueType SysTick_GetValue(void){
    SysTick_ValueType Value;
    
    Value = REG(MCU_PERI_BASE, STCURRENT);

    return Value;
}

/*******************************************************************************
 * \syntax          : SysTick_FlagType SysTick_CheckFlag(void)
 * \Description     : Checks the current status of the count flag
 * \Sync\Async      : Sync
 * \Reentrancy      : Reentrant
 * \parameters (in) : None
 * \parameters (out): SysTick_FlagType Flag
 * \Return value    : 0-1
 ******************************************************************************/
SysTick_FlagType SysTick_CheckFlag(void){
    SysTick_FlagType Flag;

    Flag = GET_BIT(REG(MCU_PERI_BASE, STCTRL), STCTRL_COUNT);

    return (Flag && 1);
}

/*******************************************************************************
 * \syntax          : void SysTick_Handler(void)
 * \Description     : Handler for the SysTick ISR
 * \Sync\Async      : Sync
 * \Reentrancy      : Non-Reentrant
 * \parameters (in) : None
 * \parameters (out): None
 * \Return value    : None
 ******************************************************************************/
void SysTick_Handler(void){
    (*Int_Handler)();
}

/*******************************************************************************
 * \syntax          : void SysTick_SetCallback(SysTick_IntHandlerType(*CallBck))
 * \Description     : Sets the callback function to the SysTick ISR
 * \Sync\Async      : Sync
 * \Reentrancy      : Non-Reentrant
 * \parameters (in) : SysTick_IntHandlerType (*CallBck)
 * \parameters (out): None
 * \Return value    : None
 ******************************************************************************/
void SysTick_SetCallback(SysTick_IntHandlerType (*CallBck)()){
    Int_Handler = CallBck;
}

/*******************************************************************************
 * \syntax          : void SysTick_EnNotification(void)
 * \Description     : Enables the SysTick interrupt
 * \Sync\Async      : Sync
 * \Reentrancy      : Non-Reentrant
 * \parameters (in) : None
 * \parameters (out): None
 * \Return value    : None
 ******************************************************************************/
void SysTick_EnNotification(void){
    SET_BIT(REG(MCU_PERI_BASE, STCTRL), STCTRL_INTEN);
}

/*******************************************************************************
 * \syntax          : void SysTick_DisNotification(void)
 * \Description     : Disables the SysTick interrupt
 * \Sync\Async      : Sync
 * \Reentrancy      : Non-Reentrant
 * \parameters (in) : None
 * \parameters (out): None
 * \Return value    : None
 ******************************************************************************/
void SysTick_DisNotification(void){
    RESET_BIT(REG(MCU_PERI_BASE, STCTRL), STCTRL_INTEN);
}

/*******************************************************************************
 * \syntax          : void SysTick_StartTimer(void)
 * \Description     : Starts the SysTick Timer
 * \Sync\Async      : Sync
 * \Reentrancy      : Reentrant
 * \parameters (in) : None
 * \parameters (out): None
 * \Return value    : None
 ******************************************************************************/
void SysTick_StartTimer(void){
    SET_BIT(REG(MCU_PERI_BASE, STCTRL), STCTRL_EN);
}

/*******************************************************************************
 * \syntax          : void SysTick_StopTimer(void)
 * \Description     : Stops the SysTick Timer
 * \Sync\Async      : Sync
 * \Reentrancy      : Reentrant
 * \parameters (in) : None
 * \parameters (out): None
 * \Return value    : None
 ******************************************************************************/
void SysTick_StopTimer(void){
    RESET_BIT(REG(MCU_PERI_BASE, STCTRL), STCTRL_EN);
}

/*******************************************************************************
 *  END OF FILE:    SysTick.c
 ******************************************************************************/
