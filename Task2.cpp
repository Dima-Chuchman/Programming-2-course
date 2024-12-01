#include <iostream>
#include <cmath>
#include <fstream>
#include <Windows.h>

using namespace std;

class Point {
protected:
    double x, y;
public:
    Point(double x = 0, double y = 0) {
        this->x = x;
        this->y = y;
    }

    void input() {
        cout << "Введіть координату x: ";
        cin >> x;
        cout << "Введіть координату y: ";
        cin >> y;
    }

    void show() const {
        cout << "Координати точки: (" << x << ", " << y << ")" << endl;
    }

    void saveToFile() const {
        ofstream outFile("point_data.txt", ios::app);
        if (outFile.is_open()) {
            outFile << "Точка 2D: (" << x << ", " << y << ")" << endl;
            outFile.close();
        }
        else {
            cout << "Не вдалося відкрити файл для запису!" << endl;
        }
    }

    double distanceFromOrigin() const {
        return sqrt(x * x + y * y);
    }

    bool isEqual(const Point& other) const {
        return (x == other.x && y == other.y);
    }
};

class Point3D : public Point {
private:
    double z;
public:
    Point3D(double x = 0, double y = 0, double z = 0) {
        this->x = x;
        this->y = y;
        this->z = z;
    }

    void input() {
        Point::input();
        cout << "Введіть координату z: ";
        cin >> z;
    }

    void show() const {
        Point::show();
        cout << "Координата z: " << z << endl;
    }

    void saveToFile() const {
        ofstream outFile("point_data.txt", ios::app);
        if (outFile.is_open()) {
            outFile << "Точка 3D: (" << x << ", " << y << ", " << z << ")" << endl;
            outFile.close();
        }
        else {
            cout << "Не вдалося відкрити файл для запису!" << endl;
        }
    }

    double distanceFromOrigin() const {
        return sqrt(x * x + y * y + z * z);
    }

    bool isEqual(const Point3D& other) const {
        return (x == other.x && y == other.y && z == other.z);
    }
};

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    Point point2D;
    point2D.input();
    point2D.show();
    point2D.saveToFile();

    Point3D point3D;
    point3D.input();
    point3D.show();
    point3D.saveToFile();


    return 0;
}
