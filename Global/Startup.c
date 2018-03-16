#include "Include.h"
#include "Initial.h"

int main(void)
{
#if CONFIG_USING_RTOS!=1
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
#if CONFIG_USING_RTOS==1
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