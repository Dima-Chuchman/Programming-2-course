/*

Task 2.6

��������� ��������� ������������ ���� ������, �� ��������� ���: 
� ������� ����� ����� ����� ��� ������ ����� - ���������� �����
�, ��� ������������ �����, � �������� ����� ����� ����� ��� ������ ����� � ���������� ����� �,
���� ������������ �����, ����� ����� ���������� ����� �. ϳ��������� ����� ����������. 
(�������:�������� ������� ��������� ������� ������ �� ������� ���������� ����� ���������� �� ��������� �����)

*/

#include <stdio.h>
#include <math.h>
#include <Windows.h>


double distance(double x1, double y1, double x2, double y2) {
    return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

double triangle_area(double a, double b, double c) {
    double s = (a + b + c) / 2;
    return sqrt(s * (s - a) * (s - b) * (s - c));
}

int main() {

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    double x1, y1, x2, y2, x3, y3;

    printf("������ ���������� ����� A (x1 y1): ");
    scanf_s("%lf %lf", &x1, &y1);

    printf("������ ���������� ����� B (x2 y2): ");
    scanf_s("%lf %lf", &x2, &y2);


    printf("������ ���������� ����� C (x3 y3): ");
    scanf_s("%lf %lf", &x3, &y3);

    double a = distance(x1, y1, x2, y2);
    double b = distance(x2, y2, x3, y3);
    double c = distance(x3, y3, x1, y1);

    double area = triangle_area(a, b, c);

    printf("����� ����������: %.2lf\n", area);
}
