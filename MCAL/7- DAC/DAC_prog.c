#include "STD_TYPES.h"

#include "Err_Type.h"

#include "DIO_interface.h"

#include "DAC_interface.h"
#include "DAC_prv.h"
#include "DAC_cfg.h"



uint8 DAC_voidSetAnalogVolt(uint16 copy_u16Volt)
{
	uint8 Local_u8ErrorState = OK;
	if(copy_u16Volt <= DAC_REFERENCE_VOLT)
	{
		DIO_u8SetPortValue(DAC_PORT,(((copy_u16Volt*DAC_RESOLUTION)/DAC_REFERENCE_VOLT)));
	}
	else
	{
		Local_u8ErrorState = NOK;
	}
	return Local_u8ErrorState;
}
