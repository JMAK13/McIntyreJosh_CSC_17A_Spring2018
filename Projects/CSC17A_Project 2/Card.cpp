/* 
 * File:   Card.cpp
 * Author: Josh McIntyre
 * Created on May 9, 2018, 10:23 AM
 */

#include "Card.h"

Card::Card(){
}

Card::~Card(){
}

Card::setSuit(string s){
    string array[4]={"Spades","Clubs","Hearts","Diamonds"};
    for(int i=0;i<4;i++){
        if(s.compare(array[i])==0) suit=s;
        //else throw an exception
    }
}

Card::setVal(int v){
    if(v<=13&&v>=1) value=v;
    else {v%=13; v==0?value=13:value=v;}
}

bool Card::operator>(const Card &right){
    bool result;
    
    if(value>right.getVal()) result=true;
    else result=false;
    
    return result;
}

bool Card::operator<(const Card &right){
    bool result;
    
    if(value<right.getVal()) result=true;
    else result=false;
    
    return result;
}

string Card::toString(int v){
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