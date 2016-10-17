#include "led_task.h"

//任务控制块
OS_TCB Led0TaskTCB;
//任务堆栈	
CPU_STK LED0_TASK_STK[LED0_STK_SIZE];

//led0任务函数
void led0_task(void *p_arg)
{
	OS_ERR err;
	p_arg = p_arg;
    printf("%s\r\n", __func__);
	while(1)
	{
		OSTimeDlyHMSM(0,0,0,800,OS_OPT_TIME_HMSM_STRICT,&err); //延时200ms
        printf("led\r\n");
	}
}
