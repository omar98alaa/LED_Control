/******************************************************************************
 *  FILE DESCRIPTION
 *  ---------------------------------------------------------------------------
 *         FILE:   Dio.h  
 *       MODULE:   DIO driver
 * 
 *  DESCRIPTION:  
 * 
 *****************************************************************************/
#ifndef DIO_H
#define DIO_H

/******************************************************************************
 *  INCLUDES
 *****************************************************************************/
#include "../../LIBRARIES/Mcu_Hw.h"
#include "Dio_Types.h"

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
 * \syntax          : Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelID)
 * \Description     : Reads the status of the desired pin.
 * \Sync\Async      : Sync
 * \Reentrancy      : Reentrant
 * \parameters (in) : Dio_ChannelType ChannelID
 * \parameters (out): Dio_LevelType Value
 * \Return value    : 0-1
 *****************************************************************************/
Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelID);

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
void Dio_WriteChannel(Dio_ChannelType ChannelID, Dio_LevelType Level);

/******************************************************************************
 * \syntax          : Dio_PortLevelType Dio_ReadPort(Dio_PortType PortID)
 * \Description     : Reads the status of the desired port
 * \Sync\Async      : Sync
 * \Reentrancy      : Reentrant
 * \parameters (in) : Dio_PortType PortID
 * \parameters (out): Dio_PortLevelType Value
 * \Return value    : 0-255
 *****************************************************************************/
Dio_PortLevelType Dio_ReadPort(Dio_PortType PortID);

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
void Dio_WritePort(Dio_PortType PortID, Dio_PortLevelType Level);

/******************************************************************************
 * \syntax          : void Dio_FlipChannel(Dio_ChannelType ChannelID)
 * \Description     : Toggles the desired pin
 * \Sync\Async      : Sync
 * \Reentrancy      : Reentrant
 * \parameters (in) : Dio_ChannelType ChannelID
 * \parameters (out): None
 * \Return value    : None
 *****************************************************************************/
void Dio_FlipChannel(Dio_ChannelType ChannelID);

#endif  /* DIO_H */

/******************************************************************************
 *  END OF FILE:    Dio.h  
 *****************************************************************************/
