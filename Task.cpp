#include <iostream>
#include <fstream>
#define _USE_MATH_DEFINES
#include <cmath>
#include <vector>
#include <math.h>


class Figure {

private:
    std::string name;
    int base_value;

public:
    Figure(std::string n, int base) {
        this->name = n;
        this->base_value = base;
    }

    void displayInfo() {
        std::cout << "Figure Name: " << name << ", Base Value: " << base_value << std::endl;
    }

    int performOperation(int multiplier) {
        return base_value * multiplier;
    }

};


class Rectangle : public Figure {

private:
    double x1, y1, x2, y2;

public:
    /*Rectangle(double x1, double y1, double x2, double y2) {
        this->x1 = x1;
        this->y1 = y1;
        this->x2 = x2;
        this->y2 = y2;
    }*/  //Не розумію чому так не можна. Виводить помилку

    Rectangle(double x1, double y1, double x2, double y2)
        : Figure("Rectangle", 0), x1(x1), y1(y1), x2(x2), y2(y2) {}

    // Метод для обчислення довжин сторін
    double sideLengthX() {
        return std::abs(x2 - x1);
    }

    double sideLengthY() {
        return std::abs(y2 - y1);
    }

    // Площа прямокутника
    double area() {
        return sideLengthX() * sideLengthY();
    }

    // Периметр прямокутника
    double perimeter() {
        return 2 * (sideLengthX() + sideLengthY());
    }

    // Центр маси
    void centerOfMass()  {
        double centerX = (x1 + x2) / 2;
        double centerY = (y1 + y2) / 2;
        std::cout << "Center of mass: (" << centerX << ", " << centerY << ")\n";
    }

    // Виведення даних
    void display()  {
        std::cout << "Rectangle coordinates: (" << x1 << ", " << y1 << ") to (" << x2 << ", " << y2 << ")\n";
        std::cout << "Area: " << area() << "\n";
        std::cout << "Perimeter: " << perimeter() << "\n";
    }
};


class Triangle : public Figure {
private:
    double x1, y1, x2, y2, x3, y3;

public:
    /*Triangle(double x1, double y1, double x2, double y2, double x3, double y3) {
        this->x1 = x1;
        this->y1 = y1;
        this->x2 = x2;
        this->y2 = y2;
        this->x3 = x3;
        this->y3 = y3;
    }*/ // Тут так само видає помилку.

    Triangle(double x1, double y1, double x2, double y2, double x3, double y3)
        : Figure("Triangle", 0), x1(x1), y1(y1), x2(x2), y2(y2), x3(x3), y3(y3) {}

    // Довжина сторін трикутника
    double sideLength1() {
        return std::sqrt(std::pow(x2 - x1, 2) + std::pow(y2 - y1, 2));
    }

    double sideLength2() {
        return std::sqrt(std::pow(x3 - x2, 2) + std::pow(y3 - y2, 2));
    }

    double sideLength3() {
        return std::sqrt(std::pow(x1 - x3, 2) + std::pow(y1 - y3, 2));
    }

    // Периметр трикутника
    double perimeter() {
        return sideLength1() + sideLength2() + sideLength3();
    }

    // Площа трикутника (за формулою Герона)
    double area() {
        double s = perimeter() / 2;
        return std::sqrt(s * (s - sideLength1()) * (s - sideLength2()) * (s - sideLength3()));
    }

    // Центр маси
    void centerOfMass()  {
        double centerX = (x1 + x2 + x3) / 3;
        double centerY = (y1 + y2 + y3) / 3;
        std::cout << "Center of mass: (" << centerX << ", " << centerY << ")\n";
    }

    void display()  {
        std::cout << "Triangle coordinates: (" << x1 << ", " << y1 << "), (" << x2 << ", " << y2 << "), (" << x3 << ", " << y3 << ")\n";
        std::cout << "Area: " << area() << "\n";
        std::cout << "Perimeter: " << perimeter() << "\n";
    }
};


class Elips : public Figure {
private:
    double a, b;

public:
    /*Elips(double a, double b) {
        this->a = a;
        this->b = b;
    }*/ // І тут так само.

    Elips(double a, double b)
        : Figure("Elips", 0), a(a), b(b) {}

    // Площа еліпса
    double area() {
        return M_PI * a * b;
    }

    // Периметр еліпса (наближено)
    double perimeter() {
        return M_PI * (3 * (a + b) - std::sqrt((3 * a + b) * (a + 3 * b)));
    }

    // Центр маси
    void centerOfMass()  {
        std::cout << "Center of mass: (0, 0)\n"; 
    }

    void display()  {
        std::cout << "Elips with semi-axes a = " << a << " and b = " << b << "\n";
        std::cout << "Area: " << area() << "\n";
        std::cout << "Perimeter: " << perimeter() << "\n";
    }
};


int main() {
    Rectangle rectangle(0, 0, 5, 3);
    Triangle triangle(0, 0, 5, 0, 2, 4);
    Elips elips(3, 2);

    rectangle.display();
    triangle.centerOfMass();

    triangle.display();
    triangle.centerOfMass();

    elips.display();
    elips.centerOfMass();

    return 0;
}
