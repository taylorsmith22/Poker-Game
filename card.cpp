/* File: card.cpp
 * Course: CS216-00x
 * Project: Lab 8 (as part of Project 2)
 * Purpose: the implementation of member functions for the Card class.
 * Author: (your name)
 */
#include "card.h"
#include <iomanip>
// Default constructor marks card as invalid
Card::Card() {
     
    suit = cSuits(0);
    point = 0;
}

// Alternate constructor
Card::Card(cSuits s, cPoints p) 
{
    suit = s;
    point = p;
}

// access the card point value
Card::cPoints Card::getPoint() const
{
   return point;
}

// access the card suit value
Card::cSuits Card::getSuit() const
{
   return suit;
}

// compare with another Card object passed in as parameter: other
// if the object your are working on has higher point than other, return 1;
// if the object your are working on has lower point than other, return -1;
// otherwise, return 0
int Card::compareTo(Card other) const
{
    if (this->point > other.point)
        return 1;
    else if (this->point < other.point)
        return -1;
    else
        return 0;

}

// Display a description of the Card object to standard output
// The output should look like:
//   the sign of suit, followed by the point, then followed by the sign of suit again   
void Card::print() const
{ 
        
    switch (suit)
    {
        case cSuits(1):
            
            cout << SPADE;
            if ( point == 11)
                cout << " J"  << SPADE;
            else if (point == 12)
                cout << " Q" << SPADE;
            else if (point == 13)
                cout << " K" << SPADE;
            else if (point == 14)
                cout << " A" << SPADE;
            else if (point < 2 || point > 13)
                cout << "Invalid card number";
            else 
                cout << setw(2) << point << SPADE;
            break;       
        case cSuits(2):
            cout << CLUB;                                        
            if ( point ==11)                                     
                cout << " J"  << CLUB;
            else if (point == 12)
                cout << " Q" << CLUB;
            else if (point == 13)
                cout << " K" << CLUB;
            else if (point ==14)                                 
                cout << " A" << CLUB;
            else if (point < 2 || point > 13)
                cout << "Invalid card number";
           else                                                  
                cout << setw(2) << point << CLUB;  
            break;
        case cSuits(3):
            cout <<HEART;                                        
            if ( point ==11)                                     
                cout << " J"  << HEART;
            else if (point == 12)
                cout << " Q" << HEART;
            else if (point == 13)
                cout << " K" << HEART;
            else if (point ==14)
                cout << " A" <<HEART;
            else if ( point < 2 || point > 13)
                cout << "Invalid card number";
           else                                                  
                cout << setw(2) << point << HEART;  
            break;
        case cSuits(4):
            cout << DIAMOND;
            if ( point ==11)                                     
                cout << " J"  << DIAMOND;
            else if (point == 12)
                cout << " Q" << DIAMOND;
            else if (point == 13)
                cout << " K" << DIAMOND;
            else if (point ==14)                                 
                cout <<" A"<<DIAMOND;
            else if (point < 2 || point > 13)
                cout << "Invalid";
           else                                                  
                cout << setw(2) << point << DIAMOND;  
            break;
    }
}
//yhyh
