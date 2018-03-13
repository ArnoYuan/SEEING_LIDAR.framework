#include "Include.h"
#include "Initial.h"

int main(void)
{
#ifndef CONFIG_USING_RTOS
    scheduler_init();
#endif
    
    if(SeSystemInit()==SE_RETURN_OK)
    {
        SeNormalPrint("System Initial Success");
    }
    else
    {
        SeErrorPrint("System Initial Failuer!");
    }
#ifdef CONFIG_USING_RTOS
    osKernelStart();
#else
    scheduler_start();
    
    for(;;)
    {
        sch_dispatch_tasks();
    }

#endif
    
    return 0;
}