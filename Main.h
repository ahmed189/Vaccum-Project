#ifndef __MAIN_H__
#define __MAIN_H__

#include <pic16f877a.h>
/***************************************************************************/
/* GPIO definitions */
//define gpio ports
#define GPIO_DATA_PORTA                         PORTA
#define GPIO_DATA_PORTB                         PORTB
#define GPIO_DATA_PORTC                         PORTC
#define GPIO_DATA_PORTD                         PORTD

//define gpio Control
#define GPIO_CONTROL_PORTA                      TRISA
#define GPIO_CONTROL_PORTB                      TRISB
#define GPIO_CONTROL_PORTC                      TRISC
#define GPIO_CONTROL_PORTD                      TRISD

//define GPIO pins
#define GPIO_PIN0                               0
#define GPIO_PIN1                               1
#define GPIO_PIN2                               2
#define GPIO_PIN3                               3
#define GPIO_PIN4                               4
#define GPIO_PIN5                               5
#define GPIO_PIN6                               6
#define GPIO_PIN7                               7

//GPIO PINOUT
#define GPIO_IN                                 1
#define GPIO_OUT                                0

//set Port
#define GPIO_PORT_INIT(CONTROL,DIRECTION)       ((CONTROL) = ((DIRECTION)?(GPIO_IN):(GPIO_OUT)))
#define GPIO_PORT_WRITE(PORT,DATA)              (PORT = DATA)
#define GPIO_PORT_READ(PORT)                    (PORT)


//set PIN
#define GPIO_PIN_INIT(CONTROL,PIN,DIRECTION)   (CONTROL = `(CONTROL & (~(1<<PIN))) | (DIRECTION<<PIN))
#define GPIO_PIN_WRITE(PORT,PIN,DATA)          ((PORT) = (PORT & (~(1 << PIN)))|(DATA << PIN))
#define GPIO_PIN_READ(PORT,PIN)                (((PORT) & (1 << PIN)) >> (PIN))
//End of GPIO DIFINITION
/***************************************************************************/
//TIMER0 DIFINITION
#define TMR0_SET_PRESCALER_256	PS2 = 1;\
								PS1 = 1;\
								PS0 = 1;\
								PSA = 0

#define TMR0_GET_FLAG			(TMR0IF)
#define TMR0_CLEAR_FLAG			(TMR0IF = 0)

#define TMR0_UPDATE_REGISTER(TIME)		(TMR0 = (u8)(256 - ((u32)(TIME) * 8)))

#define TMR0_ENABLE_INTERRUPT	(TMR0IE = 1)
#define GLOBAL_INTERRUPT_ENABLE	(GIE = 1)

#define TMR0_ENABLE_CLOCK		(T0CS = 0)
#define TMR0_DISABLE_CLOCK		(T0CS = 1)
/***************************************************************************/
//TIMER1 DIFINITION
#define TMR1_SET_PRESCALER_8	    T1CKPS1 = 1;\
                                    T1CKPS0 = 1;

#define TMR1_OSCILLATOR_ENABLE      T1OSCEN = 1
#define TMR1_OSCILLATOR_DISABLE     T1OSCEN = 0

#define TMR1_EXTERNAL_ENABLE        TMR1CS = 1
#define TMR1_INTERNAL_ENABLE        TMR1CS = 0

#define TMR1_GET_FLAG			    (TMR1IF)
#define TMR1_CLEAR_FLAG			    (TMR1IF = 0)

#define PERPHERAL_ENABLE_INTERRUPT	(PEIE = 1)
//#define TMR1_UPDATE_REGISTER(TIME)		(TMR1 = (u32)(65536 - (u32)((TIME) * 250)))
#define TMR1_UPDATE_REGISTER(ANGLE)		(TMR1L = (u8)( 65536 - (14 * (u32)ANGLE)));\
                                        (TMR1H = (u8)((65536 - (14 * (u32)ANGLE))>>8))

#define TMR1_ENABLE_INTERRUPT	(TMR1IE = 1)

#define TMR1_ENABLE_CLOCK		(TMR1ON = 1)
#define TMR1_DISABLE_CLOCK		(TMR1ON = 0)
/***************************************************************************/
//Standard datatypes
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

#endif // __MAIN_H__
