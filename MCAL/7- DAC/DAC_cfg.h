#ifndef DAC_CFG_H
#define DAC_CFG_H

/*configure ADC prescaler division factor: 1- DIVISION_BY_2
 * 										   2- DIVISION_BY_4
 * 										   3- DIVISION_BY_8
 * 										   4- DIVISION_BY_16
 * 										   5- DIVISION_BY_32
 * 										   6- DIVISION_BY_64
 * 										   7- DIVISION_BY_128*/

#define DAC_REFERENCE_VOLT					5000u /*mVolt*/
#define DAC_RESOLUTION						1024u /*8 bits*/
#define DAC_PORT							DIO_PORTB /*mVolt*/



#endif
