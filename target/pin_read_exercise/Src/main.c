/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Kacy Stocks
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 *
 *
 ******************************************************************************
 */

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

#include <stdint.h>

int main(void)
{
	uint32_t volatile *pClockControlRegister = (uint32_t*)0x40023830;
	uint32_t volatile *pPortDModeRegister = (uint32_t*)0x40020C00;
	uint32_t volatile *pPortDOutRegister = (uint32_t*)0x40020C14;

	uint32_t volatile *pPortAModeRegister = (uint32_t*)0x40020000;
	uint32_t volatile *pPortAInRegister = (uint32_t*)0x40020010;

	// Clock: enable clock for A and D by setting 0th and 3rd bits to be 1 on AHB1ENR
	*pClockControlRegister |= 1 << 3;
	*pClockControlRegister |= 1 << 0;

	// D: configure PD12 as output
	*pPortDModeRegister &= ~(3 << 24);
	// turn on 24th bit position
	*pPortDModeRegister |= (1 << 24);

	// A: configuring PA0 for input
	*pPortAModeRegister &= ~(3 << 0);
	uint8_t volatile pinStatus;

	for(;;){
		pinStatus = (uint8_t)(*pPortAInRegister & 0x1);

		if (pinStatus)
		{

		*pPortDOutRegister |= (1 << 12);
		}
		else
		{
			*pPortDOutRegister &= ~(1 << 12);
		}
	}
}
