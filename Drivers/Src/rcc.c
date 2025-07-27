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
 * @brief   System Core Clock Variable, default value is 16 MHz during startup 
 *          which is the HSI Oscillator frequency.
 * 
 */
static u32 SystemCoreClock = 16000000UL;


/**
 * @brief   Default configuration used for configuring system clock.
 *          If a NULL pointer or an invalid configuration setting is 
 *          passed to @ref RCC_ConfigSystemClock, this configuration will be used.
 *          
 *          The default settings yields the following clock tree configuration:
 *          Eth. PTP Clock -> 100 MHz
 *          HCLK, AHB Bus and DMA -> 100 MHz
 *          Cortex Sys. Timer -> 100 MHz
 *          APB1 Bus -> 50 MHz
 *          APB1 Timers -> 100 MHz
 *          APB2 Bus -> 100 MHz
 *          APB2 Timers -> 100 MHz
 * 
 * @see @ref RCC_SysClk_Config_T
 * @see @ref RCC_ConfigSystemClock
 * 
 */
static const RCC_SysClk_Config_T RCC_DefaultConfig = 
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
};

/* Private Driver Methods */
static RCC_Err_T PrvRCC_ConfigHSE(RCC_SysClk_Config_T *Config)
{
    RCC_Err_T Err = ERCC_INVARG;
    if( NULL != Config )
    {
        SET_BIT(RCC->CR, RCC_CR_HSEON);

        /* Wait for HSE to be ready (6 Systen Clock Cycles Approx.) */


    }
    return Err;
}



/* Public Driver Methods */
static RCC_Err_T RCC_ConfigSystemClock(RCC_SysClk_Config_T *Config);

static RCC_Err_T RCC_ConfigSystemClock(RCC_SysClk_Config_T *Config)
{
    RCC_SysClk_Config_T* pConfig = &RCC_DefaultConfig;
    RCC_Err_T Err = ERCC_NOCLK;

    if( NULL != Config )
    {
        pConfig = Config;
    }

    switch( pConfig->ClockSource )
    {
        case RCC_CONFIG_SYSCLK_CLKSRC_HSI:
            break;
        case RCC_CONFIG_SYSCLK_CLKSRC_PLL:
            break;
        case RCC_CONFIG_SYSCLK_CLKSRC_HSE:
            SET_BIT(RCC->CR, RCC_CR_HSEON);
            if( 0U != READ_BIT(RCC->CR, RCC_CR_HSERDY) )
            {

            }
            break;
        case RCC_CONFIG_SYSCLK_CLKSRC_LSI:
            break;
        default:
            Err = ERCC_NOCLK;
            break;
    }

    return Err;
}




