#ifndef VC_H_INCLUDED
#define VC_H_INCLUDED

#include "SW.h"
#include "Timer.h"
#include "MOTOR.h"

#define VC_TICK_TIME                                        20
typedef enum
{
    Angle_170 = 170,
    ANGLE_140 = 140,
    ANGLE_90 = 90,
    ANGLE_10 = 10
}Angles;

typedef enum
{
    SPEED_LOW = 0,
    SPEED_MID,
    SPEED_MAX
}Speeds;

void VC_Init(void);
void VC_Update(void);
Speeds VC_GetSpeed(void);

#endif // VC_H_INCLUDED
