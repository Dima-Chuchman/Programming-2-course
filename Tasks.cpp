#include <stdio.h>
# include <math.h>
typedef int MTYPE;
# define N_5 3
# define N_7 2

//Task1------------------------>

void output_matrix_1(int a[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("(%d\t)", a[i][j]);
        }
        printf("\n");
    }
}


void Task1() {
    int a[3][3] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
    unsigned N, M;
    printf("Enter N and M: ");
    scanf_s("%u, %u", &N, &M);

    for (int i = 0; i < 3; i++) {
        for (int k = 0; k < 3; k++) {
            if (a[i][k] == M) {
                a[i][k] = N;
            }
        }
    }

    output_matrix_1(a);
}

//Task2------------------------>

void output_matrix_2(double a[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("(%lf\t)", a[i][j]);
        }
        printf("\n");
    }
}

void Task2() {
    double a[3][3] = { {1.0, 2.0, 3.0}, {4.0, 5.0, 6.0}, {7.0, 8.0, 9.0} };
    unsigned int i, j;
    double value;

    printf("Enter i, j and a: ");
    scanf_s("%u, %u, %lf", &i, &j, &value);
    if (i < 3 && j < 3) {
        a[i][j] = value;
    }
    else {
        printf("The indices must be between 0 and 2.\n");
        return;
    }

    output_matrix_2(a);
}

//Task3------------------------>

void Task3() {
    double matrix[3][3];
    int m, n;
    printf("m = ");
    scanf_s("%d", &m);
    printf("n = ");
    scanf_s("%d", &n);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("matrix[%d][%d] = ", i, j);
            scanf_s("%lf", &matrix[i][j]);
        }
    }
    output_matrix(matrix);
}


//Task4------------------------>

void input_matrix(double matrix[25][25], int m, int n) {
    for (int i = 0; i < m; i++) {
        printf("matrix[%i]= ", i);
        for (int j = 0; j < n; j++) {
            scanf_s("%lf", &matrix[i][j]);
        }
    }
}

void output_matrix(double matrix[25][25], int m, int n) {
    printf("\nEnter matrix:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%lf ", matrix[i][j]);  
        }
        printf("\n");
    }
}

void Task4() {

    unsigned int m, n;
    printf("m = ");
    scanf_s("%u", &m);
    printf("n = ");
    scanf_s("%u", &n);
    double matrix[25][25];
    input_matrix(matrix, m, n);
    output_matrix(matrix, m, n);
}

void Task5() {
    const MTYPE m1[N_5][N_5] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
    MTYPE m2[N_5][N_5];
    for (int i = 0; i < N_5; i++) {
        for (int j = 0; j < N_5; j++) {
            m2[i][j] = m1[j][i];
        }
    }
    output_matrix(m2);
}


void Task6() {
    int M, N, k;
    double A[100][100], counter = 0;
    printf("k = ");
    scanf_s("%d", &k);
    printf("M = ");
    scanf_s("%d", &M);
    printf("N = ");
    scanf_s("%d", &N);
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (i - j == k) {
                counter += A[i][j];
            }
        }
    }
    printf("%lf", counter);

}



int main() {
    //Task1();
    //Task2();
    Task4();
    //Task5();
    //Task6();
    return 0;
}
