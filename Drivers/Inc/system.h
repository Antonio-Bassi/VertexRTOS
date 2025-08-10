/**
 * @file    system.h
 * @author  Antonio Vitor Grossi Bassi (antoniovitor.gb@gmail.com)
 * @brief   System Handler API.
 * @version 0.1
 * @date    26-07-2025
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#ifndef SYSTICK_H_
#define SYSTICK_H_

#include <stm32f4xx.h>
#include <core_cm4.h>
#include <rcc.h>
#include <main.h>

#define SYSTICK_1KHz_FREQ   (1UL)
#define SYSTICK_10KHz_FREQ  (10UL)
#define SYSTICK_100KHz_FREQ (100UL)
#define SYSTICK_DEFAUL_FREQ (SYSTICK_1KHz_FREQ)

#define SYSTICK_CLK_SRC_HCLK    (1UL)
#define SYSTICK_CLK_SRC_EXTCLK  (0UL)

/**
 * TODO: Codify system errors as a bit mask. use a 32bit bitmask in order to fit 
 * error description.
 * (+) category: hardware, driver, kernel, application.
 * (+) severity: critical, error, warning, info.
 * (+) issuer: entity that issued the error.
 * (+) error code: code from respective enumerator type definition.
 * 
 * Define bitmask distribution and implement macros to facilitate encoding of the errors.
 * 
 * Bits 3 downto 0: Category
 * Bits 7 downto 4: Severity
 * Bits 19 downto 8: Error Code
 * Bits 31 downto 20: Issuer
 */

#define SYSTEM_ERR_CODE_GET_CATEGORY(Err)   ((Err >> 0U) & 0xFUL)
#define SYSTEM_ERR_CODE_GET_SEVERITY(Err)   ((Err >> 4U) & 0xFUL)
#define SYSTEM_ERR_CODE_GET_ERROR(Err)      ((Err >> 8U) & 0x3FFUL)
#define SYSTEM_ERR_CODE_GET_ISSUER(Err)     ((Err >> 20U) & 0x3FFUL)

#define SYSTEM_ERR_BUILD_CODE(Err, Category, Severity, Error, Issuer) \
    Err = ((Category << 0U) | (Severity << 4U) | (Error << 8U) | (Issuer << 20U))

typedef enum sys_errcode_issuer_t
{
    SYSECI_HARDWARE = 0,
    SYSECI_DRIVER = 1,
    SYSECI_KERNEL = 2,
    SYSECI_APPLICATION = 3
}System_ErrCodeIssuer_T;

typedef enum sys_errcode_severity_t
{
    SYSECS_CRITICAL = 0,
    SYSECS_ERROR = 1,
    SYSECS_WARNING = 2,
    SYSECS_INFO = 3
}System_ErrCodeSeverity_T;

typedef enum systick_err
{   
    ESYS_INVARG = -4,
    ESYS_INVPRIOGRP = -3,
    ESYS_INVSYSTKCLKSRC = -2,
    ESYS_INVSYSTKFREQ = -1,
    ESYS_OK = 0,
}System_Err_T;

typedef void (*SYSTICK_HANDLER_CALLBACK_T)(void *pArg);

typedef struct systick_handle
{
    System_Err_T (*Start)(void);
    System_Err_T (*UpdateFreq)(u32 TickFreq);
    System_Err_T (*RegisterCallback)(SYSTICK_HANDLER_CALLBACK_T pCallback);
    void (*Stop)(void);
    void (*Resume)(void);
    void (*ConfigClockSrc)(u32 clockSource);
    void (*Count)(void);
}SysTick_Handle_T;

typedef struct syscore_handle
{
    /** TODO: Implement System Core API */
}SysCore_Handle_T;

/**
 * @brief The System handle encompasses critical services for kernel operations, hardware initialization,
 * clock tree configuration and management; System Tick configuration and Interrupt Configuration.
 * 
 */
typedef struct system_handle
{
    SysTick_Handle_T    *SystemTick;
    SysCore_Handle_T    *SystemCore; /** TODO: Implement System Core API. */
}System_Handle_T;

extern System_Handle_T *System;

#endif /* SYSTICK_H_*/