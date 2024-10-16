#ifndef _KEY_H
#define _KEY_H

#include "main.h"
#include "ctrl.h"
// 定义按键引脚
#define KEY_A_PIN               GPIO_PIN_4
#define KEY_B_PIN               GPIO_PIN_0
#define KEY_C_PIN               GPIO_PIN_9  // 高电平触发
#define KEY_DAH_PIN             GPIO_PIN_14
#define KEY_DIT_PIN             GPIO_PIN_15
#define KEY_A_B_GPIO_PORT       GPIOA
#define KEY_C_GPIO_PORT         GPIOB
#define KEY_DAH_DIT_GPIO_PORT   GPIOC

#define KEY_NUM                 5

// 长按时长的宏定义
#define KEY_LONG_PRESS_TIME     100  // 20ms * 50 = 1s
#define KEY_PRESSED_LEVEL       0   // 按键被按下时的电平

// 按键事件列表
typedef enum _KEY_EventList_TypeDef 
{
    KEY_Event_Null          = 0x00, // 空闲
    KEY_Event_SingleClick   = 0x01, // 单击
    KEY_Event_LongPress     = 0x02  // 长按
} KEY_EventList_TypeDef;

// 按键引脚电平
typedef enum
{ 
    KEY_PinLevel_Low = 0,
    KEY_PinLevel_High
} KEY_PinLevel_TypeDef;

// 按键动作
typedef enum
{ 
    KEY_Action_Press = 0,
    KEY_Action_Release
} KEY_Action_TypeDef;

// 按键状态列表
typedef enum _KEY_StatusList_TypeDef 
{
    KEY_Status_Idle            = 0, // 空闲
    KEY_Status_Debounce,             // 消抖
    KEY_Status_ConfirmPress,         // 确认按下
    KEY_Status_ConfirmPressLong      // 确认长按
} KEY_StatusList_TypeDef;

// 按键配置信息结构体
typedef struct _KEY_Configure_TypeDef 
{
    uint16_t                        KEY_Count;                 // 按键长按时长计数
    KEY_Action_TypeDef              KEY_Action;                // 按键动作，按下或释放
    KEY_StatusList_TypeDef          KEY_Status;                // 按键状态
    KEY_EventList_TypeDef           KEY_Event;                 // 按键事件
    KEY_PinLevel_TypeDef            (*KEY_ReadPin_Fcn)(void);  // 读引脚电平函数
} KEY_Configure_TypeDef;


void KEY_ReadStateMachine(void);
#endif // _KEY_H
