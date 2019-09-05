#ifndef LED_H_INCLUDED
#define LED_H_INCLUDED

#include "Port.h"

//Type definition for leds type "we only have 1 led"
typedef enum{
    LED_DUST
}LED_Type;

//Prototypes for Led module
void Led_Init(LED_Type);
void Led_Setter_ON(LED_Type);
void Led_Setter_OFF(LED_Type);
#endif // LED_H_INCLUDED
