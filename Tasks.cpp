/*
Classwork 17-09-2024

Tasks 3.1 - 3.7

*/

#include <stdio.h>
#include <math.h>
#include <stdint.h>
#include <Windows.h>

void task1() {

	int a, b, c;

	unsigned number;
	printf("n = ");
	scanf_s("%u", &number);
	if (number >= 100 && number <= 999) {
		a = number % 10;
		b = (number / 10) % 10;
		c = number / 100;
		printf("%d %d %d\n", c, b, a);
		int Sum = a + b + c;
		printf("%d\n", Sum);
		int inv = 100 * a + 10 * b + c;
		printf("%d\n", inv);
	}
}



void task2() {

    int a, b, c;
    unsigned number;

    printf("number = ");
    scanf_s("%u", &number);

    if (number >= 100 && number <= 999) {
        a = number % 10;
        b = (number / 10) % 10;
        c = number / 100;

        if (a == b && b == c) {
            printf("Всі цифри однакові: %d\n", a);
        }
        else {
            printf("Цифри різні. \n");
            printf("Перестановки числа %d:\n", number);
            printf("%d%d%d\n", a, b, c);
            printf("%d%d%d\n", a, c, b);
            printf("%d%d%d\n", b, a, c);
            printf("%d%d%d\n", b, c, a);
            printf("%d%d%d\n", c, a, b);
            printf("%d%d%d\n", c, b, a);
        }
    }
    else {
        printf("Число не є тризначним. \n");
    }
}


void task3() {

    int x, y, z;  

   
    printf("Введіть три числа через кому: ");
    scanf_s("%d,%d,%d", &x, &y, &z);

    if (abs(x) < 1024 && abs(y) < 1024 && abs(z) < 1024) {
        int product_1 = x * y * z;
        printf("Добуток чисел для межі 2^10: %d\n", product_1);
    }
    else {
        printf("Числа перевищують межу 2^10 за модулем.\n");
    }

    if (abs(x) < 2097152 && abs(y) < 2097152 && abs(z) < 2097152) {
        int product_2 = x * y * z;
        printf("Добуток чисел для межі 2^21: %d\n", product_2);
    }
    else {
        printf("Числа перевищують межу 2^21 за модулем.\n");
    }
}


void task4() {




}


void task5() {

    double a, b;

    printf("a,b = ");
    scanf_s("%lf, %lf", &a, &b);

    if (a > b)
        printf("a");
    else 
        printf("b");
}


void task6() {

    double a, b, c;

    printf("Введіть три дійсних числа через кому: ");
    scanf_s("%lf, %lf, %lf", &a, &b, &c);

    double max_abs = a;
    double min_abs = a;

    if (fabs(b) > fabs(max_abs)) {
        max_abs = b;
    }
    if (fabs(c) > fabs(max_abs)) {
        max_abs = c;
    }

    if (fabs(b) < fabs(min_abs)) {
        min_abs = b;
    }
    if (fabs(c) < fabs(min_abs)) {
        min_abs = c;
    }

    printf("Найбільше за модулем: %lf\n", max_abs);
    printf("Найменше за модулем: %lf\n", min_abs);

}

void task7() {

}

int main() {

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

	//task1();
	//task2();
    //task3();
    //task4();
    //task5();
    //task6();
    //task7();
}