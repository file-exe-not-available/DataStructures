#pragma once
#ifndef DECK_H
#define DECK_H
#include <iostream>

const int DECKSIZE = 20;

class Deck {
private:
	//records the number of cards currently in the deck
	int numCards;

	//records the index of the card a the top of the deck
	int top;

	//records the index after the index holding the top car of the deck
	int bottom;

	//array hold the values of the cards in the deck
	int deck[DECKSIZE] = { 0 };

public:
	//constructor takes the number of cards in the deck to start
	Deck(int);

	//adds a card to the bottom of the deck
	void addCard(int);

	//removes and plays a card from the top of the deck
	int takeCard();

	//returns the number of cards currently in the deck
	int getNumCards() const;

	//returns the value of the card at the top of the deck, without removing it
	int peek();
};
#endif