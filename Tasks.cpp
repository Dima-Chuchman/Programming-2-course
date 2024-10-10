#include <stdio.h>
#include <math.h>
#define N 5
#define N_1 10
#define N_5 50
#define N_6 20
#define M_E 2.718281828459045


void Task1() {
    int mas[N] = { 1, 2, 3, 4, 5 };
    double a;
    printf("a = ");
    scanf_s("%lf", &a);
    for (int i = 0; i < N; i++) {
        if (mas[i] < a) {
            printf("mas[%d] = %d\n", i, mas[i]);
        }
    }
}


void Task2() {
    int mas[] = { 5, 112, 4, 3 };
    int n = sizeof(mas) / sizeof(mas[0]);
    for (int i = n - 1; i >= 0; i--) {
        printf("mas[%d] = %d\n", i, mas[i]);
    }
}

double sum(double arr[N_1]) {
    double suma = 0;
    for (int i = 0; i < N_1; i++) {
        if (arr[i] > M_E) {
            suma += arr[i];
        }
    }
    return suma;
}


void Task3() {
    double mas[N_1];
    for (int i = 0; i < N_1; i++) {
        printf("mas[%d] = ", i);
        scanf_s("%lf", &mas[i]);
        printf("mas[%d] = %lf\n", i, mas[i]);
    }
    printf("%lf\n", sum(mas));
}

int input_arr(int arr[N]) {
    for (int i = 0; i < N; i++) {
        printf("arr[%d] = ", i);
        int r = scanf_s("%d", &arr[i]);
        if (r != 1) {
            return i;
        }
    }
    return N;
}


int input_arr_for5(int arr[N_5]) {
    for (int i = 0; i < N_5; i++) {
        printf("arr[%d] = ", i);
        scanf_s("%d", &arr[i]);
        if (arr[i] == 0) {
            return i - 1;
        }
    }
    return N_5;
}

void odd_even(int a[], int n) {
    int odd = 0, even = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] % 2 == 0) {
            even++;
        }
        else { odd++; }
    }
    printf("odd = %d even = %d\n", odd, even);
}

int max(int mas[N]) {
    int max = mas[0];
    for (int i = 1; i < N; i++) {
        if (mas[i] > max) {
            max = mas[i];
        }
    }
    return max;
}


void Task4() {
    int arr[N], maximum = 0;
    int m = input_arr(arr);
    if (m != N) {
        printf("Error\n");
        return;
    }
    printf("max = %d\n", max(arr));

}


void Task5() {
    int arr[N_5];
    int m = input_arr_for5(arr);
    odd_even(arr, m);
}

int input_vect(double v[], int n);

int input_vect(double v[], int n) {
    printf("input vect:\n");
    for (int i = 0; i < n; i++) {
        printf("v[%d] = ", i);
        scanf_s("%lf", &v[i]);
    }
}

void output_vect(const double v[], int n);

void output_vect(const double v[], int n) {
    for (int i = 0; i < n; i++) {
        printf("v[%d] = %.2lf\t", i, v[i]);
    }
}

double mult_vect(const double v1[], const double v2[], int n);

double mult_vect(const double v1[], const double v2[], int n) {
    double result = 0;
    for (int i = 0; i < n; i++) {
        result += v1[i] * v2[i];
    }
    return result;
}

void Task6() {
    double vec1[N_6];
    double vec2[N_6];
    double vec3[N_6];
    int n;
    scanf_s("%d", &n);
    input_vect(vec1, n);
    input_vect(vec2, n);
    printf("product of vec1 and vec2 = %.2lf\n", mult_vect(vec1, vec2, n));
    output_vect(vec3, n);
}

int main() {

    //Task1();
    //Task2();
    //Task3();
    //Task4();
    //Task5();
    //Task6();
}