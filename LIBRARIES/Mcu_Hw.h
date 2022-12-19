/******************************************************************************
 *  FILE DESCRIPTION
 *  ---------------------------------------------------------------------------
 *         FILE:   Mcu_Hw.h  
 *       MODULE:   -
 * 
 *  DESCRIPTION:  
 * 
 *****************************************************************************/
#ifndef MCU_HW_H
#define MCU_HW_H

/******************************************************************************
 *  INCLUDES
 *****************************************************************************/
#include "Std_Types.h"

/******************************************************************************
 *  GLOBAL CONSTANT MACROS
 *****************************************************************************/
#define F_CPU                       16000000UL

#define REG(Base, Offset)           *((volatile uint32 *)(Base + Offset))

#define MCU_PERI_BASE               0xE000E000

#define STCTRL                      0x010
#define STRELOAD                    0x014
#define STCURRENT                   0x018
#define EN0                         0x100
#define PRI0                        0x400
#define APINT                       0xD0C
#define SYSPRI1                     0xD18
#define SYSHNDCTRL                  0xD24


#define SYSCTL_BASE                 0x400FE000

#define RCGCGPIO                    0x608


#define GPIO_A                      0X40004000
#define GPIO_B                      0X40005000
#define GPIO_C                      0X40006000
#define GPIO_D                      0X40007000
#define GPIO_E                      0X40024000
#define GPIO_F                      0X40025000

#define GPIODATA                    0x3FC
#define GPIODIR                     0x400
#define GPIOIS                      0x404
#define GPIOIBE                     0x408
#define GPIOIEV                     0x40C
#define GPIOIM                      0x410
#define GPIORIS                     0x414
#define GPIOMIS                     0x418
#define GPIOICR                     0x41C
#define GPIOAFSEL                   0x420
#define GPIODR2R                    0x500
#define GPIODR4R                    0x504
#define GPIODR8R                    0x508
#define GPIOODR                     0x50C
#define GPIOPUR                     0x510
#define GPIOPDR                     0x514
#define GPIOSLR                     0x518
#define GPIODEN                     0x51C
#define GPIOLOCK                    0x520
#define GPIOCR                      0x524
#define GPIOAMSEL                   0x528
#define GPIOPCTL                    0x52C
#define GPIOADCCTL                  0x530
#define GPIODMACTL                  0x534

/******************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *****************************************************************************/


/******************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *****************************************************************************/


#endif  /* MCU_HW_H */

/******************************************************************************
 *  END OF FILE:    Mcu_Hw.h  
 *****************************************************************************/
