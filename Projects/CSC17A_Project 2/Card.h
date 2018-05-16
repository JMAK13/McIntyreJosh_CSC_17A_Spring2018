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
        //Empty Constructor
        Card();
        
        //Constructor Taking a Card Value is a Parameter
        Card(int);
        
        //Destructor
        ~Card();
        
        //Suit Accessor Member Function
        virtual std::string getSuit()const override{return suit;}
        
        //Value Accessor Member Function
        virtual int getVal()const override{return value;}
        
        //Suit Mutator Member Function
        setSuit(std::string);
        
        //Value Mutator Member Function
        setVal(int);
        
        //Relational Operator Overloaded Functions
        bool operator > (const Card &right) {return this->value>right.getVal();}
        bool operator < (const Card &right) {return this->value<right.getVal();}
        
        //Name Accessor Member Function
        virtual std::string getName(int)override;
};

#endif /* CARD_H */
