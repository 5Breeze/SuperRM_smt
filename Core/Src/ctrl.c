#include "ctrl.h"
void CTL_SET_TX()
{
	HAL_GPIO_WritePin(CTL_GPIO_PORT, CTL_RX, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(CTL_GPIO_PORT, CTL_TX, GPIO_PIN_SET);
}
void CTL_SET_RX()
{
	HAL_GPIO_WritePin(CTL_GPIO_PORT, CTL_TX, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(CTL_GPIO_PORT, CTL_RX, GPIO_PIN_SET);
}
void CTL_SET_CL()
{
	HAL_GPIO_WritePin(CTL_GPIO_PORT, CTL_TX, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(CTL_GPIO_PORT, CTL_RX, GPIO_PIN_RESET);
}
void CTL_SET_BEEP(uint16_t val)
{
	__HAL_TIM_SetCompare(&htim2, TIM_CHANNEL_3, val);
}
void CTL_DAH()
{
	CTL_SET_TX();
	CTL_SET_BEEP(500);
	HAL_Delay(360);
	CTL_SET_BEEP(0);
	CTL_SET_RX();
}
void CTL_DIT()
{
	CTL_SET_TX();
	CTL_SET_BEEP(500);
	HAL_Delay(120);
	CTL_SET_BEEP(0);
	CTL_SET_RX();
}