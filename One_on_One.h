#pragma once
#ifndef ONE_ON_ONE_H
#define ONE_ON_ONE_H

#include "Field.h"
#include "Computer_Player.h"

class One_on_One {
public:
    One_on_One(Field& field1, Field& field2, ComputerPlayer& player1, ComputerPlayer& player2, int N = 3);

    // ����� ���
    void startGame();

    // ��������� ���������� ���� ������� ����
    void displayResults();

    // ճ� ������
    void playerTurn(ComputerPlayer& currentPlayer, Field& currentField, Field& enemyField);

    // �������� �� ��������
    bool checkWinner();

private:
    Field& field1;
    Field& field2;
    ComputerPlayer& player1;
    ComputerPlayer& player2;
    int N; // ʳ������ ������� �� ���� ���
    bool gameOver;
    bool turn;
};

#endif
