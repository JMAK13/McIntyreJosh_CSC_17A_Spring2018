/* 
 * File:   Card.h
 * Author: Josh McIntyre
 * Created on May 9, 2018, 10:23 AM
 */

#ifndef CARD_H
#define CARD_H

#include <string>
using namespace std;

class Card {
    private:
        string suit;
        int value;
    public:
        Card();
        ~Card();
        string getSuit()const{return suit;}
        int getVal()const{return value;}
        setSuit(string);
        setVal(int);
        bool operator>(const Card &);
        bool operator<(const Card &);
        string toString(int);
};

#endif /* CARD_H */

