/* 
 * File:   Card.cpp
 * Author: Josh McIntyre
 * Created on May 9, 2018, 10:23 AM
 */

<<<<<<< HEAD
<<<<<<< HEAD
//Include User Libraries
#include "AbstractCard.h"
#include "Card.h"
using namespace std;

//Card Constructor
Card::Card() : AbstractCard(){
}

//Card Overloaded Constructor
=======
//Included User Libraries
#include "Card.h"
using namespace std;

//Default Card Constructor
Card::Card() : AbstractCard(){
}

//Overloaded Card Constructor
>>>>>>> 6a065f72fc054e49110588d2ea1c951ffce50626
=======
//Included User Libraries
#include "Card.h"
using namespace std;

//Default Card Constructor
Card::Card() : AbstractCard(){
}

//Overloaded Card Constructor
>>>>>>> 6a065f72fc054e49110588d2ea1c951ffce50626
Card::Card(int v) : AbstractCard(){
    if(v<=13&&v>=1) value=v;
    else {v%=13; v==0?value=13:value=v;}
}

<<<<<<< HEAD
<<<<<<< HEAD
//Card Destructor
=======
//Destructor
>>>>>>> 6a065f72fc054e49110588d2ea1c951ffce50626
=======
//Destructor
>>>>>>> 6a065f72fc054e49110588d2ea1c951ffce50626
Card::~Card(){
}

//Suit Mutator Member Function
void Card::setSuit(string s){
    string array[4]={"Spades","Clubs","Hearts","Diamonds"};
    for(int i=0;i<4;i++){
        if(s.compare(array[i])==0) suit=s;
        //else throw an exception
    }
}

//Value Mutator Member Function
void Card::setVal(int v){
    if(v<=13&&v>=1) value=v;
    else {v%=13; v==0?value=13:value=v;}
}

//Name Accessor Member Function
string Card::getName(int v){
    string s;
    if(v==1)s="Ace";
    if(v==2)s="Two";
    if(v==3)s="Three";
    if(v==4)s="Four";
    if(v==5)s="Five";
    if(v==6)s="Six";
    if(v==7)s="Seven";
    if(v==8)s="Eight";
    if(v==9)s="Nine";
    if(v==10)s="Ten";
    if(v==11)s="Jack";
    if(v==12)s="Queen";
    if(v==13)s="King";
    return s;
    //else throw exception
}

<<<<<<< HEAD
<<<<<<< HEAD
//Overloaded > Function
=======
//Overloaded > Operator Function
>>>>>>> 6a065f72fc054e49110588d2ea1c951ffce50626
=======
//Overloaded > Operator Function
>>>>>>> 6a065f72fc054e49110588d2ea1c951ffce50626
bool Card::operator > (const Card &right){
    if(value==right.getVal()) return false;
    else if(value==1&&right.getVal()>1) return true;
    else if(value>1&&right.getVal()==1) return false;
    else return value>right.getVal();
}

<<<<<<< HEAD
<<<<<<< HEAD
//Overloaded < Function
=======
//Overloaded < Operator Function
>>>>>>> 6a065f72fc054e49110588d2ea1c951ffce50626
=======
//Overloaded < Operator Function
>>>>>>> 6a065f72fc054e49110588d2ea1c951ffce50626
bool Card::operator < (const Card &right){
    if(value==right.getVal()) return false;
    else if(value==1&&right.getVal()>1) return false;
    else if(value>1&&right.getVal()==1) return true;
    else return value<right.getVal();
}

<<<<<<< HEAD
<<<<<<< HEAD
//Overloaded == Function
=======
//Overloaded == Operator Function
>>>>>>> 6a065f72fc054e49110588d2ea1c951ffce50626
=======
//Overloaded == Operator Function
>>>>>>> 6a065f72fc054e49110588d2ea1c951ffce50626
bool Card::operator == (const Card &right){
    if(value==right.getVal()) return true;
    else return false;
}