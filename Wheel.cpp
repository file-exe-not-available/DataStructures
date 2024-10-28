#include <cstdlib> // Include for rand() and srand()
#include <ctime>   // Include for time()
#include "Wheel.h"

using namespace std;

Wheel::Wheel(int maxVal) : maxValue(maxVal) {
    srand(static_cast<unsigned int>(time(0))); // Seed the random number generator
}

int Wheel::spin() {
    return (rand() % maxValue) + 1; // Generate a number between 1 and maxValue
}
