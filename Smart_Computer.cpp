#include "Smart_Computer.h"
#include <iostream>

Smart_Computer::Smart_Computer(Field& pField, Field& cField, ComputerPlayer& p, ComputerPlayer& c, int N)
    : playerField(pField), computerField(cField), player(p), computer(c), N(N), gameOver(false) {}

void Smart_Computer::startGame() {
    // ����� ������� ���
}

void Smart_Computer::playerTurn(ComputerPlayer& currentPlayer, Field& currentField, Field& enemyField) {
    // ����� ���� ������
}

void Smart_Computer::computerTurn(ComputerPlayer& currentPlayer, Field& currentField, Field& enemyField) {
    // ����� ���� ����'�����
}

void Smart_Computer::displayResults() {
    // ��������� ���������� ���� ����
}

bool Smart_Computer::checkWinner() {
    // �������� �� ��������
}
