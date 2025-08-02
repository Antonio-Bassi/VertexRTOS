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

#define NVIC_PRIORITYGROUP_0         0x00000007U /*!< 0 bits for pre-emption priority, 4 bits for subpriority */
#define NVIC_PRIORITYGROUP_1         0x00000006U /*!< 1 bits for pre-emption priority, 3 bits for subpriority */
#define NVIC_PRIORITYGROUP_2         0x00000005U /*!< 2 bits for pre-emption priority, 2 bits for subpriority */
#define NVIC_PRIORITYGROUP_3         0x00000004U /*!< 3 bits for pre-emption priority, 1 bits for subpriority */
#define NVIC_PRIORITYGROUP_4         0x00000003U /*!< 4 bits for pre-emption priority,  0 bits for subpriority */

static u32 SysTickFreq = SYSTICK_1KHz_FREQ;
static u32 SysTickIRPrio = (1UL << __NVIC_PRIO_BITS) - 1UL; /* This equates to 15UL */
static u32 SysTickCounter = 0UL;

/* SysTick Management Functions */
static void SysTick_ConfigClkSrc(u32 clockSource);
static void SysTick_Count(void);
static System_Err_T SysTick_UpdateFreq(u32 TickFreq);
static System_Err_T SysTick_StartTicks(void);
static System_Err_T SysTick_StopTicks(void);
static System_Err_T SysTick_ResumeTicks(void);


static void SysTick_ConfigClkSrc(u32 clockSource)
{
    SysTick->CTRL &= (~SysTick_CTRL_CLKSOURCE_Msk);
    SysTick->CTRL |= (clockSource << SysTick_CTRL_CLKSOURCE_Pos) & SysTick_CTRL_CLKSOURCE_Msk;
    return;
}


static void SysTick_Count(void)
{
    SysTickCounter++;
    return;
}


static System_Err_T SysTick_UpdateFreq(u32 TickFreq)
{
    System_Err_T Err = ESYS_OK;
    const u32 Temp  = SysTickFreq;
    u32 Ticks = 0UL;

    if( TickFreq != SysTickFreq )
    {
        SysTickFreq = TickFreq;
        Ticks = ( RCC_Driver->GetSystemCoreCLock() / ( 1000UL / SysTickFreq) );

        if( SysTick_Config(Ticks) )
        {
            /* Restore previous value and exit with error code */
            SysTickFreq = Temp;
            /* Update error code and exit */
            Err = ESYS_INVSYSTKFREQ;
        }
    }
    return Err;
}


static System_Err_T SysTick_StartTicks(void)
{
    System_Err_T Err = ESYS_INVSYSTKFREQ;
    const u32 Ticks = ( RCC_Driver->GetSystemCoreCLock() / ( 1000UL / SysTickFreq) );
    u32 PriorityGroup = 0UL;

    /* Update Priority Grouping Scheme in NVIC */
    NVIC_SetPriorityGrouping(NVIC_PRIORITYGROUP_4);

    /* Update System Tick Configuration */
    if( !SysTick_Config(Ticks) )
    {
        PriorityGroup = NVIC_GetPriorityGrouping();
        NVIC_SetPriority(SysTick_IRQn, NVIC_EncodePriority(PriorityGroup, SysTickIRPrio, 0U) );
        Err = ESYS_OK;
    }
    return Err;
}


static System_Err_T SystemCoreClockUpdate(const RCC_SysClk_Config_T *pConfig)
{
    
}