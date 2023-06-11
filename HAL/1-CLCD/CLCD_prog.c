#include "STD_TYPES.h"
#include <util/delay.h>
#include "BIT_MATH.h"
#include "Err_Type.h"

#include "DIO_interface.h"

#include "CLCD_interface.h"
#include "CLCD_prv.h"
#include "CLCD_cfg.h"

#if CLCD_u8CONNECTION_MODE == FOUR_BIT
static void voidSetHalfDataPort(uint8 copy_u8FourBitData)
{
	DIO_u8SetPinValue(CLCD_u8DATA_PORT,CLCD_u8D4_PIN,GET_BIT(copy_u8FourBitData,0));
	DIO_u8SetPinValue(CLCD_u8DATA_PORT,CLCD_u8D5_PIN,GET_BIT(copy_u8FourBitData,1));
	DIO_u8SetPinValue(CLCD_u8DATA_PORT,CLCD_u8D6_PIN,GET_BIT(copy_u8FourBitData,2));
	DIO_u8SetPinValue(CLCD_u8DATA_PORT,CLCD_u8D7_PIN,GET_BIT(copy_u8FourBitData,3));
}
#endif

static void voidSendEnablePulse(void)
{
	DIO_u8SetPinValue(CLCD_u8CTRL_PORT,CLCD_u8E_PIN,DIO_PIN_HIGH);
		_delay_ms(2);
		DIO_u8SetPinValue(CLCD_u8CTRL_PORT,CLCD_u8E_PIN,DIO_PIN_LOW);
}

void CLCD_voidSendCommand(uint8 copy_u8Command)
{
	/*set RS pin to low for command*/
	DIO_u8SetPinValue(CLCD_u8CTRL_PORT,CLCD_u8RS_PIN,DIO_PIN_LOW);
	/*set RW pin to low for write*/
#if CLCD_u8READ_OPERATION_ENABLE == ENABLED
	DIO_u8SetPinValue(CLCD_u8CTRL_PORT,CLCD_u8RW_PIN,DIO_PIN_LOW);
#endif
	/*send the command*/
#if CLCD_u8CONNECTION_MODE == EIGHT_BIT
	DIO_u8SetPortValue(CLCD_u8DATA_PORT,copy_u8Command);
	/*send Enable pulse*/
	DIO_u8SetPinValue(CLCD_u8CTRL_PORT,CLCD_u8E_PIN,DIO_PIN_HIGH);
	_delay_ms(2);
	DIO_u8SetPinValue(CLCD_u8CTRL_PORT,CLCD_u8E_PIN,DIO_PIN_LOW);
#endif
#if CLCD_u8CONNECTION_MODE == FOUR_BIT

	/*send the higher 4bits of the command*/
	voidSetHalfDataPort(copy_u8Command >> 4u);
	/*send Enable pulse*/
	voidSendEnablePulse();

	/*send the lower 4bits of the command*/
	voidSetHalfDataPort(copy_u8Command);
	/*send Enable pulse*/
	voidSendEnablePulse();
#endif
	
}
void CLCD_voidSendData(uint8 copy_u8Data)
{
	/*set RS pin to low for data*/
	DIO_u8SetPinValue(CLCD_u8CTRL_PORT,CLCD_u8RS_PIN,DIO_PIN_HIGH);
	/*set RW pin to low for write*/
#if CLCD_u8READ_OPERATION_ENABLE == ENABLED
	DIO_u8SetPinValue(CLCD_u8CTRL_PORT,CLCD_u8RW_PIN,DIO_PIN_LOW);
#endif
	/*send the data*/
#if CLCD_u8CONNECTION_MODE == EIGHT_BIT
	DIO_u8SetPortValue(CLCD_u8DATA_PORT,copy_u8Data);
	/*send Enable pulse*/
	DIO_u8SetPinValue(CLCD_u8CTRL_PORT,CLCD_u8E_PIN,DIO_PIN_HIGH);
	_delay_ms(2);
	DIO_u8SetPinValue(CLCD_u8CTRL_PORT,CLCD_u8E_PIN,DIO_PIN_LOW);
#elif CLCD_u8CONNECTION_MODE == FOUR_BIT

	/*send the higher 4bits of the data*/
	voidSetHalfDataPort(copy_u8Data >> 4u);
	/*send Enable pulse*/
	voidSendEnablePulse();

	/*send the lower 4bits of the data*/
	voidSetHalfDataPort(copy_u8Data);
	/*send Enable pulse*/
	voidSendEnablePulse();
#endif

}
void CLCD_voidInit(void)
{
	/*1- wait for */
	_delay_ms(40);

	/*2- set commands*/
	/* lines, font size 5x7*/
#if CLCD_u8CONNECTION_MODE == EIGHT_BIT
	CLCD_voidSendCommand(0b00111100);
#elif CLCD_u8CONNECTION_MODE == FOUR_BIT
	voidSetHalfDataPort(0b0010);
	voidSendEnablePulse();
	voidSetHalfDataPort(0b0010);
	voidSendEnablePulse();
	voidSetHalfDataPort(0b1000);
	voidSendEnablePulse();
#endif
	/* Display on/off control: Display on, cursor off, blink cursor off*/
	CLCD_voidSendCommand(0b00001100);
	/* Display clear*/
	CLCD_voidSendCommand(1);
	
}
void CLCD_voidSendString(uint8* copy_u8String)
{
	uint8 Local_u8counter;
	for(Local_u8counter= 0;copy_u8String[Local_u8counter]!= '\0';Local_u8counter++)
	{
		CLCD_voidSendData(copy_u8String[Local_u8counter]);
	}

}

