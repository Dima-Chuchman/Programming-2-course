#include "One_on_One.h"
#include <iostream>

One_on_One::One_on_One(Field& f1, Field& f2, ComputerPlayer& p1, ComputerPlayer& p2, int N)
    : field1(f1), field2(f2), player1(p1), player2(p2), N(N), gameOver(false), turn(true) {}

void One_on_One::startGame() {
    // ����� ������� ���
}

void One_on_One::playerTurn(ComputerPlayer& currentPlayer, Field& currentField, Field& enemyField) {
    // ����� ���� ������
}

void One_on_One::displayResults() {
    // ��������� ���������� ���� ����
}

bool One_on_One::checkWinner() {
    // �������� �� ��������
}
