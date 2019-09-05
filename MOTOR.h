#ifndef MOTOR_H_INCLUDED
#define MOTOR_H_INCLUDED

#include "Port.h"
#include "VC.h"
#include "UTILITIES.h"
#include "Timer.h"

//Time Ticks For motors Update functions
#define Motor_Fire_TICK_TIME                                                    10
#define Motor_SOFT_SWITCHING_TIME                                               80
#define Motor_HARMONIC_TIME                                                     20

//Type definition for state of motor safety
typedef enum{
    MOTOR_HARMONICS,
    MOTOR_SOFT_SWITCHING
}Motor_Safety_State;

//Prototypes
void Motor_Init(void);
void Motor_Fire_Update(void);
void Motor_Safety_Update(void);
void Fire_Harmonics_Set(void);
void Soft_Switching_Set(void);
void Motor_SetAngle(u8);
#endif // MOTOR_H_INCLUDED
