#ifndef TIMER_H_INCLUDED
#define TIMER_H_INCLUDED

#include "Port.h"
#include "SW.h"
#include "LED.h"
#include "Display.h"
#include "SSD.h"
#include "MOTOR.h"
#include "UTILITIES.h"
//TIMER tick
#define TIMER0_TICK_TIME                 10
#define TIMER1_TICK_TIME                 5

//Prototypes
void Timer_Init(void);
void Timer_Start(void);
void Timer_Update(void) __interrupt 0; /* ISR @  vector 0 */
#endif
