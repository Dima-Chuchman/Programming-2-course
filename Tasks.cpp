/*

Classwork(4) 27.09.2024

Tasks: 4.1 - 4.12

*/

#include <stdio.h>
#include <math.h>
#include <float.h>


//-----------------------> Task 4.1
double sin_n(double x, unsigned n) {

    double res, a;
    for (int i = 0; i < n; ++i) {
        a = sin(x);
        x = a;
    }
    return a;

}

void task1() {

    double x;
    unsigned n;
    scanf_s("%lf" "%u", &x, &n);
    printf("%.3lf\n", sin_n(x, n));
}


//-----------------------> Task 4.2
void task2() {
    int n, i = 1;
    scanf_s("%d", &n);
    printf("n! = ");
    while (i <= n) {
        printf("%d", i);
        ++i;
        if (i - 1 != n) {
            printf("*");
        }
    }
}


//-----------------------> Task 4.3
double poly_1(double x, int n) {
    double res = 1, a;
    while (n != 0) {
        a = pow(x, n);
        --n;
        res += a;

    }
    return res;
}

double poly_2(double x, double y, int n) {
    double res = 1, a;
    while (n != 0) {
        a = pow(x, 2 * n) * pow(y, n);
        --n;
        res += a;

    }
    return res;
}

void task3() {
    double x, y;
    int n;
    printf("polynomial_1: ");
    printf("%lf\n", poly_1(2, 3));
    printf("polynomial_2: ");
    printf("%lf\n", poly_2(1, 2, 4));
}


//-----------------------> Task 4.4
double poly(double x, int n) {

    double res = 0;
    while (n > 0) {
        res += n * pow(x, n);
        --n;
    }
    return res;
}

void task4() {

    double x;
    int n;
    printf("%lf\n", poly(3, 3));
}


//-----------------------> Task 4.5
unsigned double_factorial(unsigned n) {

    unsigned result = 1;
    if (n == 0) {
        return 1;
    }
    if (n % 2 == 1) {
        for (int i = 1; i <= n; i += 2) {
            result *= i;
        }
        return result;
    }
    else {
        for (int i = 2; i <= n; i += 2) {

            result *= i;
        }
        return result;
    }

}

void task5() {
    printf("%d\n", double_factorial(8));
}


//-----------------------> Task 4.6
double nested_sqrt(double n, int iterations) {

    double result = n;
    for (int i = 0; i < iterations; i++) {
        result = sqrt(3 * n + result);
    }
    return result;
}

void task6() {
    printf("sqrt: %f\n", nested_sqrt(5, 5));
}


//-----------------------> Task 4.7
long factorial(int n) {
    return n <= 1 ? 1 : n * factorial(n - 1);
}

double poly(float x, unsigned n) {

    float result = 1;
    if (x < 1 && x > -1) {
        while (n >= 1) {
            result += pow(x, n) / factorial(n);
            --n;
        }
    }
    else return 0;
    return result;

}

void task7() {
    printf("%lf", poly(0.5, 2));
}


//-----------------------> Task 4.8
int max_k(int m) {

    int k = 0;
    while (pow(4, k) <= m) {
        ++k;
    }
    return k - 1;
}
void task8() {
    printf("%d\n", max_k(256));
}


//-----------------------> Task 4.9
int min_r(int n) {

    int r = 0, a, res;
    a = n;
    for (int i = 0; i < a; i++) {
        if (pow(2, i) <= a) {
            r += 1;
        }

    }
    return r;
}
void task9() {
    int r;
    r = min_r(5);
    printf("%lf\n", pow(2, r));
}


//-----------------------> Task 4.10
void task10() {

    float a;
    int i = 0, b = 0;
    scanf_s("%f", &a);
    while (a != 0) {
        a /= 2;
        i += 1;
        b = 1 + a == 1 ? 1 : 0;
        if (b == 1) {
            break;
        }
    }
    printf("%.25lf\n", a);
}


//-----------------------> Task 4.11
double eps = 2 * DBL_EPSILON;

void task11() {

    int i = 0;
    double x, sum = 0;

    do {
        printf("a[%d] =", i++);
        scanf_s("%lf", &x);
        sum += x;

    } while (fabs(x) > eps);
    printf("sum = %lf\n", sum);
}


//-----------------------> Task 4.12
unsigned subfactorial() {

    unsigned n;
    double subfact = 1;
    printf("n = ");
    scanf_s("%u", &n);
    for (int i = 1; i <= n; i++) {
        subfact = subfact * i + pow(-1, i);
    }
    printf("!%u = %.0f\n", n, subfact);
    return 0;
}

void task12() {
    subfactorial();
}



int main() {

    //task1();
    //task2();
    //task3();
    //task4();
    //task5();
    //task6();
    //task7();
    //task8();
    //task9();
    //task10();
    //task11();
    task12();

}