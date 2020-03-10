#include <stdio.h>
#include <math.h>


int fuct(int n) {
	if (n == 1) {
		return 1;
	}
	else {
		return n * fuct(n - 1);
	}
}
double teylor(float x, int n) {
	if (n == 1)
	{

		return x;
	}
	else {
		while (x > 6.2831852) {
			x =x-(2* 3.1415926);
		}

		int b = n - 1;
		int c = 2 * n - 1;
		double answer;
		answer = (powl(-1, b) * powl(x, c)) / fuct(2 * n - 1);
		return answer + teylor(x, n - 1);
		printf("\nError. Try again ");
	}
}
void check(int a) {
	if (a != 1 && a != 2) {
		printf("\nYou entered wrong symdol, try one more time please");
	}

}

int main()
{
	float x, e, left, right, difference;
	int n, choice, p = 1, r = 1;
	while (p) {

		printf("\nEnter E: ");


		while (!scanf_s("%f", &e)) {
			printf("\nError. Try again\nEnter E: ");
			rewind(stdin);
		}
		n = 1;
		printf("\nEnter x: ");
		while (!scanf_s("%f", &x)) {
			printf("\nError. Try again\nEnter x: ");
			rewind(stdin);
		}
		while (r) {

			left = sin(x);
			right = teylor(x, n);

			printf("\nleft part  = %f\nright part = %f\n\n", left, right);
			difference = right - left;
			difference = fabs(difference);

			if (difference < e) {
				printf("\nAnswer : %d\n\n\n", n);
				break;
			}
			n++;



		}
		break;


		printf("\nContinue? 1.Yes|2.No : ");
		scanf_s("%d", &choice);
		check(choice);
		if (choice == 1)
		{
			printf("\nEntered E : ");

		}
		else {
			p = 0;
		}



	}






	_getch();
}