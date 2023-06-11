#ifndef EXTI_CFG_H
#define EXTI_CFG_H
#include "EXTI_interface.h"

/*CONFIGURE INT0 INITIAL STATE, OPTIONS			1- EXTI_LOW_LEVEL
 * 												2- EXTI_NO_CHANGE
 * 												3- EXTI_FALLING_EDGE
 * 												4- EXTI_RISING_EDGE*/
#define EXTI_u8INT0_TRIG_SRC				RISING_EDGE

#define EXTI_u8INT1_TRIG_SRC				RISING_EDGE

#define EXTI_u8INT2_TRIG_SRC				FALLING_EDGE

/*CONFIGURE INT0 INITIAL STATE, OPTIONS			1- ENABLED
 * 												2- DISABLED*/
#define EXTI_u8INT0_INT_STAT				DISABLED
/*CONFIGURE INT1 INITIAL STATE, OPTIONS			1- ENABLED
 * 												2- DISABLED*/
#define EXTI_u8INT1_INT_STAT				DISABLED
/*CONFIGURE INT2 INITIAL STATE, OPTIONS			1- ENABLED
 * 												2- DISABLED*/
#define EXTI_u8INT2_INT_STAT				DISABLED

#endif