#ifndef EXTI_REG_H
#define EXTI_REG_H

#define MCUCR 			*((volatile uint8*)0x55)
#define MCUCR_ISC00		0U
#define MCUCR_ISC01		1U
#define MCUCR_ISC10		2U
#define MCUCR_ISC11		3U

#define MCUCSR 			*((volatile uint8*)0x54)
#define MCUCSR_ISC2		6U



#define GICR			*((volatile uint8*)0x5B)
#define GICR_INT1		7u
#define GICR_INT0		6u
#define GICR_INT2		5u



#endif
