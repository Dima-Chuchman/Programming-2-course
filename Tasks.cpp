#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int read_file(const char* fname, double* ar) {

    FILE* fp = fopen(fname, "rb");
    double item;
    int k = 0;
    while (!feof(fp)) {
        int res = fread(&item, sizeof(item), 1, fp);
        if (res!= 1) {
            break;
        }
        arr[k++] = item;

    }
    fclose(fp);
    return k;
}

int write_file(const char* fname, double* ar, int n) {

    FILE* fp = fopen(fname, "wb");
    int res = fwrite(ar, sizeof(*ar), n, fp);
    fclose(fp);
    return res; // Повертає елементи, що реально записані.

}


//void save_array(const char* filename, double* array, int length) {
//    FILE* file = fopen(filename, "w");
//
//    for (int i = 0; i < length; i++) {
//        fprintf(file, "%.2f", array[i]);
//        if (i < length - 1) {
//            fprintf(file, ",");
//        }
//    }
//
//    fclose(file);
//}

void Task1() {

    int length;

    // Введення довжини масиву
    printf("Enter lenght: ");
    scanf_s("%d", &length);

    double array[length];

    printf("Elements:\n");
    for (int i = 0; i < length; i++) {
        scanf_s("%lf", &array[i]);
    }

    const char* filename = "test_file.txt";

    save_array(filename, array, length);

    printf("Content in the file: ");
    printf("\n");
}


void filterNumbers(const char* fileF, const char* fileG, float a) {
    FILE* fIn = fopen(fileF, "r");
    FILE* fOut = fopen(fileG, "w");

    if (fIn == NULL) {
        printf("error opening input file '%s' for reading\n", fileF);
        return;
    }
    if (fOut == NULL) {
        printf("error opening output file '%s' for writing\n", fileG);
        fclose(fIn);
        return;
    }

    float number;
    while (fscanf(fIn, "%f", &number) != EOF) {
        if (fabs(number) < a) {
            fprintf(fOut, "%.2f ", number);
        }
    }

    fclose(fIn);
    fclose(fOut);
}

void removeNumbers(const char* fileF, float a) {
    FILE* fIn = fopen(fileF, "r");
    FILE* tempFile = fopen("temp.txt", "w");

    if (fIn == NULL) {
        printf("Error opening input file '%s' for reading\n", fileF);
        return;
    }
    if (tempFile == NULL) {
        printf("error creating temporary file for writing\n");
        fclose(fIn);
        return;
    }

    float number;
    while (fscanf(fIn, "%f", &number) != EOF) {
        if (fabs(number) >= a) {
            fprintf(tempFile, "%.2f ", number);
        }
    }

    fclose(fIn);
    fclose(tempFile);


    if (remove(fileF) != 0) {
        printf("error deleting original file '%s'.\n", fileF);
    }
    else if (rename("temp.txt", fileF) != 0) {
        printf("error renaming temporary file to '%s'.\n", fileF);
    }
}

void task2() {
    char fileF[100], fileG[100];
    float a;

    printf("enter the filename for input (F): ");
    scanf_s("%s", fileF);

    printf("enter the filename for output (G): ");
    scanf_s("%s", fileG);

    printf("enter the threshold value (a > 0): ");
    scanf_s("%f", &a);

    if (a <= 0) {
        printf("the threshold value must be greater than 0.\n");
        return;
    }
    filterNumbers(fileF, fileG, a);
    printf("filtered numbers have been saved to '%s'\n", fileG);
    removeNumbers(fileF, a);
    printf("updated file '%s' with numbers removed\n", fileF);
}


typedef struct {
    int id;
    float x1, y1;
    float x2, y2;
} Rectangle;

void writeRectanglesToFile(const char* filename, Rectangle* rectangles, int count) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        printf("error opening file for writing\n");
        return;
    }
    for (int i = 0; i < count; i++) {
        fprintf(file, "%d %.2f %.2f %.2f %.2f\n", rectangles[i].id, rectangles[i].x1, rectangles[i].y1, rectangles[i].x2, rectangles[i].y2);
    }
    fclose(file);
}

void findLargestRectangle(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("error opening file for reading\n");
        return;
    }

    Rectangle rect;
    int largestId = -1;
    float largestArea = 0.0f;

    while (fscanf(file, "%d %f %f %f %f", &rect.id, &rect.x1, &rect.y1, &rect.x2, &rect.y2) != EOF) {
        float area = (rect.x2 - rect.x1) * (rect.y2 - rect.y1);
        if (area > largestArea) {
            largestArea = area;
            largestId = rect.id;
        }
    }

    fclose(file);

    if (largestId != -1) {
        printf("largest Rectangle ID: %d, Area: %.2f\n", largestId, largestArea);
    }
    else {
        printf("0 rectangles found\n");
    }
}

