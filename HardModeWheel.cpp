#include "HardModeWheel.h"
#include <iostream>
#include <random>

using namespace std;

HardModeWheel::HardModeWheel() : Wheel(10) {}
int HardModeWheel::spin(int playerOutcome) {
	random_device rd;   // used chatGPT to to get the random number generator because rand() wasn't working properly.             
	mt19937 gen(rd());
	uniform_int_distribution<> dist(1, playerOutcome);

	return dist(gen);
}