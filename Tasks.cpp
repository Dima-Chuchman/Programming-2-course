/*

Homework 18.10.2024

Tasks: 8.21

*/


#include <stdio.h>
#include <math.h>
#define MAX_ROWS 100
#define MAX_COLS 100

void swap_columns(int matrix[MAX_ROWS][MAX_COLS], int n, int m, int col1, int col2) {

    for (int i = 0; i < n; i++) {
        int temp = matrix[i][col1];
        matrix[i][col2] = matrix[i][col1];
        matrix[i][col1] = temp;
    }
}

void move_min_element(int matrix[MAX_ROWS][MAX_COLS], int n, int m) {

    int min_index = 0;
    for (int j = 0; j < m; j++) {
        for (int i = 1; i < n; i++) {
            if (matrix[i][j] < matrix[min_index][j]) {
                min_index = i;
            }
        }

        if (min_index != 0) {
            int temp = matrix[0][j];
            matrix[0][j] = matrix[min_index][j];
            matrix[min_index][j] = temp;
        }
    }

}

void print_matrix(int matrix[MAX_ROWS][MAX_COLS], int n, int m) {

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

}



int main() {

    int n, m;
    int matrix[MAX_ROWS][MAX_COLS];

    printf("Enter the number of rows: ");
    scanf_s("%d", & n);
    printf("Enter the number of columns: ");
    scanf_s("%d", &m);


    printf("Enter elements matrix: ");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf_s("%d", &matrix[i][j]);
        }
    }

    printf("The initial matrix:\n");
    print_matrix(matrix, n, m);

    move_min_element(matrix, n, m);

    printf("New matrix:\n");
    print_matrix(matrix, n, m);
}
