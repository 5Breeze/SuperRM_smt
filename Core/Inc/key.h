#ifndef _KEY_H
#define _KEY_H

#include "main.h"
#include "ctrl.h"
// ���尴������
#define KEY_A_PIN               GPIO_PIN_4
#define KEY_B_PIN               GPIO_PIN_0
#define KEY_C_PIN               GPIO_PIN_9  // �ߵ�ƽ����
#define KEY_DAH_PIN             GPIO_PIN_14
#define KEY_DIT_PIN             GPIO_PIN_15
#define KEY_A_B_GPIO_PORT       GPIOA
#define KEY_C_GPIO_PORT         GPIOB
#define KEY_DAH_DIT_GPIO_PORT   GPIOC

#define KEY_NUM                 5

// ����ʱ���ĺ궨��
#define KEY_LONG_PRESS_TIME     100  // 20ms * 50 = 1s
#define KEY_PRESSED_LEVEL       0   // ����������ʱ�ĵ�ƽ

// �����¼��б�
typedef enum _KEY_EventList_TypeDef 
{
    KEY_Event_Null          = 0x00, // ����
    KEY_Event_SingleClick   = 0x01, // ����
    KEY_Event_LongPress     = 0x02  // ����
} KEY_EventList_TypeDef;

// �������ŵ�ƽ
typedef enum
{ 
    KEY_PinLevel_Low = 0,
    KEY_PinLevel_High
} KEY_PinLevel_TypeDef;

// ��������
typedef enum
{ 
    KEY_Action_Press = 0,
    KEY_Action_Release
} KEY_Action_TypeDef;

// ����״̬�б�
typedef enum _KEY_StatusList_TypeDef 
{
    KEY_Status_Idle            = 0, // ����
    KEY_Status_Debounce,             // ����
    KEY_Status_ConfirmPress,         // ȷ�ϰ���
    KEY_Status_ConfirmPressLong      // ȷ�ϳ���
} KEY_StatusList_TypeDef;

// ����������Ϣ�ṹ��
typedef struct _KEY_Configure_TypeDef 
{
    uint16_t                        KEY_Count;                 // ��������ʱ������
    KEY_Action_TypeDef              KEY_Action;                // �������������»��ͷ�
    KEY_StatusList_TypeDef          KEY_Status;                // ����״̬
    KEY_EventList_TypeDef           KEY_Event;                 // �����¼�
    KEY_PinLevel_TypeDef            (*KEY_ReadPin_Fcn)(void);  // �����ŵ�ƽ����
} KEY_Configure_TypeDef;


void KEY_ReadStateMachine(void);
#endif // _KEY_H
