#ifndef HARDMODEWHEEL_H
#define HARDMODEWHEEL_H

#include "Wheel.h"

class HardModeWheel : public Wheel {
public:
    HardModeWheel();

    int spin(int playerOutcome); // overload spin function
};

#endif