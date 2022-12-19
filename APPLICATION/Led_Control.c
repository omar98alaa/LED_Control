/*******************************************************************************
 *  FILE DESCRIPTION
 *  --------------------------------------------------------------------------*/
/**         \file   Led_Control.c
 *         \brief   Application for LED control
 *         
 *       \details   -
 ******************************************************************************/

/*******************************************************************************
 *  INCLUDES
 ******************************************************************************/
#include "../HAL/Inc/Led.h"
#include "../HAL/Inc/Switch.h"
#include "../SERVICE/Delay.h"
#include "Led_Control.h"

/*******************************************************************************
 *  LOCAL MACROS CONSTANT\FUNCTION
 ******************************************************************************/
#define OFF                     0
#define ON                      1

/*******************************************************************************
 *  LOCAL DATA
 ******************************************************************************/


/*******************************************************************************
 *  GLOBAL DATA
 ******************************************************************************/
volatile static uint8 Tick;
volatile static uint8 clicks;
volatile static uint8 OnOff;
volatile static uint8 ON_OFF[2];

/*******************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 ******************************************************************************/
void Delay_ISR(void);
void Switch1_ISR(void);
void Switch2_ISR(void);

/*******************************************************************************
 *  LOCAL FUNCTIONS
 ******************************************************************************/
void Delay_ISR(void){
    ++Tick;
    Tick %= 100;
}

void Switch1_ISR(void){
    clicks++;
}

void Switch2_ISR(void){
    OnOff++;
	OnOff &= 1;
	if(clicks){
		ON_OFF[OnOff] = clicks;
		clicks = 0;
	}
}
/*******************************************************************************
 *  GLOBAL FUNCTIONS
 ******************************************************************************/


/*******************************************************************************
 * \syntax          : void Led_Control(void)
 * \Description     : Toggles an LED after for given ON and OFF time
 * \Sync\Async      : Sync
 * \Reentrancy      : Non-Reentrant
 * \parameters (in) : None
 * \parameters (out): None
 * \Return value    : None
 ******************************************************************************/
void Led_Control(void){
    Delay_Timer_Init(Delay_ISR);
    Swtich_SetCallback(SW1, Switch1_ISR);
    Swtich_SetCallback(SW2, Switch2_ISR);

    static uint8 i = 0;
    static uint8 Time;

    ON_OFF[ON]  = 1;
    ON_OFF[OFF] = 1;

    Time = ON_OFF[ON];

    Led_On(BLUE_LED);
    Delay_Ms(1000);

    while(1){
        if((Tick / Time) == 1){
            Led_Toggle(BLUE_LED);
            Time = ON_OFF[i++];
            i &= 1;
            Tick = 0;
        }
    }
}

/*******************************************************************************
 *  END OF FILE:    Led_Control.c
 ******************************************************************************/
