/*******************************************************************************
 *  FILE DESCRIPTION
 *  ----------------------------------------------------------------------------
 *         FILE:   SysTick_Types.h  
 *       MODULE:   SysTick
 * 
 *  DESCRIPTION:  
 * 
 ******************************************************************************/
#ifndef SYSTICK_TYPES_H
#define SYSTICK_TYPES_H

/*******************************************************************************
 *  INCLUDES
 ******************************************************************************/
#include "../../LIBRARIES/Mcu_Hw.h"

/*******************************************************************************
 *  GLOBAL CONSTANT MACROS
 ******************************************************************************/


/*******************************************************************************
 *  GLOBAL FUNCTION MACROS
 ******************************************************************************/


/*******************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 ******************************************************************************/
typedef uint8 SysTick_FlagType;

typedef void SysTick_IntHandlerType;

typedef uint32 SysTick_ValueType;

typedef enum {
    STCTRL_EN,
    STCTRL_INTEN,
    STCTRL_CLKSRC,
    STCTRL_COUNT = 16
} SysTick_StCtrlFields;

typedef enum {
    SYSTICK_PIOSC,
    SYSTICK_SYSCLK
} SysTick_ClkSrcType;

typedef enum {
    SYSTICK_DIS_NOTIFICATION,
    SYSTICK_EN_NOTIFICATION
} SysTick_NotificationType;

typedef struct {
    SysTick_ClkSrcType ClkSrc; 
    SysTick_ValueType Value;
    SysTick_IntHandlerType (*CallBck)();
    SysTick_NotificationType Notification;
} SysTick_ConfigType;

/*******************************************************************************
 *  GLOBAL DATA PROTOTYPES
 ******************************************************************************/


/*******************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 ******************************************************************************/


/*******************************************************************************
 * \syntax          : -
 * \Description     : -
 * \Sync\Async      : -
 * \Reentrancy      : -
 * \parameters (in) : -
 * \parameters (out): -
 * \Return value    : -
 ******************************************************************************/


#endif  /* SYSTICK_TYPES_H */

/*******************************************************************************
 *  END OF FILE:    SysTick_Types.h  
 ******************************************************************************/
