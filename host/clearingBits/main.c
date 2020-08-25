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
	fprint("Enter a number and I'll clear it's 4th, 5th, and 6th bits: ");
	scanf("%d", &num1);
	printf("Your number is: %d\n", (num1 &  ~0x90));
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

