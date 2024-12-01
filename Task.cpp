#include <iostream>
#include <vector>
#include <Windows.h>

template <typename T>

class Masive {

private:
    std::vector<T> data;

public:

    Masive(const std::vector<T>& elements) : data(elements) {}

    void print() const {
        for (const auto& elem : data) {
            std::cout << elem << " ";
        }
        std::cout << std::endl;
    }

    void insertionSort() {
        for (size_t i = 1; i < data.size(); ++i) {
            T key = data[i];
            size_t j = i;
            while (j > 0 && data[j - 1] > key) {
                data[j] = data[j - 1];
                --j;
            }
            data[j] = key;
        }
    }

    static void insertionSort(std::vector<T>& arr) {
        for (size_t i = 1; i < arr.size(); ++i) {
            T key = arr[i];
            size_t j = i;
            while (j > 0 && arr[j - 1] > key) {
                arr[j] = arr[j - 1];
                --j;
            }
            arr[j] = key;
        }
    }
};

int main() {

    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    std::vector<int> elements = { 5, 2, 9, 1, 5, 6 };
    Masive<int> myArray(elements);

    std::cout << "Початковий масив: ";
    myArray.print();

    myArray.insertionSort();
    std::cout << "Відсортований масив (inplace): ";
    myArray.print();

    std::vector<int> staticArray = { 3, 7, 4, 9, 2 };
    std::cout << "Початковий масив (static): ";
    for (const auto& elem : staticArray) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    Masive<int>::insertionSort(staticArray);
    std::cout << "Відсортований масив (static): ";
    for (const auto& elem : staticArray) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    return 0;
}
