#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "Err_Type.h"

#include "DIO_interface.h"

#include "SSD_interface.h"
#include "SSD_prv.h"
#include "SSD_cfg.h"

#include <util/delay.h>

uint8 SSD_u8DisplayDigit(sint8 copy_s8Digit, uint8 copy_u8SSDNum)
{
	uint8 Local_u8ErrorState = OK;
	
	static uint8 Local_u8SSDArr[SSD_u8ARR_SIZE] = SSD_u8DIGIT_ARR;

	if((copy_s8Digit >=0)&&(copy_s8Digit < 10))
	{
#if SSD_NO == ONE_SSD

		/*init Com for SSD 1*/
		DIO_u8SetPinValue(SSD_u8COM,SSD_u8C6_PIN,DIO_PIN_HIGH);
		DIO_u8SetPinValue(SSD_u8COM,SSD_u8C7_PIN,DIO_PIN_LOW);
		switch(copy_s8Digit)
		{
			case 0:
				DIO_u8SetPinValue(SSD_u8DIGIT_PORT,SSD_u8A1_PIN,GET_BIT(Local_u8SSDArr[0],0));
				DIO_u8SetPinValue(SSD_u8DIGIT_PORT,SSD_u8A2_PIN,GET_BIT(Local_u8SSDArr[0],1));
				DIO_u8SetPinValue(SSD_u8DIGIT_PORT,SSD_u8A3_PIN,GET_BIT(Local_u8SSDArr[0],2));
				DIO_u8SetPinValue(SSD_u8DIGIT_PORT,SSD_u8A4_PIN,GET_BIT(Local_u8SSDArr[0],3));
				DIO_u8SetPinValue(SSD_u8DIGIT_PORT,SSD_u8A5_PIN,GET_BIT(Local_u8SSDArr[0],4));
				DIO_u8SetPinValue(SSD_u8DIGIT_PORT,SSD_u8A6_PIN,GET_BIT(Local_u8SSDArr[0],5));
				DIO_u8SetPinValue(SSD_u8DIGIT_PORT,SSD_u8A7_PIN,GET_BIT(Local_u8SSDArr[0],6));
				break;
			case 1:
				DIO_u8SetPinValue(DIO_PORTA,DIO_PIN1,GET_BIT(Local_u8SSDArr[1],0));
				DIO_u8SetPinValue(DIO_PORTA,DIO_PIN2,GET_BIT(Local_u8SSDArr[1],1));
				DIO_u8SetPinValue(DIO_PORTA,DIO_PIN3,GET_BIT(Local_u8SSDArr[1],2));
				DIO_u8SetPinValue(DIO_PORTA,DIO_PIN4,GET_BIT(Local_u8SSDArr[1],3));
				DIO_u8SetPinValue(DIO_PORTA,DIO_PIN5,GET_BIT(Local_u8SSDArr[1],4));
				DIO_u8SetPinValue(DIO_PORTA,DIO_PIN6,GET_BIT(Local_u8SSDArr[1],5));
				DIO_u8SetPinValue(DIO_PORTA,DIO_PIN7,GET_BIT(Local_u8SSDArr[1],6));
				break;
			case 2:
				DIO_u8SetPinValue(DIO_PORTA,DIO_PIN1,GET_BIT(Local_u8SSDArr[2],0));
				DIO_u8SetPinValue(DIO_PORTA,DIO_PIN2,GET_BIT(Local_u8SSDArr[2],1));
				DIO_u8SetPinValue(DIO_PORTA,DIO_PIN3,GET_BIT(Local_u8SSDArr[2],2));
				DIO_u8SetPinValue(DIO_PORTA,DIO_PIN4,GET_BIT(Local_u8SSDArr[2],3));
				DIO_u8SetPinValue(DIO_PORTA,DIO_PIN5,GET_BIT(Local_u8SSDArr[2],4));
				DIO_u8SetPinValue(DIO_PORTA,DIO_PIN6,GET_BIT(Local_u8SSDArr[2],5));
				DIO_u8SetPinValue(DIO_PORTA,DIO_PIN7,GET_BIT(Local_u8SSDArr[2],6));
				break;

			case 3:
				DIO_u8SetPinValue(DIO_PORTA,DIO_PIN1,GET_BIT(Local_u8SSDArr[3],0));
				DIO_u8SetPinValue(DIO_PORTA,DIO_PIN2,GET_BIT(Local_u8SSDArr[3],1));
				DIO_u8SetPinValue(DIO_PORTA,DIO_PIN3,GET_BIT(Local_u8SSDArr[3],2));
				DIO_u8SetPinValue(DIO_PORTA,DIO_PIN4,GET_BIT(Local_u8SSDArr[3],3));
				DIO_u8SetPinValue(DIO_PORTA,DIO_PIN5,GET_BIT(Local_u8SSDArr[3],4));
				DIO_u8SetPinValue(DIO_PORTA,DIO_PIN6,GET_BIT(Local_u8SSDArr[3],5));
				DIO_u8SetPinValue(DIO_PORTA,DIO_PIN7,GET_BIT(Local_u8SSDArr[3],6));
				break;
			case 4:
				DIO_u8SetPinValue(DIO_PORTA,DIO_PIN1,GET_BIT(Local_u8SSDArr[4],0));
				DIO_u8SetPinValue(DIO_PORTA,DIO_PIN2,GET_BIT(Local_u8SSDArr[4],1));
				DIO_u8SetPinValue(DIO_PORTA,DIO_PIN3,GET_BIT(Local_u8SSDArr[4],2));
				DIO_u8SetPinValue(DIO_PORTA,DIO_PIN4,GET_BIT(Local_u8SSDArr[4],3));
				DIO_u8SetPinValue(DIO_PORTA,DIO_PIN5,GET_BIT(Local_u8SSDArr[4],4));
				DIO_u8SetPinValue(DIO_PORTA,DIO_PIN6,GET_BIT(Local_u8SSDArr[4],5));
				DIO_u8SetPinValue(DIO_PORTA,DIO_PIN7,GET_BIT(Local_u8SSDArr[4],6));
				break;
			case 5:
				DIO_u8SetPinValue(DIO_PORTA,DIO_PIN1,GET_BIT(Local_u8SSDArr[5],0));
				DIO_u8SetPinValue(DIO_PORTA,DIO_PIN2,GET_BIT(Local_u8SSDArr[5],1));
				DIO_u8SetPinValue(DIO_PORTA,DIO_PIN3,GET_BIT(Local_u8SSDArr[5],2));
				DIO_u8SetPinValue(DIO_PORTA,DIO_PIN4,GET_BIT(Local_u8SSDArr[5],3));
				DIO_u8SetPinValue(DIO_PORTA,DIO_PIN5,GET_BIT(Local_u8SSDArr[5],4));
				DIO_u8SetPinValue(DIO_PORTA,DIO_PIN6,GET_BIT(Local_u8SSDArr[5],5));
				DIO_u8SetPinValue(DIO_PORTA,DIO_PIN7,GET_BIT(Local_u8SSDArr[5],6));
				break;
			case 6:
				DIO_u8SetPinValue(DIO_PORTA,DIO_PIN1,GET_BIT(Local_u8SSDArr[6],0));
				DIO_u8SetPinValue(DIO_PORTA,DIO_PIN2,GET_BIT(Local_u8SSDArr[6],1));
				DIO_u8SetPinValue(DIO_PORTA,DIO_PIN3,GET_BIT(Local_u8SSDArr[6],2));
				DIO_u8SetPinValue(DIO_PORTA,DIO_PIN4,GET_BIT(Local_u8SSDArr[6],3));
				DIO_u8SetPinValue(DIO_PORTA,DIO_PIN5,GET_BIT(Local_u8SSDArr[6],4));
				DIO_u8SetPinValue(DIO_PORTA,DIO_PIN6,GET_BIT(Local_u8SSDArr[6],5));
				DIO_u8SetPinValue(DIO_PORTA,DIO_PIN7,GET_BIT(Local_u8SSDArr[6],6));
				break;

			case 7:
				DIO_u8SetPinValue(DIO_PORTA,DIO_PIN1,GET_BIT(Local_u8SSDArr[7],0));
				DIO_u8SetPinValue(DIO_PORTA,DIO_PIN2,GET_BIT(Local_u8SSDArr[7],1));
				DIO_u8SetPinValue(DIO_PORTA,DIO_PIN3,GET_BIT(Local_u8SSDArr[7],2));
				DIO_u8SetPinValue(DIO_PORTA,DIO_PIN4,GET_BIT(Local_u8SSDArr[7],3));
				DIO_u8SetPinValue(DIO_PORTA,DIO_PIN5,GET_BIT(Local_u8SSDArr[7],4));
				DIO_u8SetPinValue(DIO_PORTA,DIO_PIN6,GET_BIT(Local_u8SSDArr[7],5));
				DIO_u8SetPinValue(DIO_PORTA,DIO_PIN7,GET_BIT(Local_u8SSDArr[7],6));
				break;
			case 8:
				DIO_u8SetPinValue(DIO_PORTA,DIO_PIN1,GET_BIT(Local_u8SSDArr[8],0));
				DIO_u8SetPinValue(DIO_PORTA,DIO_PIN2,GET_BIT(Local_u8SSDArr[8],1));
				DIO_u8SetPinValue(DIO_PORTA,DIO_PIN3,GET_BIT(Local_u8SSDArr[8],2));
				DIO_u8SetPinValue(DIO_PORTA,DIO_PIN4,GET_BIT(Local_u8SSDArr[8],3));
				DIO_u8SetPinValue(DIO_PORTA,DIO_PIN5,GET_BIT(Local_u8SSDArr[8],4));
				DIO_u8SetPinValue(DIO_PORTA,DIO_PIN6,GET_BIT(Local_u8SSDArr[8],5));
				DIO_u8SetPinValue(DIO_PORTA,DIO_PIN7,GET_BIT(Local_u8SSDArr[8],6));
				break;
			case 9:
				DIO_u8SetPinValue(DIO_PORTA,DIO_PIN1,GET_BIT(Local_u8SSDArr[9],0));
				DIO_u8SetPinValue(DIO_PORTA,DIO_PIN2,GET_BIT(Local_u8SSDArr[9],1));
				DIO_u8SetPinValue(DIO_PORTA,DIO_PIN3,GET_BIT(Local_u8SSDArr[9],2));
				DIO_u8SetPinValue(DIO_PORTA,DIO_PIN4,GET_BIT(Local_u8SSDArr[9],3));
				DIO_u8SetPinValue(DIO_PORTA,DIO_PIN5,GET_BIT(Local_u8SSDArr[9],4));
				DIO_u8SetPinValue(DIO_PORTA,DIO_PIN6,GET_BIT(Local_u8SSDArr[9],5));
				DIO_u8SetPinValue(DIO_PORTA,DIO_PIN7,GET_BIT(Local_u8SSDArr[9],6));
				break;
			default:
				Local_u8ErrorState = NOK;
				break;
		}
		_delay_ms(10);
#elif SSD_NO ==TWO_SSD
		if(copy_u8SSDNum == FIRST_SSD)
		{
			DIO_u8SetPinValue(SSD_u8COM,SSD_u8C6_PIN,DIO_PIN_HIGH);
			DIO_u8SetPinValue(SSD_u8COM,SSD_u8C7_PIN,DIO_PIN_LOW);
		}
		else if(copy_u8SSDNum == SECOND_SSD)
		{
			DIO_u8SetPinValue(SSD_u8COM,SSD_u8C6_PIN,DIO_PIN_LOW);
			DIO_u8SetPinValue(SSD_u8COM,SSD_u8C7_PIN,DIO_PIN_HIGH);
		}

		switch(copy_s8Digit)
		{
			case 0:
				DIO_u8SetPinValue(SSD_u8DIGIT_PORT,SSD_u8A1_PIN,GET_BIT(Local_u8SSDArr[0],0));
				DIO_u8SetPinValue(SSD_u8DIGIT_PORT,SSD_u8A2_PIN,GET_BIT(Local_u8SSDArr[0],1));
				DIO_u8SetPinValue(SSD_u8DIGIT_PORT,SSD_u8A3_PIN,GET_BIT(Local_u8SSDArr[0],2));
				DIO_u8SetPinValue(SSD_u8DIGIT_PORT,SSD_u8A4_PIN,GET_BIT(Local_u8SSDArr[0],3));
				DIO_u8SetPinValue(SSD_u8DIGIT_PORT,SSD_u8A5_PIN,GET_BIT(Local_u8SSDArr[0],4));
				DIO_u8SetPinValue(SSD_u8DIGIT_PORT,SSD_u8A6_PIN,GET_BIT(Local_u8SSDArr[0],5));
				DIO_u8SetPinValue(SSD_u8DIGIT_PORT,SSD_u8A7_PIN,GET_BIT(Local_u8SSDArr[0],6));
				break;
			case 1:
				DIO_u8SetPinValue(DIO_PORTA,DIO_PIN1,GET_BIT(Local_u8SSDArr[1],0));
				DIO_u8SetPinValue(DIO_PORTA,DIO_PIN2,GET_BIT(Local_u8SSDArr[1],1));
				DIO_u8SetPinValue(DIO_PORTA,DIO_PIN3,GET_BIT(Local_u8SSDArr[1],2));
				DIO_u8SetPinValue(DIO_PORTA,DIO_PIN4,GET_BIT(Local_u8SSDArr[1],3));
				DIO_u8SetPinValue(DIO_PORTA,DIO_PIN5,GET_BIT(Local_u8SSDArr[1],4));
				DIO_u8SetPinValue(DIO_PORTA,DIO_PIN6,GET_BIT(Local_u8SSDArr[1],5));
				DIO_u8SetPinValue(DIO_PORTA,DIO_PIN7,GET_BIT(Local_u8SSDArr[1],6));
				break;
			case 2:
				DIO_u8SetPinValue(DIO_PORTA,DIO_PIN1,GET_BIT(Local_u8SSDArr[2],0));
				DIO_u8SetPinValue(DIO_PORTA,DIO_PIN2,GET_BIT(Local_u8SSDArr[2],1));
				DIO_u8SetPinValue(DIO_PORTA,DIO_PIN3,GET_BIT(Local_u8SSDArr[2],2));
				DIO_u8SetPinValue(DIO_PORTA,DIO_PIN4,GET_BIT(Local_u8SSDArr[2],3));
				DIO_u8SetPinValue(DIO_PORTA,DIO_PIN5,GET_BIT(Local_u8SSDArr[2],4));
				DIO_u8SetPinValue(DIO_PORTA,DIO_PIN6,GET_BIT(Local_u8SSDArr[2],5));
				DIO_u8SetPinValue(DIO_PORTA,DIO_PIN7,GET_BIT(Local_u8SSDArr[2],6));
				break;

			case 3:
				DIO_u8SetPinValue(DIO_PORTA,DIO_PIN1,GET_BIT(Local_u8SSDArr[3],0));
				DIO_u8SetPinValue(DIO_PORTA,DIO_PIN2,GET_BIT(Local_u8SSDArr[3],1));
				DIO_u8SetPinValue(DIO_PORTA,DIO_PIN3,GET_BIT(Local_u8SSDArr[3],2));
				DIO_u8SetPinValue(DIO_PORTA,DIO_PIN4,GET_BIT(Local_u8SSDArr[3],3));
				DIO_u8SetPinValue(DIO_PORTA,DIO_PIN5,GET_BIT(Local_u8SSDArr[3],4));
				DIO_u8SetPinValue(DIO_PORTA,DIO_PIN6,GET_BIT(Local_u8SSDArr[3],5));
				DIO_u8SetPinValue(DIO_PORTA,DIO_PIN7,GET_BIT(Local_u8SSDArr[3],6));
				break;
			case 4:
				DIO_u8SetPinValue(DIO_PORTA,DIO_PIN1,GET_BIT(Local_u8SSDArr[4],0));
				DIO_u8SetPinValue(DIO_PORTA,DIO_PIN2,GET_BIT(Local_u8SSDArr[4],1));
				DIO_u8SetPinValue(DIO_PORTA,DIO_PIN3,GET_BIT(Local_u8SSDArr[4],2));
				DIO_u8SetPinValue(DIO_PORTA,DIO_PIN4,GET_BIT(Local_u8SSDArr[4],3));
				DIO_u8SetPinValue(DIO_PORTA,DIO_PIN5,GET_BIT(Local_u8SSDArr[4],4));
				DIO_u8SetPinValue(DIO_PORTA,DIO_PIN6,GET_BIT(Local_u8SSDArr[4],5));
				DIO_u8SetPinValue(DIO_PORTA,DIO_PIN7,GET_BIT(Local_u8SSDArr[4],6));
				break;
			case 5:
				DIO_u8SetPinValue(DIO_PORTA,DIO_PIN1,GET_BIT(Local_u8SSDArr[5],0));
				DIO_u8SetPinValue(DIO_PORTA,DIO_PIN2,GET_BIT(Local_u8SSDArr[5],1));
				DIO_u8SetPinValue(DIO_PORTA,DIO_PIN3,GET_BIT(Local_u8SSDArr[5],2));
				DIO_u8SetPinValue(DIO_PORTA,DIO_PIN4,GET_BIT(Local_u8SSDArr[5],3));
				DIO_u8SetPinValue(DIO_PORTA,DIO_PIN5,GET_BIT(Local_u8SSDArr[5],4));
				DIO_u8SetPinValue(DIO_PORTA,DIO_PIN6,GET_BIT(Local_u8SSDArr[5],5));
				DIO_u8SetPinValue(DIO_PORTA,DIO_PIN7,GET_BIT(Local_u8SSDArr[5],6));
				break;
			case 6:
				DIO_u8SetPinValue(DIO_PORTA,DIO_PIN1,GET_BIT(Local_u8SSDArr[6],0));
				DIO_u8SetPinValue(DIO_PORTA,DIO_PIN2,GET_BIT(Local_u8SSDArr[6],1));
				DIO_u8SetPinValue(DIO_PORTA,DIO_PIN3,GET_BIT(Local_u8SSDArr[6],2));
				DIO_u8SetPinValue(DIO_PORTA,DIO_PIN4,GET_BIT(Local_u8SSDArr[6],3));
				DIO_u8SetPinValue(DIO_PORTA,DIO_PIN5,GET_BIT(Local_u8SSDArr[6],4));
				DIO_u8SetPinValue(DIO_PORTA,DIO_PIN6,GET_BIT(Local_u8SSDArr[6],5));
				DIO_u8SetPinValue(DIO_PORTA,DIO_PIN7,GET_BIT(Local_u8SSDArr[6],6));
				break;

			case 7:
				DIO_u8SetPinValue(DIO_PORTA,DIO_PIN1,GET_BIT(Local_u8SSDArr[7],0));
				DIO_u8SetPinValue(DIO_PORTA,DIO_PIN2,GET_BIT(Local_u8SSDArr[7],1));
				DIO_u8SetPinValue(DIO_PORTA,DIO_PIN3,GET_BIT(Local_u8SSDArr[7],2));
				DIO_u8SetPinValue(DIO_PORTA,DIO_PIN4,GET_BIT(Local_u8SSDArr[7],3));
				DIO_u8SetPinValue(DIO_PORTA,DIO_PIN5,GET_BIT(Local_u8SSDArr[7],4));
				DIO_u8SetPinValue(DIO_PORTA,DIO_PIN6,GET_BIT(Local_u8SSDArr[7],5));
				DIO_u8SetPinValue(DIO_PORTA,DIO_PIN7,GET_BIT(Local_u8SSDArr[7],6));
				break;
			case 8:
				DIO_u8SetPinValue(DIO_PORTA,DIO_PIN1,GET_BIT(Local_u8SSDArr[8],0));
				DIO_u8SetPinValue(DIO_PORTA,DIO_PIN2,GET_BIT(Local_u8SSDArr[8],1));
				DIO_u8SetPinValue(DIO_PORTA,DIO_PIN3,GET_BIT(Local_u8SSDArr[8],2));
				DIO_u8SetPinValue(DIO_PORTA,DIO_PIN4,GET_BIT(Local_u8SSDArr[8],3));
				DIO_u8SetPinValue(DIO_PORTA,DIO_PIN5,GET_BIT(Local_u8SSDArr[8],4));
				DIO_u8SetPinValue(DIO_PORTA,DIO_PIN6,GET_BIT(Local_u8SSDArr[8],5));
				DIO_u8SetPinValue(DIO_PORTA,DIO_PIN7,GET_BIT(Local_u8SSDArr[8],6));
				break;
			case 9:
				DIO_u8SetPinValue(DIO_PORTA,DIO_PIN1,GET_BIT(Local_u8SSDArr[9],0));
				DIO_u8SetPinValue(DIO_PORTA,DIO_PIN2,GET_BIT(Local_u8SSDArr[9],1));
				DIO_u8SetPinValue(DIO_PORTA,DIO_PIN3,GET_BIT(Local_u8SSDArr[9],2));
				DIO_u8SetPinValue(DIO_PORTA,DIO_PIN4,GET_BIT(Local_u8SSDArr[9],3));
				DIO_u8SetPinValue(DIO_PORTA,DIO_PIN5,GET_BIT(Local_u8SSDArr[9],4));
				DIO_u8SetPinValue(DIO_PORTA,DIO_PIN6,GET_BIT(Local_u8SSDArr[9],5));
				DIO_u8SetPinValue(DIO_PORTA,DIO_PIN7,GET_BIT(Local_u8SSDArr[9],6));
				break;
			default:
				Local_u8ErrorState = NOK;
				break;
		}
		_delay_ms(10);
#endif
	}
	else
	{
		Local_u8ErrorState = NOK;
	}
	return Local_u8ErrorState;

}
