/*

Homework(4) 30.09.2024

Tasks: 4.18æ; 4.27º

æ) x(k) = ((-1)^k * x^(2k+1))/((2k+1)!)

*/


#include <stdio.h>
#include <math.h>


unsigned long long fact(int n) {

    unsigned long long result = 1;
    for (int i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}

double calculate_xk(int k, double x) {

    double num = (k % 2 == 0) ? 1 : -1;

    double power_x = 1;
    for (int i = 0; i < (2 * k + 1); i++) {
        power_x *= x;
    }

    unsigned long long fact_value = fact(2 * k + 1);

    return num * power_x / fact_value;
}

int task1() {

    double x;
    int k;

    printf("Enter x: ");
    scanf_s("%lf", &x);
    printf("Enter k: ");
    scanf_s("%d", &k);

    double result = calculate_xk(k, x);
    printf("x_%d = %.10lf\n", k, result);
    return 0;
}

double calculate_pi(double eps) {

    double pi = 0.0;
    double term = 1.0;
    int k = 0;

    while (fabs(term) > eps) {
        term = (pow(-1, k) / pow(16, k)) * (
            (8.0 / (8 * k + 2)) +
            (4.0 / (8 * k + 3)) +
            (4.0 / (8 * k + 4)) -
            (1.0 / (8 * k + 7))
            );

        pi += term;
        k++;
    }

    return pi * 2;
}

int task2() {

    double eps;

    printf("Enter epsilon: ");
    scanf_s("%lf", &eps);

    double pi = calculate_pi(eps);
    printf("Result %.10lf: %.10lf\n", eps, pi / 2);
    return 0;
}

int main() {

    task1();
    //task2();

}


/*  
    0.1 = 6.1010822511
    0.01 = 6.1042521437
    0.001 = 6.1041138528
*/