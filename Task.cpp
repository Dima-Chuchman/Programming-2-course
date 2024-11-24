/*

Homework 12 16.11.2024
Task: 12.19

*/

#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <limits>
#include <cstring>
#include <Windows.h>

struct Point {
    int x1, x2, x3;
};

double distance(const Point& p1, const Point& p2) {

    return std::sqrt(
        std::pow(p1.x1 - p2.x1, 2) +
        std::pow(p1.x2 - p2.x2, 2) +
        std::pow(p1.x3 - p2.x3, 2)
    );
}


int main() {

    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);


    std::ifstream file("points.txt");
    if (!file) {
        std::cerr << "Не вдалося відкрити файл points.txt\n";
        return 1;
    }

    std::vector<Point> points;
    std::string line;
    char buffer[256];

    while (file.getline(buffer, sizeof(buffer), ';')) {
        Point point;
        if (std::sscanf(buffer, "%d,%d,%d", &point.x1, &point.x2, &point.x3) == 3) {
            points.push_back(point);
        }
    }
    file.close();

    if (points.size() < 2) {
        std::cerr << "У файлі недостатньо точок для обчислення відрізків\n";
        return 1;
    }

    double max_distance = -std::numeric_limits<double>::infinity();
    Point max_p1, max_p2;

    for (size_t i = 0; i < points.size(); ++i) {
        for (size_t j = i + 1; j < points.size(); ++j) {
            double d = distance(points[i], points[j]);
            if (d > max_distance) {
                max_distance = d;
                max_p1 = points[i];
                max_p2 = points[j];
            }
        }
    }

    std::cout << "Максимальна довжина відрізка: " << max_distance << "\n";
    std::cout << "Точки: (" << max_p1.x1 << ", " << max_p1.x2 << ", " << max_p1.x3 << ") і ("
        << max_p2.x1 << ", " << max_p2.x2 << ", " << max_p2.x3 << ")\n";

    return 0;
}
