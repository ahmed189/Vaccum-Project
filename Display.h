#ifndef __DISPLAY_H__
#define __DISPLAY_H__
#include "SSD.h"
#include "Timer.h"
#include "Port.h"
#include "VC.h"
#include "SW.h"

//Time tick definition for the Display update
#define DISPLAY_TIME_TICK                               20


//Prototypes for the processing display module
void Display_Init(void);
void Display_Update(void);

#endif // __DISPLAY_H__
