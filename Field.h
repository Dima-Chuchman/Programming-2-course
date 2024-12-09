#ifndef FIELD_H
#define FIELD_H

#include <vector>
#include <utility> // ��� std::pair

const int SIZE = 10;  // ����� ����

// ���������� ���� �������
enum Cell {
    EMPTY,
    SHIP,
    HIT,
    MISS
};

class Field {
public:
    Field();  // ����������� �����

    // ������ ��� ���
    void placePlayerShips();  // ��������� ������� ������
    void placeComputerShips(const Field& playerField);   // ��������� ������� ����'�����. 
    bool canPlaceShip(int x, int y, int size, bool horizontal) const; // ��������, �� ����� ��������� ��������
    void shootAt(int x, int y);  // ��������� �������
    void printField(bool isComputerField) const;  // ��������� ���� (��� ������ �� ����'�����)
    bool isCellFreeWithBuffer(int x, int y, int size, bool horizontal); // �� � ����� ���� ��� �������.
    bool areAllShipsSunk() const;// �������� �� ���������� ��� �������
    bool areShipsAdjacent(int x, int y, int size, bool horizontal) const; // ����� ��� �������� �� �������� ������� �����

private:
    std::vector<std::vector<Cell>> grid;  // ���� ���
    bool isCellEmpty(int x, int y) const;  // ��������, �� ������� �����
    void setShip(int x, int y);  // ������������ �������
    void markSurroundingCells(int x, int y);  // ����������� ������� ������� ����������
    bool isSurroundingEmpty(int x, int y, int size, bool horizontal) const; // �������� �� �������� ������� �����
};

#endif
