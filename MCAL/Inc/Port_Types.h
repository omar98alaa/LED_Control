/******************************************************************************
 *  FILE DESCRIPTION
 *  ---------------------------------------------------------------------------
 *         FILE:   Port_Types.h  
 *       MODULE:   Port
 * 
 *  DESCRIPTION:  
 * 
 *****************************************************************************/
#ifndef PORT_TYPES_H
#define PORT_TYPES_H

/******************************************************************************
 *  INCLUDES
 *****************************************************************************/
#include "../../LIBRARIES/Mcu_Hw.h"

/******************************************************************************
 *  GLOBAL CONSTANT MACROS
 *****************************************************************************/


/******************************************************************************
 *  GLOBAL FUNCTION MACROS
 *****************************************************************************/


/******************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *****************************************************************************/
typedef enum {
    /* PORT A*/
    PinA0,
    PinA1,
    PinA2,
    PinA3,
    PinA4,
    PinA5,
    PinA6,
    PinA7,
    /* PORT B*/
    PinB0,
    PinB1,
    PinB2,
    PinB3,
    PinB4,
    PinB5,
    PinB6,
    PinB7,
    /* PORT C*/
    PinC0,
    PinC1,
    PinC2,
    PinC3,
    PinC4,
    PinC5,
    PinC6,
    PinC7,
    /* PORT D*/
    PinD0,
    PinD1,
    PinD2,
    PinD3,
    PinD4,
    PinD5,
    PinD6,
    PinD7,
    /* PORT E*/
    PinE0,
    PinE1,
    PinE2,
    PinE3,
    PinE4,
    PinE5,
    PinE6,
    PinE7,
    /* PORT F*/
    PinF0,
    PinF1,
    PinF2,
    PinF3,
    PinF4,
    PinF5,
    PinF6,
    PinF7
} Port_PinType;

typedef enum {
    INPUT,
    OUTPUT
} Port_PinDirectionType;

typedef enum {
    DIO,
    EXT_INT,
    ADC_TRIG,
    DMA_TRIG,
    ANALOG_IN,
    ALT_FUNC
} Port_PinModeType;

typedef enum {
    NO_ATTACHMENT,
    PULL_UP,
    PULL_DOWN,
    OPEN_DRAIN
} Port_PinInternalAttachType;

typedef enum {
    NO_OUT_CURRENT,
    _2MA,
    _4MA,
    _8MA,
    _8MA_W_SLR
} Port_PinOutputCurrentType;

typedef enum {
    NO_LEVEL,
    LOW_LEVEL,
    HIGH_LEVEL,
    FALLING = 1,
    RISING
} Port_PinEdgeType;

typedef enum {
    NO_TRIGGER,
    LEVEL,
    SINGLE_EDGE,
    BOTH_EDGES
} Port_PinInterruptTriggerType;

typedef void Port_IntHandlerType;

typedef struct {
    Port_PinType PinType;
    Port_PinModeType PinMode;
    Port_PinDirectionType PinDirection;
    Port_PinInternalAttachType PinInternalAttach;
    Port_PinOutputCurrentType PinOutputCurrent;
    Port_PinInterruptTriggerType PinInterruptTrigger;
    Port_PinEdgeType PinEdge;
} Port_ConfigType;

/******************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *****************************************************************************/


/******************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *****************************************************************************/


/******************************************************************************
 * \syntaC          : -
 * \Description     : -
 * \Sync\Async      : -
 * \Reentrancy      : -
 * \parameters (in) : -
 * \parameters (out): -
 * \Return value    : -
 *****************************************************************************/


#endif  /* PORT_TYPES_H */

/******************************************************************************
 *  END OF FILE:    Port_Types.h  
 *****************************************************************************/
