/* 
 * File:   Card.cpp
 * Author: Josh McIntyre
 * Created on May 9, 2018, 10:23 AM
 */

#include "AbstractCard.h"
#include "Card.h"
using namespace std;

Card::Card() : AbstractCard(){
}

Card::Card(int v) : AbstractCard(){
    if(v<=13&&v>=1) value=v;
    else {v%=13; v==0?value=13:value=v;}
}

Card::~Card(){
}

void Card::setSuit(string s){
    string array[4]={"Spades","Clubs","Hearts","Diamonds"};
    for(int i=0;i<4;i++){
        if(s.compare(array[i])==0) suit=s;
        //else throw an exception
    }
}

void Card::setVal(int v){
    if(v<=13&&v>=1) value=v;
    else {v%=13; v==0?value=13:value=v;}
}

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