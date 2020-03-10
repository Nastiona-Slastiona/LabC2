#include <malloc.h>
#include <math.h>
#include<stdio.h>
#define M_PI 3.14159265

int menu() {
	int m;
	printf("\n1.Enter complex number\n2.Output of complex numbers in algebraic form\n3.Output of complex numbers in exponential form\n4.Getting the conjugate of a complex number\n5.Raising a complex number to a positive integer power\n6.Information about the version and author of the program\n7.Exit\n");
	while (!scanf_s("%d", &m)) {
		printf("\nError.Please try again\n1.Enter complex number\n2.Output of complex numbers in algebraic form\n3.Output of complex numbers in exponential form\n4.Getting the conjugate of a complex number\n5.Raising a complex number to a positive integer power\n6.Information about the version and author of the program\n7.Exit\n");

		rewind(stdin);
	}
	return m;

}
int size = 0;
void enter(int* re, int* im) {
	if (size == 0) {
		size++;

		printf("\nEnter a complex numbers: ");
		while (!scanf_s("%d%d%*c", &re[size - 1], &im[size - 1])) {
			printf("\nEnter a complex numbers: ");
			rewind(stdin);

		}
	}
	else {


		size++;
		printf("\nEnter a complex numbers: ");
		while (!scanf_s("%d%d%*c", &re[size - 1], &im[size - 1])) {
			printf("\nEnter a complex numbers: ");
			rewind(stdin);

		}


	}


}
void show1(int* re, int* im) {

	if (size == 0) {
		printf("\nThere isn't any complex numbers\n");
	}
	else if (size == 1) {
		printf("\nComplex number : %d%+di", re[size - 1], im[size - 1]);
	}
	else {
		printf("\nShow all or some defined complex numbers? \n1.All\n2.Some of them\n");
		int choice;
		if (scanf_s("%d", &choice)) {
			switch (choice) {
			case 1:
				for (int i = 0; i < size; i++) {
					printf("\n%d) %d%+di", i + 1, re[i], im[i]);
				}
				break;
			case 2: printf("\nWhich one?\n");
				scanf_s("%d", &choice);
				printf("\n Complex number : %d%+di", re[choice - 1], im[choice - 1]);
				break;
			default: printf("\nThere is no such option\n"); break;
			}
		}
		else {
			printf("\nYou entered a wrong symbol\n");
		}

	}

}
void form(int* re, int* im, float* r, float* y) {

	r[size - 1] = sqrt(powl(re[size - 1], 2) + powl(im[size - 1], 2));
	if (re[size - 1] < 0 && im[size - 1]>0) {
		y[size - 1] = M_PI + atan(im[size - 1] / re[size - 1]);
	}
	else if (re[size - 1] < 0 && im[size - 1] < 0) {
		y[size - 1] = atan(im[size - 1] / re[size - 1]) - M_PI;
	}
	else {
		y[size - 1] = atan(im[size - 1] / re[size - 1]);
	}

}
void show2(int* re, int* im, float* r, float* y) {

	if (size == 0) {
		printf("\nThere isn't any complex numbers\n");
	}
	else if (size == 1) {

		form(re, im, r, y, size);
		printf("\nComplex number in exponential form : %f * (e^i*%f)", r[size - 1], y[size - 1]);
	}
	else {
		int choice;

		printf("\nShow all or some defined complex numbers? \n1.All\n2.Some of them\n");

		if (scanf_s("%d", &choice)) {
			switch (choice) {
			case 1: printf("\nComplex number in exponential form :");
				for (int i = 0; i < size; i++) {
					form(re, im, r, y, i + 1);
					printf("\n%f * (e^i*%f)", r[i], y[i]);

				}
				break;
			case 2: printf("\nWhich one?");
				scanf_s("%d", &choice);
				form(re, im, r, y, choice);
				printf("\nComplex number in exponential form : %f * (e^i*%f)", r[choice - 1], y[choice - 1]);
				break;
			default: printf("\nThere is no such option\n"); break;
			}

		}
		else {
			printf("\nYou entered a wrong symbol\n");
		}

	}



}
void conjugate(int* re, int* im) {
	if (size == 0) {
		printf("\nThere isn't any complex numbers\n");
	}
	else if (size == 1) {
		int im_conjugate = (-1) * im[size - 1];
		printf("\nConjugate complex number : %d%+di", re[size - 1], im_conjugate);
	}
	else {
		int* im_conjugate = (int*)malloc(size * sizeof(int));
		int choice;

		printf("\nShow all or some defined complex numbers? \n1.All\n2.Some of them\n");

		if (scanf_s("%d", &choice)) {
			switch (choice) {
			case 1: printf("\nConjugate complex number :");
				for (int i = 0; i < size; i++) {
					im_conjugate[i] = (-1) * im[i];
					printf("\n%d) %d%+di", i + 1, re[i], im_conjugate[i]);
				}
				break;
			case 2: printf("\nWhich one?");
				scanf_s("%d", &choice);
				im_conjugate[choice - 1] = (-1) * im[choice - 1];
				printf("%d%+di", re[choice - 1], im_conjugate[choice - 1]);
				break;
			default: printf("\nThere is no such option\n"); break;
			}

		}
		else {
			printf("\nYou entered a wrong symbol\n");
		}
	}
}
void powerr(int* re, int* im, int* r, int* y) {
	if (size == 0) {
		printf("\nThere isn't any complex numbers\n");
	}
	else if (size == 1) {
		int power;

		printf("\nTo what power should the number be raised ? \n");
		scanf_s("%d", &power);
		form(re, im, r, y, size);
		printf("\nComplex number in a positive integer power: %f*(%f+%fi)", powl(r[size - 1], power), cos(y[size - 1] * power), sin(y[size - 1] * power));

	}
	else {
		int choice;
		int power;

		printf("\nTo what power should the number be raised ? \n");
		scanf_s("%d", &power);
		form(re, im, r, y, size);

		printf("\nShow all or some defined complex numbers? \n1.All\n2.Some of them\n");

		if (scanf_s("%d", &choice)) {
			switch (choice) {
			case 1:
				printf("\nComplex number in a positive integer power:");
				for (int i = 0; i < size; i++) {
					printf("%d)% f* (% f + % fi)", i + 1, powl(r[i], power), cos(y[i] * power), sin(y[i] * power));
				}
				break;
			case 2: printf("\nWhich one?");
				scanf_s("%d", &choice);
				printf("\nComplex number in a positive integer power: %f*(%f+%fi)", powl(r[choice - 1], power), cos(y[choice - 1] * power), sin(y[choice - 1] * power));
				break;
			default:printf("\nThere is no such option\n"); break;
			}
		}
		else {
			printf("\nYou entered a wrong symbol\n");

		}


	}


}
void inf() {
	printf("\nAbout version : 1.0.0\nAuthor: Kruglaya Anastasiya Alekseevna :)\n");
}

int main()
{
	int* Re, * Im;
	float* r, * y;
	Re = (int*)malloc(size * sizeof(int));
	Im = (int*)malloc(size * sizeof(int));
	r = (float*)malloc(size * sizeof(float));
	y = (float*)malloc(size * sizeof(float));
	int  t = 1;
	while (t) {

		switch (menu()) {
		case 1:enter(Re, Im, size); break;
		case 2:show1(Re, Im, size); break;
		case 3:show2(Re, Im, r, y, size); break;
		case 4:conjugate(Re, Im, size); break;
		case 5:powerr(Re, Im, r, y, size); break;
		case 6:inf(); break;
		case 7:return 0;
		default:printf("\nThere is no such option\n");  break;
		}

	}
	free(Re);
	free(Im);
	free(r);
	free(y);
	return 0;
}

