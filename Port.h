#ifndef __PORT_H__
#define __PORT_H__

#include "Main.h"
/******************************************************************/
//SW Definitions
#define SW_PLUS_CONTROL                     GPIO_CONTROL_PORTB
#define SW_PLUS_PORT                        GPIO_DATA_PORTB
#define SW_PLUS_PIN                         GPIO_PIN1

#define SW_MINUS_CONTROL                    GPIO_CONTROL_PORTB
#define SW_MINUS_PORT                       GPIO_DATA_PORTB
#define SW_MINUS_PIN                        GPIO_PIN0

#define SW_DUST_CONTROL                     GPIO_CONTROL_PORTB
#define SW_DUST_PORT                        GPIO_DATA_PORTB
#define SW_DUST_PIN                         GPIO_PIN2
//end of SW DIFINITION
/******************************************************************/
//LED Definitions
#define LED_DUST_CONTROL                         GPIO_CONTROL_PORTB
#define LED_DUST_PORT                            GPIO_DATA_PORTB
#define LED_DUST_PIN                             GPIO_PIN3
//end of LED DIFINITION
/******************************************************************/
//SSD Definitions
#define SSD_MIN_CONTROL                         GPIO_CONTROL_PORTB
#define SSD_MIN_PORT                            GPIO_DATA_PORTB
#define SSD_MIN_PIN                             GPIO_PIN7

#define SSD_MID_CONTROL                         GPIO_CONTROL_PORTB
#define SSD_MID_PORT                            GPIO_DATA_PORTB
#define SSD_MID_PIN                             GPIO_PIN6

#define SSD_MAX_CONTROL                         GPIO_CONTROL_PORTB
#define SSD_MAX_PORT                            GPIO_DATA_PORTB
#define SSD_MAX_PIN                             GPIO_PIN5

#define SSD_DATA_CONTROL                        GPIO_CONTROL_PORTD
#define SSD_DATA_PORT                           GPIO_DATA_PORTD
//end of SSD DIFINITION
/******************************************************************/
//Motor PIN
#define MOTOR_CONTROL                     GPIO_CONTROL_PORTC
#define MOTOR_PORT                        GPIO_DATA_PORTC
#define MOTOR_PIN                         GPIO_PIN0


#endif
