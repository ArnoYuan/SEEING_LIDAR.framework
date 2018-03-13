#include "Initial.h"

extern SeInt8 SeUserDriverInit(void);
extern SeInt8 SeUserApplicationInit(void);

SeInt8 SeSystemInit(void)
{
    if(SeUserDriverInit()!=SE_RETURN_OK)
    {
        return SE_RETURN_ERROR;
    }
    
    if(SeUserApplicationInit()!=SE_RETURN_OK)
    {
        return SE_RETURN_ERROR;
    }
    
    return SE_RETURN_OK;
}