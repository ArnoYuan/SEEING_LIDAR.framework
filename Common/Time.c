#include "Time.h"


SeMillis SeTimeGetMilliSecond(void)
{
    SeMillis nMs = 0;
#ifdef CONFIG_USING_RTOS
    portTickType tCount = xTaskGetTickCount();
    nMs = tCount;
#endif
    return nMs;
}

void SeDelayMs(SeMillis nMs)
{
    SeMillis jiffies = SeTimeGetMilliSecond();
    jiffies += nMs;
    while(SeTimeGetMilliSecond()<jiffies);
}

void SeSleepMs(SeMillis nMs)
{
#ifdef CONFIG_USING_RTOS
    
#else
    SeDelayMs(nMs);
#endif
}



