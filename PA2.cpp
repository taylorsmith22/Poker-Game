//Taylor Smith
//CS 216 - 002
//Project 2

#include <iostream>
#include <iomanip>
#include <vector>
#include "pokerhand.h"
#include "deck.h"

using namespace std;

//Set global constants
const int TOTALCARDS = 7;
const int HANDS = 5;

//Find the best 5 cards for a poker hand
PokerHand best_FIVE_out_of_SEVEN(const vector<Card>& cards);

int main() {

    char input;
    while (input != 'Q' && input != 'q') {

    //Create and shuffle a deck
    Deck playDeck;
    playDeck.createDeck();
    playDeck.shuffleDeck();

    //Create card vectors for the player, the computer, and then the shared cards between them
    vector<Card> Cards;
    vector<Card> cardsInMyHand;
    vector<Card> cardsInComputersHand;

    //Assign the first 2 cards that are in the players hand and print them
    cardsInMyHand.push_back(playDeck.deal_a_card());
    cardsInMyHand.push_back(playDeck.deal_a_card());
    cout << "The cards in your hand are:" << endl;
    cout << "    ";
    cardsInMyHand[0].print();
    cout << endl << "         ";
    cardsInMyHand[1].print();
    cout << endl;

    //Assign the 5 shared cards between the computer and the player and print them
    for (int i = 0; i < HANDS; i++)
        Cards.push_back(playDeck.deal_a_card());
    cout << "The FIVE cards on the deck to share are:" << endl;
    cout << "    *************************" << endl;
    for (int i = 0; i < HANDS; i++)
    {
        cout << "    *   ";
        Cards[i].print();
        cout << "        *" << endl;
    }
    cout << "    *************************" << endl;

    //Assign the first two cards of the computers hand and print them
    cardsInComputersHand.push_back(playDeck.deal_a_card());
    cardsInComputersHand.push_back(playDeck.deal_a_card());
    cout << "The Cards in computer's hand are:" << endl;
    cout << "    ";
    cardsInComputersHand[0].print();
    cout << endl << "         ";
    cardsInComputersHand[1].print();
    cout << endl;

    //Add the shared cards to both the players and the computers hands
    for(int i = 0; i < HANDS; i++)
    {
        cardsInMyHand.push_back(Cards[i]);
        cardsInComputersHand.push_back(Cards[i]);
    }

    //Create poker hands for the player and the computer
    PokerHand playersCards;
    PokerHand computersCards;

    //Get the best 5 out of 7 cards for the players hand and print the best hand
    cout << endl << "Player 1: You" << endl;
    playersCards = best_FIVE_out_of_SEVEN(cardsInMyHand);
    cout << "*** Best five-card hand ***" << endl;
    playersCards.print();

    //Get the best 5 out of 7 cards for the computers hand and print the best hand 
    cout << endl << endl << "Player 2: Computer" << endl;
    computersCards = best_FIVE_out_of_SEVEN(cardsInComputersHand);
    cout << "*** Best five-card hand ***" << endl;
    computersCards.print();
    cout << endl << endl;

    //Check to see who wins the game
    if (playersCards.compareHand(computersCards) == 1) //If the player wins a message will appear
        cout << "Congratulations, you win the game!" << endl;
    else if (playersCards.compareHand(computersCards) == -1) //if the player loses a message will appear
        cout << "Sorry, the computer wins the game!" << endl;
    else      
        cout << "It is a tie game!" << endl; //If the theres a tie a message will appear

    //Asks the user if they would like to play again
    cout << endl << "Do you want to play poker game again (press \'q\' or \'Q\' to quit the program) ";
    cin.get(input);
   // cin.ignore();
    cin.clear();
  //  cin.ignore(256,'\n');
   }

    //thank the user for using the program
    cout << "Thank you for using this program!" << endl;
    return 0;
}

PokerHand best_FIVE_out_of_SEVEN(const vector<Card>& cards)
 {

     PokerHand bestH;
     PokerHand cardsH;

     // check if the parameter is valid
     if (cards.size() != TOTALCARDS)
     {
         cout << "Invalid Cards, we need SEVEN cards!" << endl;
         return cardsH; // return a PokerHand object by default constructor
     }

     // Consider all possible ways of dropping two cards
     // from all seven cards
     // i is the index of the first card dropped
     // and j is the index of the second card dropped.
     // There are 21 different ways to pick 5 cards out of 7
     for (int i=0; i < TOTALCARDS; i++)
     {
         for (int j=i+1; j < TOTALCARDS; j++)
         {
             Card pick[HANDS];
             int index = 0;

             // Iterate over all seven cards and assign them to the pick[] array
             // exclude cards with index numbers of #i and #j.
             for (int k=0 ; k < TOTALCARDS ; k++)
             {
                 if (k == i || k == j)
                     continue;
                 pick[index] = cards[k];
                 index++;
             }

             // create a PokerHand with pick[]
             cardsH.setPokerHand(pick, HANDS);

             // Check to see if current pick is better than
             // the best you have seen so far
             if (bestH.compareHand(cardsH) < 0)
             {
                 bestH = cardsH ;
             }
         }
     }
     return bestH;
 }
