#include "Timer.h"

//initializing 2 timers
void Timer_Init(void)
{
    TMR0_SET_PRESCALER_256;
    TMR0_DISABLE_CLOCK;

    TMR1_SET_PRESCALER_8;
    TMR1_DISABLE_CLOCK;
}

//start the 2 timers
void Timer_Start(void)
{
    TMR0_CLEAR_FLAG;
    TMR0_UPDATE_REGISTER(TIMER0_TICK_TIME);
    GLOBAL_INTERRUPT_ENABLE;
    PERPHERAL_ENABLE_INTERRUPT;
    TMR0_ENABLE_INTERRUPT;
    TMR0_ENABLE_CLOCK;

    TMR1_CLEAR_FLAG;
    TMR1_UPDATE_REGISTER(170);
    PERPHERAL_ENABLE_INTERRUPT;
    TMR1_ENABLE_INTERRUPT;
    TMR1_INTERNAL_ENABLE;
    TMR1_OSCILLATOR_ENABLE;
    TMR1_ENABLE_CLOCK;
}

void Timer_Update(void) __interrupt 0
{
    if(TMR1_GET_FLAG)
    {
        TMR1_CLEAR_FLAG;
        Motor_Fire_Update();
    }
    else if(TMR0_GET_FLAG)
    {
        RC7 = 1 ^ RC7;
        TMR0_CLEAR_FLAG;
        TMR0_UPDATE_REGISTER(TIMER0_TICK_TIME);

        Motor_Safety_Update();
        SDD_Update();
        SW_Update();
        VC_Update();
        Display_Update();

    }
}
