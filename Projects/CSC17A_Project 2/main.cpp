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
#include "Card.h"
using namespace std;

//User Libraries

//Function Prototypes

//Main Function
int main(int argc, char** argv) {
    
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
            
            //Beta Test for Deck of Cards
            for(int i=1; i<=52; i++){
                Card c;
                
                c.setVal(i);
                if(i>0&&i<=13) c.setSuit("Spades");
                if(i>=14&&i<=26) c.setSuit("Clubs");
                if(i>=27&&i<=39) c.setSuit("Hearts");
                if(i>=40&&i<=52) c.setSuit("Diamonds");
                
                cout<<c.toString(c.getVal())<<" of "<<c.getSuit()<<endl;
            }
            
            break;
        }
    }

    //Exits Program
    return 0;
}

