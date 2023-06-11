#ifndef EXTI_INTERFACE_H
#define EXTI_INTERFACE_H




#define LOW_LEVEL				1U
#define ON_CHANGE				2U

#define FALLING_EDGE			3U
#define RISING_EDGE				4U



typedef enum
{
	INT0=0,
	INT1,
	INT2,
}EXTI_IntNum_t;

void EXTI_voidInit(void);
uint8 EXTI_u8SenseCtrl(uint8 copy_SenseCtrl, EXTI_IntNum_t copy_IntNum);

uint8 EXITI_u8IntEnable(EXTI_IntNum_t copy_IntNum);
uint8 EXITI_u8IntDisable(EXTI_IntNum_t copy_IntNum);

uint8 EXTI_u8CallBack(EXTI_IntNum_t copy_IntNum, void(*copy_pvFuncPtr)(void));

#endif
