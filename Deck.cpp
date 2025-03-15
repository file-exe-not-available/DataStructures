#include "Deck.h"
#include <random>
#include <iostream>
using namespace std;

Deck::Deck(int number_of_cards){
	//set top to point the the index 0 in deck
	top = 0;

	//set bottom to point to the index 10 int the deck
	bottom = number_of_cards;

	//set numCards to 10
	numCards = number_of_cards;

	//creating a random number generator that will generate numbers from 1 to 10, inclusive
	random_device dev;
	mt19937 rng(dev());
	uniform_int_distribution<std::mt19937::result_type> dist10(1, 10);

	//fill the first <number_of_cards> indexes of the deck with random numbers [1,10]
	for (int i = 0; i < number_of_cards; i++) {
		deck[i] = dist10(rng);
	}
}

void Deck::addCard(int card)
{
	//set the value at index bottom to the input value
	deck[bottom] = card;

	//move the bottom pointer up one and mod by the lenth of the deck array in case it is supposed to wrap around to the start of the array
	bottom = (bottom + 1) % DECKSIZE;

	//increment numCards
	numCards++;
}

int Deck::takeCard() {
	//save the value at index top to be returned
	int card = deck[top];

	//move the top pointer up one and mod by the lenth of the deck array in case it is supposed to wrap around to the start of the array
	top = (top + 1) % DECKSIZE;
	
	//decrement numCards
	numCards--;

	//return the value saved before
	return card;
}

int Deck::peek() {
	//return the value at index top
	return deck[top];
}

int Deck::getNumCards() const{
	//return the value of numCards
	return numCards;
}
