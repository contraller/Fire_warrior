#include "motor.h"

char motor_order;

void motor_init()
{
	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_6,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB,GPIO_PIN_0,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_7,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB,GPIO_PIN_1,GPIO_PIN_RESET);
}

void motor_con(char order)
{
	if(order=='L')
	{
		HAL_GPIO_WritePin(GPIOA,GPIO_PIN_6,GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOB,GPIO_PIN_0,GPIO_PIN_SET);
	}
	else if(order == 'R')
	{
		HAL_GPIO_WritePin(GPIOA,GPIO_PIN_7,GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOB,GPIO_PIN_1,GPIO_PIN_RESET);
	}
	else if(order == 'T')
	{
		HAL_GPIO_WritePin(GPIOA,GPIO_PIN_7,GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOB,GPIO_PIN_1,GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOA,GPIO_PIN_6,GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOB,GPIO_PIN_0,GPIO_PIN_SET);
	}
	else if(order == 'B')
	{
		HAL_GPIO_WritePin(GPIOA,GPIO_PIN_7,GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOB,GPIO_PIN_1,GPIO_PIN_SET);
		
		HAL_GPIO_WritePin(GPIOA,GPIO_PIN_6,GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOB,GPIO_PIN_0,GPIO_PIN_RESET);
	}
	else if(order == 'N')
	{
		HAL_GPIO_WritePin(GPIOA,GPIO_PIN_6,GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOB,GPIO_PIN_0,GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOA,GPIO_PIN_7,GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOB,GPIO_PIN_1,GPIO_PIN_RESET);
	}
}

void beep_con(uint8_t state)
{
	if(state) HAL_GPIO_WritePin(GPIOA,GPIO_PIN_15,GPIO_PIN_SET);
	else HAL_GPIO_WritePin(GPIOA,GPIO_PIN_15,GPIO_PIN_RESET);
}

void led_init()
{
	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_11,GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_10,GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_9,GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_8,GPIO_PIN_SET);
}


uint8_t led_flag=0;
void led_con()
{
  if(led_slow) return;
	
	led_flag = 1-led_flag;
	if(HAL_GPIO_ReadPin(IN1_GPIO_Port,IN1_Pin))
	{
		HAL_GPIO_WritePin(GPIOA,GPIO_PIN_9,led_flag);
		HAL_GPIO_WritePin(LB_GPIO_Port,LB_Pin,led_flag);
		HAL_GPIO_WritePin(GPIOA,GPIO_PIN_11,GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOA,GPIO_PIN_10,GPIO_PIN_SET);
		
	}
	else if(HAL_GPIO_ReadPin(IN2_GPIO_Port,IN2_Pin))
	{
		HAL_GPIO_WritePin(R_GPIO_Port,R_Pin,led_flag);
		HAL_GPIO_WritePin(RB_GPIO_Port,RB_Pin,led_flag);
		HAL_GPIO_WritePin(GPIOA,GPIO_PIN_9,GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOA,GPIO_PIN_8,GPIO_PIN_SET);
	}
	else if(HAL_GPIO_ReadPin(IN3_GPIO_Port,IN3_Pin)|HAL_GPIO_ReadPin(IN4_GPIO_Port,IN4_Pin))
	{
		HAL_GPIO_WritePin(GPIOA,GPIO_PIN_11,GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOA,GPIO_PIN_10,GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOA,GPIO_PIN_9,GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOA,GPIO_PIN_8,GPIO_PIN_SET);
	}
}



void blue_order()
{
	if(HAL_GPIO_ReadPin(IN1_GPIO_Port,IN1_Pin))
	{
		motor_con('L');
	}		
	else if(HAL_GPIO_ReadPin(IN2_GPIO_Port,IN2_Pin)) 
	{
		motor_con('R');
	}
	else if(HAL_GPIO_ReadPin(IN3_GPIO_Port,IN3_Pin)) 
	{
		motor_con('T');
	}
	else if(HAL_GPIO_ReadPin(IN4_GPIO_Port,IN4_Pin))
	{
		motor_con('B');
	}		
  else
	{
		motor_con('N');
	}		
}

