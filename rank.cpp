/* File: rank.cpp
 * Course: CS216-00x
 * Project: Lab 9 (as part of Project 2)
 * Purpose: the implementation of member functions for the Rank class.
 *
 */
#include <iostream>
#include "rank.h"
#include <iomanip>

using namespace std;

// Default constructor.
Rank::Rank()
{
   kind = hRanks::NoRank;
   point = 0;
}

// Alternate constructor.
// Create a Rank object with specified ranking name and points.
Rank::Rank(hRanks r, rPoints p)
{
    kind = r;
    point = p;
}

// access the hand ranking kind
Rank::hRanks Rank::getKind() const
{
    return kind;
}

// access the card point value of the corresponding ranking kind
Rank::rPoints Rank::getPoint() const
{
    return point;
}

// Display a description of the hand-ranking category to standard output.
// The output should look like:
//   FourOfAKind( 4)
//   FullHouse(10)
//   Flush( A)
//   ...
void Rank::print() const
{
    if (kind == hRanks::NoRank){
        if (point == 11)
            cout << RANK_NAMES[0] << "( J)" << endl;
        else if (point == 12)
            cout << RANK_NAMES[0] << "( Q)" << endl;
        else if (point == 13)
            cout << RANK_NAMES[0] << "( K)" << endl;
        else if (point == 14)
            cout << RANK_NAMES[0] << "( A)" << endl;
        else if (point < 2 || point > 14)
            cout << "Invalid card number" << endl;
        else
            cout << RANK_NAMES[0] << "(" << setw(2) << point << ")" << endl;
    }
    else if (kind == hRanks::HighCard){
        if (point == 11)
            cout << RANK_NAMES[1] << "( J)" << endl;
        else if (point == 12)
            cout << RANK_NAMES[1] << "( Q)" << endl;
        else if (point == 13)
            cout << RANK_NAMES[1] << "( K)" << endl;
        else if (point == 14)
            cout << RANK_NAMES[1] << "( A)" << endl;
        else if (point < 2 || point > 14)
            cout << "Invalid card number" << endl;
        else
            cout << RANK_NAMES[1] << "(" << setw(2) <<  point << ")" << endl;
    }
    else if (kind == hRanks::Pair){
        if (point == 11)
            cout << RANK_NAMES[2] << "( J)" << endl;
        else if (point == 12)
            cout << RANK_NAMES[2] << "( Q)" << endl;
        else if (point ==13)
            cout << RANK_NAMES[2] << "( K)" << endl;
        else if (point == 14)
            cout << RANK_NAMES[2] << "( A)" << endl;
        else if (point < 2 || point > 14)
            cout << "Invalid card number" << endl;
        else
            cout << RANK_NAMES[2] << "(" << setw(2) << point << ")" << endl;
    }
    else if (kind == hRanks::ThreeOfAKind){
        if (point == 11)
            cout << RANK_NAMES[3] << "( J)" << endl;
        else if (point == 12)
            cout << RANK_NAMES[3] << "( Q)" << endl;
        else if (point == 13)
            cout << RANK_NAMES[3] << "( K)" << endl;
        else if (point == 14)
            cout << RANK_NAMES[3] << "( A)" << endl;
        else if (point < 2 || point > 14)
            cout << "Invalid card number" << endl;
        else
            cout << RANK_NAMES[3] << "(" << setw(2) << point << ")" << endl;
    }
    else if (kind == hRanks::Straight){
        if (point == 11)
            cout << RANK_NAMES[4] << "( J)" << endl;
        else if (point == 12)
            cout << RANK_NAMES[4] << "( Q)" << endl;
        else if (point == 13)
            cout << RANK_NAMES[4] << "( K)" << endl;
        else if (point == 14)
            cout << RANK_NAMES[4] << "( A)" << endl;
        else if (point < 2 || point > 14)
            cout << "Invalid card number" << endl;
        else
            cout << RANK_NAMES[4] << "(" << setw(2) << point << ")" << endl;
    }
    else if (kind == hRanks::Flush){
        if (point == 11)
            cout << RANK_NAMES[5] << "( J)" << endl;
        else if (point == 12)
            cout << RANK_NAMES[5] << "( Q)" << endl;
        else if (point == 13) 
            cout << RANK_NAMES[5] << "( K)" << endl;
        else if (point == 14)
            cout << RANK_NAMES[5] << "( A)" << endl;
        else if (point < 2 || point > 14)
            cout << "Invalid card number" << endl;
        else
            cout << RANK_NAMES[5] << "(" << setw(2) << point << ")" << endl;
    }
    else if (kind == hRanks::FullHouse){
        if (point == 11)
            cout << RANK_NAMES[6] << "( J)" << endl;
        else if (point == 12)
            cout << RANK_NAMES[6] << "( Q)" << endl;
        else if (point == 13)
            cout << RANK_NAMES[6] << "( K)" << endl;
        else if (point == 14)
            cout << RANK_NAMES[6] << "( A)" << endl;
        else if (point < 2 || point > 14)
            cout << "Invalid card number" << endl;
        else
            cout << RANK_NAMES[6] << "(" << setw(2) << point << ")" << endl;
    }
    else if (kind == hRanks::FourOfAKind){
        if (point == 11)
            cout << RANK_NAMES[7] << "( J)" << endl;
        else if (point == 12)
            cout << RANK_NAMES[7] << "( Q)" << endl;
        else if (point == 13)
            cout << RANK_NAMES[7] << "( K)" << endl;
        else if (point == 14)
            cout << RANK_NAMES[7] << "( A)" << endl;
        else if (point < 2 || point > 14)
            cout << "Invalid card number" << endl;
        else
            cout << RANK_NAMES[7] << "(" << setw(2) << point << ")" << endl;
    }
    else if (kind == hRanks::StraightFlush){
        if (point == 11)
            cout << RANK_NAMES[8] << "( J)" << endl;
        else if (point == 12)
            cout << RANK_NAMES[8] << "( Q)" << endl;
        else if (point == 13)
            cout << RANK_NAMES[8] << "( K)" << endl;
        else if (point == 14)
            cout << RANK_NAMES[8] << "( A)" << endl;
        else if (point < 2 || point > 14)
            cout << "Invalid card number" << endl;
        else
            cout << RANK_NAMES[8] << "(" << setw(2) << point << ")" << endl;
    }
    else 
        cout << "Invalid Rank" << endl;

}

