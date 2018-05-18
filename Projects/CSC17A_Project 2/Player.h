/* 
 * File:   Player.h
 * Author: Josh McIntyre
 * Created on May 16, 2018, 1:28 PM
 */

#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include "Card.h"
#include "Deck.h"
using namespace std;

class Player{
    private:
        string name;
        int *hand;
        int inHand;
    public:
        Player();
        Player(string);
        ~Player();
        string getName()const{return name;}
        void shuffle(Deck<Card> &);
        bool isPlayer()const{return true;}
        int getHand(int i)const{return hand[i];}
        void setHand(int,int);
        void dealCrds(Deck<Card> &,int);
        int cntHand();
        int getTop();
        void setTop();
        void toBot(int);
};

#endif /* PLAYER_H */

