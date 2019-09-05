#ifndef __SSD_H__
#define __SSD_H__

#include "Port.h"
#include "Timer.h"

#define SSD_NUM                                 3
#define SSD_SYMBOL_NUM                          4

#define SSD_TICK_TIME                           10

typedef enum {
    SSD_MIN,
    SSD_MID,
    SSD_MAX
}SSD_Type;

typedef enum {
    SSD_OFF,
    SSD_ON
}SSD_Status;

typedef enum
{
    SSD_SYM_L,
    SSD_SYM_M,
    SSD_SYM_X,
    SSD_NULL
}SSD_Symbol;

void SDD_Init(SSD_Type);
void SDD_Update(void);
void SSD_SetValue(SSD_Type ssd, SSD_Symbol ssd_symbol);
void SSD_SetState(SSD_Type ssd, SSD_Status state);

#endif // __SSD_H__
