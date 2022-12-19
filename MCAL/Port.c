/******************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------*/
/**         \file   Port.c
 *         \brief   Driver for GPIO Port module.
 *         
 *       \details   -
 *****************************************************************************/

/******************************************************************************
 *  INCLUDES
 *****************************************************************************/
#include "../LIBRARIES/Mcu_Hw.h"
#include "../Config/Port_Cfg.h"
#include "Inc/Port.h"

/******************************************************************************
 *  LOCAL MACROS CONSTANT\FUNCTION
 *****************************************************************************/


/******************************************************************************
 *  LOCAL DATA
 *****************************************************************************/


/******************************************************************************
 *  GLOBAL DATA
 *****************************************************************************/
extern Port_ConfigType ConfigPtr[];
static Port_IntHandlerType (*Port_IntHandlers[])() = 
{
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL
};


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
 * \syntax          : void Port_Init(void)
 * \Description     : Configures GPIO pins functionalities
 * \Sync\Async      : Sync
 * \Reentrancy      : Non-Reentrant
 * \parameters (in) : None
 * \parameters (out): None
 * \Return value    : None
 *****************************************************************************/
void Port_Init(void){
    uint8 i;
    uint32 Ports[] = {GPIO_A, GPIO_B, GPIO_C, GPIO_D, GPIO_E, GPIO_F};

    for(i=0; i<NUM_OF_USED_PINS; i++){
        /* Get the GPIO Port address and Pin number */
        uint32 Port = Ports[(ConfigPtr[i].PinType / 8)];
        uint8 Pin   = (ConfigPtr[i].PinType % 8);
        
        /* Enable Clock to the GPIO module */
        SET_BIT(REG(SYSCTL_BASE, RCGCGPIO), (ConfigPtr[i].PinType / 8));

        /* Set pin direction */
        switch(ConfigPtr[i].PinDirection){
            case INPUT:
                RESET_BIT(REG(Port, GPIODIR), Pin);
            break;

            case OUTPUT:
                SET_BIT(REG(Port, GPIODIR), Pin);
                
                /* Set output current ans slew rate control */
                switch(ConfigPtr[i].PinOutputCurrent){
                    case _2MA:
                        SET_BIT(REG(Port, GPIODR2R), Pin);
                    break;

                    case _4MA:
                        SET_BIT(REG(Port, GPIODR4R), Pin);
                    break;

                    case _8MA:
                        SET_BIT(REG(Port, GPIODR8R), Pin);
                    break;

                    case _8MA_W_SLR:
                        SET_BIT(REG(Port, GPIODR8R), Pin);
                        SET_BIT(REG(Port, GPIOSLR), Pin);
                    break;

                    default:
                    break;
                }
            break;

            default:
            break;
        }

        /* Unlock the commit register if needed */
        if(!GET_BIT(REG(Port, GPIOCR), Pin)){
            REG(Port, GPIOLOCK) = 0x4C4F434Bu;
            SET_BIT(REG(Port, GPIOCR), Pin);
        }

        /* Set the internal attachment */
        switch(ConfigPtr[i].PinInternalAttach){
            case PULL_UP:
                SET_BIT(REG(Port, GPIOPUR), Pin);
            break;

            case PULL_DOWN:
                SET_BIT(REG(Port, GPIOPDR), Pin);
            break;

            case OPEN_DRAIN:
                SET_BIT(REG(Port, GPIOODR), Pin);
            break;

            default:
            break;
        }

        /* Configure mode specific registers */
        switch(ConfigPtr[i].PinMode){
            case DIO:
                SET_BIT(REG(Port, GPIODEN), Pin);   
            break;

            case ANALOG_IN:
                RESET_BIT(REG(Port, GPIODIR), Pin);
                SET_BIT(REG(Port, GPIOAMSEL), Pin);
            break;

            case ALT_FUNC:
                SET_BIT(REG(Port, GPIOAFSEL), Pin);
                SET_BIT(REG(Port, GPIODEN), Pin);
            break;

            /* 
                Default includes configurations for:
                    - External interrupt
                    - ADC trigger
                    - DMA trigger
            */
            default:
                RESET_BIT(REG(Port, GPIODIR), Pin);
                SET_BIT(REG(Port, GPIODEN), Pin);
                RESET_BIT(REG(Port, GPIOIM), Pin);
                
                switch(ConfigPtr[i].PinInterruptTrigger){
                    case LEVEL:
                        SET_BIT(REG(Port, GPIOIS), Pin);
                    break;

                    case SINGLE_EDGE:
                        RESET_BIT(REG(Port, GPIOIS), Pin);
                        RESET_BIT(REG(Port, GPIOIBE), Pin);
                    break;

                    case BOTH_EDGES:
                        RESET_BIT(REG(Port, GPIOIS), Pin);
                        SET_BIT(REG(Port, GPIOIBE), Pin);
                    break;

                    default:
                    break;
                }

                switch(ConfigPtr[i].PinEdge){
                    case FALLING:
                        RESET_BIT(REG(Port, GPIOIEV), Pin);
                    break;

                    case RISING:
                        SET_BIT(REG(Port, GPIOIEV), Pin);
                    break;

                    default:
                    break;
                }

                if(ConfigPtr[i].PinMode == ADC_TRIG){
                    SET_BIT(REG(Port, GPIOADCCTL), Pin);
                }

                else if(ConfigPtr[i].PinMode == DMA_TRIG){
                    SET_BIT(REG(Port, GPIODMACTL), Pin);
                }

                SET_BIT(REG(Port, GPIOIM), Pin);
            break;
        }

    }
}

