#include "led_task.h"

//������ƿ�
OS_TCB Led0TaskTCB;
//�����ջ	
CPU_STK LED0_TASK_STK[LED0_STK_SIZE];

//led0������
void led0_task(void *p_arg)
{
	OS_ERR err;
	p_arg = p_arg;
    printf("%s\r\n", __func__);
	while(1)
	{
		OSTimeDlyHMSM(0,0,0,800,OS_OPT_TIME_HMSM_STRICT,&err); //��ʱ200ms
        printf("led\r\n");
	}
}
