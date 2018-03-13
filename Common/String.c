#include "String.h"



#ifdef CONFIG_USING_PRINT

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>




#ifdef __GNUC__
/* With GCC/RAISONANCE, small printf (option LD Linker->Libraries->Small printf
   set to 'Yes') calls __io_fputchar() */
#define PUTCHAR_PROTOTYPE int __io_putchar(int ch)
#else
#define PUTCHAR_PROTOTYPE int fputc(int ch, FILE *f)
#endif /* __GNUC__ */

static SeStdioOperation* pSeStdio = SeNull;

int SeNormalPrint(SeConstString csFormat, ...)
{
    va_list vArgs;
    int ret;
    
    SeChar sPrintString[SE_BUFFER_SIZE_128]={0};
    
    va_start(vArgs, csFormat);
    ret = vsprintf(sPrintString, csFormat, vArgs);
    va_end(vArgs);
    
    if(ret>=0)
    {
        ret = printf(sPrintString);
        ret += printf("\r\n");
    }
    return ret;
}

#if CONFIG_LOG_LEVEL!=LOG_LEVEL_CLOSE
int SePrintLog(SeInt8 nlevel, const SeChar *fmt, ...)
{
    int ret = 0;
    va_list args;
    SeChar sPrintString[SE_BUFFER_SIZE_128]={0};
    
    va_start(args, fmt);
    ret = vsprintf(sPrintString, fmt, args);
    va_end(args);
    
    if(ret>=0)
    {
        switch(nLevel)
        {
        case LOG_LEVEL_ERROR:
            ret+=printf("\033[2m\033[31m[ERROR]\033[0m");
            break;
        case LOG_LEVEL_WARN:
            ret+=printf("\033[2m\033[33m[WARN]\033[0m");
            break;
        case LOG_LEVEL_INFO:
            ret+=printf("[INFO]");
            break;
        case LOG_LEVEL_DEBUG:
            ret+=printf("\033[2m\033[32m[DEBUG]\033[0m");
            break;
        }
        
        ret = printf(sPrintString);
        ret += printf("\r\n");
        
    }
    return ret;
}
#endif

SeInt8 SeStdConfig(SeStdioOperation* pStdio)
{
    if(pStdio == SeNull)
    {
        return SE_RETURN_ERROR;
    }

    pSeStdio = pStdio;

    if(pSeStdio->fpSeStdioInit() == SE_RETURN_ERROR)
    {

        return SE_RETURN_ERROR;
    }

    return SE_RETURN_OK;
}

SeChar SePutCh(SeChar cOut)
{
    if(pSeStdio->fpSeFputc != SeNull)
    {
        pSeStdio->fpSeFputc(cOut);
    }
    return (cOut);
}

SeChar SeGetCh(void)
{
    SeUInt8 bGetChar;

    if(pSeStdio->fpSeFgetc != SeNull)
    {
        pSeStdio->fpSeFgetc(&bGetChar);
    }

    return bGetChar;
}


PUTCHAR_PROTOTYPE
{
    SePutCh((SeChar)ch);
    return ch;
}

#endif