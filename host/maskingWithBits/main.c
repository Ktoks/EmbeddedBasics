/*
 * main.c
 *
 *  Created on: Jul 17, 2020
 *      Author: kacy
 */
#include<stdint.h>
#include<stdio.h>
void wait_for_user_input();
void fprint(char*);

int main(void) {

	int32_t num1;
	fprint("Enter a number and I'll figure out if it's even or odd with masking: ");
	scanf("%d", &num1);
	(num1 & 1) ? fprint("Your number is odd.\n"): fprint("Your number is even.\n");
	wait_for_user_input();
}

void wait_for_user_input(){
	fprint("Press enter to exit this application. ");
	while(getchar() != '\n') {

	}
	getchar();
}

void fprint(char* some_string){
	printf(some_string);
	fflush(stdout);
}

