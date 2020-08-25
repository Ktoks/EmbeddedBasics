/*
 * main.c
 *
 *  Created on: Jul 15, 2020
 *      Author: kstoc
 */
#include<stdio.h>

void mprint(char* some_char) {
	printf((char *)some_char);
	fflush(stdout);
}

int main(void) {
	mprint("Area calculation program\nCircle = c\nTriangle = t\nRectangle = r\nSquare = s\nTrapezoid = z\n");
	mprint("Enter code here: ");
	char choice = getchar();
	switch (choice){
	case 0:
		mprint("Sorry, you have to choose one...\nPress Enter to leave.\n");
		while (getchar() != '\n') {

		}
		getchar();
		break;
	case 'c':
		mprint("Enter radius: ");
		float radius;
		scanf("%f", &radius);
		(radius <= 0) ? mprint("Improper input...\n") : printf("The area of your circle is %0.2f.\n", (3.145926535 * (radius * radius)));
		break;
	case 't':
		mprint("Enter height, base width, and the length of one other side ");
		float theight, tbaseWidth, tside;
		scanf("%f %f %f", &theight, &tbaseWidth, &tside);
		((theight > 0) && (tbaseWidth > 0) && (tside > 0)) ? printf("Area of your triangle is %0.2f.\n", (theight * tbaseWidth) / 2) : mprint("Improper input or improper triangle...\n");
		break;
	case 'r':
		mprint("Enter height, and width: ");
		float rheight, rwidth;
		scanf("%f %f", &rheight, &rwidth);
		((rheight > 0) && (rwidth > 0)) ? printf("Area of your rectangle is: %0.2f.\n", (rheight * rwidth)) : mprint("Improper input or improper rectangle...\n");
		break;
	case 's':
		mprint("Enter width: ");
		float swidth;
		scanf("%f", &swidth);
		(swidth > 0) ? printf("Area of your square is: %0.2f.\n", (swidth * swidth)) : mprint("Improper input or improper square...\n");
		break;
	case 'z':
		mprint("Enter height, a and b: ");
		float zheight, a, b;
		scanf("%f %f %f", &zheight, &a, &b);
		((zheight > 0) && (a > 0) && (b > 0)) ? printf("Area of your trapezoid is: %0.2f.\n", ((a + b)/2) * zheight) : mprint("Improper input or improper trapezoid...\n");
		break;
	default:
		mprint("You entered an improper input...\n");
	}
	fflush(stdout);
}
