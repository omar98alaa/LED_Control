/******************************************************************************
 *  FILE DESCRIPTION
 *  ---------------------------------------------------------------------------
 *         FILE:   Std_Types.h  
 *       MODULE:   -
 * 
 *  DESCRIPTION:  
 * 
 *****************************************************************************/
#ifndef STD_TYPES_H
#define STD_TYPES_H

/******************************************************************************
 *  INCLUDES
 *****************************************************************************/
#include <stdint.h>

/******************************************************************************
 *  GLOBAL CONSTANT MACROS
 *****************************************************************************/
#define NULL                            ((void *)0)

#define FALSE                           0u
#define TRUE                            1u

#define LOW                             0u
#define HIGH                            1u

#define SET_BIT(Reg, Pin)               (Reg |=  (1 << Pin))
#define RESET_BIT(Reg, Pin)             (Reg &= ~(1 << Pin))
#define GET_BIT(Reg, Pin)               (Reg &   (1 << Pin))
#define TOGGLE_BIT(Reg, Pin)            (Reg ^=  (1 << Pin))

#define SET_VAL(Reg, Pin, Value)        (Reg |=  (Value << Pin))
#define RESET_VAL(Reg, Pin, Value)      (Reg &= ~(Value << Pin))
#define GET_VAL(Reg, Pin, Value)        (Reg &   (Value << Pin))
#define TOGGLE_VAL(Reg, Pin)            (Reg ^=  (Value << Pin))

/******************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *****************************************************************************/
typedef signed char                     int8;
typedef short                           int16;
typedef int                             int32;
typedef long long                       int64;
typedef unsigned char                   uint8;
typedef unsigned short                  uint16;
typedef unsigned int                    uint32;
typedef unsigned long long              uint64;

/******************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *****************************************************************************/


#endif  /* STD_TYPES_H */

/******************************************************************************
 *  END OF FILE:    Std_Types.h  
 *****************************************************************************/
