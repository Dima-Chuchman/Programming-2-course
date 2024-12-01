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
		cout << "������ ����� �������: ";
		cin >> real;
		cout << "������ ����� �������: ";
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
		if (denominator == 0) throw std::invalid_argument("ĳ����� �� ����!");
		return Complex((real * other.real + imagine * other.imagine) / denominator,
			(imagine * other.real - real * other.imagine) / denominator);
	}

	Complex arctg(double epsilon) const {
		if (modul() >= 1) {
			throw std::domain_error("������ z �� ���� ������ �� 1!");
		}
		if (epsilon <= 0) {
			throw std::invalid_argument("epsilon �� ���� ����� �� 0!");
		}

		Complex term = *this; // ������ ������� (z)
		Complex sum = term;   // ���� ����
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
		std::cout << "������ ���������� ����� z:\n";
		z.input();

		double epsilon;
		std::cout << "������ ������� epsilon: ";
		std::cin >> epsilon;

		Complex result = z.arctg(epsilon);
		std::cout << "��������� arctg(z): ";
		result.output();
	}
	catch (const std::exception& e) {
		std::cerr << "�������: " << e.what() << std::endl;
	}

	return 0;
}