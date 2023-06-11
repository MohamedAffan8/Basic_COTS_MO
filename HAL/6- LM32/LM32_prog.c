#include "STD_TYPES.h"
#include "Err_Type.h"

#include "ADC_interface.h"

#include "LM32_interface.h"
#include "LM32_prv.h"
#include "LM32_cfg.h"


sint8 LM32_s8GetTemperature(uint16 copy_u16Volt)
{
	sint8 Local_s8Temp;
	ADC_u8GetChannelReadingSynch(LM32_SINGLE_ENDED, &copy_u16Volt);
	Local_s8Temp = (sint8)(((uint32)copy_u16Volt * 500u)/1024u);
	return Local_s8Temp;
}
