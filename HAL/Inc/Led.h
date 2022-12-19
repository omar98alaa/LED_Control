/*******************************************************************************
 *  FILE DESCRIPTION
 *  ----------------------------------------------------------------------------
 *         FILE:   Led.h  
 *       MODULE:   LED
 * 
 *  DESCRIPTION:  
 * 
 ******************************************************************************/
#ifndef LED_H
#define LED_H

/*******************************************************************************
 *  INCLUDES
 ******************************************************************************/
#include "../../MCAL/Inc/Dio_Types.h"

/*******************************************************************************
 *  GLOBAL CONSTANT MACROS
 ******************************************************************************/
#define RED_LED                     PF1
#define BLUE_LED                    PF2
#define GREEN_LED                   PF3

/*******************************************************************************
 *  GLOBAL FUNCTION MACROS
 ******************************************************************************/


/*******************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 ******************************************************************************/
typedef Dio_ChannelType Led_InstanceType;

/*******************************************************************************
 *  GLOBAL DATA PROTOTYPES
 ******************************************************************************/


/*******************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 ******************************************************************************/


/*******************************************************************************
 * \syntax          : void Led_On(Led_InstanceType Led_Channel)
 * \Description     : Turns on the desired LED
 * \Sync\Async      : Sync
 * \Reentrancy      : Reentrant
 * \parameters (in) : Led_InstanceType Led_Channel
 * \parameters (out): None
 * \Return value    : None
 ******************************************************************************/
void Led_On(Led_InstanceType Led_Channel);

/*******************************************************************************
 * \syntax          : void Led_Off(Led_InstanceType Led_Channel)
 * \Description     : Turns off the desired LED
 * \Sync\Async      : Sync
 * \Reentrancy      : Reentrant
 * \parameters (in) : Led_InstanceType Led_Channel
 * \parameters (out): None
 * \Return value    : None
 ******************************************************************************/
void Led_Off(Led_InstanceType Led_Channel);

/*******************************************************************************
 * \syntax          : void Led_Toggle(Led_InstanceType Led_Channel)
 * \Description     : Toggles the desired LED
 * \Sync\Async      : Sync
 * \Reentrancy      : Reentrant
 * \parameters (in) : Led_InstanceType Led_Channel
 * \parameters (out): None
 * \Return value    : None
 ******************************************************************************/
void Led_Toggle(Led_InstanceType Led_Channel);

#endif  /* LED_H */

/*******************************************************************************
 *  END OF FILE:    Led.h  
 ******************************************************************************/
