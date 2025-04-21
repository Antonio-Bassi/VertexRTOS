/**
 * @file    main.h
 * @author  Antonio Vitor Grossi Bassi (antoniovitor.gb@gmail.com)
 * @brief   main program header file for type definitions and constants. 
 * @version 0.1
 * @date    19-04-2025
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#ifndef MAIN_H
#define MAIN_H

/** Reserved Data Type definitions */
typedef unsigned char       u8;
typedef unsigned short      u16;
typedef unsigned long       u32;
typedef unsigned long long  u64;

typedef signed char         s8;
typedef signed short        s16;
typedef signed long         s32;
typedef signed long long    s64;    

typedef float               f32;
typedef double              f64;

/**
 * @brief   XMM, YMM and ZMM registers software implementation:
 *          XMM - 128 bits.
 *          YMM - 256 bits.
 *          ZMM - 512 bits.
 *          All of the register are 32 bit aligned and aliased in bytes, words, long words, floats and doubles.
 */
typedef union soft_xmm
{
    u8  ByteAlias[16U];
    u32 WordAlias[8U];
    u64 DwordAlias[4U];
    f32 FloatAlias[4U];
    f64 DoubleAlias[2U];
}Soft_XMM_T;

typedef union soft_ymm
{
    u8  ByteAlias[32U];
    u32 WordAlias[16U];
    u64 DwordAlias[8U];
    f32 FloatAlias[8U];
    f64 DoubleAlias[4U];
}Soft_YMM_T;

typedef union soft_ymm
{
    u8  ByteAlias[64U];
    u32 WordAlias[32U];
    u64 DwordAlias[16U];
    f32 FloatAlias[16U];
    f64 DoubleAlias[8U];
}Soft_ZMM_T;


typedef enum syserror
{
    ESYSNULLPTR = -4,
    ESYSINVPTR  = -3,
    ESYSINVARG  = -2,
    ESYSBUSY    = -1,
    ESYSOK      = 0,
} SysError_T;

#endif /* MAIN_H */