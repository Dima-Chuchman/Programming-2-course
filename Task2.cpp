#include <stdio.h>
#include <Windows.h>

typedef struct {

	char last_name[20];
	char first_name[20];
	char gender[7];
	char birth[11];
    int n;

} People;

void inputPeople(People* person) {
    printf("Введіть прізвище: ");
    scanf_s("%s", person->last_name, sizeof(person->last_name));
    printf("Введіть ім'я: ");
    scanf_s("%s", person->first_name, sizeof(person->first_name));
    printf("Введіть стать (чоловіча/жіноча): ");
    scanf_s("%s", person->gender, sizeof(person->gender));
    printf("Введіть дату народження (YYYY-MM-DD): ");
    scanf_s("%s", person->birth, sizeof(person->birth));
}

void displayPeople(const People* person) {
    printf("Прізвище: %s\n", person->last_name);
    printf("Ім'я: %s\n", person->first_name);
    printf("Стать: %s\n", person->gender);
    printf("Дата народження: %s\n", person->birth);
}

int main(People* m) {

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int m;

    printf("Введіть кількість людей: ");
    scanf_s("%d", m->n);

    People people[n];

    for (int i = 0; i < n; i++) {
        printf("\nВведіть інформацію про людину %d:\n", i + 1);
        inputPeople(&people[i]);
    }

    printf("\nСписок людей:\n");
    for (int i = 0; i < n; i++) {
        printf("\nІнформація про людину %d:\n", i + 1);
        displayPeople(&people[i]);
    }
}