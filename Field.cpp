#include "Field.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

Field::Field() : grid(SIZE, std::vector<Cell>(SIZE, EMPTY)) {}


// Перевірка, чи клітинка пуста
bool Field::isCellEmpty(int x, int y) const {
    return grid[x][y] == EMPTY;
}


// Встановлення корабля
void Field::setShip(int x, int y) {
    grid[x][y] = SHIP;
}


// Функція для перевірки, чи є клітинки поруч з кораблем зайнятими
bool Field::isCellFreeWithBuffer(int x, int y, int size, bool horizontal) {
    // Перевірка всіх клітинок навколо корабля, щоб між кораблями була вільна клітинка
    for (int j = 0; j < size; ++j) {
        int nx = x + (horizontal ? 0 : j);
        int ny = y + (horizontal ? j : 0);

        // Перевірка на зайнятість клітинок навколо корабля
        for (int dx = -1; dx <= 1; ++dx) {
            for (int dy = -1; dy <= 1; ++dy) {
                int nx_near = nx + dx;
                int ny_near = ny + dy;

                // Перевірка, чи клітинка знаходиться в межах поля
                if (nx_near >= 0 && nx_near < SIZE && ny_near >= 0 && ny_near < SIZE) {
                    if (!isCellEmpty(nx_near, ny_near)) {
                        return false; // Якщо хоча б одна клітинка навколо зайнята, повертаємо false
                    }
                }
            }
        }
    }
    return true;
}


// Додано функцію для перевірки на наявність кораблів поруч(для клітинки)
bool Field::areShipsAdjacent(int x, int y, int size, bool horizontal) const {
    // Перевірка, чи не стоять кораблі поруч з поточним (включаючи діагоналі)
    for (int dx = -1; dx <= size; ++dx) {
        for (int dy = -1; dy <= 1; ++dy) {
            int nx = x + (horizontal ? 0 : dx);
            int ny = y + (horizontal ? dy : 0);

            if (nx >= 0 && ny >= 0 && nx < SIZE && ny < SIZE) {
                if (grid[nx][ny] == SHIP) {
                    return true;  // Якщо поряд є корабель, повертаємо true
                }
            }
        }
    }
    return false;  // Якщо поруч немає кораблів
}


// Перевірка на наявність кораблів поруч (включаючи діагоналі)
bool Field::isSurroundingEmpty(int x, int y, int size, bool horizontal) const {
    // Перевіряємо всі клітинки навколо корабля (включаючи його межі)
    // щоб переконатись, що не буде перехресних кораблів чи кораблів по сусідству
    for (int dx = -1; dx <= size; ++dx) {
        for (int dy = -1; dy <= 1; ++dy) {
            int nx = x + (horizontal ? 0 : dx);
            int ny = y + (horizontal ? dy : 0);

            // Перевірка, чи не вийшли за межі поля
            if (nx >= 0 && ny >= 0 && nx < SIZE && ny < SIZE) {
                // Перевірка на наявність іншого корабля у сусідніх клітинках
                if (grid[nx][ny] == SHIP) {
                    return false;
                }
            }
        }
    }

    return true;  // Якщо поруч немає кораблів
}


// Перевірка, чи можна поставити корабель
bool Field::canPlaceShip(int x, int y, int size, bool horizontal) const {
    // Перевірка, чи є місце для корабля без перекриттів
    if (!isSurroundingEmpty(x, y, size, horizontal)) {
        return false;  // Якщо є сусідні кораблі, повертаємо false
    }

    for (int i = 0; i < size; ++i) {
        int nx = x + (horizontal ? 0 : i);
        int ny = y + (horizontal ? i : 0);
        if (nx < 0 || ny < 0 || nx >= SIZE || ny >= SIZE || grid[nx][ny] == SHIP) {
            return false;  // Якщо виходить за межі або клітинка вже зайнята, повертаємо false
        }
    }
    return true;
}

// Функція для розміщення кораблів для гравця
void Field::placePlayerShips() {
    std::srand(static_cast<unsigned int>(std::time(0)));
    std::vector<std::pair<int, int>> ships = {
        {4, 1},  // Один чотирипалубний
        {3, 2},  // Два трипалубних
        {2, 3},  // Три двопалубних
        {1, 4}   // Чотири однопалубних
    };

    for (const auto& ship : ships) {
        int size = ship.first;
        int count = ship.second;
        for (int i = 0; i < count; ++i) {
            bool placed = false;
            while (!placed) {
                int x = std::rand() % SIZE;
                int y = std::rand() % SIZE;
                bool horizontal = std::rand() % 2;  // Випадковий вибір орієнтації

                // Перевірка на можливість розміщення корабля
                if (canPlaceShip(x, y, size, horizontal)) {
                    // Перевірка на перекриття з іншими кораблями та відстань між ними
                    if (isCellFreeWithBuffer(x, y, size, horizontal)) {
                        // Розміщення кораблів на полі гравця
                        for (int j = 0; j < size; ++j) {
                            int nx = x + (horizontal ? 0 : j);
                            int ny = y + (horizontal ? j : 0);
                            setShip(nx, ny);  // Встановлюємо корабель у відповідну клітинку
                        }
                        placed = true;
                    }
                }
            }
        }
    }
}


