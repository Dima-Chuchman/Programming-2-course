/*
Homework(3) 25.007.2024

Tasks: 3.8 ; 3.23(�).

Task 8:
	������ ��� ����������� 32-����� ����� �� ������� �� ���� �� 32-���� �����,
	���� ���� ������������ ����. � ���������� ������� ������� ��� �� �����������.
	��������� ��������� ������� ����� 32-����� �����.


*/

#include <stdio.h>
#include <math.h>
#include <Windows.h>

// ������� softExponential
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

// ������� softExponential
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

    long long int_max = 2147483647; // ����������� �������� 32-������ �����
    long long int_min = -2147483648; // ̳������� �������� 32-������ ����� 

    printf("������ ��� ����� ����� ����: ");
    scanf_s("%d, %d", &a, &b);

    long long sum = (long long)a + b;
    long long product = (long long)a * b;

    if (product > int_max || product < int_min) {
        printf("������������ � �������\n");
    }
    else {
        printf("�������� = %lld\n", product);
    }

    if (sum > int_max || sum < int_min) {
        printf("������������\n");
    }
    else {
        printf("��������� = %lld\n", sum);
    }
}

int main() {

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    double a, x;

    printf("������ �������� a: ");
    scanf_s("%lf", &a);
    printf("������ �������� x: ");
    scanf_s("%lf", &x);

    double result = softExponential(a, x);
    double derivative = derivativeSoftExponential(a, x);

    printf("softExponential(a, x) = %lf\n", result);
    printf("������� softExponential(a, x) = %lf\n", derivative);

    //task8();
}
