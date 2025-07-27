/**
 * @file    systick.h
 * @author  Antonio Vitor Grossi Bassi (antoniovitor.gb@gmail.com)
 * @brief   System Tick Driver API reference header.
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

#endif /* SYSTICK_H_ */