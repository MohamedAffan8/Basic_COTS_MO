#ifndef TIMER_REGISTER_H_
#define TIMER_REGISTER_H_

#define TCCR0                *((volatile uint8*)0x53)
/*Prescaler bits*/
#define TCCR0_CS00			 0
#define TCCR0_CS01			 1
#define TCCR0_CS02			 2
/*Mode selection bits*/
#define TCCR0_WGM00			 6                           /*Reference selection Bit0*/
#define TCCR0_WGM01			 3                           /*Reference selection Bit1*/
/*Comparison mode bits*/
#define TCCR0_COM00			 4
#define TCCR0_COM01			 5

/*Timer0 Register*/
#define TIMSK                *((volatile uint8*)0x59)		/*Interrupt register*/
#define TIMSK_TOIE0			 0
#define TIMSK_OCIE0			 1

/*Timer0 Register*/
#define TCNT0                *((volatile uint8*)0x52)		/*Data register*/



#endif
