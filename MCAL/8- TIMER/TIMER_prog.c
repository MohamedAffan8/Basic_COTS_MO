#include "STD_TYPES.h"

#include "BIT_MATH.h"
#include "Err_Type.h"

#include "TIMER_interface.h"

#include "TIMER_prv.h"
#include "TIMER_cfg.h"

#include "TIMER_reg.h"


static uint16 TIMER_pu16DigResult = 0;
static void (*TIMER_pfFuncPtr[3])(void)= {NULL,NULL,NULL};
static uint8 TIMER_u8BusyFlag = IDLE;


void TIMER_voidInit(void)
{

	/*prescaler configuration setting */
	SET_BIT(TCCR0,TCCR0_CS00);
	CLR_BIT(TCCR0,TCCR0_CS01);
	SET_BIT(TCCR0,TCCR0_CS02);


	/*set Normal mode*/
	CLR_BIT(TCCR0,TCCR0_WGM00);
	CLR_BIT(TCCR0,TCCR0_WGM01);



	/*prescaler configuration setting */
	//TCCR0 &= PRESCALER_MASK; /*clear the prescaler bits*/
	//TCCR0 |= TIMER_u8PRESCALER;



	/*Enable overflow Interrupt */
	SET_BIT(TIMSK,TIMSK_TOIE0);

	TCNT0 = 0;


}

void TIMER_SetPreload(uint16 copy_u16Preload_Val)
{
	TIMER_pu16DigResult = copy_u16Preload_Val;

}

uint8 TIMER_u8CallBack(TIMER_IntNum_t copy_IntNum, void(*copy_pvFuncPtr)(void))
{
	uint8 Local_u8ErrorState = OK;

	if(copy_pvFuncPtr != NULL)
	{
		if((copy_IntNum>= TIMER0) && (copy_IntNum <=TIMER2))
		{
			TIMER_pfFuncPtr[copy_IntNum] = copy_pvFuncPtr;
		}
		else
		{
			Local_u8ErrorState = NOK;
		}
	}
	else
	{
		Local_u8ErrorState = NULL_PTR;
	}

	return Local_u8ErrorState;
}

/*TIMER conversion complete ISR*/
void __vector_11 (void)		__attribute__((signal));
void __vector_11 (void)
{


	/*invoke the callback notification function*/
	if(TIMER_pfFuncPtr[TIMER0]!= NULL)
	{
		TIMER_pfFuncPtr[TIMER0]();
	}
	else
	{
		/*do nothing*/
	}

}








/*set preload value*/
	//TCNT0 = (uint8)TIMER_pu16DigResult;
	/*TIMER interrupt disable*/
	//CLR_BIT(TIMSK,TIMSK_TOIE0);

	/*TIMER is now Idle*/
	//TIMER_u8BusyFlag = IDLE;
