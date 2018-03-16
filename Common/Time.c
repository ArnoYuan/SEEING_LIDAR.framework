#include "Time.h"


SeMillis SeTimeGetMilliSecond(void)
{
    SeMillis nMs = 0;
#if CONFIG_USING_RTOS==1
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
#if CONFIG_USING_RTOS==1
    osDelay(nMs);
#else
    SeDelayMs(nMs);
#endif
}



