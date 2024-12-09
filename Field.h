#ifndef FIELD_H
#define FIELD_H

#include <vector>
#include <utility> // Для std::pair

const int SIZE = 10;  // Розмір поля

// Оголошення типу клітинки
enum Cell {
    EMPTY,
    SHIP,
    HIT,
    MISS
};

class Field {
public:
    Field();  // Конструктор класу

    // Методи для гри
    void placePlayerShips();  // Розміщення кораблів гравця
    void placeComputerShips(const Field& playerField);   // Розміщення кораблів комп'ютера. 
    bool canPlaceShip(int x, int y, int size, bool horizontal) const; // Перевірка, чи можна поставити корабель
    void shootAt(int x, int y);  // Виконання пострілу
    void printField(bool isComputerField) const;  // Виведення поля (для гравця чи комп'ютера)
    bool isCellFreeWithBuffer(int x, int y, int size, bool horizontal); // Чи є вільне місце біля корабля.
    bool areAllShipsSunk() const;// Перевірка на потоплення всіх кораблів
    bool areShipsAdjacent(int x, int y, int size, bool horizontal) const; // Метод для перевірки на наявність кораблів поруч

private:
    std::vector<std::vector<Cell>> grid;  // Поле гри
    bool isCellEmpty(int x, int y) const;  // Перевірка, чи клітинка пуста
    void setShip(int x, int y);  // Встановлення корабля
    void markSurroundingCells(int x, int y);  // Замальовуємо клітинки навколо пошкодженої
    bool isSurroundingEmpty(int x, int y, int size, bool horizontal) const; // Перевірка на наявність кораблів поруч
};

#endif
