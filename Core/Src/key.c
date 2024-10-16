#include "key.h"

// 读取特定引脚的电平
static KEY_PinLevel_TypeDef KEY_ReadPin(GPIO_TypeDef* port, uint16_t pin) 
{
    return (KEY_PinLevel_TypeDef)HAL_GPIO_ReadPin(port, pin);
}

// 按键读取函数
static KEY_PinLevel_TypeDef KEY_ReadPinA(void) { return KEY_ReadPin(GPIOA, GPIO_PIN_4); }  // KeyA
static KEY_PinLevel_TypeDef KEY_ReadPinB(void) { return KEY_ReadPin(GPIOA, GPIO_PIN_0); }  // KeyB
static KEY_PinLevel_TypeDef KEY_ReadPinC(void) { return !KEY_ReadPin(GPIOB, GPIO_PIN_9); }  // KeyC
static KEY_PinLevel_TypeDef KEY_ReadPinDAH(void) { return KEY_ReadPin(GPIOC, GPIO_PIN_14); } // DAH
static KEY_PinLevel_TypeDef KEY_ReadPinDIT(void) { return KEY_ReadPin(GPIOC, GPIO_PIN_15); } // DIT

// 按键配置信息的全局结构体数组
KEY_Configure_TypeDef Keys[KEY_NUM] = {
    {0, KEY_Action_Release, KEY_Status_Idle, KEY_Event_Null, KEY_ReadPinA}, // KeyA
    {0, KEY_Action_Release, KEY_Status_Idle, KEY_Event_Null, KEY_ReadPinB}, // KeyB
    {0, KEY_Action_Release, KEY_Status_Idle, KEY_Event_Null, KEY_ReadPinC}, // KeyC
    {0, KEY_Action_Release, KEY_Status_Idle, KEY_Event_Null, KEY_ReadPinDAH}, // DAH
    {0, KEY_Action_Release, KEY_Status_Idle, KEY_Event_Null, KEY_ReadPinDIT}  // DIT
};

// 获取按键动作，保存到结构体
static void KEY_GetAction(KEY_Configure_TypeDef *key) 
{
    if (key->KEY_ReadPin_Fcn() == KEY_PRESSED_LEVEL) {
        key->KEY_Action = KEY_Action_Press;
    } else {
        key->KEY_Action = KEY_Action_Release;
    }
}

// 状态机读取按键状态
void KEY_ReadStateMachine(void)
{
    for (int i = 0; i < KEY_NUM; i++) {
        KEY_Configure_TypeDef *key = &Keys[i];
        KEY_GetAction(key);  // 更新当前按键的状态
        
        switch (key->KEY_Status) {
            case KEY_Status_Idle:
                if (key->KEY_Action == KEY_Action_Press) {
                    key->KEY_Status = KEY_Status_Debounce;
                    key->KEY_Event = KEY_Event_Null;
                }
								else
								{
									  key->KEY_Status = KEY_Status_Idle;
                    key->KEY_Event = KEY_Event_Null;
								}
                break;

            case KEY_Status_Debounce:
                if (key->KEY_Action == KEY_Action_Press) {
                    key->KEY_Status = KEY_Status_ConfirmPress;
                    key->KEY_Event = KEY_Event_Null;
                } else {
                    key->KEY_Status = KEY_Status_Idle;
                }
                break;

            case KEY_Status_ConfirmPress:
                if (key->KEY_Action == KEY_Action_Press) {
                    if (key->KEY_Count >= 70) {
                        key->KEY_Count = 0;
                        key->KEY_Status = KEY_Status_ConfirmPressLong;
                    } else {
                        key->KEY_Count++;
                    }
                } else {
                    key->KEY_Count = 0;
                    key->KEY_Status = KEY_Status_Idle;
                    key->KEY_Event = KEY_Event_SingleClick;
                }
                break;

            case KEY_Status_ConfirmPressLong:
                if (key->KEY_Action == KEY_Action_Press) {
									
                } else {
                    key->KEY_Status = KEY_Status_Idle;
                    key->KEY_Event = KEY_Event_LongPress;
                }
                break;

            default:
                break;
        }
    }
}
