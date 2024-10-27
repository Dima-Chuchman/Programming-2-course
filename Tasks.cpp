#include <iostream>
#include <cmath>
#include <string>
#include <fstream>

void Task1() {

	int x;
	int y;

	std::cout << "Enter x: ";
	std::cin >> x;
	std::cout << "Enter y: ";
	std::cin >> y;

	if (y == 0) {
	std::cout << "Error";
	}
	else {
		float result = pow(x, y);

		std::cout << result << std::endl;
	}

}


void Task2() {

	char str[10];
	unsigned a;
	unsigned long long sum = 0UL;
	std::cout << "Enter:\n";
	unsigned n = 0;
	unsigned mas[1000];
	size_t SZ;
	while (std::cin.get(str, 0)) {
		std::cout << str << "," << std::endl;
		a = std::stoull(str, &SZ);
		mas[n] = a;
		n++;
		sum += a;
	}
	std::cout << "S = " << sum << "\n";


}


void Task3() {
	int n;
	std::cout << "Enter n: ";
	std::cin >> n;

	for (int i = 1; i <= n; i++) {
		float result = pow(i, 0.5);
		std::cout << "sqrt(" << i << ") = " << result << std::endl;
	}

	std::string b(n, '+');

	std::cout << b << std::endl;
}


void Task4() {

	unsigned n;
	std::cin >> n;
	int* m = new int[n];
	double* x = new double[n];

	for (unsigned i = 0; i < n; i++) {

		std::cout<<"m["<<i<<"]=";
		std::cin >> m[i];
	}

	ifstream f1("input.txt");
	unsigned i = 0;
	while (!f1.eof()) {
		if (f1 >> x[i]) {
			clog << i << "-th number = x[i]" << "\n";
			i++;
		}
		if (i >= n) {
			break;
		}
		f1.close();
	}

	if (i < n) {
		std::cout << "not enough data in file";
		ofstream f2("output.txt") {
			for (unsigned i = 0; i < n; i++) {
				double z = pow(x[i], m[i]);
				f2 << z << "\n";
			}
			f2.close();
		}
	}

}

void Task5() {

	double mas[1 << 16];

	ifstream f1("input_1.txt");
	unsigned i = 0;
	while (!f1.eof(1)) {
		if (f1 >> mas[i]) {
			i++;
		}
		f1.close();
	}

}


int main() {


	//Task1();
	//Task2();
	Task3();
}