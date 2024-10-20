/*

Homework(9) 20.10.2024

Tasks: 9.9(б); 9.9(y)

*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
//----------------------------------> Task1

void print_array(int** array, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }
}

void Task1() {

    int N, M, k, choice;

    printf("Enter number of rows (N): ");
    scanf_s("%d", &N);
    printf("Enter number of columns (M): ");
    scanf_s("%d", &M);

    int** array = (int**)malloc(N * sizeof(int*));
    for (int i = 0; i < N; i++) {
        array[i] = (int*)malloc(M * sizeof(int));
    }

    printf("Fill the array with random numbers (1) or from the console (2)? ");
    scanf_s("%d", &choice);

    if (choice == 1) {
        srand(time(NULL));  // Ініціалізація генератора випадкових чисел
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                array[i][j] = rand() % 100;  // Випадкові числа від 0 до 99
            }                        // Знайшов в інтернеті як робити випадкові числа
        }
    }
    else {
        printf("Enter array elements:\n");
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                scanf_s("%d", &array[i][j]);
            }
        }
    }

    printf("Start array:\n");
    print_array(array, N, M);

    printf("Enter the column number k %d after which to add a new column: ", M - 1);
    scanf_s("%d", &k);

    if (k < 0 || k >= M) {
        printf("Incorrect column number. \n");
    }

    for (int i = 0; i < N; i++) {
        array[i] = (int*)realloc(array[i], (M + 1) * sizeof(int));
    }

    for (int i = 0; i < N; i++) {
        for (int j = M; j > k + 1; j--) {
            array[i][j] = array[i][j - 1];
        }
        array[i][k + 1] = 0;
    }

    M++;

    printf("Final array:\n");
    print_array(array, N, M);

    for (int i = 0; i < N; i++) {
        free(array[i]);
    }
    free(array);

}


//----------------------------------> Task2

void Task2() {

    int N, M, k, choice;

    printf("Enter number of rows (N): ");
    scanf_s("%d", &N);
    printf("Enter number of columns (M): ");
    scanf_s("%d", &M);

    int** array = (int**)malloc(N * sizeof(int*));
    for (int i = 0; i < N; i++) {
        array[i] = (int*)malloc(M * sizeof(int));
    }

    printf("Fill the array with random numbers (1) or from the console (2)? ");
    scanf_s("%d", &choice);

    if (choice == 1) {
        srand(time(NULL));  // Ініціалізація генератора випадкових чисел
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                array[i][j] = rand() % 100;  // Випадкові числа від 0 до 99
            }                        // Знайшов в інтернеті як робити випадкові числа
        }
    }
    else {
        printf("Enter array elements:\n");
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                scanf_s("%d", &array[i][j]);
            }
        }
    }

    printf("Start array:\n");
    print_array(array, N, M);

    for (int i = 0; i < N; i++) {
        array[i] = (int*)realloc(array[i], (M + M / 2) * sizeof(int));
    }

    int newCols = M;
    for (int j = 1; j < newCols; j += 2) {
        newCols++;

        for (int i = 0; i < N; i++) {
            for (int col = newCols - 1; col > j; col--) {
                array[i][col] = array[i][col - 1];
            }
            array[i][j + 1] = 0;
        }
    }


    printf("Final array:\n");
    print_array(array, N, newCols);

    for (int i = 0; i < N; i++) {
        free(array[i]);
    }
    free(array);

}


int main() {

    //Task1();
    Task2();
}

// Не розумію чому видає помилку в realloc. 
// Програма в 2 завданні приривається та і ще не правильно переставляє стовпці.