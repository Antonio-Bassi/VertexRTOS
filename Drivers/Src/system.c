/**
 * @file    systick.c
 * @author  Antonio Vitor Grossi Bassi (antoniovitor.gb@gmail.com)
 * @brief   System Tick Driver API
 * @version 0.1
 * @date    26-07-2025
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include <system.h>

static u32 SysTickFreq = 1UL;
static u32 SysTickIRPrio = 0UL;

static void SysTick_ConfigClkSrc(u32 clockSource)
{
    SysTick->CTRL &= (~SysTick_CTRL_CLKSOURCE_Msk);
    SysTick->CTRL |= (clockSource << SysTick_CTRL_CLKSOURCE_Pos) & SysTick_CTRL_CLKSOURCE_Msk;
    return;
}

static void SysTick_ConfigFreq(u32 TickFreq)
{

}

