#include "MOTOR.h"

static const u8 Motor_Angles_Values[4] = {170,140,90,10};
volatile static u8 Current_Angles_Value;

static u8 Desired_Angles_Value;
static u8 flag = 0;
static Motor_Safety_State motor_safety_state;

void Motor_Init(void)
{
    //initialize motor pin as output LOW
    GPIO_PIN_INIT(MOTOR_CONTROL,MOTOR_PIN,GPIO_OUT);
    GPIO_PIN_WRITE(MOTOR_PORT,MOTOR_PIN,GPIO_OUT);

    //initializing angles (Desired and Current)
    Desired_Angles_Value = Motor_Angles_Values[2];
    Current_Angles_Value = Motor_Angles_Values[0];

    //initialize state of motor
    motor_safety_state = MOTOR_SOFT_SWITCHING;
}

//Fire gate of the triac
void Motor_Fire_Update(void)
{
    //Pulse with width 100Us for the Triac gate for motor to be on
    GPIO_PIN_WRITE(MOTOR_PORT,MOTOR_PIN,GPIO_IN);
    DELAY_100US(1);
    GPIO_PIN_WRITE(MOTOR_PORT,MOTOR_PIN,GPIO_OUT);
}

//Update safety function
void Motor_Safety_Update(void)
{
    static u8 Soft_Switching_counter = 0;
    static u8 Harmonic_counter = 0;

    //disable then enable clock before update "in datasheet"
    TMR1_DISABLE_CLOCK;
    TMR1_UPDATE_REGISTER(Current_Angles_Value);
    TMR1_ENABLE_CLOCK;

    //state machine for the state of the motor
    switch(motor_safety_state)
    {
        case MOTOR_HARMONICS:
            //Update each 20 ms
            Harmonic_counter += TIMER0_TICK_TIME;
            if(Harmonic_counter != Motor_HARMONIC_TIME)
                return;
            else;
            Harmonic_counter = 0;
            Soft_Switching_counter = 0;
            Fire_Harmonics_Set();
            break;
        case MOTOR_SOFT_SWITCHING:
            //Update each 80 ms
            Soft_Switching_counter += TIMER0_TICK_TIME;
            if(Soft_Switching_counter != Motor_SOFT_SWITCHING_TIME)
                return;
            else;
            Soft_Switching_counter = 0;
            Harmonic_counter = 0;
            flag = 0;
            Soft_Switching_Set();
            break;
        default :
            break;
    }
}

//Function for harmonics algorithm
void Fire_Harmonics_Set(void)
{
    //state machine for the state of Fired angle to apply Kurz algorithm to reduce harmonics
    switch(flag)
    {
        case 0:
            Current_Angles_Value = Current_Angles_Value + 5;
            flag = 1;
            break;
        case 1:
            Current_Angles_Value = Current_Angles_Value - 10;
            flag = 2;
            break;
        case 2:
            Current_Angles_Value = Current_Angles_Value + 10;
            flag = 1;
            break;
    }
}
//function for soft switching
void Soft_Switching_Set(void)
{
    if(Current_Angles_Value < Desired_Angles_Value)
        Current_Angles_Value++;
    else if(Current_Angles_Value > Desired_Angles_Value)
        Current_Angles_Value--;
    else;

    if(Current_Angles_Value == Desired_Angles_Value)
        motor_safety_state = MOTOR_HARMONICS;
    else;
}

void Motor_SetAngle(u8 angle)
{
    //Check if the target_angle is being changed to change the mode to soft_switching
    if(Desired_Angles_Value != angle)
    {
        motor_safety_state = MOTOR_SOFT_SWITCHING;
        Desired_Angles_Value = angle;
    }
    else
        motor_safety_state = MOTOR_HARMONICS;

}
