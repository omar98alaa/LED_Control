/******************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------*/
/**         \file   IntCtrl.c
 *         \brief   Driver for interrupt control module
 *         
 *       \details   -
 *****************************************************************************/

/******************************************************************************
 *  INCLUDES
 *****************************************************************************/
#include "../LIBRARIES/Mcu_Hw.h"
#include "../Config/IntCtrl_Cfg.h"
#include "Inc/IntCtrl.h"

/******************************************************************************
 *  LOCAL MACROS CONSTANT\FUNCTION
 *****************************************************************************/


/******************************************************************************
 *  LOCAL DATA
 *****************************************************************************/


/******************************************************************************
 *  GLOBAL DATA
 *****************************************************************************/
extern IntCtrl_ConfigType IntCtrl_Config[];

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
 * \syntax          :   void IntCtrl_Init(void)
 * \Description     :   Initialize NVIC/SCB Module by parsing the config
 * 
 * \Sync\Async      :   Sync
 * \Reentrancy      :   Non-Reentrant
 * \parameters (in) :   None
 * \parameters (out):   None
 * \Return value    :   None
 *****************************************************************************/
void IntCtrl_Init(void){
    /* Grouping and subgrouping config */
    REG(MCU_PERI_BASE, APINT) = (0x05FA0000U | (PRIGROUPS << 8));

    /* Set priorities for interrupts and exceptions */
    /* Enable/Disable interrupts ans exceptions */
    uint8 i;
    
    for(i=0; i<NUM_OF_USED_INTS; i++){
        switch(IntCtrl_Config[i].InterruptType < 16){
            case TRUE:
                SET_VAL(
                    REG(
                        MCU_PERI_BASE, 
                        (SYSPRI1 + (((IntCtrl_Config[i].InterruptType /4)-1)*4))
                    ), 
                    (((IntCtrl_Config[i].InterruptType % 4) * 8) + 5), 
                    (IntCtrl_Config[i].PriorityValueType & 0x07u)
                );
                
                if(IntCtrl_Config[i].InterruptType < 7){
                    SET_BIT(
                        REG(MCU_PERI_BASE, SYSHNDCTRL), 
                        (IntCtrl_Config[i].InterruptType + 12)
                    );
                }
            break;

            default:
                IntCtrl_Config[i].InterruptType -= 16;
                SET_VAL(
                    REG(
                        MCU_PERI_BASE, 
                        (PRI0 + ((IntCtrl_Config[i].InterruptType / 4)*4))
                    ),
                    (((IntCtrl_Config[i].InterruptType % 4) * 8) + 5), 
                    (IntCtrl_Config[i].PriorityValueType & 0x07u)  
                );

                SET_BIT(
                    REG(
                        MCU_PERI_BASE, 
                        (EN0 + ((IntCtrl_Config[i].InterruptType / 32)*4))
                    ), 
                    (IntCtrl_Config[i].InterruptType % 32)
                );
            break;
        }
    }
}

/******************************************************************************
 *  END OF FILE:    IntCtrl.c
 *****************************************************************************/
