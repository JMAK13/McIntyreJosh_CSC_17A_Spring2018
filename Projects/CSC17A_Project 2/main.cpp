/* 
 * File:   main.cpp
 * Author: Josh McIntyre
 * Created on May 9, 2018, 9:53 AM
 */

//Global Constants

//System Libraries
#include <iostream>     //cout,endl,cin,getline
#include <cctype>       //isalpha
#include <fstream>      //fstream,write,read
#include <cstdlib>      //rand,srand
#include <ctime>        //time
using namespace std;

//User Libraries
#include "Card.h"
#include "Deck.h"

//Function Prototypes
void toBot(int **,int,int);     //Puts the top card of a player's hand on the bottom
int getTop(int **,int);         //Gets the top card of a player's hand
void setTop(int **,int);        //Resets the top card of a player's hand to 0
void war(int **, Card **);       //Initiates the 'war' protocol
int cntCard(int **,int);

//Main Function
int main(int argc, char** argv) {
    
    //Seed Random Function With Time
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variables
    bool menu=false;
    char menuIn;
    
    //Menu
    cout<<"###########################################"<<endl;
    cout<<"#  Welcome to War v2.0 by Josh McIntyre!  #"<<endl;
    cout<<"###########################################"<<endl<<endl;
    
    //Menu Input Validation
    do{
        cout<<"Enter 1 to Play, 2 to View Rules, or 0 to Exit: ";
        cin>>menuIn;
        if(isalpha(menuIn)) cout<<"Invalid input, please try again!"<<endl;
        else if(menuIn-48<0||menuIn-48>2) cout<<"Invalid input, please try again!"<<endl;
        else menu=true;
    }while(!menu);
    
    cout<<"\n\n";
    
    //Menu Input Protocol
    switch(menuIn-48){
        
        //Exit Protocol
        case 0:{
            cout<<"I guess you don't want to play, see you later!"<<endl;
            break;
        }
        
        //Rules Protocol
        case 2:{
            cout<<"Both players start with 26 shuffled cards, and each turn they each flip the their top card.";
            cout<<"\nThe player whose card is a higher value takes both cards.";
            cout<<"If the cards are of the same value\nthen the 'War' protocol is initiated, each player will place down another face down card, then";
            cout<<"\nanother face up card, and whichever second face up card is of higher value that player takes all cards.";
            cout<<"\nPlayers keep repeating the 'War' protocol as long as their face ups cards are of the same value.";
            cout<<"!!! IMPORTANT NOTE: Ace cards are the least valued cards while Kings are the most valued cards !!!";
            break;
        }
        
        //Game Protocol
        case 1:{
            
            //Declare Game Variables
            string name1,name2;
            fstream dataFile("players.dat",ios::out | ios::binary);
            
            //Ask Players For Their Names and Write Them to Binary File
            cout<<"Player 1, please enter your name:  ";
            cin.ignore();
            getline(cin,name1);
            dataFile.write(&name1[0], sizeof(name1));
            cout<<"Player 2, please enter your name:  ";
            getline(cin,name2);
            dataFile.write(&name2[0], sizeof(name2));
            dataFile.close();
            cout<<"\n";
            
            //Initialize Deck
            Deck<Card> deck(52);
            
            //Allocate Memory for Cards
            Card **c=new Card*[52];
            //Initialize Cards
            for(int i=0; i<52; i++){
                c[i]=new Card(i+1);
                if(i>=0&&i<=12) c[i]->setSuit("Spades");
                if(i>=13&&i<=25) c[i]->setSuit("Clubs");
                if(i>=26&&i<=38) c[i]->setSuit("Hearts");
                if(i>=39&&i<=51) c[i]->setSuit("Diamonds");
                //cout<<c[i]->getName(c[i]->getVal())<<" of "<<c[i]->getSuit()<<endl;
            }
            
            //Shuffle Deck
            deck.shuffle();
            
            //Deal Cards to Both Players
            int *hand1=deck.deal(26);
            int *hand2=deck.deal(26);
            int **hands=new int*[2];
            hands[0]=new int[52];
            hands[1]=new int[52];
            for(int i=0; i<52; i++){
                if(i<26){
                    hands[0][i]=hand1[i];
                    hands[1][i]=hand2[i];
                }else{
                    hands[0][i]=0;
                    hands[1][i]=0;
                }
            }
            delete []hand1;
            delete []hand2;
            
            char ans;
            do{
                //Initialize Deck
                Deck<Card> deck(52);

                //Allocate Memory for Cards
                Card **c=new Card*[52];
                
                //Initialize Cards
                for(int i=0; i<52; i++){
                    c[i]=new Card(i+1);
                    if(i>=0&&i<=12) c[i]->setSuit("Spades");
                    if(i>=13&&i<=25) c[i]->setSuit("Clubs");
                    if(i>=26&&i<=38) c[i]->setSuit("Hearts");
                    if(i>=39&&i<=51) c[i]->setSuit("Diamonds");
                    //cout<<c[i]->getName(c[i]->getVal())<<" of "<<c[i]->getSuit()<<endl;
                }

                //Shuffle Deck
                deck.shuffle();

                //Deal Cards to Both Players
                int *hand1=deck.deal(26);
                int *hand2=deck.deal(26);
                int **hands=new int*[2];
                hands[0]=new int[52];
                hands[1]=new int[52];
                for(int i=0; i<52; i++){
                    if(i<26){
                        hands[0][i]=hand1[i];
                        hands[1][i]=hand2[i];
                    }else{
                        hands[0][i]=0;
                        hands[1][i]=0;
                    }
                }
                delete []hand1;
                delete []hand2;
                
                ans=' ';

                //Game Loop
                do{
                    cout<<endl<<endl;
                    cout<<"Press enter to begin turn: ";
                    cin.get();
                    cout<<"Player 1 placed down a "<<c[getTop(hands,0)-1]->getName(c[getTop(hands,0)-1]->getVal())<<" of "<<c[getTop(hands,0)-1]->getSuit()<<endl;
                    cout<<"Player 2 placed down a "<<c[getTop(hands,1)-1]->getName(c[getTop(hands,1)-1]->getVal())<<" of "<<c[getTop(hands,1)-1]->getSuit()<<endl;
                    if(*c[getTop(hands,0)-1] > *c[getTop(hands,1)-1]) {
                        cout<<"Player 1 wins this round!"<<endl;
                        toBot(hands,getTop(hands,0),0);
                        toBot(hands,getTop(hands,1),0);
                        setTop(hands,0);
                        setTop(hands,1);
                    }
                    else if(*c[getTop(hands,0)-1] < *c[getTop(hands,1)-1]) {
                        cout<<"Player 2 wins this round!"<<endl;
                        toBot(hands,getTop(hands,1),1);
                        toBot(hands,getTop(hands,0),1);
                        setTop(hands,1);
                        setTop(hands,0);
                    }
                    else {
                        cout<<"War has been initiated!"<<endl;
                        war(hands,c);
                    }
                }while(cntCard(hands,0)!=52&&cntCard(hands,1)!=52);

                //Displays Winner
                cout<<endl<<endl;
                if(cntCard(hands,0)==52) cout<<"Player 1 wins the game!"<<endl;
                if(cntCard(hands,1)==52) cout<<"Player 2 wins the game!"<<endl;

                cout<<"Would you like to play again? [Y/N]";
                cin>>ans;
                
                //Deallocate Memory
                delete []c;
                delete []hands[0];
                delete []hands[1];
                delete []hands; 

            }while(toupper(ans)=='Y');
            
            break;
        }
    }

    //Exits Program
    return 0;
}

