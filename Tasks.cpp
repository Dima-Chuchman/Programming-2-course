/*

Homework2	20.09.2024
Tasks: 2.12 ; 2.17(e)

Task 2.12:
������ ��'�� ������, ���� ����� ���� ����� ������ �� ������.


Task 2.17(e):
�������� ����� �������, �� ���������� ������� ������ �� ������� ����� �������, �� ������ �������� ������ ����� �������.


*/

#include <stdio.h>
#include <Windows.h>
#include <Math.h>


void task1() {

	double r, h;
	float pi = 3.14;

	printf("������ �������� ������ �� ������ ������: \n");
	printf("r = ");
	scanf_s("%lf", &r); 
	printf("h = ");
	scanf_s("%lf", &h);  

	double V = (1.0 / 3.0) * (pi * r * r * h);
	
	printf("³������: %.2lf\n", V);
}


double softPlus(double x) {
	return log(1 + exp(x));
}


double softPlus_der(double x) {
	return exp(x) / (1 + exp(x));
}


void task2() {

	double x;

	printf("������ �������� x: ");
	scanf_s("%lf", &x);

	double softPlus_result = softPlus(x);
	double softPlus_der_result = softPlus_der(x);

	printf("softPlus(x) = %lf\n", softPlus_result);
	printf("softPlus'(x) = %lf\n", softPlus_der_result);
}


int main() {

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	//task1();
	//task2();

}