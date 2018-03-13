#ifndef __STRING_H__
#define __STRING_H__
#include "../Global/Include.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct{
    SeInt8 (*fpSeStdioInit)(void);
    SeInt8 (*fpSeFputc)(SeUInt8 bChar);
    SeInt8 (*fpSeFgetc)(SeUInt8 *bChar);
}SeStdioOperation;


#define LOG_LEVEL_CLOSE     0
#define LOG_LEVEL_ERROR     1
#define LOG_LEVEL_WARN      2
#define LOG_LEVEL_INFO   3
#define LOG_LEVEL_DEBUG     4

#ifndef CONFIG_USING_PRINT
#define SeErrorPrint(fmt,...)
#define SeWarnPrint(fmt,...)
#define SeInfoPrint(fmt,...)
#define SeDebugPrint(fmt,...)
#define SeNormalPrint(fmt, ...)
#elif CONSOLE_LOG_LEVEL==LOG_LEVEL_DEBUG
#define SeErrorPrint(fmt,...)   SeLogPrint(LOG_LEVEL_ERROR,fmt, ##__VA_ARGS__)
#define SeWarnPrint(fmt,...)  SeLogPrint(LOG_LEVEL_WARN, ##__VA_ARGS__)
#define SeInfoPrint(fmt,...)    SeLogPrint(LOG_LEVEL_INFO,fmt, ##__VA_ARGS__)
#define SeDebugPrint(fmt,...) SeLogPrint(LOG_LEVEL_DEBUG,fmt, ##__VA_ARGS__)
#elif CONSOLE_LOG_LEVEL==LOG_LEVEL_INFO
#define SeErrorPrint(fmt,...)   SeLogPrint(LOG_LEVEL_ERROR,fmt, ##__VA_ARGS__)
#define SeWarnPrint(fmt,...)  SeLogPrint(LOG_LEVEL_WARN, ##__VA_ARGS__)
#define SeInfoPrint(fmt,...)    SeLogPrint(LOG_LEVEL_MESSAGE,fmt, ##__VA_ARGS__)
#define SeDebugPrint(fmt,...)
#elif CONSOLE_LOG_LEVEL==LOG_LEVEL_WARN
#define SeErrorPrint(fmt,...)   SeLogPrint(LOG_LEVEL_ERROR,fmt, ##__VA_ARGS__)
#define SeWarnPrint(fmt,...)  SeLogPrint(LOG_LEVEL_WARN, fmt, ##__VA_ARGS__)
#define SeInfoPrint(fmt,...)
#define SeDebugPrint(fmt,...)
#elif CONSOLE_LOG_LEVEL==LOG_LEVEL_ERROR
#define SeErrorPrint(fmt,...)   SeLogPrint(LOG_LEVEL_ERROR,fmt, ##__VA_ARGS__)
#define SeWarnPrint(fmt,...)
#define SeInfoPrint(fmt,...)
#define SeDebugPrint(fmt,...)
#elif CONSOLE_LOG_LEVEL==LOG_LEVEL_CLOSE
#define SeErrorPrint(fmt,...)
#define SeWarnPrint(fmt,...)
#define SeInfoPrint(fmt,...)
#define SeDebugPrint(fmt,...)
#endif

#ifdef CONFIG_USING_PRINT
int SeNormalPrint(SeConstString csFormat, ...);
#endif
int SePrintLog(SeInt8 nlevel, const SeChar *fmt, ...);
SeInt8 SeStdConfig(SeStdioOperation* pStdio);
SeChar SePutCh(SeChar cOut);
SeChar SeGetCh(void);
#ifdef __cplusplus
}
#endif


#endif