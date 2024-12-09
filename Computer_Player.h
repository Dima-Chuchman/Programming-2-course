#ifndef COMPUTER_PLAYER_H
#define COMPUTER_PLAYER_H

#include "Field.h"
#include <cstdlib>
#include <ctime>
#include <set>

class ComputerPlayer {
public:
    ComputerPlayer();
    std::pair<int, int> makeShot();

private:
    std::set<std::pair<int, int>> shotHistory;  // Множина для збереження вже зроблених пострілів, без повторень.
};

#endif
