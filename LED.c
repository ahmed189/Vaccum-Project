#include "LED.h"

void Led_Init(LED_Type led_Type)
{
    //initialize pin led as output
    switch(led_Type)
    {
        case LED_DUST:
            GPIO_PIN_INIT(LED_DUST_CONTROL,LED_DUST_PIN,GPIO_OUT);
            break;
        default:
            break;
    }
    //Turn off specific led
    Led_Setter_OFF(led_Type);
}

//Setter to Turn on specific led
void Led_Setter_ON(LED_Type led_Type)
{
    switch(led_Type)
    {
        case LED_DUST:
            GPIO_PIN_WRITE(LED_DUST_PORT,LED_DUST_PIN,GPIO_IN);
            break;
        default:
            break;
    }
}

//Setter to Turn off specific led
void Led_Setter_OFF(LED_Type led_Type)
{
    switch(led_Type)
    {
        case LED_DUST:
            GPIO_PIN_WRITE(LED_DUST_PORT,LED_DUST_PIN,GPIO_OUT);
            break;
        default:
            break;
    }
}
