#include "SidePile.h"

SidePile::SidePile()
{
    top = -1;
    for (int i = 0; i < maxCap; i++) {
        stack[i] = 0;
    }
}

void SidePile::push(int card) {
    if (top < maxCap - 1) {
        stack[++top] = card;
    }
    else {
        std::cout << "Side pile is full." << std::endl;
    }
}
int SidePile::pop() {
    if (top >= 0) {
        return stack[top--];
    }
    else {
        std::cout << "Side pile is empty." << std::endl;
    }
}
int SidePile::RemainingCards() const {
    return top + 1;
}
