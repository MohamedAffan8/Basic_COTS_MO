#ifndef TIMER_PRV_H
#define TIMER_PRV_H

#define PRESCALER_MASK							0b11111000
#define MODE_SELECTION_MASK						0b10110111

#define EIGHT_BITS						1u
#define SIXTEEN_BITS					2u

#define NO_CLK_SOURCE					0u
#define CLK_WITHOUT_PRE					1u
#define DIVISION_BY_8					2u
#define DIVISION_BY_64					3u
#define DIVISION_BY_256					4u
#define DIVISION_BY_1024				5u
#define EXTERNAL_CLK_FALLING			6u
#define EXTERNAL_CLK_RISING				7u

#define IDLE							0u
#define BUSY							1u




#endif
