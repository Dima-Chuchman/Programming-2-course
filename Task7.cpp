/*

Task 1.7

������ ����� ����� x �� ��������� ��� �� � ��������� ������������ ������� ���� C ���� ���� �� ������� �������, �������� ���� �����,
�� ����� x �� �������� ����, �� ����� x, � ����� ���� ��������� ��������. �������� ��������� ������ ��� ��'������ �����.

*/

//#include <stdio.h>
//#include <Windows.h>
//
//
//int main() {
//
//    SetConsoleCP(1251);
//    SetConsoleOutputCP(1251);
//
//    double x;
//    printf("������ ����� �����: ");
//    scanf_s("%lf", &x);
//
//    // ֳ�� �������
//    int int_part = (int)x;
//    printf("ֳ�� �������: %d\n", int_part);
//
//    // ������� �������
//    double frac_part = x - int_part;
//    printf("������� �������: %.10lf\n", frac_part);
//
//    // �������� ����, ����� �� x
//    int ceil_value = (int)(x + (x > int_part ? 1 : 0));
//    printf("�������� ����, ����� �� x: %d\n", ceil_value);
//
//    // �������� ����, ����� �� x
//    int floor_value = (int)(x - (x < int_part ? 1 : 0));
//    printf("�������� ����, ����� �� x: %d\n", floor_value);
//
//    // ��������� ��������
//    int rounded_value = (int)(x >= 0 ? x + 0.5 : x - 0.5);
//    printf("��������� ��������: %d\n", rounded_value);
//
//}
