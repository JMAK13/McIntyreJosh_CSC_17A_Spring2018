/* 
 * File:   Card.h
 * Author: Josh McIntyre
 * Created on May 9, 2018, 10:23 AM
 */

#ifndef CARD_H
#define CARD_H

//Included User Libraries
#include "AbstractCard.h"

<<<<<<< HEAD
//Card Class Derived From AbstractCard Base Class
=======
//Card Class Derived from Abstract Base Card Class
>>>>>>> 6a065f72fc054e49110588d2ea1c951ffce50626
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
        void setSuit(std::string);
        
        //Value Mutator Member Function
        void setVal(int);
        
        //Overloaded > Function
        bool operator > (const Card &right);
        
        //Overloaded < Function
        bool operator < (const Card &right);
        
        //Overloaded == Function
        bool operator == (const Card &right);
        
        //Name Accessor Member Function
        virtual std::string getName(int)override;
};

#endif /* CARD_H */
