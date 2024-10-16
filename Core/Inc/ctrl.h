#ifndef _CTRL_H
#define _CTRL_H

#include "main.h"

extern TIM_HandleTypeDef htim2;

// 定义引脚，高电平有效
#define CTL_TX GPIO_PIN_9		
#define CTL_RX GPIO_PIN_7
#define CTL_GPIO_PORT GPIOA


void CTL_SET_TX(void);//发送控制使能函数
void CTL_SET_RX(void);//接受控制使能函数
void CTL_SET_CL(void);//禁用发射和接收
void CTL_SET_BEEP(uint16_t val);//设置pwm输出值
void CTL_DAH(void);
void CTL_DIT(void);

#endif 
