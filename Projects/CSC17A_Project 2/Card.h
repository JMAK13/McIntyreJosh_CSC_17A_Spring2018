/* 
 * File:   Card.h
 * Author: Josh McIntyre
 * Created on May 9, 2018, 10:23 AM
 */

#ifndef CARD_H
#define CARD_H

#include "AbstractCard.h"

class Card:public AbstractCard{
    private:
        std::string suit;
        int value;
    public:
        Card();
        Card(int);
        ~Card();
        virtual std::string getSuit()const override{return suit;}
        virtual int getVal()const override{return value;}
        setSuit(std::string);
        setVal(int);
        bool operator>(const Card &);
        bool operator<(const Card &);
        virtual std::string getName(int)override;
};

#endif /* CARD_H */
