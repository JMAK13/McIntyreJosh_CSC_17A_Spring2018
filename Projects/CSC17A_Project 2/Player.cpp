/* 
 * File:   Player.cpp
 * Author: Josh McIntyre
 * Created on May 16, 2018, 1:28 PM
 */

//Included User Libraries
#include "Player.h"

<<<<<<< HEAD
//Player Constructor
Player::Player():GameEntity(){
    isPl=true;
=======
//Default Player Constructor
Player::Player(){
>>>>>>> 6a065f72fc054e49110588d2ea1c951ffce50626
    name="Player Name";
    inHand=0;
    hand=new int[52];
    for(int i=0; i<52; i++){
        hand[i]=-1;
    }
}

<<<<<<< HEAD
//Player Overloaded Constructor
Player::Player(string s):GameEntity(){
    isPl=true;
=======
//Overloaded Player Constructor with Name Parameter
Player::Player(string s){
>>>>>>> 6a065f72fc054e49110588d2ea1c951ffce50626
    name=s;
    inHand=0;
    hand=new int[52];
    for(int i=0; i<52; i++){
        hand[i]=-1;
    }
}

//Player Destructor
Player::~Player(){
    delete []hand;
}

<<<<<<< HEAD
//Hand Mutator Member Function
=======
//Index Mutator Member Function
>>>>>>> 6a065f72fc054e49110588d2ea1c951ffce50626
void Player::setHand(int i, int v){
    if(i>=0) hand[i]=v;
    //else throw invalid index exception
}

<<<<<<< HEAD
//Counts Amount of Cards in Player's Hand
=======
//Shuffles Indexes in Player's Hand
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

//Deals Indexes to Player's Array of Indexes
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

//Counts Indexes in Player's Array
>>>>>>> 6a065f72fc054e49110588d2ea1c951ffce50626
int Player::cntHand(){
    int count=0;
    for(int i=0; i<52; i++){
        if(hand[i]>=0)count++;
    }
    return count;
}

<<<<<<< HEAD
//Gets Top Card of Player's Hand
=======
//Gets Index at Top of Player's Array
>>>>>>> 6a065f72fc054e49110588d2ea1c951ffce50626
int Player::getTop(){
    for(int i=0; i<52; i++){
        if(getHand(i+1)==-1) return getHand(i);
    }
}

<<<<<<< HEAD
//Clears Top Card of Player's Hand
=======
//Sets Index at Top of Player's Array to -1
>>>>>>> 6a065f72fc054e49110588d2ea1c951ffce50626
void Player::setTop(){
    for(int i=0; i<52; i++){
        if(getHand(i+1)==-1) setHand(i,-1);
    }
}

<<<<<<< HEAD
//Moves Top Card of Player's Hand to Bottom
=======
//Moves Index at Top of Player's Array to the Bottom of Player's Array
>>>>>>> 6a065f72fc054e49110588d2ea1c951ffce50626
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