/******************************************************************************
 * \syntax          : void GPIOA_Handler(void)
 * \Description     : Port A interrupt handler
 * \Sync\Async      : Sync
 * \Reentrancy      : Non-Reentrant
 * \parameters (in) : None
 * \parameters (out): None
 * \Return value    : None
 *****************************************************************************/
void GPIOA_Handler(void){
    uint8 Int_Status = REG(GPIO_A, GPIOMIS);
    uint8 i = 0;
    while(Int_Status){
        if(Int_Status & 1){
            (*(Port_IntHandlers[i]))();
            SET_BIT(REG(GPIO_A, GPIOICR), i);
            break;
        }
        Int_Status >>= 1;
        i++;
    }
}

/******************************************************************************
 * \syntax          : void GPIOB_Handler(void)
 * \Description     : Port B interrupt handler
 * \Sync\Async      : Sync
 * \Reentrancy      : Non-Reentrant
 * \parameters (in) : None
 * \parameters (out): None
 * \Return value    : None
 *****************************************************************************/
void GPIOB_Handler(void){
    uint8 Int_Status = REG(GPIO_B, GPIOMIS);
    uint8 i = 0;
    while(Int_Status){
        if(Int_Status & 1){
            (*(Port_IntHandlers[i+8]))();
            SET_BIT(REG(GPIO_B, GPIOICR), i);
            break;
        }
        Int_Status >>= 1;
        i++;
    }
}

/******************************************************************************
 * \syntax          : void GPIOC_Handler(void)
 * \Description     : Port C interrupt handler
 * \Sync\Async      : Sync
 * \Reentrancy      : Non-Reentrant
 * \parameters (in) : None
 * \parameters (out): None
 * \Return value    : None
 *****************************************************************************/
void GPIOC_Handler(void){
    uint8 Int_Status = REG(GPIO_C, GPIOMIS);
    uint8 i = 0;
    while(Int_Status){
        if(Int_Status & 1){
            (*(Port_IntHandlers[i+16]))();
            SET_BIT(REG(GPIO_C, GPIOICR), i);
            break;
        }
        Int_Status >>= 1;
        i++;
    }
}

/******************************************************************************
 * \syntax          : void GPIOD_Handler(void)
 * \Description     : Port D interrupt handler
 * \Sync\Async      : Sync
 * \Reentrancy      : Non-Reentrant
 * \parameters (in) : None
 * \parameters (out): None
 * \Return value    : None
 *****************************************************************************/
void GPIOD_Handler(void){
    uint8 Int_Status = REG(GPIO_D, GPIOMIS);
    uint8 i = 0;
    while(Int_Status){
        if(Int_Status & 1){
            (*(Port_IntHandlers[i+24]))();
            SET_BIT(REG(GPIO_D, GPIOICR), i);
            break;
        }
        Int_Status >>= 1;
        i++;
    }
}

/******************************************************************************
 * \syntax          : void GPIOE_Handler(void)
 * \Description     : Port E interrupt handler
 * \Sync\Async      : Sync
 * \Reentrancy      : Non-Reentrant
 * \parameters (in) : None
 * \parameters (out): None
 * \Return value    : None
 *****************************************************************************/
void GPIOE_Handler(void){
    uint8 Int_Status = REG(GPIO_E, GPIOMIS);
    uint8 i = 0;
    while(Int_Status){
        if(Int_Status & 1){
            (*(Port_IntHandlers[i+32]))();
            SET_BIT(REG(GPIO_E, GPIOICR), i);
            break;
        }
        Int_Status >>= 1;
        i++;
    }
}

/******************************************************************************
 * \syntax          : void GPIOF_Handler(void)
 * \Description     : Port F interrupt handler
 * \Sync\Async      : Sync
 * \Reentrancy      : Non-Reentrant
 * \parameters (in) : None
 * \parameters (out): None
 * \Return value    : None
 *****************************************************************************/
void GPIOF_Handler(void){
    uint8 Int_Status = REG(GPIO_F, GPIOMIS);
    uint8 i = 0;
    while(Int_Status){
        if(Int_Status & 1){
            (*(Port_IntHandlers[i+40]))();
            SET_BIT(REG(GPIO_F, GPIOICR), i);
            break;
        }
        Int_Status >>= 1;
        i++;
    }
}

/******************************************************************************
 * \syntax          : void Port_SetCallBack(Port_PinType Pin, 
 *                                          Port_IntHandlerType (*CallBack)())
 * \Description     : Sets the corresponding callback function
 * \Sync\Async      : Sync
 * \Reentrancy      : Non-Reentrant
 * \parameters (in) : Port_PinType Pin
 *                    Port_IntHandlerType (*CallBack)
 * \parameters (out): None
 * \Return value    : None
 *****************************************************************************/
void Port_SetCallBack(Port_PinType Pin, Port_IntHandlerType (*CallBack)()){
    Port_IntHandlers[Pin] = CallBack;
}

/******************************************************************************
 *  END OF FILE:    Port.c
 *****************************************************************************/
