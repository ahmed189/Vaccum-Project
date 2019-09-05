#include "Port.h"
#include "SW.h"
#include "Timer.h"
#include "LED.h"

u32 __at(0x2007) CONFIG = _HS_OSC & _WDT_OFF & _PWRTE_ON & _BODEN_OFF & _LVP_OFF & _CPD_OFF & _WRT_OFF & _DEBUG_OFF & _CP_OFF;
/*  note  */
//This code is ok if the timer auto reload but if not then we need to get the tasks out of the interrupt
void main (void)
{
    /* Initialization */
    SW_Init(SW_PLUS);
    SW_Init(SW_MINUS);
    SW_Init(SW_DUST);
    VC_Init();
    Display_Init();
    Led_Init(LED_DUST);
    Motor_Init();
    Timer_Init();
    Timer_Start();


    //Used for debugging
    TRISC7 = 0;
    TRISC6 = 0;
    RC7 = 0;
    RC6 = 0;

    while (1)
    {

    };

}

