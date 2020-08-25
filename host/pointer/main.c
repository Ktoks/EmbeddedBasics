/*
 * main.c
 *
 *  Created on: Jul 14, 2020
 *      Author: kstoc
 */

#include<stdio.h>

int main(void)
{

	char mychar = 100;
	printf("My char's value = %d\n", mychar);

	char* mypointer = &mychar;
	printf("My Char's address = %p\n", mypointer);

	char otherchar = *mypointer;
	printf("Other Char's value = %d\n", otherchar);

	*mypointer = 65;
	printf("My Char's new value = %d\n", mychar);

	fflush(stdout);
	getchar();
}
