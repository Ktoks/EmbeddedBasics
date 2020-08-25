/*
 * main.c
 *
 *  Created on: Jul 14, 2020
 *      Author: kacy
 */


#include<stdio.h>

void main(void) {
	char a,b,c,d,e,f;
	printf("Please enter 6 characters to be converted to ascii:");
	fflush(stdout);
	scanf("%c %c %c %c %c %c", &a, &b, &c, &d, &e, &f);
	printf("Here are your hex representations of the characters you entered:\n%d\n%d\n%d\n%d\n%d\n%d", a,b,c,d,e,f);
	fflush(stdout);
	while (getchar() != '\n') {

	}
	printf("\nPress enter to leave. Bai.\n");
	fflush(stdout);
	getchar();
}
