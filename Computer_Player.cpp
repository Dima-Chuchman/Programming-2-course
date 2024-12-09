#include "Computer_Player.h"
#include <cstdlib>
#include <ctime>


ComputerPlayer::ComputerPlayer() {
    std::srand(static_cast<unsigned int>(std::time(0))); // Конструктор, який ініціалізує генератор випадкових чисел
}


std::pair<int, int> ComputerPlayer::makeShot() {
    int x = std::rand() % 10;
    int y = std::rand() % 10;
    return {x, y};
}
