#include <iostream>
#include <string>
#include <iomanip>
#include "Player.h"
#include "HardModeWheel.h"
double getBet();
int getBetChange();
bool yesOrNo(std::string);


int main() {
    Player player = Player(1000);
    Wheel housewheel = Wheel(10);
    HardModeWheel hardwheel = HardModeWheel();
    int hardsize = 10;
    bool hard = false;
    int playerBall;
    int houseBalls[2];
    int houseLosses = 0;
    int houseWins = 0;
    double bet;
    int num;

    std::cout << std::fixed;
    std::cout << std::setprecision(2);

    if (yesOrNo("Activate hard mode? (y/n)\n")) {
        hard = true;
    }

    while (player.getMoney() > 0) {

        bet = getBet();

        playerBall = player.spinWheel();
        std::cout << "You rolled a " << playerBall << ". Would you like to: \n(1) Double your bet?\n(2) Halve your bet?\n(3)Keep your bet the same?\n";

        num = getBetChange();
        if (num == 1) {
            bet = bet * 2;
            houseBalls[0] = hard ? hardwheel.spin(hardsize) : housewheel.spin();
            houseBalls[1] = hard ? hardwheel.spin(hardsize) : housewheel.spin();
            std::cout << "The house rolled a " << houseBalls[0] << " and a " << houseBalls[1] << ".\n";
            if (playerBall <= houseBalls[0] || playerBall <= houseBalls[1]) {
                std::cout << "You lost $" << bet << ".\n";
                player.setMoney(player.getMoney() - bet);
                houseLosses = 0;
                houseWins++;
            }
            else {
                std::cout << "You won $" << bet << "!\n";
                player.setMoney(player.getMoney() + bet);
                houseLosses++;
                houseWins = 0;
            }
        }
        if (num == 2) {
            bet = bet / 2;
            houseBalls[0] = hard ? hardwheel.spin(hardsize) : housewheel.spin();
            houseBalls[1] = hard ? hardwheel.spin(hardsize) : housewheel.spin();
            std::cout << "The house rolled a " << houseBalls[0] << " and a " << houseBalls[1] << ".\n";
            if (playerBall <= houseBalls[0] && playerBall <= houseBalls[1]) {
                std::cout << "You lost $" << bet << ".\n";
                player.setMoney(player.getMoney() - bet);
                houseLosses = 0;
                houseWins++;
            }
            else {
                std::cout << "You won $" << bet << "!\n";
                player.setMoney(player.getMoney() + bet);
                houseLosses++;
                houseWins = 0;
            }
        }
        if (num == 3) {
            bet = bet;
            houseBalls[0] = hard ? hardwheel.spin(hardsize) : housewheel.spin();
            std::cout << "The house rolled a " << houseBalls[0] << ".\n";
            if (playerBall <= houseBalls[0]) {
                std::cout << "You lost $" << bet << ".\n";
                player.setMoney(player.getMoney() - bet);
                houseLosses = 0;
                houseWins++;
            }
            else {
                std::cout << "You won $" << bet << "!\n";
                player.setMoney(player.getMoney() + bet);
                houseLosses++;
                houseWins = 0;
            }
        }
        if (houseLosses == 2) {
            houseLosses = 0;
            if (hardsize == 5) {
                hardsize = 10;
            }
            else {
                hardsize = 20;
            }
        }
        else if(houseWins == 2) {
            houseWins = 0;
            if (hardsize == 20) {
                hardsize = 10;
            }
            else {
                hardsize = 5;
            }
        }

        if (player.getMoney() > 0 && yesOrNo("Would you like to cash out? (y/n)\n")) {
            std::cout << "Congratulations!! You cashed out with $" << player.getMoney() << "!!\n";
            return 1;
        }
    }
    std::cout << "Congratulations!! You are Broke!!\n";
    return 1;
}

int getBetChange() {
    std::string input;
    int num = 0;
    while (!(num == 1 || num == 2 || num == 3)) {
        std::cout << "(press 1, 2 or 3 and press enter)\n";
        std::cin >> input;
        num = stoi(input);
    }
    return num;
}

double getBet() {
    double bet;
    std::string input;
    bet = 0;
    while (bet <= 0) {
        std::cout << "Place your bet:\n";
        std::cin >> input;
        bet = stod(input);
    }
    return bet;
}

bool yesOrNo(std::string message) {
	std::string input;
    while (!(input == "y" || input == "Y" || input == "n" || input == "N" || input == "yes" || input == "Yes" || input == "no" || input == "No")) {
        std::cout << message;
        std::cin >> input;
    }
    return (input == "y" || input == "Y" || input == "yes" || input == "Yes");
}