void deleteRectangle(const char* filename, int id) {
    FILE* file = fopen(filename, "r");
    FILE* tempFile = fopen("temp.txt", "w");

    if (file == NULL || tempFile == NULL) {
        printf("error opening files.\n");
        return;
    }

    Rectangle rect;
    while (fscanf(file, "%d %f %f %f %f", &rect.id, &rect.x1, &rect.y1, &rect.x2, &rect.y2) != EOF) {
        if (rect.id != id) {
            fprintf(tempFile, "%d %.2f %.2f %.2f %.2f\n", rect.id, rect.x1, rect.y1, rect.x2, rect.y2);
        }
    }

    fclose(file);
    fclose(tempFile);

    remove(filename);
    rename("temp.txt", filename);
}


void replaceRectangle(const char* filename, int id, Rectangle newRect) {
    FILE* file = fopen(filename, "r");
    FILE* tempFile = fopen("temp.txt", "w");

    if (file == NULL || tempFile == NULL) {
        printf("error opening files\n");
        return;
    }

    Rectangle rect;
    while (fscanf(file, "%d %f %f %f %f", &rect.id, &rect.x1, &rect.y1, &rect.x2, &rect.y2) != EOF) {
        if (rect.id == id) {
            fprintf(tempFile, "%d %.2f %.2f %.2f %.2f\n", newRect.id, newRect.x1, newRect.y1, newRect.x2, newRect.y2);
        }
        else {
            fprintf(tempFile, "%d %.2f %.2f %.2f %.2f\n", rect.id, rect.x1, rect.y1, rect.x2, rect.y2);
        }
    }

    fclose(file);
    fclose(tempFile);
    remove(filename);
    rename("temp.txt", filename);
}

//task3(b,d)

int isPowerOfThree(int n) {
    if (n < 1) return 0;
    while (n % 3 == 0) {
        n /= 3;
    }
    return n == 1;
}

int isPalindrome(int n) {
    int reversed = 0, original = n, remainder;
    while (n != 0) {
        remainder = n % 10;
        reversed = reversed * 10 + remainder;
        n /= 10;
    }
    return original == reversed;
}

void processNumbers(FILE* F, FILE* G) {
    int num;
    while (fscanf(F, "%d", &num) && num != 0) {
        if (isPowerOfThree(num) || isPalindrome(num)) {
            fprintf(G, "%d\n", num);
        }
    }
}



int main() {

    //Task1();
    //Task2();
    //Task3(b);
    //Task3(d);

    FILE* fileF, * fileG;
    int number;

    FILE* F = fopen("F.txt", "r");
    FILE* G = fopen("G.txt", "w");


    fileF = fopen("F.txt", "w");
    if (fileF == NULL) {
        printf("failed to open file F for writing.\n");
        return 1;
    }


    while (1) {
        printf("enter an integer (0 to exit): ");
        scanf("%d", &number);
        if (number == 0) {
            break;
        }
        fprintf(fileF, "%d\n", number);
    }

    fclose(fileF);


    fileG = fopen("G.txt", "w");
    if (fileG == NULL) {
        printf("dailed to open file G for writing\n");
        return 1;
    }


    fileF = fopen("F.txt", "r");
    if (fileF == NULL) {
        printf("failed to open file F for reading\n");
        fclose(fileG);
        return 1;
    }


    while (fscanf(fileF, "%d", &number) != EOF) {
        if (number % 2 == 0) {
            fprintf(fileG, "%d\n", number);
        }
    }

    fclose(fileF);
    fclose(fileG);

    printf("File G successfully created with even numbers from file F.\n");

    const char* filename = "rectangles.txt";


    Rectangle rectangles[] = {
        {1, 1.0, 1.0, 4.0, 5.0},
        {2, 2.0, 2.0, 3.0, 3.0},
        {3, 0.0, 0.0, 6.0, 4.0}
    };

    writeRectanglesToFile(filename, rectangles, 3);


    findLargestRectangle(filename);
    deleteRectangle(filename, 2);

    Rectangle newRect = { 1, 1.0, 1.0, 5.0, 6.0 };
    replaceRectangle(filename, 1, newRect);
    printf("updated rectangle data:\n");
    findLargestRectangle(filename);

    if (F == NULL || G == NULL) {
        printf("Не вдалося відкрити файли.\n");
        return 1;
    }

    processNumbers(F, G);

    fclose(F);
    fclose(G);
}

