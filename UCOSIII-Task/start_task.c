#include "start_task.h"
#include "led_task.h"

//������ƿ�
OS_TCB StartTaskTCB;
//�����ջ	
CPU_STK START_TASK_STK[START_STK_SIZE];

//���ȼ�0���жϷ������������� OS_IntQTask()
//���ȼ�1��ʱ�ӽ������� OS_TickTask()
//���ȼ�2����ʱ���� OS_TmrTask()
//���ȼ�OS_CFG_PRIO_MAX-2��ͳ������ OS_StatTask()
//���ȼ�OS_CFG_PRIO_MAX-1���������� OS_IdleTask()


//��ʼ������
void start_task(void *p_arg)
{
    OS_ERR err;
    CPU_SR_ALLOC();
    p_arg = p_arg;

    printf("1\r\n");
    CPU_Init();
#if OS_CFG_STAT_TASK_EN > 0u
    //OSStatTaskCPUUsageInit(&err);  	//ͳ������
#endif

#ifdef CPU_CFG_INT_DIS_MEAS_EN		//���ʹ���˲����жϹر�ʱ��
    CPU_IntDisMeasMaxCurReset();
#endif

    printf("3\r\n");
#if	OS_CFG_SCHED_ROUND_ROBIN_EN  //��ʹ��ʱ��Ƭ��ת��ʱ��
    //ʹ��ʱ��Ƭ��ת���ȹ���,ʱ��Ƭ����Ϊ1��ϵͳʱ�ӽ��ģ���1*5=5ms
    OSSchedRoundRobinCfg(DEF_ENABLED,1,&err);
#endif

    printf("4\r\n");
	OS_CRITICAL_ENTER();	//�����ٽ���
    printf("5\r\n");
	 
	OSTaskCreate((OS_TCB 	* )&Led0TaskTCB,		
			 (CPU_CHAR	* )"led0 task", 		
							 (OS_TASK_PTR )led0_task, 			
							 (void		* )0,					
							 (OS_PRIO	  )LED0_TASK_PRIO,     
							 (CPU_STK   * )&LED0_TASK_STK[0],	
							 (CPU_STK_SIZE)LED0_STK_SIZE/10,	
							 (CPU_STK_SIZE)LED0_STK_SIZE,		
							 (OS_MSG_QTY  )0,					
							 (OS_TICK	  )0,					
							 (void   	* )0,					
							 (OS_OPT      )OS_OPT_TASK_STK_CHK|OS_OPT_TASK_STK_CLR,
							 (OS_ERR 	* )&err);				
	
    printf("6\r\n");
	OS_TaskSuspend((OS_TCB*)&StartTaskTCB,&err);		//����ʼ����			
    printf("7\r\n");
								 
	OS_CRITICAL_EXIT();	//�����ٽ���
    printf("8\r\n");
}