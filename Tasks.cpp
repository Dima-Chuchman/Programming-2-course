/*

Homework 5	10.10.2024

Tasks: 5.12(a); 5.17(â).

*/

#include <stdio.h>
#include <math.h>



//-----------------------> Task 5.12(a)

void Task1() {
	
	int n;

	printf("Enter n: ");
	scanf_s("%d", &n);

	long long a1 = 0, a2 = 1, ak;
	long long sum = 0;

	for (int k = 1; k <= n; k++) {
		if (k == 1) {
			ak = a1;
		}
		else if (k == 2) {
			ak = a2;
		}
		else {
			ak = a2 + k + a1;
			a1 = a2;
			a2 = ak;
		}
	sum += pow(2, k) * ak;
	}
	printf("Sum S_%d = %lld\n", n, sum);
}

//-----------------------> Task 5.17(â)

long long factorial(int n) {
	long long fact = 1;
	for (int i = 1; i <= n; i++) {
		fact *= i;
	}
	return fact;
}

void Task2() {
	double x, epsilon;

	printf("Enter x: ");
	scanf_s("%lf", &x);

	printf("Enter epsilon: ");
	scanf_s("%lf", &epsilon);

	double sum = 0.0, term;
	int k = 0;
	int count = 0;

	do {
		term = (pow(x, 2 * k)) / (pow(2, k) * factorial(k));

		sum += term;

		count++;

		k++;
	} while (term >= epsilon);

	printf("Sum : %.10lf\n", sum);
	printf("Numbers of terms: %d\n", count);
}


int main() {

	//Task1();
	Task2();
}