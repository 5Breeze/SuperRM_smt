#ifndef _CTRL_H
#define _CTRL_H

#include "main.h"

extern TIM_HandleTypeDef htim2;

// �������ţ��ߵ�ƽ��Ч
#define CTL_TX GPIO_PIN_9		
#define CTL_RX GPIO_PIN_7
#define CTL_GPIO_PORT GPIOA


void CTL_SET_TX(void);//���Ϳ���ʹ�ܺ���
void CTL_SET_RX(void);//���ܿ���ʹ�ܺ���
void CTL_SET_CL(void);//���÷���ͽ���
void CTL_SET_BEEP(uint16_t val);//����pwm���ֵ
void CTL_DAH(void);
void CTL_DIT(void);

#endif 
