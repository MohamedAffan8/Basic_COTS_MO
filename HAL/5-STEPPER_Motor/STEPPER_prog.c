#include "STD_TYPES.h"
#include <util/delay.h>
#include "Err_Type.h"

#include "DIO_interface.h"

#include "STEPPER_interface.h"
#include "STEPPER_prv.h"
#include "STEPPER_cfg.h"


uint8 STEPPER_u8Rotate(uint16 copy_Angle, uint8 copy_u8Dir)
{
	uint8 Local_u8ErrorState = OK;
	uint16 Local_u16Counter;
	uint16 Local_u16Steps = (uint16)((((uint32)copy_Angle)*2048UL)/360UL);
	if(copy_u8Dir == STEPPER_DIR_CW)
	{

		for(Local_u16Counter=0;Local_u16Counter<Local_u16Steps;Local_u16Counter++)
		{
			if(Local_u16Counter %4 == 0)
			{
				DIO_u8SetPinValue(STEPPER_u8PORT,STEPPER_u8BLUE,DIO_PIN_LOW);
				DIO_u8SetPinValue(STEPPER_u8PORT,STEPPER_u8PINK,DIO_PIN_HIGH);
				DIO_u8SetPinValue(STEPPER_u8PORT,STEPPER_u8YELLOW,DIO_PIN_HIGH);
				DIO_u8SetPinValue(STEPPER_u8PORT,STEPPER_u8ORANGE,DIO_PIN_HIGH);
				_delay_ms(STP_DELAY);
			}
			else if(Local_u16Counter %4 == 1)
			{
				DIO_u8SetPinValue(STEPPER_u8PORT,STEPPER_u8PINK,DIO_PIN_LOW);
				DIO_u8SetPinValue(STEPPER_u8PORT,STEPPER_u8BLUE,DIO_PIN_HIGH);
				DIO_u8SetPinValue(STEPPER_u8PORT,STEPPER_u8YELLOW,DIO_PIN_HIGH);
				DIO_u8SetPinValue(STEPPER_u8PORT,STEPPER_u8ORANGE,DIO_PIN_HIGH);
				_delay_ms(STP_DELAY);
			}
			else if(Local_u16Counter %4 == 2)
			{
				DIO_u8SetPinValue(STEPPER_u8PORT,STEPPER_u8YELLOW,DIO_PIN_LOW);
				DIO_u8SetPinValue(STEPPER_u8PORT,STEPPER_u8BLUE,DIO_PIN_HIGH);
				DIO_u8SetPinValue(STEPPER_u8PORT,STEPPER_u8PINK,DIO_PIN_HIGH);
				DIO_u8SetPinValue(STEPPER_u8PORT,STEPPER_u8ORANGE,DIO_PIN_HIGH);
				_delay_ms(STP_DELAY);
			}
			else if(Local_u16Counter %4 == 3)
			{
				DIO_u8SetPinValue(STEPPER_u8PORT,STEPPER_u8ORANGE,DIO_PIN_LOW);
				DIO_u8SetPinValue(STEPPER_u8PORT,STEPPER_u8BLUE,DIO_PIN_HIGH);
				DIO_u8SetPinValue(STEPPER_u8PORT,STEPPER_u8PINK,DIO_PIN_HIGH);
				DIO_u8SetPinValue(STEPPER_u8PORT,STEPPER_u8YELLOW,DIO_PIN_HIGH);
				_delay_ms(STP_DELAY);
			}

		}
	}
	else if(copy_u8Dir == STEPPER_DIR_CCW)
	{
		for(Local_u16Counter=0; Local_u16Counter <= Local_u16Steps; Local_u16Counter++)
		{
			if(Local_u16Counter % 4 == 0)
			{
				DIO_u8SetPinValue(STEPPER_u8PORT,STEPPER_u8ORANGE,DIO_PIN_LOW);
				DIO_u8SetPinValue(STEPPER_u8PORT,STEPPER_u8YELLOW,DIO_PIN_HIGH);
				DIO_u8SetPinValue(STEPPER_u8PORT,STEPPER_u8PINK,DIO_PIN_HIGH);
				DIO_u8SetPinValue(STEPPER_u8PORT,STEPPER_u8BLUE,DIO_PIN_HIGH);
				_delay_ms(STP_DELAY);

			}
			else if(Local_u16Counter % 4 == 1)
			{
				DIO_u8SetPinValue(STEPPER_u8PORT,STEPPER_u8YELLOW,DIO_PIN_LOW);
				DIO_u8SetPinValue(STEPPER_u8PORT,STEPPER_u8BLUE,DIO_PIN_HIGH);
				DIO_u8SetPinValue(STEPPER_u8PORT,STEPPER_u8PINK,DIO_PIN_HIGH);
				DIO_u8SetPinValue(STEPPER_u8PORT,STEPPER_u8ORANGE,DIO_PIN_HIGH);
				_delay_ms(STP_DELAY);
			}
			else if(Local_u16Counter % 4 == 2)
			{
				DIO_u8SetPinValue(STEPPER_u8PORT,STEPPER_u8PINK,DIO_PIN_LOW);
				DIO_u8SetPinValue(STEPPER_u8PORT,STEPPER_u8BLUE,DIO_PIN_HIGH);
				DIO_u8SetPinValue(STEPPER_u8PORT,STEPPER_u8YELLOW,DIO_PIN_HIGH);
				DIO_u8SetPinValue(STEPPER_u8PORT,STEPPER_u8ORANGE,DIO_PIN_HIGH);
				_delay_ms(STP_DELAY);
			}
			else if(Local_u16Counter % 4 == 3)
			{
				DIO_u8SetPinValue(STEPPER_u8PORT,STEPPER_u8BLUE,DIO_PIN_LOW);
				DIO_u8SetPinValue(STEPPER_u8PORT,STEPPER_u8ORANGE,DIO_PIN_HIGH);
				DIO_u8SetPinValue(STEPPER_u8PORT,STEPPER_u8YELLOW,DIO_PIN_HIGH);
				DIO_u8SetPinValue(STEPPER_u8PORT,STEPPER_u8PINK,DIO_PIN_HIGH);
				_delay_ms(STP_DELAY);
			}
		}
	}
	else
	{
		Local_u8ErrorState == NOK;
	}
	return Local_u8ErrorState;
}
