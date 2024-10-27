/*

Homework(11) 25.10.2024
Tasks: 11.8; 11.12(d)

*/
#define MAX_NAME_LENGTH 50
#define MAX_CATEGORY_LENGTH 30
#define MAX_PRODUCTS 100
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void Task1(const char* inputFile, const char* outputFile, int n) {

    FILE* fInput = fopen(inputFile, "r");
    FILE* fOutput = fopen(outputFile, "w");

    if (!fInput || !fOutput) {
        printf("Error opening files.\n");
        return;
    }

    int num, count = 0, maxVal;

    while (fscanf(fInput, "%d", &num) == 1) {
        if (count == 0) {
            maxVal = num;
        }
        else if (num > maxVal) {
            maxVal = num;
        }

        count++;

        if (count == n) {
            fprintf(fOutput, "%d\n", maxVal);
            count = 0;
        }
    }

    if (count > 0) {
        fprintf(fOutput, "%d\n", maxVal);
    }

    fclose(fInput);
    fclose(fOutput);
}

// --------------------------------> Task2

typedef struct {

    char name[MAX_NAME_LENGTH];
    char category[MAX_CATEGORY_LENGTH];
    float price;
    int quantity;

} Product;

void displayProducts(const Product products[], int productCount) {

    printf("Products:\n");
    printf("Name\tCategory\tPrice\tQuantity\n");
    for (int i = 0; i < productCount; i++) {
        printf("%s\t%s\t%.2f\t%d\n", products[i].name,
            products[i].category,
            products[i].price,
            products[i].quantity);
    }

}

void readData(const char* inputFile, Product products[], int* productCount) {

    FILE* file = fopen(inputFile, "r");
    if (!file) {
        printf("Error opening file %s.\n", inputFile);
    }

}

int main() {

    /*int n;
    printf("Enter the number of elements per group (n): ");
    scanf_s("%d", &n);


    Task1("F.txt", "G.txt", n);

    printf("File G created with maximum values from groups of %d elements.\n", n);
    return 0;*/


    Product products[MAX_PRODUCTS];
    int productCount;

    readData("data.txt", products, &productCount);
    displayProducts(products, productCount);

    return 0;

}
