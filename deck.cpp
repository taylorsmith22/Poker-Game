#include "deck.h"

void Deck::createDeck() {

    for (int s= (int)Card::cSuits::Spade; s < (int)Card::cSuits::Spade+SUITS; s++) {
        for (Card::cPoints val = CARD_START; val < CARD_START + POINTS; val++) {
          //  Card::cSuits suit = static_cast<Card::cSuits>(s);
            Card::cSuits suit = Card::cSuits(s);
            Card newcard(suit, val);
            deck.push_back(newcard);
        }
    }
}


void Deck::shuffleDeck(){
    
    srand(time(0));
    Card temp;
    for (int i = deck.size()-1; i>= 1; i--)
    {
        int j = rand() % (i+1);
        temp = deck[j];
        deck[j] = deck[i];
        deck[i] = temp;
    }
}

Card Deck::deal_a_card() {
    if (deck.size() == 0) {
        cout << "The deck size is invalid";
        return Card(Card::cSuits::Invalid,0);
    }
    else {
    int cardNum = deck.size() - 1;
    Card card = deck[cardNum];
    deck.pop_back();
    return card;
    }
}
