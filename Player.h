#pragma once
#include "Wheel.h"
class Player {
private:
    
    double money;
    Wheel wheel = Wheel(10);

public:
    Player();
    Player(int initial_Money);
    void setMoney(double amount);
    double getMoney() const;
    int spinWheel();
};
