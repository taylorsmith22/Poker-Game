#include "pokerhand.h"

//Set the poker hands point to 0 and its rank to NoRank
PokerHand::PokerHand(){
    hand_rank.point = 0;
    hand_rank.kind = Rank::hRanks::NoRank;
}

//Sets the 5 cards in a players PokerHand and then determines the PokerHands rank
void PokerHand::setPokerHand(Card in_hand[], int size){
    if (size != HANDS)
        cout << "Invalid number of cards!" << endl;
    else {
        for (int i = 0; i < HANDS; i++)
            cards[i] = in_hand[i];
    }

    isHighCard();
    isPair();
    isThreeOfAKind();
    isStraight();
    isFlush();
    isFullHouse();
    isFourOfAKind();
    isStraightFlush();
    
}

//Sorts the PokerHand from highest to lowest point value
void PokerHand::sort() {
    for (int i = 0; i < HANDS-1; i++){
        for (int j = i+1; j < HANDS; j++){
            if (cards[j].point > cards[i].point){
                Card temp = cards[i];
                cards[i] = cards[j];
                cards[j] = temp;
            }
                
        }
    }
}

//Determines if the PokerHands cards all have the same suit
bool PokerHand::isAllOneSuit() const {
    if ((cards[0].suit == cards[1].suit) && (cards[1].suit == cards[2].suit) && (cards[2].suit == cards[3].suit) && (cards[3].suit == cards[4].suit))
                    return true;
    else
        return false;
}

//Determines if the PokerHands Cards point values come one right after the other
bool PokerHand::isSequence() const {
    if ((cards[0].point == cards[1].point + 1) && (cards[1].point == cards[2].point + 1) && (cards[2].point == cards[3].point + 1) && (cards[3].point == cards[4].point + 1))
                    return true; 
    else 
        return false;
}
 
//Determines if the PokerHands rank is a Straight Flush
bool PokerHand::isStraightFlush(){
    sort();
    if ((isSequence() == true) && (isAllOneSuit() == true)){
        hand_rank.kind = Rank::hRanks::StraightFlush;
        hand_rank.point = cards[0].point;
        return true;
    }
    else 
        return false;
}

//Determines if the PokerHands rank is a Four of a Kind
bool PokerHand::isFourOfAKind(){
    sort();
    if ((cards[0].point == cards[1].point) && (cards[1].point == cards[2].point) && (cards[2].point == cards[3].point)){
                hand_rank.kind = Rank::hRanks::FourOfAKind;
                hand_rank.point = cards[0].point;
                    return true;
                    }
    else if ((cards[1].point == cards[2].point) && (cards[2].point == cards[3].point) && (cards[3].point == cards[4].point)){
                hand_rank.kind = Rank::hRanks::FourOfAKind;
                hand_rank.point = cards[1].point;
                return true; }
    else 
        return false;
}

//Determines if the PokerHands rank is a Full House
bool PokerHand::isFullHouse() {
    sort();
    if ((cards[0].point == cards[1].point) && (cards[1].point == cards[2].point) && (cards[3].point == cards[4].point)) {
                hand_rank.kind = Rank::hRanks::FullHouse;
                hand_rank.point = cards[0].point;
                return true; 
            } 
    else if ((cards[0].point == cards[1].point) && (cards[2].point == cards[3].point) && (cards[3].point == cards[4].point)) {
                hand_rank.kind = Rank::hRanks::FullHouse;
                hand_rank.point = cards[4].point;
                return true;
            }
    else 
        return false;
}

//Determines if the PokerHands rank is a Flush
bool PokerHand::isFlush() {
    sort();
    if (isAllOneSuit() == true) {
       hand_rank.kind = Rank::hRanks::Flush;
       hand_rank.point = cards[0].point;
       return true;
    }
    else 
        false;
}

//Determines if the PokerHands rank is a Straight
bool PokerHand::isStraight() {
    sort();
    if (isSequence() == true){
        hand_rank.kind = Rank::hRanks::Straight;
        hand_rank.point = cards[0].point;
        return true;
    }
    else 
        return false;
}

//Determines if the PokerHands rank is a three of a kind
bool PokerHand::isThreeOfAKind() {
    sort();
    
    int num;
    int same = 1;
    if ((cards[0].point == cards[1].point) && (cards[1].point == cards[2].point)) {
        same++;
        num = cards[0].point;
    }
    if ((cards[1].point == cards[2].point) && (cards[2].point == cards[3].point)) {
        same++;
        num = cards[1].point;
    }
    if ((cards[2].point == cards[3].point) && (cards[3].point == cards[4].point)) {
        same++;
        num = cards[2].point;
    }

    if (same == 2){
        hand_rank.kind = Rank::hRanks::ThreeOfAKind;
        hand_rank.point = num;
        return true;
    }
    else
        return false;
}

//Determines if the PokerHands rank is a Pair
bool PokerHand::isPair() {
    sort();
    int num;
    int same = 1;
    for (int i = 0; i < HANDS - 1; i++){
        if ((same < 2) && (cards[i].point == cards[i+1].point)){
            same++;
            num = cards[i].point;
        }
    }

    if (same == 2){
        hand_rank.kind = Rank::hRanks::Pair;
        hand_rank.point = num;
        return true;
    }
    else 
        return false;
}

//Determines if the PokerHands rank is a High Card
bool PokerHand::isHighCard() {
    sort();
    hand_rank.kind = Rank::hRanks::HighCard;
    hand_rank.point = cards[0].point;
    return true;
}

//Returns the rank of Poker Hand
Rank PokerHand::getRank() const{
    return hand_rank;
}

//Compares two PokerHands and determines which one is better
int PokerHand::compareHand(const PokerHand &otherHand) const {
    if (this->hand_rank.kind < otherHand.hand_rank.kind)
        return -1;
    else if (this->hand_rank.kind > otherHand.hand_rank.kind)
        return 1;
    else {
        if (this->hand_rank.point < otherHand.hand_rank.point)
            return -1;
        else if (this->hand_rank.point > otherHand.hand_rank.point)
            return 1;
        else 
            return 0;
    }
}

//Prints the PokerHand
void PokerHand::print() const{
    cout << "Five Cards in order:" << endl;
    for (int i = 0; i < HANDS; i++){
        cards[i].print();
        cout << "    ";
    }
    cout << endl;
    cout << "Its rank is: ";
    hand_rank.print();

}
