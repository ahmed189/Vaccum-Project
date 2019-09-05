#include "SSD.h"

static u8 SSD_Value[SSD_SYMBOL_NUM]=
{
    0b00001000,
    0b01001000,
    0b01001001,
    0b00000000
};

static SSD_Type SSD_Current = SSD_MIN;
static SSD_Symbol SSD_Values[SSD_NUM] = {SSD_NULL};

static void SSD_Set_out(SSD_Type, SSD_Symbol);

//initialization for SSD
void SDD_Init(SSD_Type SSD_type)
{
    GPIO_PORT_INIT(SSD_DATA_CONTROL,GPIO_OUT);
    SSD_SetValue(SSD_type,SSD_NULL);
    //define SSD as outputs
    switch(SSD_type)
    {
        case SSD_MIN:
            GPIO_PIN_INIT(SSD_MIN_CONTROL,SSD_MIN_PIN,GPIO_OUT);
            break;

        case SSD_MID:
            GPIO_PIN_INIT(SSD_MID_CONTROL,SSD_MID_PIN,GPIO_OUT);
            break;

        case SSD_MAX:
            GPIO_PIN_INIT(SSD_MAX_CONTROL,SSD_MAX_PIN,GPIO_OUT);
            break;

        default:
            break;
    }
    //initialize state of SSD
    SSD_SetState(SSD_type, SSD_OFF);
}

void SDD_Update(void)
{
    //update fn of SSD each 10 ms
    static u8 SSD_Counter = 0;
    SSD_Counter += TIMER0_TICK_TIME;
    if(SSD_Counter != SSD_TICK_TIME)
        return;
    SSD_Counter = 0;
    //display a value on new SSD
    SSD_Set_out(SSD_Current,SSD_Values[SSD_Current]);
    if(SSD_Current == SSD_MAX)
        SSD_Current = SSD_MIN;
    else
        SSD_Current++;
}



//Put value in specific SSD
void SSD_SetValue(SSD_Type ssd, SSD_Symbol ssd_symbol)
{
    SSD_Values[ssd] = ssd_symbol;
}

//Save state in specific SSD
void SSD_SetState(SSD_Type ssd, SSD_Status state)
{
    switch(ssd)
    {
        case SSD_MIN:
            GPIO_PIN_WRITE(SSD_MIN_PORT,SSD_MIN_PIN,state);
            break;
        case SSD_MID:
            GPIO_PIN_WRITE(SSD_MID_PORT,SSD_MID_PIN,state);
            break;
        case SSD_MAX:
            GPIO_PIN_WRITE(SSD_MAX_PORT,SSD_MAX_PIN,state);
            break;
        default:
            break;
    }
}

//OUTPUT for the SSD
void SSD_Set_out(SSD_Type ssd, SSD_Symbol ssd_symbol)
{
    SSD_SetState(SSD_MIN,SSD_OFF);
    SSD_SetState(SSD_MID,SSD_OFF);
    SSD_SetState(SSD_MAX,SSD_OFF);

    GPIO_PORT_WRITE(SSD_DATA_PORT,SSD_Value[ssd_symbol]);

    SSD_SetState(ssd,SSD_ON);
}
