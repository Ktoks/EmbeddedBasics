/*
 * main.c
 *
 *  Created on: Jul 17, 2020
 *      Author: kacy
 */
#include<stdint.h>
#include<stdio.h>
void wait_for_user_input();

int main(void) {

	int32_t num1, num2;
	printf("Enter 2 numbers to see their bits: ");
	fflush(stdout);
	scanf("%d %d", &num1, &num2);
	printf("bitwise AND(&): %d\n", (num1 & num2));
	printf("bitwise OR(|): %d\n", (num1 | num2));
	printf("bitwise XOR(^): %d\n", (num1 ^ num2));
	printf("bitwise NOT(~) of the first number: %d\n", (~num1));
	printf("bitwise NOT(~) of the second number: %d\n", (~num2));
	fflush(stdout);

	wait_for_user_input();
}

void wait_for_user_input(){
	printf("Press enter to exit this application. ");
	while(getchar() != '\n') {

	}
	getchar();
}
