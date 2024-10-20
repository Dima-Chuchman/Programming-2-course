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
    printf("������ �������: ");
    scanf_s("%s", person->last_name, sizeof(person->last_name));
    printf("������ ��'�: ");
    scanf_s("%s", person->first_name, sizeof(person->first_name));
    printf("������ ����� (�������/�����): ");
    scanf_s("%s", person->gender, sizeof(person->gender));
    printf("������ ���� ���������� (YYYY-MM-DD): ");
    scanf_s("%s", person->birth, sizeof(person->birth));
}

void displayPeople(const People* person) {
    printf("�������: %s\n", person->last_name);
    printf("��'�: %s\n", person->first_name);
    printf("�����: %s\n", person->gender);
    printf("���� ����������: %s\n", person->birth);
}

int main(People* m) {

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int m;

    printf("������ ������� �����: ");
    scanf_s("%d", m->n);

    People people[n];

    for (int i = 0; i < n; i++) {
        printf("\n������ ���������� ��� ������ %d:\n", i + 1);
        inputPeople(&people[i]);
    }

    printf("\n������ �����:\n");
    for (int i = 0; i < n; i++) {
        printf("\n���������� ��� ������ %d:\n", i + 1);
        displayPeople(&people[i]);
    }
}