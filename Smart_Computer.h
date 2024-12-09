#ifndef SMART_COMPUTER_H
#define SMART_COMPUTER_H

#include "Field.h"
#include "Computer_Player.h"

class Smart_Computer {
public:
    Smart_Computer(Field& playerField, Field& computerField, ComputerPlayer& player, ComputerPlayer& computer, int N = 3);

    // ����� ���
    void startGame();

    // ��������� ���������� ���� ������� ����
    void displayResults();

    // ճ� ������
    void playerTurn(ComputerPlayer& player, Field& playerField, Field& enemyField);

    // ճ� ����'�����
    void computerTurn(ComputerPlayer& computer, Field& playerField, Field& computerField);

    // �������� �� ��������
    bool checkWinner();

private:
    Field& playerField;
    Field& computerField;
    ComputerPlayer& player;
    ComputerPlayer& computer;
    int N; // ʳ������ ������� �� ���� ���
    bool gameOver;
};

#endif
#pragma once
