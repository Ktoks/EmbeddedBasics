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



int main(void)
{
	uint32_t *pClockControlRegister = (uint32_t*)0x40023830;
	uint32_t *pPortDModeRegister = (uint32_t*)0x40020C00;
	uint32_t *pPortDOutRegister = (uint32_t*)0x40020C14;

	// enable the clock by setting the 3rd bit to be 1
	*pClockControlRegister |= 1 << 3;

	// clear the 24th and 25th bit positions
	*pPortDModeRegister &= ~(3 << 24);
	// turn on 24th bit position
	*pPortDModeRegister |= 1 << 24;

	// set the 12th bit of the output data register to turn on the led
	*pPortDOutRegister |= 1 << 12;

	for(;;);
}
