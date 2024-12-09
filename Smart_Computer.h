#ifndef SMART_COMPUTER_H
#define SMART_COMPUTER_H

#include "Field.h"
#include "Computer_Player.h"

class Smart_Computer {
public:
    Smart_Computer(Field& playerField, Field& computerField, ComputerPlayer& player, ComputerPlayer& computer, int N = 3);

    // Старт гри
    void startGame();

    // Виведення результатів після кожного ходу
    void displayResults();

    // Хід гравця
    void playerTurn(ComputerPlayer& player, Field& playerField, Field& enemyField);

    // Хід комп'ютера
    void computerTurn(ComputerPlayer& computer, Field& playerField, Field& computerField);

    // Перевірка на перемогу
    bool checkWinner();

private:
    Field& playerField;
    Field& computerField;
    ComputerPlayer& player;
    ComputerPlayer& computer;
    int N; // Кількість пострілів за один хід
    bool gameOver;
};

#endif
#pragma once
