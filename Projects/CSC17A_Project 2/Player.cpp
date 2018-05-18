/* 
 * File:   Player.cpp
 * Author: Josh McIntyre
 * Created on May 16, 2018, 1:28 PM
 */

#include "Player.h"

Player::Player(){
    name="Player Name";
    inHand=0;
    hand=new int[52];
    for(int i=0; i<52; i++){
        hand[i]=-1;
    }
}

Player::Player(string s){
    name=s;
    inHand=0;
    hand=new int[52];
    for(int i=0; i<52; i++){
        hand[i]=-1;
    }
}

Player::~Player(){
    delete []hand;
}

void Player::setHand(int i, int v){
    if(i>=0) hand[i]=v;
    //else throw invalid index exception
}

void Player::shuffle(Deck<Card> &d){
    for(int shfl=0; shfl<=3; shfl++){
        for(int i=0; i<d.numCards(); i++){
            int random=rand()%d.numCards();
            int temp=d.getI(i);
            d.setI(i,d.getI(random));
            d.setI(random,temp);
        }
    }
}

void Player::dealCrds(Deck<Card> &d, int n){
    if(n+d.getDelt()>52) {}//throw an exception
    else {
        int ind=0;
        for(int i=d.getDelt(); i<n+d.getDelt(); i++){
            hand[ind]=d.getI(i);
            ind++;
        }
        d.setDelt(d.getDelt()+n);
    }
}

int Player::cntHand(){
    int count=0;
    for(int i=0; i<52; i++){
        if(hand[i]>=0)count++;
    }
    return count;
}

int Player::getTop(){
    for(int i=0; i<52; i++){
        if(getHand(i+1)==-1) return getHand(i);
    }
}

void Player::setTop(){
    for(int i=0; i<52; i++){
        if(getHand(i+1)==-1) setHand(i,-1);
    }
}

void Player::toBot(int c){
    int tmp,tmp2;
    for(int i=0; i<52; i++){
        if(i==0){
            tmp=hand[i];
            hand[i]=c;
        }else{
            tmp2=hand[i];
            hand[i]=tmp;
            tmp=tmp2;
        }
    }
    setHand(0,c);
}