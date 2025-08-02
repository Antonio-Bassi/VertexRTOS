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
 * (+) category: hardware(critical), driver, kernel, application. 
 * (+) severity: critical, error, warning, info
 * (+) error code: code from respective enumerator type definition.
 * 
 */

typedef enum systick_err
{   
    ESYS_INVARG = -4,
    ESYS_INVPRIOGRP = -3,
    ESYS_INVSYSTKCLKSRC = -2,
    ESYS_INVSYSTKFREQ = -1,
    ESYS_OK = 0,
}System_Err_T;

typedef struct system_driver
{
    
    System_Err_T (*StartTicks)(void);
    System_Err_T (*StopTicks)(void);
    System_Err_T (*ResumeTicks)(void);
    System_Err_T (*UpdateFreq)(u32 TickFreq);
    void (*ConfigClockSrc)(u32 clockSource);
    void (*SysTickCount)(void)

}SysTick_Handler_T;


#endif /* SYSTICK_H_ */