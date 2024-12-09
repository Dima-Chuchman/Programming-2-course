#include "Smart_Computer.h"
#include <iostream>

Smart_Computer::Smart_Computer(Field& pField, Field& cField, ComputerPlayer& p, ComputerPlayer& c, int N)
    : playerField(pField), computerField(cField), player(p), computer(c), N(N), gameOver(false) {}

void Smart_Computer::startGame() {
    // Логіка початку гри
}

void Smart_Computer::playerTurn(ComputerPlayer& currentPlayer, Field& currentField, Field& enemyField) {
    // Логіка ходу гравця
}

void Smart_Computer::computerTurn(ComputerPlayer& currentPlayer, Field& currentField, Field& enemyField) {
    // Логіка ходу комп'ютера
}

void Smart_Computer::displayResults() {
    // Виведення результатів після ходу
}

bool Smart_Computer::checkWinner() {
    // Перевірка на перемогу
}
