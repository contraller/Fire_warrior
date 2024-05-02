#include "FireCon.h"
uint8_t fire_state=0;


uint8_t fire_get()
{
		if(HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_4)==0)
			return 1;
		else 
			return 0;
}

void water_con()//低电平导通
{
	fire_state = fire_get();
	/*
	if(fire_state)
		HAL_GPIO_WritePin(GPIOA,GPIO_PIN_6,GPIO_PIN_RESET);
	else
		HAL_GPIO_WritePin(GPIOA,GPIO_PIN_6,GPIO_PIN_SET);
	*/
	
	if(fire_state == 1)
		beep_con(1);
	else
		beep_con(0);
}



