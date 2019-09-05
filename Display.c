#include "Display.h"

//Initializing the Display_processing
void Display_Init(void)
{
    //initializing SSDs
    SDD_Init(SSD_MIN);
    SDD_Init(SSD_MID);
    SDD_Init(SSD_MAX);

    //Put Null value in SSDs
    SSD_SetValue(SSD_MIN,SSD_NULL);
    SSD_SetValue(SSD_MID,SSD_NULL);
    SSD_SetValue(SSD_MAX,SSD_NULL);
}

//the updated fn each 20 ms
void Display_Update(void)
{
    //Check time to update each 20 ms
    static u8 Display_Counter = 0;
    Display_Counter += TIMER0_TICK_TIME;
    if(Display_Counter != DISPLAY_TIME_TICK)
        return;
    Display_Counter = 0;

    //get value of speed from vc to control SSDs depend on value of speed
    switch(VC_GetSpeed())
    {
        case SPEED_LOW:
            SSD_SetValue(SSD_MIN,SSD_SYM_L);
            SSD_SetValue(SSD_MID,SSD_NULL);
            SSD_SetValue(SSD_MAX,SSD_NULL);
            break;
        case SPEED_MID:
            SSD_SetValue(SSD_MIN,SSD_SYM_L);
            SSD_SetValue(SSD_MID,SSD_SYM_M);
            SSD_SetValue(SSD_MAX,SSD_NULL);
            break;
        case SPEED_MAX:
            SSD_SetValue(SSD_MIN,SSD_SYM_L);
            SSD_SetValue(SSD_MID,SSD_SYM_M);
            SSD_SetValue(SSD_MAX,SSD_SYM_X);
            break;
    }
    //Display Control The led of Dust Led by checking the sensor "or the button pressed"
    if(SW_GetState(SW_DUST)== SW_PRESSED)
        Led_Setter_ON(LED_DUST);
    else
        Led_Setter_OFF(LED_DUST);
}
