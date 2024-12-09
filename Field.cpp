#include "Field.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

Field::Field() : grid(SIZE, std::vector<Cell>(SIZE, EMPTY)) {}


// ��������, �� ������� �����
bool Field::isCellEmpty(int x, int y) const {
    return grid[x][y] == EMPTY;
}


// ������������ �������
void Field::setShip(int x, int y) {
    grid[x][y] = SHIP;
}


// ������� ��� ��������, �� � ������� ����� � �������� ���������
bool Field::isCellFreeWithBuffer(int x, int y, int size, bool horizontal) {
    // �������� ��� ������� ������� �������, ��� �� ��������� ���� ����� �������
    for (int j = 0; j < size; ++j) {
        int nx = x + (horizontal ? 0 : j);
        int ny = y + (horizontal ? j : 0);

        // �������� �� ��������� ������� ������� �������
        for (int dx = -1; dx <= 1; ++dx) {
            for (int dy = -1; dy <= 1; ++dy) {
                int nx_near = nx + dx;
                int ny_near = ny + dy;

                // ��������, �� ������� ����������� � ����� ����
                if (nx_near >= 0 && nx_near < SIZE && ny_near >= 0 && ny_near < SIZE) {
                    if (!isCellEmpty(nx_near, ny_near)) {
                        return false; // ���� ���� � ���� ������� ������� �������, ��������� false
                    }
                }
            }
        }
    }
    return true;
}


// ������ ������� ��� �������� �� �������� ������� �����(��� �������)
bool Field::areShipsAdjacent(int x, int y, int size, bool horizontal) const {
    // ��������, �� �� ������ ������ ����� � �������� (��������� �������)
    for (int dx = -1; dx <= size; ++dx) {
        for (int dy = -1; dy <= 1; ++dy) {
            int nx = x + (horizontal ? 0 : dx);
            int ny = y + (horizontal ? dy : 0);

            if (nx >= 0 && ny >= 0 && nx < SIZE && ny < SIZE) {
                if (grid[nx][ny] == SHIP) {
                    return true;  // ���� ����� � ��������, ��������� true
                }
            }
        }
    }
    return false;  // ���� ����� ���� �������
}


// �������� �� �������� ������� ����� (��������� �������)
bool Field::isSurroundingEmpty(int x, int y, int size, bool horizontal) const {
    // ���������� �� ������� ������� ������� (��������� ���� ���)
    // ��� ������������, �� �� ���� ����������� ������� �� ������� �� ��������
    for (int dx = -1; dx <= size; ++dx) {
        for (int dy = -1; dy <= 1; ++dy) {
            int nx = x + (horizontal ? 0 : dx);
            int ny = y + (horizontal ? dy : 0);

            // ��������, �� �� ������ �� ��� ����
            if (nx >= 0 && ny >= 0 && nx < SIZE && ny < SIZE) {
                // �������� �� �������� ������ ������� � ������ ��������
                if (grid[nx][ny] == SHIP) {
                    return false;
                }
            }
        }
    }

    return true;  // ���� ����� ���� �������
}


// ��������, �� ����� ��������� ��������
bool Field::canPlaceShip(int x, int y, int size, bool horizontal) const {
    // ��������, �� � ���� ��� ������� ��� ����������
    if (!isSurroundingEmpty(x, y, size, horizontal)) {
        return false;  // ���� � ����� ������, ��������� false
    }

    for (int i = 0; i < size; ++i) {
        int nx = x + (horizontal ? 0 : i);
        int ny = y + (horizontal ? i : 0);
        if (nx < 0 || ny < 0 || nx >= SIZE || ny >= SIZE || grid[nx][ny] == SHIP) {
            return false;  // ���� �������� �� ��� ��� ������� ��� �������, ��������� false
        }
    }
    return true;
}

// ������� ��� ��������� ������� ��� ������
void Field::placePlayerShips() {
    std::srand(static_cast<unsigned int>(std::time(0)));
    std::vector<std::pair<int, int>> ships = {
        {4, 1},  // ���� ��������������
        {3, 2},  // ��� �����������
        {2, 3},  // ��� �����������
        {1, 4}   // ������ ������������
    };

    for (const auto& ship : ships) {
        int size = ship.first;
        int count = ship.second;
        for (int i = 0; i < count; ++i) {
            bool placed = false;
            while (!placed) {
                int x = std::rand() % SIZE;
                int y = std::rand() % SIZE;
                bool horizontal = std::rand() % 2;  // ���������� ���� ��������

                // �������� �� ��������� ��������� �������
                if (canPlaceShip(x, y, size, horizontal)) {
                    // �������� �� ���������� � ������ ��������� �� ������� �� ����
                    if (isCellFreeWithBuffer(x, y, size, horizontal)) {
                        // ��������� ������� �� ��� ������
                        for (int j = 0; j < size; ++j) {
                            int nx = x + (horizontal ? 0 : j);
                            int ny = y + (horizontal ? j : 0);
                            setShip(nx, ny);  // ������������ �������� � �������� �������
                        }
                        placed = true;
                    }
                }
            }
        }
    }
}


// ������� ��� ��������� ������� ��� ����'�����
void Field::placeComputerShips(const Field& playerField) {
    std::srand(static_cast<unsigned int>(std::time(0)));
    std::vector<std::pair<int, int>> ships = {
        {4, 1},  // ���� ��������������
        {3, 2},  // ��� �����������
        {2, 3},  // ��� �����������
        {1, 4}   // ������ ������������
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

                // �������� �� ��������� ��������� ������� ��� ���������� � ����� ������
                if (canPlaceShip(x, y, size, horizontal)) {
                    bool overlap = false;
                    // ��������, �� ���� ���������� � ��������� ������
                    for (int j = 0; j < size; ++j) {
                        int nx = x + (horizontal ? 0 : j);
                        int ny = y + (horizontal ? j : 0);
                        if (playerField.isCellEmpty(nx, ny) == false) {
                            overlap = true;
                            break;
                        }
                    }

                    // ���� ���� ���������� � ��������� ������, ���������� ������� �� ���������
                    if (!overlap) {
                        bool bufferClear = true;
                        // ���������� �� ������� �� ���������
                        for (int j = 0; j < size; ++j) {
                            int nx = x + (horizontal ? 0 : j);
                            int ny = y + (horizontal ? j : 0);

                            // �������� �� ����� �� ���������
                            if (!isCellFreeWithBuffer(nx, ny, size, horizontal)) {
                                bufferClear = false;
                                break;
                            }
                        }

                        if (bufferClear) {
                            // �������� ������ �� ��� ����'�����
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


// ��������� �������
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


// ����������� ������� ������� ����������
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


// ��������� ���� (��� ������ �� ����'�����)
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
                // ��� ���� ����'����� �������� ����� ���������� ������� (���� �������)
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
                // ��� ���� ������ �������� �� ������ �� ���������� ���������
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


// �������� �� ���������� ��� �������
bool Field::areAllShipsSunk() const {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            if (grid[i][j] == SHIP) {
                return false;  // ������� �� ������������ ��������
            }
        }
    }
    return true;  // �� ������ ��������
}

