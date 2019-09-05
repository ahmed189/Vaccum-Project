#include "SW.h"

/************************************************************************************/
//definition
#define PRESSED_LEVEL                   (1)
#define RELEASED_LEVEL                  (0)

/************************************************************************************/
//typedef of switch information
typedef struct
{
    u8 SW_Sample[2];
    SW_State SW_State;
}SWITCH_Info;

static SWITCH_Info SW_Info[SW_NUM];
/************************************************************************************/
//private data for Dust button

//to check if it pressed for specific time
#define COUNT_TIME                      30000

//flag
static u8 Dust_Pressed = 0;

static void Check_Dust_Pressed(Dust_Action);
static void Count_Time(u16 *);
/************************************************************************************/
//prototypes
void SW_Init(SW_Type sw_type)
{
    //make sw as inputs
    switch(sw_type)
    {
        case SW_PLUS:
        GPIO_PIN_INIT(SW_PLUS_CONTROL,SW_PLUS_PIN,GPIO_IN);
        break;

        case SW_MINUS:
        GPIO_PIN_INIT(SW_MINUS_CONTROL,SW_MINUS_PIN,GPIO_IN);
        break;

        case SW_DUST:
        GPIO_PIN_INIT(SW_DUST_CONTROL,SW_DUST_PIN,GPIO_IN);
        break;
    }

    //initialize states
    SW_Info[sw_type].SW_State = RELEASED_LEVEL;

    //initialize samples
    SW_Info[sw_type].SW_Sample[0] = SW_RELEASED;
    SW_Info[sw_type].SW_Sample[1] = SW_RELEASED;

}
void SW_Update(void)
{
    //update the switch data every time > bounce time
    static sw_counter = 0;
    static u16 Counter_time = 0;
    u8 index = 0;
    sw_counter += TIMER0_TICK_TIME;

    if(sw_counter != SW_TICK_TIME)
    {
        return;
    }
    sw_counter = 0;

    //update the switch data
    for(index = SW_PLUS ; index < SW_NUM ; index++)
    {
        //update switch sample 0
        SW_Info[index].SW_Sample[0] = SW_Info[index].SW_Sample[1];

        //read new sample 1
        switch(index)
        {
            case SW_PLUS:
            SW_Info[index].SW_Sample[1] = GPIO_PIN_READ(SW_PLUS_PORT,SW_PLUS_PIN);
            break;

            case SW_MINUS:
            SW_Info[index].SW_Sample[1] = GPIO_PIN_READ(SW_MINUS_PORT,SW_MINUS_PIN);
            break;

            case SW_DUST:
            SW_Info[index].SW_Sample[1] = GPIO_PIN_READ(SW_DUST_PORT,SW_DUST_PIN);
            break;

            default:
                break;
        }

        //check state and update it
        switch(SW_Info[index].SW_State)
        {
            case SW_RELEASED:
                if(SW_Info[index].SW_Sample[0] == RELEASED_LEVEL &&
                   SW_Info[index].SW_Sample[1] == RELEASED_LEVEL)
                    SW_Info[index].SW_State = SW_PREPRESSED;
                else;
                break;

            case SW_PREPRESSED:
                if(SW_Info[index].SW_Sample[1] == RELEASED_LEVEL)
                   SW_Info[index].SW_State = SW_PRESSED;
                else;
                break;

            case SW_PRESSED:
                if(SW_Info[index].SW_Sample[0] == PRESSED_LEVEL &&
                   SW_Info[index].SW_Sample[1] == PRESSED_LEVEL)
                   SW_Info[index].SW_State = SW_PRERELEASED;
                else;
                break;

            case SW_PRERELEASED:
                if(SW_Info[index].SW_Sample[1] == PRESSED_LEVEL)
                   SW_Info[index].SW_State = SW_RELEASED;
                else;
                break;
        }
    }

    if(SW_Info[SW_DUST].SW_State == SW_PRESSED)
        Count_Time(&Counter_time);
    else
        Counter_time = 0;

}

SW_State SW_GetState(SW_Type sw_type)
{
     return SW_Info[sw_type].SW_State;
}

static void Count_Time(u16 * Counter_time)
{
    *Counter_time += TIMER0_TICK_TIME;

    if(*Counter_time != COUNT_TIME)
    {
        Check_Dust_Pressed(DUST_TIME_NOT_PASSED);
        return;
    }
    Check_Dust_Pressed(DUST_TIME_PASSED);
    *Counter_time = 0;

}
Dust_Action Get_Dust_Pressed(void)
{
    return Dust_Pressed;
}
static void Check_Dust_Pressed(Dust_Action DATA)
{
    Dust_Pressed = DATA;
}

