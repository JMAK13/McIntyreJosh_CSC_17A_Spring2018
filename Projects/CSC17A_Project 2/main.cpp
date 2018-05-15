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
            cout<<""<<endl;
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
                cout<<c[i]->getName(c[i]->getVal())<<" of "<<c[i]->getSuit()<<endl;
            }
            //Shuffle Deck
            deck.shuffle();
            //Deal Cards
            int *hand1=deck.deal(26);
            int *hand2=deck.deal(26);
            //Display Player 1's Hand
            for(int i=0; i<26; i++){
                cout<<i+1<<") "<<c[hand1[i]-1]->getName(c[hand1[i]-1]->getVal())<<" of "<<c[hand1[i]-1]->getSuit()<<endl;
            }
            //Display Player 2's Hand
            for(int i=0; i<26; i++){
                cout<<i+27<<") "<<c[hand2[i]-1]->getName(c[hand2[i]-1]->getVal())<<" of "<<c[hand2[i]-1]->getSuit()<<endl;
            }
            
            //Deallocate Memory
            delete []c;
            delete []hand1;
            delete []hand2;
            
            break;
        }
    }

    //Exits Program
    return 0;
}