// Функція для розміщення кораблів для комп'ютера
void Field::placeComputerShips(const Field& playerField) {
    std::srand(static_cast<unsigned int>(std::time(0)));
    std::vector<std::pair<int, int>> ships = {
        {4, 1},  // Один чотирипалубний
        {3, 2},  // Два трипалубних
        {2, 3},  // Три двопалубних
        {1, 4}   // Чотири однопалубних
    };

    for (const auto& ship : ships) {
        int size = ship.first;
        int count = ship.second;
        for (int i = 0; i < count; ++i) {
            bool placed = false;
            while (!placed) {
                int x = std::rand() % SIZE;
                int y = std::rand() % SIZE;
                bool horizontal = std::rand() % 2;

                // Перевірка на можливість розміщення корабля без перекриття з полем гравця
                if (canPlaceShip(x, y, size, horizontal)) {
                    bool overlap = false;
                    // Перевірка, чи немає перекриттів з кораблями гравця
                    for (int j = 0; j < size; ++j) {
                        int nx = x + (horizontal ? 0 : j);
                        int ny = y + (horizontal ? j : 0);
                        if (playerField.isCellEmpty(nx, ny) == false) {
                            overlap = true;
                            break;
                        }
                    }

                    // Якщо немає перекриттів з кораблями гравця, перевіряємо відстань між кораблями
                    if (!overlap) {
                        bool bufferClear = true;
                        // Перевіряємо на відстань між кораблями
                        for (int j = 0; j < size; ++j) {
                            int nx = x + (horizontal ? 0 : j);
                            int ny = y + (horizontal ? j : 0);

                            // Перевірка на буфер між кораблями
                            if (!isCellFreeWithBuffer(nx, ny, size, horizontal)) {
                                bufferClear = false;
                                break;
                            }
                        }

                        if (bufferClear) {
                            // Розміщуємо кораблі на полі комп'ютера
                            for (int j = 0; j < size; ++j) {
                                int nx = x + (horizontal ? 0 : j);
                                int ny = y + (horizontal ? j : 0);
                                setShip(nx, ny);
                            }
                            placed = true;
                        }
                    }
                }
            }
        }
    }
}


// Виконання пострілу
void Field::shootAt(int x, int y) {
    if (grid[x][y] == SHIP) {
        grid[x][y] = HIT;
        std::cout << "Hit!\n";
        markSurroundingCells(x, y);
    }
    else if (grid[x][y] == EMPTY) {
        grid[x][y] = MISS;
        std::cout << "Miss.\n";
    }
}


// Замальовуємо клітинки навколо пошкодженої
void Field::markSurroundingCells(int x, int y) {
    for (int dx = -1; dx <= 1; ++dx) {
        for (int dy = -1; dy <= 1; ++dy) {
            int nx = x + dx, ny = y + dy;
            if (nx >= 0 && ny >= 0 && nx < SIZE && ny < SIZE && grid[nx][ny] == EMPTY) {
                grid[nx][ny] = MISS;
            }
        }
    }
}


// Виведення поля (для гравця чи комп'ютера)
void Field::printField(bool isComputerField) const {
    std::cout << "   ";
    for (int j = 0; j < SIZE; ++j) {
        std::cout << static_cast<char>('A' + j) << " ";
    }
    std::cout << "\n";

    for (int i = 0; i < SIZE; ++i) {
        std::cout << (i + 1 < 10 ? " " : "") << i + 1 << " ";
        for (int j = 0; j < SIZE; ++j) {
            if (isComputerField) {
                // Для поля комп'ютера показуємо тільки результати пострілів (немає кораблів)
                switch (grid[i][j]) {
                case MISS:
                    std::cout << "O ";
                    break;
                case HIT:
                    std::cout << "X ";
                    break;
                default:
                    std::cout << ". ";
                    break;
                }
            }
            else {
                // Для поля гравця показуємо всі кораблі та результати попадання
                switch (grid[i][j]) {
                case EMPTY:
                    std::cout << ". ";
                    break;
                case SHIP:
                    std::cout << "S ";
                    break;
                case HIT:
                    std::cout << "X ";
                    break;
                case MISS:
                    std::cout << "O ";
                    break;
                }
            }
        }
        std::cout << "\n";
    }
}


// Перевірка на потоплення всіх кораблів
bool Field::areAllShipsSunk() const {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            if (grid[i][j] == SHIP) {
                return false;  // Знайшов ще непотоплений корабель
            }
        }
    }
    return true;  // Всі кораблі потоплені
}