//Puts the Player's Top Card on the Bottom
void toBot(int **hand, int ind, int row){
    int tmp,tmp2;
    for(int col=0; col<52; col++) {
        if(col==0){
            tmp=hand[row][col];
            hand[row][col]=ind;
        }else{
            tmp2=hand[row][col];
            hand[row][col]=tmp;
            tmp=tmp2;
        }
    }
}

//Gets the Top Card of a Player's Hand
int getTop(int **hand,int row){
    for(int col=0; col<52; col++){
        if(hand[row][col+1]==0)return hand[row][col];
    }
    return 52;
}

//Resets the Player's Top Card to Zero
void setTop(int **hand,int row){
    for(int col=0; col<52; col++) {
        if(hand[row][col+1]==0)hand[row][col]=0;
    }
}

//Initiates 'war' Protocol
void war(int **hand, Card **c){
    int wars=1;
    bool end=false;
    
    do{
        bool done=false;
        int ind1,ind2,col=0;
        while(!done){
            if(hand[0][col]==0){
                ind1=hand[0][col-(wars*2)-1];
                done=true;
            }
            col++;
        }
        col=0;
        done=false;
        while(!done){
            if(hand[1][col]==0){
                ind2=hand[1][col-(wars*2)-1];
                done=true;
            }
            col++;
        }
        cout<<"Player 1 placed down a "<<c[ind1-1]->getName(c[ind1-1]->getVal())<<" of "<<c[ind1-1]->getSuit()<<endl;
        cout<<"Player 2 placed down a "<<c[ind2-1]->getName(c[ind2-1]->getVal())<<" of "<<c[ind2-1]->getSuit()<<endl;
        if(*c[ind1-1] > *c[ind2-1]){
            for(int j=0; j<(wars*2)+1; j++){
                toBot(hand,getTop(hand,0),0);
                toBot(hand,getTop(hand,1),0);
                setTop(hand,0);
                setTop(hand,1);
            }
            cout<<"Player 1 won the war!"<<endl;
            end=true;
        }
        else if(*c[ind1-1] < *c[ind2-1]){
            for(int j=0; j<(wars*2)+1; j++){
                toBot(hand,getTop(hand,1),1);
                toBot(hand,getTop(hand,0),1);
                setTop(hand,1);
                setTop(hand,0);
            }
            cout<<"Player 2 won the war!"<<endl;
            end=true;
        }
        else{
            wars++;
        }
    }while(!end);
}

//Counts the Number of Cards in a Player's Hand
int cntCard(int **hand, int row){
    int count=1;
    for(int i=0; i<52; i++){
        if(hand[row][i]>0)count++;
    }
    return count;
}