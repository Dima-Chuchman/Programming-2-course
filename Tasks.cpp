/*

Homework 6	10.10.2024

Tasks: 6.17, 6.22;

*/


#include <stdio.h>
#include <math.h>

//-----------------------> Task 6.17

void Binary(unsigned int num) {
	
	//32-бітове представлення
	for (int i = sizeof(num) * 8 - 1; i >= 0; i--) {
		printf("%d", (num >> i) & 1);
	}
}

unsigned int Bits(unsigned int num) {
	return ~num;
}

void Task1() {

	unsigned int num;
	printf("Emter number: ");
	scanf_s("%u", &num);
	unsigned int Number = Bits(num);
	printf("%u", Number);
	Binary(Number);
	printf("\n");
	printf("%u\n", Number);
}


//-----------------------> Task 6.22

// Не зрозумів завдання.









int main() {
	Task1();
}