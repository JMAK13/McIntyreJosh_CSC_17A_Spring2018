/* 
 * File:   main.cpp
 * Author: Josh McIntyre
 * Purpose: War - The Well Known and Popular Card Game
 *              - CSC17A Game Project 1
 * Created on April 15, 2018, 3:01 PM
 */

//Global Constants

//System Libraries
#include <iostream>     //cout,cin,cin.get()
#include <ctime>        //time(0)
#include <cstdlib>      //srand(),rand()
#include <cstring>      //to use string variables
#include <cctype>
#include <fstream>      //binary file input/output
#include "Hands.h"      //player's hands structure
using namespace std;

//User Libraries

//Function Prototypes
bool used(Hands *,int);         //Checks to see if a card already exists
Hands *fillAry(int,int);        //Allocates memory and creates both player's hands
string toString(int);           //Translates card numbers into their card names
int getTop(Hands *,int);        //Gets the top card of a player's hand
void setTop(Hands *,int);       //Resets the top card of a player's hand to 0
void toBot(Hands *,int,int);    //Puts the top card of a player's hand on the bottom
void war(Hands *);              //Initiates the 'war' protocol
void destroy(Hands *);          //Deallocates any allocated memory

//Main Function
int main(int argc, char** argv) {
    //Declare Variables
    bool valid=false;
    int input;
    fstream file;
    
    //Seed Random Function With Time
    srand(static_cast<unsigned int>(time(0)));
    
    //Player Menu
    cout<<"Welcome to War by Josh McIntyre\nPress 0 to Exit\nPress 1 to Play\nPress 2 for Rules\n\n";
    do{
        cin>>input;
        if(input>=0&&input<=2) valid=true;
        else cout<<"Invalid input, press 0, 1, or 2";
    }while(!valid);
    
    switch(input) {
        //Exits Game
        case 0:{
            cout<<"Hope to see you again soon, good bye!";
            return 0;
            
            //Exits Switch Statement
            break;
        }
        
        //Plays Game
        case 1:{
            char ans;
            do{
                //Declares Variables
                int rows=2,cols=52;
                string winner;
                ans=' ';

                //Allocates Memory for Both Player's Hands
                Hands *hands=fillAry(rows,cols);

                //Game Loop
                do{
                    cout<<"Press enter to begin turn: ";
                    cin.get();
                    cout<<"Player 1 placed down a "<<toString(getTop(hands,0))<<endl;
                    cout<<"Player 2 placed down a "<<toString(getTop(hands,1))<<endl;
                    if(getTop(hands,0)>getTop(hands,1)) {
                        cout<<"Player 1 wins this round!"<<endl;
                        toBot(hands,getTop(hands,0),0);
                        toBot(hands,getTop(hands,1),0);
                        setTop(hands,0);
                        setTop(hands,1);
                    }
                    else if(getTop(hands,0)<getTop(hands,1)) {
                        cout<<"Player 2 wins this round!"<<endl;
                        toBot(hands,getTop(hands,1),1);
                        toBot(hands,getTop(hands,0),1);
                        setTop(hands,0);
                        setTop(hands,1);
                    }
                    else {
                        cout<<"War has been initiated!"<<endl;
                        war(hands);
                    }
                }while(getTop(hands,0)!=cols&&getTop(hands,1)!=cols);

                //Displays Winner
                cout<<endl<<endl;
                if(getTop(hands,0)==cols) cout<<"Player 1 wins the game!"<<endl;
                if(getTop(hands,1)==cols) cout<<"Player 2 wins the game!"<<endl;
                cout<<"Dear Winner, please input your name: ";
                cin>>winner;

                //Write Winner's Name to Binary File
                file.open("data.dat",ios::out|ios::binary);
                file.write(&winner[0], sizeof(winner));
                file.close();

                //Deallocates Memory
                destroy(hands);

                cout<<"Would you like to play again? [Y/N]";
                cin>>ans;

            }while(toupper(ans)=='Y');
            
            //Exits Switch Statement
            break;
        }
        
        //Displays Rules
        case 2:{
            cout<<"Both players start with 26 shuffled cards, and each turn they each flip the their top card.";
            cout<<"\nThe player whose card is a higher value takes both cards.";
            cout<<"If the cards are of the same value\nthen the 'War' protocol is initiated, each player will place down another face down card, then";
            cout<<"\nanother face up card, and whichever second face up card is of higher value that player takes all cards.";
            cout<<"\nPlayers keep repeating the 'War' protocol as long as their face ups cards are of the same value.";
            
            //Exits Switch Statement
            break;
        }
    }

    //Exits Program
    return 0;
}

