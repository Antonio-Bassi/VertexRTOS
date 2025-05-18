/**
 * @file    gpio.h
 * @author  Antonio Vitor Grossi Bassi (antoniovitor.gb@gmail.com)
 * @brief   General Purpose Input/Output Driver header file.
 * @version 0.1
 * @date    20-04-2025
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#ifndef GPIO_H_
#define GPIO_H_

#include <stm32f4xx.h>
#include <main.h>

typedef enum gpio_err
{
    EGPIO_INVFN  = -5,
    EGPIO_INVPIN = -4,
    EGPIO_INVPORT = -3,
    EGPIO_INVARG = -2,
    EGPIO_BUSY = -1,
    EGPIO_OK = 0
} GPIO_Err_T;

typedef enum gpio_port_id
{
    GPIO_PORT_A,
    GPIO_PORT_B,
    GPIO_PORT_C,
    GPIO_PORT_D,
    GPIO_PORT_E,
    GPIO_PORT_H
}GPIO_PortID_T;

typedef enum gpio_pin_id
{
    GPIO_PIN_0,
    GPIO_PIN_1,
    GPIO_PIN_2,
    GPIO_PIN_3,
    GPIO_PIN_4,
    GPIO_PIN_5,
    GPIO_PIN_6,
    GPIO_PIN_7,
    GPIO_PIN_8,
    GPIO_PIN_9, 
    GPIO_PIN_10,
    GPIO_PIN_11,
    GPIO_PIN_12,
    GPIO_PIN_13,
    GPIO_PIN_14,
    GPIO_PIN_15,
}GPIO_PinID_T;

typedef union gpio_config
{
    struct gpio_config_bitfield
    {
        u32 Mode          : 2;
        u32 Drive         : 1;
        u32 Speed         : 2;
        u32 PullType      : 2;
        u32 AltFunction   : 4;
        u32 Reserved      : 24;
    }Bit;
    u32 Word;
}GPIO_Config_T;

typedef struct gpio_handle
{
    const GPIO_PortID_T PortID;
    const GPIO_PinID_T  PinID;
    const GPIO_Err_T    (*Config)(GPIO_Config_T *Config);
    const GPIO_Err_T    (*Toggle)(void);
    const GPIO_Err_T    (*Read)(void);
    const GPIO_Err_T    (*Write)(u32 Value);
    const GPIO_Err_T    (*Lock)(void);
    const GPIO_Err_T    (*Reset)(void);
}GPIO_Handle_T;

typedef struct gpio_driver
{
    const GPIO_Err_T    (*InitPin)(GPIO_PortID_T PortID, GPIO_PinID_T PinID);
    const GPIO_Err_T    (*TakePin)(GPIO_Handle_T *hgpio, GPIO_PortID_T PortID, GPIO_PinID_T PinID);
    const GPIO_Err_T    (*ReleasePin)(GPIO_Handle_T *hgpio);
}GPIO_Driver_T;

GPIO_Driver_T *GPIO_Driver;

#endif /* GPIO_H_ */
