#include "Deck.h"
#include "SidePile.h"
#include <iostream>
using namespace std;


void playRound(Deck& playerDeck, Deck& computerDeck, SidePile& playerSide, SidePile& computerSide, int& playerScore, int& computerScore);
bool isGameOver(const Deck& playerDeck, const Deck& computerDeck);

int main() {

    int playStyle;
    int maxRounds = 0;

    cout << "Welcome to the Card Game!" << endl;
    cout << "Choose play style:" << endl;
    cout << "1. Play until one participant runs out of cards." << endl;
    cout << "2. Play for a fixed number of rounds." << endl;
    cout << "Enter choice: ";
    cin >> playStyle;

    if (playStyle == 2) {
        cout << "Enter the number of rounds to play: ";
        cin >> maxRounds;
    }

    Deck playerDeck(10); // initialize the player and computer's deck
    Deck computerDeck(10);
    SidePile playerSide;
    SidePile computerSide;

    int playerScore = 0, computerScore = 0;
    int roundCounter = 0;

    while (true) {
        if (playStyle == 1 && isGameOver(playerDeck, computerDeck)) {
            break; // End game if deck is empty
        }
        else if (playStyle == 2 && roundCounter >= maxRounds) {
            break; // End game after max rounds
        }
        // transfers side pile to deck for player
        if (playerDeck.getNumCards() == 0 && playerSide.RemainingCards() > 0) {
            for (int i = 0; i < playerSide.RemainingCards(); ++i) {
                playerDeck.addCard(playerSide.pop());
            }
            cout << "Player's side pile has been transferred to the main deck." << endl;
        }

        // transfers side pile to deck for computer
        if (computerDeck.getNumCards() == 0 && computerSide.RemainingCards() > 0) {
            for (int i = 0; i < computerSide.RemainingCards(); ++i) {
                computerDeck.addCard(computerSide.pop());
            }
            cout << "Computer's side pile has been transferred to the main deck." << endl;
        }

        playRound(playerDeck, computerDeck, playerSide, computerSide, playerScore, computerScore);
        roundCounter++;
    }

    // check for the winner
    if (playStyle == 1) {
        if (playerDeck.getNumCards() == 0)
            cout << "Computer wins, player is out of cards!" << endl;
        else if (computerDeck.getNumCards() == 0)
            cout << "Player wins, computer is out of cards!" << endl;
    }
    else {
        cout << "Game over after " << maxRounds << " rounds." << endl;
        if (playerScore > computerScore)
            cout << "Player wins with " << playerScore << " rounds won!" << endl;
        else if (computerScore > playerScore)
            cout << "Computer wins with " << computerScore << " rounds won!" << endl;
        else
            cout << "It's a draw!" << endl;
    }

    return 0;
}

void playRound(Deck& playerDeck, Deck& computerDeck, SidePile& playerSide, SidePile& computerSide, int& playerScore, int& computerScore) {
    //if stack is neither empty nor full, prompt player for their action
    string playerChoice;
    if (playerSide.RemainingCards() != 5 && playerSide.RemainingCards() != 0) {
        cout << "The card on top of your deck is " << playerDeck.peek() << " and there are "<< playerSide.RemainingCards() 
            << " cards remaining in your stack. Would you like to (2) play it and the top card of your stack or (1) push it to your stack and play the next card?" << endl;
        while (playerChoice != "1" && playerChoice != "2") {
            cin >> playerChoice;
        }
    }
    else if (playerSide.RemainingCards() == 0) {
        cout << "Your sidePile is empty, so you must push a card to it and play the next one." << endl;
        playerChoice = "1";
    }
    else {
        cout << "Your sidePile is full, so you must pull a card from it and play it." << endl;
    }

    int playerCard = playerDeck.takeCard();
    int playerSecondCard = 0;
    //push drawn card and draw new one or ...
    if (playerChoice == "1") {
        playerSide.push(playerCard);
        playerCard = playerDeck.takeCard();
    }
    //... pop top card from stack to be used as second card
    else { 
        playerSecondCard = playerSide.pop();
    }


    int computerCard = computerDeck.takeCard();
    int computerSecondCard = 0;
    //push drawn card and draw new one or ...
    if (computerSide.RemainingCards() == 0 || (computerCard <= 5 && computerSide.RemainingCards() != 5)) {
        computerSide.push(computerCard);
        computerCard = computerDeck.takeCard();
    }
    //... pop top card from stack to be used as second card
    else{
        computerSecondCard = computerSide.pop();
    }

    cout << "Player draws: " << playerCard; 
    if (playerSecondCard) cout << " and " << playerSecondCard;
    cout << ", Computer draws: " << computerCard;
    if (computerSecondCard) cout << " and " << computerSecondCard;
    cout << endl;

    if (playerCard + playerSecondCard > computerCard + computerSecondCard) {
        cout << "Player wins the round!" << endl;
        //if add cards to the player's deck
        playerDeck.addCard(playerCard);
        playerDeck.addCard(computerCard);
        //if second cards were played, add them to the deck
        if (playerSecondCard) playerDeck.addCard(playerSecondCard);
        if (computerSecondCard) playerDeck.addCard(computerSecondCard);
        playerScore++;
    }
    else if (computerCard + computerSecondCard > playerCard + playerSecondCard) {
        cout << "Computer wins the round!" << endl;
        //if add cards to the computer's deck
        computerDeck.addCard(playerCard);
        computerDeck.addCard(computerCard);
        //if second cards were played, add them to the deck
        if (playerSecondCard) computerDeck.addCard(playerSecondCard);
        if (computerSecondCard) computerDeck.addCard(computerSecondCard);
        computerScore++;
    }
    else {
        cout << "It's a tie! Cards go to the computer." << endl;
        //if add cards to the computer's deck
        computerDeck.addCard(playerCard);
        computerDeck.addCard(computerCard);
        //if second cards were played, add them to the deck
        if (playerSecondCard) computerDeck.addCard(playerSecondCard);
        if (computerSecondCard) computerDeck.addCard(computerSecondCard);
        computerScore++;
    }
}

bool isGameOver(const Deck& playerDeck, const Deck& computerDeck) {
    return playerDeck.getNumCards() == 0 || computerDeck.getNumCards() == 0;
}