//Checks to see if the card already exists
bool used(Hands *h, int num){
    for(int row=0; row<2; row++) {
        for(int col=0; col<52; col++) {
            if(h->data[row][col]==num) return true;
        }
    }
    return false;
}

//Creates Both Player's Hands
Hands *fillAry(int rows,int cols){
    //Is the size parameter valid
    if(rows<=0)return 0;
    if(cols<=0)return 0;
    
    //Allocate memory
    Hands *hands=new Hands;
    hands->rows=rows;
    hands->cols=cols;
    hands->data=new int*[rows];
    for(int row=0;row<rows;row++){
        hands->data[row]=new int[cols];
    }
    
    //Fill with 2 digit random numbers
    for(int row=0;row<rows;row++){
        for(int col=0;col<cols;col++){
            hands->data[row][col]=0;
        }
    }
    for(int row=0;row<rows;row++){
        for(int col=0;col<cols/2;col++){
            bool val=false;
            do{
                int n=(1+rand()%(53)-1);
                if(!used(hands,n)) {hands->data[row][col]=n;val=true;}
            }while(!val);
        }
    }
    
    //Returns Hands
    return hands;
}

//Returns the String Value of a Card
string toString(int n){
    string s;
    if(n>13)n%=13;
    if(n==0)n=13;
    switch(n){
        case 1:{s="Two";break;}
        case 2:{s="Three";break;}
        case 3:{s="Four";break;}
        case 4:{s="Five";break;}
        case 5:{s="Six";break;}
        case 6:{s="Seven";break;}
        case 7:{s="Eight";break;}
        case 8:{s="Nine";break;}
        case 9:{s="Ten";break;}
        case 10:{s="Jack";break;}
        case 11:{s="Queen";break;}
        case 12:{s="King";break;}
        case 13:{s="Ace";break;}
    }
    return s;
}

//Gets the Top Card of a Player's Hand
int getTop(Hands *h,int row){
    for(int col=0; col<52; col++){
        int n;
        if(h->data[row][col]==0) {
            n=h->data[row][col-1];
            if(n>13){
                n%=13;
                if(n==0) n=13;
                return n;
            }
            else return n;
        }
    }
    return 52;
}

//Resets the Player's Top Card to Zero
void setTop(Hands *h,int row){
    for(int col=0; col<52; col++) {
        if(h->data[row][col]==0)h->data[row][col-1]=0;
    }
}

//Puts the Player's Top Card on the Bottom
void toBot(Hands *h, int crd, int row){
    int tmp,tmp2;
    for(int col=0; col<52; col++) {
        if(col==0){
            tmp=h->data[row][col];
            h->data[row][col]=crd;
        }else{
            tmp2=h->data[row][col];
            h->data[row][col]=tmp;
            tmp=tmp2;
        }
    }
}

//Initiates 'war' Protocol
void war(Hands *h){
    int wars=1;
    bool end=false;
    
    do{
        bool done=false;
        int crd1,crd2,col=0;
        while(!done){
            if(h->data[0][col]==0){
                crd1=h->data[0][col-(wars*2)-1];
                done=true;
                if(crd1>13){
                    crd1%=13;
                    if(crd1==0) crd1=13;
                }
            }
            col++;
        }
        col=0;
        done=false;
        while(!done){
            if(h->data[1][col]==0){
                crd2=h->data[1][col-(wars*2)-1];
                done=true;
                if(crd2>13){
                    crd2%=13;
                    if(crd2==0) crd2=13;
                }
            }
            col++;
        }
        cout<<"Player 1 placed down a "<<toString(crd1)<<endl;
        cout<<"Player 2 placed down a "<<toString(crd2)<<endl;
        if(crd1>crd2){
            for(int j=0; j<(wars*2)+1; j++){
                toBot(h,getTop(h,0),0);
                toBot(h,getTop(h,1),0);
                setTop(h,0);
                setTop(h,1);
            }
            cout<<"Player 1 won the war!"<<endl;
            end=true;
        }
        else if(crd2>crd1){
            for(int j=0; j<(wars*2)+1; j++){
                toBot(h,getTop(h,1),1);
                toBot(h,getTop(h,0),1);
                setTop(h,0);
                setTop(h,1);
            }
            cout<<"Player 2 won the war!"<<endl;
            end=true;
        }
        else{
            wars++;
        }
    }while(!end);
}

//Deallocates Memory
void destroy(Hands *h){
    if(!h)return;
    for(int row=0;row<h->rows;row++){
        delete []h->data[row];
    }
    delete []h->data;
    delete h;
}