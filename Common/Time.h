#ifndef __TIME_H__
#define __TIME_H__
#include "../Global/Include.h"

#ifdef __cplusplus
extern "C" {
#endif


SeMillis SeTimeGetMilliSecond(void);
void SeDelayMs(SeMillis nMs);
void SeSleepMs(SeMillis nMs);

#ifdef __cplusplus
}
#endif
#endif