/*
Homework 14
Task: 15.13

*/

#include <iostream>
#include <cmath>


class Vector3 {

public:
	double x, y, z;

	Vector3(double x = 0, double y = 0, double z = 0) {
		this->x = x;
		this->y = y;
		this->z = z;
	}

	Vector3 operator+(const Vector3& other) const {
		return Vector3(x + other.x, y + other.y, z + other.z);
	}

	Vector3 operator-(const Vector3& other) const {
		return Vector3(x - other.x, y - other.y, z - other.z);
	}

	Vector3 operator*(double scalar) const {
		return Vector3(x * scalar, y * scalar, z * scalar);
	}

	double abs() const {
		return std::sqrt(x * x + y * y + z * z);
	}

	void printVector() const {
		std::cout << "(" << x << ", " << y << ", " << z << ")";
	}
};

class Matrix3 {
private:
	double data[3][3];

public:
	Matrix3() {
		for (int i = 0; i < 3; ++i)
			for (int j = 0; j < 3; ++j)
				data[i][j] = 0;
	}

	Matrix3(double values[3][3]) {
		for (int i = 0; i < 3; ++i)
			for (int j = 0; j < 3; ++j)
				data[i][j] = values[i][j];
	}

	Matrix3 operator+(const Matrix3& other) const {
		Matrix3 result;
		for (int i = 0; i < 3; ++i)
			for (int j = 0; j < 3; ++j)
				result.data[i][j] = data[i][j] + other.data[i][j];
		return result;
	}

	Matrix3 operator-(const Matrix3& other) const {
		Matrix3 result;
		for (int i = 0; i < 3; ++i)
			for (int j = 0; j < 3; ++j)
				result.data[i][j] = data[i][j] - other.data[i][j];
		return result;
	}

	Vector3 operator*(const Vector3& vec) const {
		double x = data[0][0] * vec.x + data[0][1] * vec.y + data[0][2] * vec.z;
		double y = data[1][0] * vec.x + data[1][1] * vec.y + data[1][2] * vec.z;
		double z = data[2][0] * vec.x + data[2][1] * vec.y + data[2][2] * vec.z;
		return Vector3(x, y, z);
	}

	double det() const {
		return data[0][0] * (data[1][1] * data[2][2] - data[1][2] * data[2][1]) -
			data[0][1] * (data[1][0] * data[2][2] - data[1][2] * data[2][0]) +
			data[0][2] * (data[1][0] * data[2][1] - data[1][1] * data[2][0]);
	}

	double abs() const {
		double sum = 0;
		for (int i = 0; i < 3; ++i)
			for (int j = 0; j < 3; ++j)
				sum += data[i][j] * data[i][j];
		return std::sqrt(sum);
	}

	void printMatrix() const {
		for (int i = 0; i < 3; ++i) {
			for (int j = 0; j < 3; ++j) {
				std::cout << data[i][j] << " ";
			}
			std::cout << "\n";
		}
	}

};


int main() {
	Vector3 v1(1, 2, 3), v2(4, 5, 6);
	std::cout << "v1 + v2 = ";
	(v1 + v2).printVector();
	std::cout << "\n";

	std::cout << "v1 - v2 = ";
	(v1 - v2).printVector();
	std::cout << "\n";

	std::cout << "v1 * 2 = ";
	(v1 * 2).printVector();
	std::cout << "\n";

	std::cout << "Norm of v1 = " << v1.abs() << "\n";

	double m1_values[3][3] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
	double m2_values[3][3] = { {9, 8, 7}, {6, 5, 4}, {3, 2, 1} };
	Matrix3 m1(m1_values), m2(m2_values);

	std::cout << "m1 + m2 =\n";
	(m1 + m2).printMatrix();

	std::cout << "m1 - m2 =\n";
	(m1 - m2).printMatrix();

	std::cout << "Determinant of m1 = " << m1.det() << "\n";
	std::cout << "Norm of m1 = " << m1.abs() << "\n";

	std::cout << "m1 * v1 = ";
	(m1 * v1).printVector();
	std::cout << "\n";

	return 0;
}