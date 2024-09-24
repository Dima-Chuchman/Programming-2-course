/*
Homework(3) 25.007.2024

Tasks: 3.8 ; 3.23(є).

Task 8:
	Введіть два натуральних 32-бітних числа та виведіть їх суму як 32-бітне число,
	якщо немає переповнення типу. В противному випадку виведіть про це повідомлення.
	Аналогічно підрахуйте добуток цілих 32-бітних чисел.


*/

#include <stdio.h>
#include <math.h>
#include <Windows.h>

// Функція softExponential
double softExponential(double a, double x) {

    if (a < 0) {
        return -log(1 - a * (x + a)) / a;
    }
    else if (a == 0) {
        return x;
    }
    else {  // a > 0
        return (exp(a * x) - 1) / a + a;
    }
}

// Похідна softExponential
double derivativeSoftExponential(double a, double x) {

    if (a < 0) {
        return 1 / (1 - a * (x + a));
    }
    else if (a == 0) {
        return 1;
    }
    else {  // a > 0
        return exp(a * x);
    }
}

void task8() {

    int a;
    int b;

    long long int_max = 2147483647; // Максимальне значення 32-бітного числа
    long long int_min = -2147483648; // Мінімальне значення 32-бітного числа 

    printf("Введіть два числа через кому: ");
    scanf_s("%d, %d", &a, &b);

    long long sum = (long long)a + b;
    long long product = (long long)a * b;

    if (product > int_max || product < int_min) {
        printf("Переповнення в множенні\n");
    }
    else {
        printf("Множення = %lld\n", product);
    }

    if (sum > int_max || sum < int_min) {
        printf("Переповнення\n");
    }
    else {
        printf("Додавання = %lld\n", sum);
    }
}

int main() {

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    double a, x;

    printf("Введіть значення a: ");
    scanf_s("%lf", &a);
    printf("Введіть значення x: ");
    scanf_s("%lf", &x);

    double result = softExponential(a, x);
    double derivative = derivativeSoftExponential(a, x);

    printf("softExponential(a, x) = %lf\n", result);
    printf("Похідна softExponential(a, x) = %lf\n", derivative);

    //task8();
}
