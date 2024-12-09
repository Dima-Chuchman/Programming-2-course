#include <iostream>
#include <string>
#include <limits> // ��� std::numeric_limits
#include "Field.h"
#include "Computer_Player.h"

int Your_choice() {
    int choice;

    do {
        // ������� ���� ���.
        std::cout << "\033[1;33m==============================================\033[0m" << std::endl;
        std::cout << "\033[1;32m   Congratulations in the game 'Sea Battle' \033[0m" << std::endl;
        std::cout << "\033[1;33m==============================================\033[0m" << std::endl << std::endl;

        std::cout << "\033[1;34m     Choose which mode you want to play: \033[0m" << std::endl << std::endl;
        std::cout << "\033[1;35m 1) \033[0m1 VS 1, against each other." << std::endl;
        std::cout << "\033[1;35m 2) \033[0mYou VS Computer. " << std::endl;
        std::cout << "\033[1;35m 3) \033[0mYou VS Smart Computer. " << std::endl << std::endl;

        std::cout << "\033[1;36m Your choice: \033[0m";
        std::cin >> choice;

        // ����� �������� �� ����������� ����� ������� ���. // ��� std::numeric_limits // ������� � ��������.
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "\033[1;31m ERROR: You entered a non-numeric value. Please enter a number between 1 and 3.\033[0m" << std::endl;
            continue;
        }

        switch (choice) {
        case 1: std::cout << "You have chosen the first option and you will play 1 VS 1 on your computer." << std::endl << std::endl; break;
        case 2: std::cout << "You have chosen option two and will be playing against a computer that shoots randomly." << std::endl << std::endl; break;
        case 3: std::cout << "You have chosen the third option and will play against a smart computer." << std::endl << std::endl; break;
        default:
            std::cout << "\033[1;31m ERROR: You have chosen an option that does not exist, choose an option from 1 to 3.\033[0m" << std::endl << std::endl;
            break;
        }

    } while (choice < 1 || choice > 3);

    return choice;
}

void viewField(int choice) {
    if (choice == 1) {
        std::cout << "\033[1;33mMode: 1 VS 1\033[0m\n" << std::endl;
    }
    else if (choice == 2) {
        std::cout << "\033[1;33mMode: You VS Random Computer\033[0m\n" << std::endl;
    }
    else if (choice == 3) {
        std::cout << "\033[1;33mMode: You VS Smart Computer\033[0m\n" << std::endl;
    }
}

void playGameAgainstRandomComputer() {
    Field playerField; // ������ ���� ��� ������(����)
    Field computerField;  // ������ ���� ��� ����'�����.

    // �������� ������ �� �����
    playerField.placePlayerShips();  // ������� ������ ������
    computerField.placeComputerShips(playerField);  // ����'���� ������ ��� ������

    ComputerPlayer computerPlayer;

    int shotsPerTurn;
    std::cout << "Enter the number of shots per turn (default is 3): ";
    std::cin >> shotsPerTurn;

    // �������� ���� ���
    while (true) {
        // �������� ����
        std::cout << "Your field:\n";
        playerField.printField(false);  // ���� ������
        std::cout << "\nComputer's field (your shots):\n";
        computerField.printField(true);  // ���� ����'�����

        // ճ� ������
        for (int i = 0; i < shotsPerTurn; ++i) {
            char col;
            int row;
            std::cout << "Enter your shot (for example, A1): ";
            std::cin >> col >> row;

            col = toupper(col); // ����� ������ ������, ��� ��������.

            int x = row - 1;
            int y = col - 'A';

            if (x < 0 || x >= SIZE || y < 0 || y >= SIZE) {
                std::cout << "Invalid coordinates. Try again.\n";
                --i;
                continue;
            }
            computerField.shootAt(x, y);
        }

        // ճ� ����'�����
        for (int i = 0; i < shotsPerTurn; ++i) {
            std::pair<int, int> shot = computerPlayer.makeShot(); // �������� ���� ���������
            int x = shot.first;  // ����� �������� ����
            int y = shot.second; // ����� �������� ����
            std::cout << "Computer shot at: " << char('A' + y) << x + 1 << "\n";
            playerField.shootAt(x, y);
        }

        // �������� ���������� ���
        if (computerField.areAllShipsSunk()) {
            std::cout << "\nCongratulations! You won!\n";
            break;
        }

        if (playerField.areAllShipsSunk()) {
            std::cout << "\nGame Over! The computer won.\n";
            break;
        }
    }
}


int main() {
    int choice = Your_choice();

    if (choice == 1) {
        std::cout << "In the process of development, soon..." << std::endl;
    }
    else if(choice == 2) {
        playGameAgainstRandomComputer();
    }
    else if (choice == 3) {
        std::cout << "In the process of development, soon..." << std::endl;
    }


    return 0;
}
