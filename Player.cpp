#include <iostream>
#include "Player.h"

    Player::Player() {
        money = 0;
    }
    Player::Player(int initial_Money) {
        money = initial_Money;
    }    
    void Player::setMoney(double amount) {
        money = amount;
    }
    double Player::getMoney() const {
        return money;
    }
    int Player::spinWheel() {
        return wheel.spin();  //I am not completely sure of this implementation
    }
 

