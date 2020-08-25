/*
 * main.c
 *
 *  Created on: Aug 4, 2020
 *      Author: kstoc
 */


/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Kacy Stocks
 * @brief          : Main program body
 ******************************************************************************
 */

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

#include<stdint.h>
#include<stdio.h>

struct Packet{
	uint32_t crc		:2;
	uint32_t status		:1;
	uint32_t payload	:12;
	uint32_t bat		:3;
	uint32_t sensor		:3;
	uint32_t longAddr	:8;
	uint32_t shortAddr	:2;
	uint32_t addrMode	:1;
};

int main(void)
{
	uint32_t packetValue;
	printf("Enter a 32-bit packet value: ");
    scanf("%X", &packetValue);

    struct Packet packet;

	packet.crc = 		(uint8_t)	(packetValue & 0X3);
	packet.status = 	(uint8_t)	((packetValue >> 2) & 0X1);
	packet.payload = 	(uint16_t)	((packetValue >> 3) & 0XFFF);
	packet.bat = 		(uint8_t)	((packetValue >> 15)& 0X7);
	packet.sensor = 	(uint8_t)	((packetValue >> 18)& 0X7);
	packet.longAddr =	(uint16_t)	((packetValue >> 21)& 0XFF);
	packet.shortAddr =	(uint8_t)	((packetValue >> 29)& 0X3);
	packet.addrMode =	(uint8_t)	(packetValue >> 31);


    printf("CRC:          %#x\n", packet.crc);
    printf("Status:       %#x\n", packet.status);
    printf("Payload:      %#x\n", packet.payload);
    printf("Bat:          %#x\n", packet.bat);
    printf("Sensor:       %#x\n", packet.sensor);
    printf("LongAddress:  %#x\n", packet.longAddr);
    printf("ShortAddress: %#x\n", packet.shortAddr);
    printf("AddressMode:  %#x\n", packet.addrMode);

    printf("Size of struct: %I64u", sizeof(packet));
	fflush(stdout);


	while(getchar() != '\n');
	getchar();

	return 0;
}
