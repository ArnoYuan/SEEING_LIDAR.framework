#include "Scheduler.h"

#if CONFIG_USE_RTOS!=1

#ifndef CONFIG_MAX_TASK_NUM
#define CONFIG_MAX_TASK_NUM    5
#endif

static task_t task_lists[CONFIG_MAX_TASK_NUM];
static SeUInt8 task_curr_index = 0;
static SeBool sch_is_ready = SeFalse;

SeInt8 sch_add(SeInt8 (*func)(void),
        const SeUInt16 delay,
        const SeUInt16 period)
{
    SeUInt8 index = 0;
    
    while(task_lists[index].func&&(index<CONFIG_MAX_TASK_NUM))
    {
        if(task_lists[index].func==func)
        break;
        index++;
    }
    if(CONFIG_MAX_TASK_NUM==index)
        return SE_RETURN_ERROR;
    task_lists[index].func = func;
    task_lists[index].delay = delay;
    task_lists[index].period = period;
    task_lists[index].run_me = 0;
    SeDebugPrint("add task[%d][period=%d,delay=%d] to scheduler.", index, period, delay);
    return index;
}

SeInt8 sch_delete(const SeUInt8 index)
{
    if(task_lists[index].func==SeNull)
       return SE_RETURN_ERROR;
    task_lists[index].func = SeNull;
    task_lists[index].period = 0;
    task_lists[index].delay = 0;
    task_lists[index].run_me = 0;
    return SE_RETURN_OK;
}

void sch_update(void)
{
    SeUInt8 index;
    task_t *task;
    for(index = 0;index<CONFIG_MAX_TASK_NUM;index++)
    {
        task = &task_lists[index];
        if(task->func)
        {
            if(0==task->delay)
            {
                task->run_me+=1;
                if(task->period)
                {
                    task->delay = task->period;
                }
            }
            else
            {
                task->delay--;
            }
        }
    }
}

void sch_dispatch_tasks(void)
{
    task_t *task;
    if(sch_is_ready==SeFalse)
        return;
    for(task_curr_index = 0;task_curr_index<CONFIG_MAX_TASK_NUM;task_curr_index++)
    {
        task = &task_lists[task_curr_index];
        if(task->run_me>0)
        {
            task->func();
            task->run_me--;
            if(task->period == 0)
                sch_delete(task_curr_index);
        }
    }
    
#ifdef CONFIG_USE_SCH_IDLE
    sch_idle_task();
#endif
}

void scheduler_start(void)
{
    sch_is_ready = SeTrue;
}

void scheduler_init(void)
{
    SeUInt8 index = 0;
    for(index = 0;index<CONFIG_MAX_TASK_NUM;index++)
    {
        sch_delete(index);
    }
}

#endif
