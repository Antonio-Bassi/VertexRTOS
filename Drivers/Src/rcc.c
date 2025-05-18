/**
 * @file    rcc.c
 * @author  Antonio Vitor Grossi Bassi (antoniovitor.gb@gmail.com)
 * @brief   Reset and Clock Control Drivers 
 * @version 0.1
 * @date    23-02-2025
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include <rcc.h>

#define RCC_CONFIG_DEFAULT_HSITRIM_VALUE (1UL << 7U)

/**
 * @brief Default configuration used for configuring system clock.
 *        If a NULL pointer or an invalid configuration setting is 
 *        passed to @ref RCC_ConfigSystemClock, this configuration will be used.
 * 
 */
static const RCC_SysClk_Config_T RCC_DefaultConfig = 
{
    .Bit = 
    {
        .ClockSource        = RCC_CONFIG_SYSCLK_CLKSRC_PLL,
        .ExternalBypass     = false,
        .PLL_Source         = RCC_CONFIG_PLL_CLKSRC_HSE,
        .HSI_TrimValue      = RCC_CONFIG_DEFAULT_HSITRIM_VALUE,
        .PLL_Q_DivFactor    = 2U,
        .PLL_P_DivFactor    = RCC_CONFIG_PLL_P_2,
        .PLL_N_MulFactor    = 192U,
        .PLL_M_DivFactor    = 24U,
        .AHB_Prescaler      = RCC_CFGR_HPRE_DIV1
    }
};


static RCC_Err_T RCC_ConfigSystemClock(RCC_SysClk_Config_T *Config);


static RCC_Err_T RCC_ConfigSystemClock(RCC_SysClk_Config_T *Config)
{
    if( NULL == Config ) return ERCC_INVARG;


}




