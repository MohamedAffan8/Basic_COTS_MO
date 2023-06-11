#ifndef TIMER_INTERFACE_H
#define TIMER_INTERFACE_H


typedef enum
{
	TIMER0=0,
	TIMER1,
	TIMER2,
}TIMER_IntNum_t;

void TIMER_voidInit(void);

uint8 TIMER_u8CallBack(TIMER_IntNum_t copy_IntNum, void(*copy_pvFuncPtr)(void));

void TIMER_SetPreload(uint16 copy_u16Preload_Val);

#endif
