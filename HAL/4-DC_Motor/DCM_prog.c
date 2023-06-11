#include "STD_TYPES.h"
#include <util/delay.h>
#include "BIT_MATH.h"
#include "Err_Type.h"

#include "DIO_interface.h"

#include "DCM_interface.h"
#include "DCM_prv.h"
#include "DCM_cfg.h"


void DCM_voidRotateCW(void)
{

	DIO_u8SetPinValue(DCM_u8PORT,DCM_u8PIN2,DIO_PIN_LOW);

	DIO_u8SetPinValue(DCM_u8PORT,DCM_u8PIN1,DIO_PIN_HIGH);
}

void DCM_voidRotateCCW(void)
{

	DIO_u8SetPinValue(DCM_u8PORT,DCM_u8PIN1,DIO_PIN_LOW);

	DIO_u8SetPinValue(DCM_u8PORT,DCM_u8PIN2,DIO_PIN_HIGH);
}

void DCM_voidStop(void)
{
	DIO_u8SetPinValue(DCM_u8PORT,DCM_u8PIN1,DIO_PIN_LOW);
	DIO_u8SetPinValue(DCM_u8PORT,DCM_u8PIN2,DIO_PIN_LOW);
}
