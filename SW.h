#ifndef __SW_H__
#define __SW_H__

#include "Port.h"
#include "Timer.h"
#include "LED.h"

#define SW_NUM                                      3
#define SW_TICK_TIME                                20

/*********************************************************************/
//Type definitions
//type of SW
typedef enum{
    SW_PLUS,
    SW_MINUS,
    SW_DUST
}SW_Type;

//State of SW
typedef enum{
    SW_RELEASED,
    SW_PREPRESSED,
    SW_PRESSED,
    SW_PRERELEASED
}SW_State;

typedef enum{
    DUST_TIME_NOT_PASSED,
    DUST_TIME_PASSED
}Dust_Action;
/*********************************************************************/
//prototypes
void SW_Init(SW_Type);
void SW_Update(void);
SW_State SW_GetState(SW_Type);

Dust_Action Get_Dust_Pressed(void);
/*********************************************************************/

#endif
