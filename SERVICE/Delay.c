/*******************************************************************************
 *  FILE DESCRIPTION
 *  --------------------------------------------------------------------------*/
/**         \file   Delay.c
 *         \brief   Driver for delay service module
 *         
 *       \details   -
 ******************************************************************************/

/*******************************************************************************
 *  INCLUDES
 ******************************************************************************/
#include "../MCAL/Inc/SysTick.h"
#include "Delay.h"

/*******************************************************************************
 *  LOCAL MACROS CONSTANT\FUNCTION
 ******************************************************************************/


/*******************************************************************************
 *  LOCAL DATA
 ******************************************************************************/


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
 * \syntax          : void Delay_Timer_Init(Delay_IntHandlerType (*CallBack)())
 * \Description     : Initializes the Timer used for providing delay
 * \Sync\Async      : Sync
 * \Reentrancy      : Non-Reentrant
 * \parameters (in) : Delay_IntHandlerType (*CallBack)
 * \parameters (out): None
 * \Return value    : None
 ******************************************************************************/
void Delay_Timer_Init(Delay_IntHandlerType (*CallBack)()){
    SysTick_ConfigType Config = 
    {
        SYSTICK_SYSCLK,
        0,
        CallBack,
        SYSTICK_EN_NOTIFICATION
    };
    SysTick_Init(&Config);
}

/*******************************************************************************
 * \syntax          : void Delay_Ms(uint32 Delay)
 * \Description     : Starts a delay for the given periode
 * \Sync\Async      : Sync
 * \Reentrancy      : Non-Reentrant
 * \parameters (in) : uint32 Delay
 * \parameters (out): None
 * \Return value    : None
 ******************************************************************************/
void Delay_Ms(uint32 Delay){
    SysTick_Reload(Delay*1000*16);
    SysTick_StartTimer();
}

/*******************************************************************************
 *  END OF FILE:    Delay.c
 ******************************************************************************/