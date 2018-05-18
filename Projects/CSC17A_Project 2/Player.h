/* 
 * File:   Player.h
 * Author: Josh McIntyre
 * Created on May 16, 2018, 1:28 PM
 */

#ifndef PLAYER_H
#define PLAYER_H

//Included System Libraries
#include <string>

//Included User Libraries
#include "Card.h"
#include "Deck.h"
using namespace std;

//Player Class
class Player{
    private:
        string name;
        int *hand;
        int inHand;
    public:
        //Default Player Constructor
        Player();
        
        //Overloaded Player Constructor with Name Parameter
        Player(string);
        
        //Player Destructor
        ~Player();
        
        //Name Accessor Member Function
        string getName()const{return name;}
        
        //Shuffles Player's Array of Indexes User to Query Cards
        void shuffle(Deck<Card> &);
        
        //Gets Index from Array of Indexes Given its Index in that Array
        int getHand(int i)const{return hand[i];}
        
        //Mutator Function for Setting Indexes
        void setHand(int,int);
        
        //Deals Designated Amount of Cards from a Deck to Player
        void dealCrds(Deck<Card> &,int);
        
        //Counts Number of Cards in Player's Hand
        int cntHand();
        
        //Gets the Index at the Top of the Player's Hand
        int getTop();
        
        //Sets the Index at the Top of the Player's Hand to -1
        void setTop();
        
        //Moves an Index to the Bottom of the Array(Used for moving cards to bottom of deck)
        void toBot(int);
};

#endif /* PLAYER_H */

