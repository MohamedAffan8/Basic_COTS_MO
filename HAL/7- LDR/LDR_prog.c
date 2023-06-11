#include "STD_TYPES.h"
#include "Err_Type.h"

#include "DIO_interface.h"
#include "ADC_interface.h"

#include "LDR_interface.h"
#include "LDR_cfg.h"
#include "LDR_prv.h"


void LDR_voidSimpleAutoLight(void)
{
	uint16 Local_u16AnalogReading=0;
	ADC_u8GetChannelReadingSynch(LDR_FIRST_ADC_CHANNEL,&Local_u16AnalogReading);
	if(Local_u16AnalogReading> LDR_REFERENCE_VOLT)
	{
		DIO_u8SetPinValue(LDR_LED_PORT,LDR_LED_PIN0,DIO_PIN_LOW);
	}
	else
	{
		DIO_u8SetPinValue(LDR_LED_PORT,LDR_LED_PIN0,DIO_PIN_HIGH);
	}

#if LDR_NUM == ONE_LDR
	/*do nothing*/
#elif LDR_NUM == TWO_LDR
	ADC_u8GetChannelReadingSynch(LDR_SECOND_ADC_CHANNEL,&Local_u16AnalogReading);
	if(Local_u16AnalogReading> LDR_REFERENCE_VOLT)
	{
		DIO_u8SetPinValue(LDR_LED_PORT,LDR_LED_PIN1,DIO_PIN_LOW);
	}
	else
	{
		DIO_u8SetPinValue(LDR_LED_PORT,LDR_LED_PIN1,DIO_PIN_HIGH);
	}
#endif

}



uint8 LDR_voidAdvanceAutoLight(void)
{
	uint8 Local_u8LightLevel;
	uint16 Local_u16AnalogReading=0;
	ADC_u8GetChannelReadingSynch(LDR_FIRST_ADC_CHANNEL,&Local_u16AnalogReading);
	if((Local_u16AnalogReading>= 0u)&&(Local_u16AnalogReading< LDR_1_REFERENCE))
	{
		Local_u8LightLevel =1u;
	}
	else if((Local_u16AnalogReading>= LDR_1_REFERENCE)&&(Local_u16AnalogReading< LDR_2_REFERENCE))
	{
		Local_u8LightLevel =2u;
	}
	else if((Local_u16AnalogReading>= LDR_2_REFERENCE)&&(Local_u16AnalogReading< LDR_3_REFERENCE))
	{
		Local_u8LightLevel =3u;
	}
	else if((Local_u16AnalogReading>= LDR_3_REFERENCE)&&(Local_u16AnalogReading< LDR_4_REFERENCE))
	{
		Local_u8LightLevel =4u;
	}
	else if((Local_u16AnalogReading>= LDR_4_REFERENCE)&&(Local_u16AnalogReading< LDR_5_REFERENCE))
	{
		Local_u8LightLevel =5u;
	}
	else if((Local_u16AnalogReading>= LDR_5_REFERENCE)&&(Local_u16AnalogReading< LDR_6_REFERENCE))
	{
		Local_u8LightLevel =6u;
	}
	else if((Local_u16AnalogReading>= LDR_6_REFERENCE)&&(Local_u16AnalogReading< LDR_7_REFERENCE))
	{
		Local_u8LightLevel =7u;
	}
	else if(Local_u16AnalogReading > LDR_7_REFERENCE)
	{
		Local_u8LightLevel =8u;
	}


	return Local_u8LightLevel;
}
