#ifndef __SCHEDULER_H__
#define __SCHEDULER_H__
#include "../Global/Include.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef SeInt8 task_id_t;


typedef struct _task{
    const char *name;
    SeUInt8 run_me;
    SeUInt16 period;
    SeUInt16 delay;
    void *args;
    SeInt8 (*func)(void);
}task_t;

SeInt8 sch_add(SeInt8 (*func)(void),
        const SeUInt16 delay,
        const SeUInt16 period);
SeInt8 sch_delete(const SeUInt8 index);
void sch_update(void);
void sch_dispatch_tasks(void);
void scheduler_init(void);
void sch_idle_task(void);

#ifdef __cplusplus
}
#endif

#endif
