#include <stdio.h>
#include <math.h>


void task1() {

    double a, sum = 0, n = 1;
    int counter = 0;
    printf("enter a: ");
    scanf_s("%lf", &a);
    while (sum < a) {
        sum += 1.0 / n;
        ++n;
        ++counter;
    }
    printf("%lf\n", sum);
    printf("%d\n", counter);
}


int task2_a(int n) {

    unsigned long long F_0 = 0, F_1 = 1, F;
    int a;
    for (int i = 2; i < n; i++) {
        F = F_0 + F_1;
        F_0 = F_1;
        F_1 = F;
    }
    return F;

}


void task3() {

    unsigned n, a0, a, counter_of_steps, max_of_steps, number_with_max_steps;
    printf("Enter n: ");
    scanf_s("%d", &n);
    max_of_steps = 0;
    number_with_max_steps = 0;
    for (int i = 1; i < n; i++) {
        a0 = i;
        a = a0;
        counter_of_steps = 0;
        while (a != 1) {
            if (a % 2 == 0) {
                a = a / 2;
            }
            else {
                a = 3 * a + 1;
            }
            counter_of_steps++;
        }
        if (counter_of_steps > max_of_steps) {
            max_of_steps = counter_of_steps;
            number_with_max_steps = i;
        }
    }

    printf("Number with maximum steps: %d\n", number_with_max_steps);
    printf("Maximum steps: %d\n", max_of_steps);
}

//Обчислення факторіалу 
long long factorial(int n) {

    if (n == 0 || n == 1) return 1;
    long long fact = 1;
    for (int i = 2; i <= n; i++) {
        fact *= i;
    }
    return fact;
}


void task4_a() {

    int n;
    scanf_s("%d", &n);
    double P_n = 1.0;
    for (int i = 1; i <= n; i++) {
        P_n *= (1 + 1.0 / factorial(i));
    }
    printf("pn=%lf\n", P_n);
}


void task5() {

    int x_1 = -99, x_2 = -99, x_3 = -99, x_n, k = 3;
    while (1) {
        x_n = x_1 + x_3 + 100;
        x_2 = x_3;
        x_3 = x_n;
        k++;
        if (x_n > 0) {
            break;
        }
    }

}


void task6_a() {

    double b, b_n, n, denominator_, denominator_copy, fraction, result;
    scanf_s("%lf", &b);
    scanf_s("%lf", &n);
    denominator_ = (1 / b);
    for (int i = 0; i < n; i++) {
        denominator_copy = denominator_;
        fraction = 1 / (b + denominator_copy);
        denominator_ = fraction;
    }
    result = b + fraction;
    printf("%lf\n", result);
}


void task8_a() {

    double x = 0, eps, y, t;
    int i;
    printf("x = ");
    scanf_s("%lf", &x);
    do {
        printf("eps = ");
        scanf_s("%lf", &eps);
    } while (eps <= 0);
    t = 1;
    i = 1;
    y = t;
    while (t > eps) {
        t *= (x / i);
        i++;
        y += t;
        printf("y = %lf, %lf", y, exp(x));
    }
}

int main() {
    // task1();
    // task2_a();
    // task3();
    // task4_a();
    // task5();
    // task6_a();
    // task8_a();
}