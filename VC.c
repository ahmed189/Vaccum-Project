#include "VC.h"

static Speeds Current_Speed = 0;
static Angles Current_Angles = 0;

//initialize for speed and angle processing
void VC_Init(void)
{
    Current_Speed = SPEED_MID;
    Current_Angles = ANGLE_90;
    Motor_SetAngle(Current_Angles);
}

//update processing each 20 ms
void VC_Update(void)
{
    static u8 vc_counter = 0;
    vc_counter += TIMER0_TICK_TIME;
    if(vc_counter != VC_TICK_TIME)
        return;
    else;
    vc_counter = 0;

    if(SW_GetState(SW_PLUS) == SW_PREPRESSED && SW_GetState(SW_DUST) != SW_PRESSED)
    {
        if(Current_Speed == SPEED_MAX)
            Motor_SetAngle(ANGLE_10);
        else if(Current_Speed == SPEED_MID)
        {
            Current_Speed = SPEED_MAX;
            Motor_SetAngle(ANGLE_10);
        }
        else if(Current_Speed == SPEED_LOW)
        {
            Current_Speed = SPEED_MID;
            Motor_SetAngle(ANGLE_90);
        }
        else;

    }
    else if( (SW_GetState(SW_MINUS) == SW_PREPRESSED && SW_GetState(SW_DUST) != SW_PRESSED) || Get_Dust_Pressed() == DUST_TIME_PASSED)
    {
        if(Current_Speed == SPEED_LOW)
            Motor_SetAngle(ANGLE_140);
        else if(Current_Speed == SPEED_MID)
        {
            Current_Speed = SPEED_LOW;
            Motor_SetAngle(ANGLE_140);
        }
        else if(Current_Speed == SPEED_MAX)
        {
            Current_Speed = SPEED_MID;
            Motor_SetAngle(ANGLE_90);
        }
        else;
    }
    else;
}

//return speed
Speeds VC_GetSpeed(void)
{
    return Current_Speed;
}
