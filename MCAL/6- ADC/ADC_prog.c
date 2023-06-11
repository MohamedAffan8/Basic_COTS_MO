#include "STD_TYPES.h"

#include "BIT_MATH.h"
#include "Err_Type.h"

#include "ADC_prv.h"
#include "ADC_cfg.h"

#include "ADC_reg.h"
#include "ADC_interface.h"

static uint16* ADC_pu16DigResult = NULL;
static void (*ADC_pvNotificationFunc)(void) = NULL;
static uint8 ADC_u8BusyFlag = IDLE;

void ADC_voidInit(void)
{
	/*reference selection at AVCC mode*/
	SET_BIT(ADMUX,ADMUX_REFS0);
	CLR_BIT(ADMUX,ADMUX_REFS1);

	/*prepare Left adjust*/
#if ADC_u8BRESOLUTION == EIGHT_BITS
	SET_BIT(ADMUX,ADMUX_ADLAR);
#elif ADC_u8BRESOLUTION == TEN_BITS
	CLR_BIT(ADMUX,ADMUX_ADLAR);
#else
#error "wrong ADC_u8BRESOLUTION configuration value"
#endif

	/*check on prescaler configuration setting */
	ADCSRA &= PRESCALER_MASK; /*clear the prescaler bits*/
	ADCSRA |= ADC_u8PRESCALER;

	/*Enable ADC */
	SET_BIT(ADCSRA,ADCSRA_ADEN);


}

uint8 ADC_u8GetChannelReadingSynch(ADC_Channel_t copy_u8Channel, uint16* copy_pu16DigResult)
{
	uint8 Local_u8ErrorState = OK;
	if(copy_pu16DigResult != NULL)
	{
		if(ADC_u8BusyFlag == IDLE)
		{
			uint32 Local_u32Counter=0u;

			ADC_u8BusyFlag = BUSY;
			/*SET the required channel */
			ADMUX &= CHANNEL_SELECTION_MASK;
			ADMUX |= copy_u8Channel;


			/*Start conversion */
			SET_BIT(ADCSRA,ADCSRA_ADSC);

			/*polling with blocking the flag */
			while((GET_BIT(ADCSRA,ADCSRA_ADIF)==0)&&(Local_u32Counter<ADC_u32TIMEOUT_COUNT))
			{
				Local_u32Counter++;
			}
			if(Local_u32Counter ==ADC_u32TIMEOUT_COUNT)
			{
				Local_u8ErrorState = TIMEOUT_ERR;
			}
			else
			{
				/*clear the flag */
				SET_BIT(ADCSRA,ADCSRA_ADIF);

			#if ADC_u8BRESOLUTION == EIGHT_BITS
				*copy_pu16DigResult= (uint16)ADCH;
			#elif ADC_u8BRESOLUTION == TEN_BITS
				*copy_pu16DigResult= ADC;
			#endif

				/**/
				ADC_u8BusyFlag= IDLE;
			}

		}
		else
		{
			Local_u8ErrorState = BUSY_ERR;
		}

	}
	else
	{
		Local_u8ErrorState =NULL_PTR;
	}

	return Local_u8ErrorState;
	
}

uint8 ADC_u8GetChannelReadingASynch(ADC_Channel_t copy_u8Channel, uint16* copy_pu16DigResult, void(*copy_puNotificationFunc)(void))
{
	uint8 Local_u8ErrorState = OK;
	if((copy_pu16DigResult != NULL)&&(copy_puNotificationFunc != NULL))
	{
		if(ADC_u8BusyFlag == IDLE)
		{
			/*ADC is now busy*/
			ADC_u8BusyFlag =BUSY;

			/*convert the Digital result & notification function into global variable*/
			ADC_pu16DigResult = copy_pu16DigResult;

			ADC_pvNotificationFunc= copy_puNotificationFunc;
			/*SET the required channel */
			ADMUX &= CHANNEL_SELECTION_MASK;
			ADMUX |= copy_u8Channel;


			/*Start conversion */
			SET_BIT(ADCSRA,ADCSRA_ADSC);

			/*enable ADC conversion complete interrupt*/
			SET_BIT(ADCSRA,ADCSRA_ADIE);
		}
		else
		{
			Local_u8ErrorState = BUSY_ERR;
		}

	}
	else
	{
		Local_u8ErrorState = NULL_PTR;
	}
	return Local_u8ErrorState;
}

/*ADC conversion complete ISR*/
void __vector_16 (void)		__attribute__((signal));
void __vector_16 (void)
{
#if ADC_u8BRESOLUTION == EIGHT_BITS
	*ADC_pu16DigResult = (uint16)ADCH;
#elif ADC_u8BRESOLUTION == TEN_BITS
	*ADC_pu16DigResult = ADC;
#endif

	/*ADC interrupt disable*/
	CLR_BIT(ADCSRA,ADCSRA_ADIE);

	/*ADC is now Idle*/
	ADC_u8BusyFlag = IDLE;

	/*invoke the callback notification function*/
	if(ADC_pvNotificationFunc != NULL)
	{
		ADC_pvNotificationFunc();
	}
	else
	{
		/*do nothing*/
	}
}
