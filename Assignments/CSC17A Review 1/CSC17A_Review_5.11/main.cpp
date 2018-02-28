/* 
 * File:   main.cpp
 * Author: Josh McIntyre
 * Created on February 26, 2018, 1:33 PM
 */

//System Libraries
#include <iostream>
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes

//Main Function
int main(int argc, char** argv) {
    
    //Loops Through Numbers 0 to 100
    for(int i=0;i<=100;i++) {
        
        //Iterates Through Every Fifth Number
        if(i%5==0)
            
            //Displays Every Fifth Number
            cout<<i<<endl;
    }
    
    //Exits Program
    return 0;
}

