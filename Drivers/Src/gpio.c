/**
 * @file    gpio.c
 * @author  Antonio Vitor Grossi Bassi (antoniovitor.gb@gmail.com)
 * @brief   General Purpose Input/Output Drivers 
 * @version 0.1
 * @date    20-04-2025
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include <rcc.h>
#include <gpio.h>

/* Driver Functions */
static GPIO_Err_T GPIO_InitPin(GPIO_PortID_T PortID, GPIO_PinID_T PinID);
static GPIO_Err_T GPIO_TakePin(GPIO_Handle_T *hgpio, GPIO_PortID_T PortID, GPIO_PinID_T PinID);
static GPIO_Err_T GPIO_ReleasePin(GPIO_Handle_T *hgpio);

/* Driver Handle Functions */
static GPIO_Err_T GPIO_Config(GPIO_Config_T *Config);
static GPIO_Err_T GPIO_Toggle(void);
static GPIO_Err_T GPIO_Read(void);
static GPIO_Err_T GPIO_Write(u32 value);
static GPIO_Err_T GPIO_Lock(void);
static GPIO_Err_T GPIO_Reset(void);

static GPIO_Err_T GPIO_InitPin(GPIO_PortID_T PortID, GPIO_PinID_T PinID)
{
    if( ( PortID < GPIO_PORT_A ) || ( PortID > GPIO_PORT_H ) )  return EGPIO_INVPORT;
    if( ( PortID < GPIO_PIN_0 ) || ( PortID > GPIO_PIN_15 ) )   return EGPIO_INVPIN;
    

    
}