void CLCD_voidSendNumber(sint32 copy_s32Var)
{
	char Local_chNumber[10];
	uint8 Local_u8RightDigit, Local_u8Counter1=0;
	sint8 Local_s8Counter2;
	if(copy_s32Var == 0)
	{
		CLCD_voidSendData('0');
		return;
	}
	else if(copy_s32Var < 0)
	{

		CLCD_voidSendData('-');
		copy_s32Var *=(-1);
	}

	while(copy_s32Var)
	{
		Local_u8RightDigit = copy_s32Var % 10;
		copy_s32Var /= 10;
		Local_chNumber[Local_u8Counter1]= Local_u8RightDigit + '0';
		Local_u8Counter1++;
	}

	for(Local_s8Counter2 = (sint8) Local_u8Counter1 - 1; Local_s8Counter2 >= 0; Local_s8Counter2--)
	{
		CLCD_voidSendData(Local_chNumber[(uint8)Local_s8Counter2]);
	}
}

void CLCD_voidGoToXY(uint8 copy_u8XPos, uint8 copy_u8YPos)
{
	uint8 Local_u8DDRamAdd = (copy_u8YPos * 0x40u) + copy_u8XPos;
	SET_BIT(Local_u8DDRamAdd,7u);
	CLCD_voidSendCommand(Local_u8DDRamAdd);
}

uint8 CLCD_u8WriteSpecialCharacter(uint8 copy_u8PatternNumber, uint8 copy_u8PatternArr[], uint8 copy_u8XPos, uint8 copy_u8YPos)
{
	uint8 Local_u8ErrorStatus = OK;

	if(copy_u8PatternArr != NULL)
	{
		uint8 Local_u8CGRAMAdd = copy_u8PatternNumber * 8u;
		uint8 Local_u8Iterator;
		/*set bit 6 & clear bit7 for setting CGRAM Address*/
		SET_BIT(Local_u8CGRAMAdd ,6u);
		/*set CGRAM Address*/
		CLCD_voidSendCommand(Local_u8CGRAMAdd);
		for(Local_u8Iterator=0;Local_u8Iterator<8u;Local_u8Iterator++)
		{
			CLCD_voidSendData(copy_u8PatternArr[Local_u8Iterator]);

		}
		CLCD_voidGoToXY(copy_u8XPos,copy_u8YPos);

		CLCD_voidSendData(copy_u8PatternNumber);
	}
	else
	{
		Local_u8ErrorStatus = NULL_PTR;
	}
	return Local_u8ErrorStatus;
}
