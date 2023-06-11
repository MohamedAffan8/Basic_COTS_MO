#include "STD_TYPES.h"
#include "MAP.h"

sint32 MAP(sint32 InputRangeMin, sint32 InputRangeMax, sint32 OutputRangeMin, sint32 OutputrangeMax, sint32 InputValue)
{
	sint32 Local_s32OutputValue=0;
	
	Local_s32OutputValue = ((OutputrangeMax-OutputRangeMin)*(InputValue-InputRangeMin))/((InputRangeMax-InputRangeMin)+OutputRangeMin);
	
	return Local_s32OutputValue;
}
