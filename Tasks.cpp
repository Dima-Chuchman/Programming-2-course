/*

Homework(7) 15.10.2024

Tasks: 7.9(ã); 7.10(a)

*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>


void Task1() {

    int n;

    printf("Enter n: ");
    scanf_s("%d", &n);

    double* a = (double*)malloc(n * sizeof(double));

    printf("Enter elements: ");

    for (int i = 0; i < n; i++) {
        scanf_s("%lf", &a[i]);
    }

    double min = a[0];
    for (int i = 2; i < n; i += 2) {
        if (a[i] < min) {
            min = a[i];
        }
    }

    printf("Result: %.2lf\n", min);
    free(a);
}



void Task2() {

    int n;

    printf("Enter n: ");
    scanf_s("%d", &n);

    int* a = (int*)malloc(n * sizeof(int));

    printf("Enter elements: ");

    for (int i = 0; i < n; i++) {
        scanf_s("%d", &a[i]);
    }

    int min = a[0];
    for (int i = 1; i < n; i++) {
        int product = (i + 1) * a[i];
        if (product < min) {
            min = product;
        }
    }

    printf("Result: %d\n", min);
    free(a);
}


int main() {

    //Task1();
    Task2();

}