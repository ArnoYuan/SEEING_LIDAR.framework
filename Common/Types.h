#ifndef __TYPES_H__
#define __TYPES_H__


#ifdef __cplusplus
extern "C" {
#endif

/*
 * define basic variant types
 */
typedef signed char SeInt8;
typedef unsigned char SeUInt8;
typedef signed short SeInt16;
typedef unsigned short SeUInt16;
typedef signed long SeInt32;
typedef unsigned long SeUInt32;
typedef signed long long SeInt64;
typedef unsigned long long SeUInt64;
typedef float SeFloat;
typedef double SeDouble;
typedef char* SeString;
typedef char SeChar;
typedef const SeString SeConstString;
typedef SeUInt32 SeMillis;


#define SeNull ((void*)0)

#define SE_BIT(b)	(1<<(b))
#define SE_SET_BIT(x, b)		((x)|=(SE_BIT(b)))
#define SE_CLEAR_BIT(x, b)	((x)&=~(SE_BIT(b)))
#define SE_SET_BITS(x, bits)	((x)|=(bits))
#define SE_CLEAR_BITS(x, bits)	((x)~=(bits))
#define SE_TEST_BIT(x, b)		(((x)&(BIT(b)))?1:0)
#define SE_TEST_BITS(x, bits)		(((x)&(bits))?1:0)


typedef enum{
    SeFalse = 0,
    SeTrue = 1,
}SeBool;

typedef struct
{
    SeUInt64 iUtcSeconds;
    SeUInt64 iMicroSeconds;
}SeTimeValue;

/*
 * define function return value
 */
#define SE_RETURN_OK				1
#define SE_RETURN_ERROR				0
#define SE_RETURN_TIMEOUT			-1

/*
 * define data buffer common sizes
 */
#define SE_BUFFER_SIZE_8	8
#define SE_BUFFER_SIZE_16	16
#define SE_BUFFER_SIZE_32	32
#define SE_BUFFER_SIZE_64	64
#define SE_BUFFER_SIZE_128	128
#define SE_BUFFER_SIZE_256	256
#define SE_BUFFER_SIZE_512	512
#define SE_BUFFER_SIZE_1024	1024


#ifdef __cplusplus
}
#endif

#endif