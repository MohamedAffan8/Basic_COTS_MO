#ifndef LDR_CFG_H
#define LDR_CFG_H

/*Configuration NUMBER of LDRs */
#define LDR_NUM						2u /*one LDR*/
/*Configuration PORT of LDRs */
#define LDR_LED_PORT				DIO_PORTC /**/
#define LDR_LED_PIN0				DIO_PIN0 /**/
#define LDR_LED_PIN1				DIO_PIN1 /**/

#define LDR_FIRST_ADC_CHANNEL		ADC5_SINGLE_ENDED /*First LDR*/
#define LDR_SECOND_ADC_CHANNEL		ADC6_SINGLE_ENDED /*First LDR*/



#define LDR_REFERENCE_VOLT			10u /*mV*/
/*LDR REFERENCE VOLT at 8 levels*/
#define LDR_MAX_VOLT				0u /*mV*/
#define LDR_MIN_VOLT				220u /*mV*/
#define LDR_STEP_VOLT				31u /*mV*/

#define LDR_1_REFERENCE				10u /*mV*/
#define LDR_2_REFERENCE				31u /*mV*/
#define LDR_3_REFERENCE				62u /*mV*/
#define LDR_4_REFERENCE				93u /*mV*/
#define LDR_5_REFERENCE				124u /*mV*/
#define LDR_6_REFERENCE				155u /*mV*/
#define LDR_7_REFERENCE				186u /*mV*/


#endif
