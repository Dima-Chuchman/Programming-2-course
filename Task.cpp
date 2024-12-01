#include <iostream>
#include <cmath>
#include <Windows.h>


using namespace std;

class Complex {
private:
	double real;
	double imagine;

public:
	Complex(double real = 0, double imagine = 0) {
		this->real = real;
		this->imagine = imagine;
	}

	void input() {
		cout << "Введіть дійсну частину: ";
		cin >> real;
		cout << "Введіть уявну частину: ";
		cin >> imagine;
	}

	void output() const {
		cout << real;
		if (imagine >= 0)
			cout << "+" << imagine << "i";
		else
			cout << "-" << imagine << "i";
		cout << endl;
	}

	double modul() const {
		return std::sqrt(real * real + imagine * imagine);
	}

	Complex operator+(const Complex& other) const {
		return Complex(real + other.real, imagine + other.imagine);
	}

	Complex operator-(const Complex& other) const {
		return Complex(real - other.real, imagine - other.imagine);
	}

	Complex operator*(const Complex& other) const {
		return Complex(real * other.real - imagine * other.imagine,
			real * other.imagine + imagine * other.real);
	}

	Complex operator/(const Complex& other) const {
		double denominator = other.real * other.real + other.imagine * other.imagine;
		if (denominator == 0) throw std::invalid_argument("Ділення на нуль!");
		return Complex((real * other.real + imagine * other.imagine) / denominator,
			(imagine * other.real - real * other.imagine) / denominator);
	}

	Complex arctg(double epsilon) const {
		if (modul() >= 1) {
			throw std::domain_error("Модуль z має бути меншим за 1!");
		}
		if (epsilon <= 0) {
			throw std::invalid_argument("epsilon має бути більше за 0!");
		}

		Complex term = *this; // Перший доданок (z)
		Complex sum = term;   // Сума ряду
		int n = 1;

		while (term.modul() >= epsilon) {
			Complex zn = *this;
			for (int i = 1; i < 2 * n + 1; ++i) {
				zn = zn * (*this);
			}
			term = zn * Complex(std::pow(-1, n), 0) / Complex(2 * n + 1, 0);
			sum = sum + term;
			++n;
		}
		return sum;
	}


};

int main() {

	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	try {
		Complex z;
		std::cout << "Введіть комплексне число z:\n";
		z.input();

		double epsilon;
		std::cout << "Введіть точність epsilon: ";
		std::cin >> epsilon;

		Complex result = z.arctg(epsilon);
		std::cout << "Результат arctg(z): ";
		result.output();
	}
	catch (const std::exception& e) {
		std::cerr << "Помилка: " << e.what() << std::endl;
	}

	return 0;
}