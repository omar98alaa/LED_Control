/******************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------*/
/**         \file   Dio.c
 *         \brief   Driver for DIO module
 *         
 *       \details   -
 *****************************************************************************/

/******************************************************************************
 *  INCLUDES
 *****************************************************************************/
#include "Inc/Dio.h"

/******************************************************************************
 *  LOCAL MACROS CONSTANT\FUNCTION
 *****************************************************************************/


/******************************************************************************
 *  LOCAL DATA
 *****************************************************************************/
const static uint32 Ports[] = {GPIO_A, GPIO_B, GPIO_C, GPIO_D, GPIO_E, GPIO_F};

/******************************************************************************
 *  GLOBAL DATA
 *****************************************************************************/


/******************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *****************************************************************************/


/******************************************************************************
 *  LOCAL FUNCTIONS
 *****************************************************************************/


/******************************************************************************
 *  GLOBAL FUNCTIONS
 *****************************************************************************/


/******************************************************************************
 * \syntax          : Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelID)
 * \Description     : Reads the status of the desired pin.
 * \Sync\Async      : Sync
 * \Reentrancy      : Reentrant
 * \parameters (in) : Dio_ChannelType ChannelID
 * \parameters (out): Dio_LevelType Value
 * \Return value    : 0-1
 *****************************************************************************/
Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelID){
    Dio_LevelType Value;
    uint32 Port = Ports[(ChannelID / 8)];
    uint8 Pin   = (ChannelID % 8);
    
    /* Value = GET_BIT(REG(Port, (1 << (Pin + 2))), Pin); */
    Value = GET_BIT(REG(Port, GPIODATA), Pin);
    
    return (Value && 1);
}

/******************************************************************************
 * \syntax          : void Dio_WriteChannel(Dio_ChannelType ChannelID, 
 *                                          Dio_LevelType Level)
 * \Description     : Writes to the desired pin.
 * \Sync\Async      : sync
 * \Reentrancy      : Reentrant
 * \parameters (in) : Dio_ChannelType ChannelID
 *                    Dio_LevelType Level
 * \parameters (out): None
 * \Return value    : None
 *****************************************************************************/
void Dio_WriteChannel(Dio_ChannelType ChannelID, Dio_LevelType Level){
    uint32 Port = Ports[(ChannelID / 8)];
    uint8 Pin   = (ChannelID % 8);
    
    switch(Level){
        case LOW:
            /* REG(Port, (1 << (Pin + 2))) =  0; */
            RESET_BIT(REG(Port, GPIODATA), Pin);
        break;

        default:
            /* REG(Port, (1 << (Pin + 2))) = 0xFFu; */
            SET_BIT(REG(Port, GPIODATA), Pin);
        break;
    }
    
}

/******************************************************************************
 * \syntax          : Dio_PortLevelType Dio_ReadPort(Dio_PortType PortID)
 * \Description     : Reads the status of the desired port
 * \Sync\Async      : Sync
 * \Reentrancy      : Reentrant
 * \parameters (in) : Dio_PortType PortID
 * \parameters (out): Dio_PortLevelType Value
 * \Return value    : 0-255
 *****************************************************************************/
Dio_PortLevelType Dio_ReadPort(Dio_PortType PortID){
    Dio_PortLevelType Value;

    Value = REG(PortID, GPIODATA);

    return Value;
}

/******************************************************************************
 * \syntax          : void Dio_WritePort(Dio_PortType PortID, 
 *                                       Dio_PortLevelType Level)
 * \Description     : Writes to the desired port
 * \Sync\Async      : Sync
 * \Reentrancy      : Reentrant
 * \parameters (in) : Dio_PortType PortID
 *                    Dio_PortLevelType Level
 * \parameters (out): None
 * \Return value    : None
 *****************************************************************************/
void Dio_WritePort(Dio_PortType PortID, Dio_PortLevelType Level){
    REG(PortID, GPIODATA) = Level;
}

/******************************************************************************
 * \syntax          : void Dio_FlipChannel(Dio_ChannelType ChannelID)
 * \Description     : Toggles the desired pin
 * \Sync\Async      : Sync
 * \Reentrancy      : Reentrant
 * \parameters (in) : Dio_ChannelType ChannelID
 * \parameters (out): None
 * \Return value    : None
 *****************************************************************************/
void Dio_FlipChannel(Dio_ChannelType ChannelID){
    uint32 Port = Ports[(ChannelID / 8)];
    uint8 Pin   = (ChannelID % 8);

    /* TOGGLE_BIT(REG(Port, (1 << (Pin + 2))), Pin); */
    TOGGLE_BIT(REG(Port, GPIODATA), Pin);
}

/******************************************************************************
 *  END OF FILE:    Dio.c
 *****************************************************************************/
