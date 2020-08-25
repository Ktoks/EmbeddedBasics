/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Kacy Stocks
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 ******************************************************************************
 */

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

#include <stdint.h>
#include <stdio.h>

int main(void)
{
	uint32_t data = 0xB410;
	uint8_t output = (uint8_t)((data >> 9) & 0x003F);

	printf("This is your output: %d",output);

	for(;;);
}
