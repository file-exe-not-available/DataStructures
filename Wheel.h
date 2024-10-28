#ifndef WHEEL_H
#define WHEEL_H

#include <iostream>
#include<random>
using namespace std;

class Wheel {
protected:
    int maxValue;

public:
    Wheel(int maxVal);

    int spin();
};

#endif