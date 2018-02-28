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

    //Declare Variables
    int x=4,y=5;
    
    //Performs Calculations
    if (x > y) {
        cout << "x is the greater.\n";
    }
    else {
        cout << "x is not the greater.\n";
    }
    if (y <= x) {
        cout << "x is not the greater.\n";
    }
    else {
        cout << "x is the greater.\n";
    }
    
    //Display Output
    cout<<"The outputs are different, the second statement is syntactically correct, but logically incorrect.\n";
    cout<<"The statements are the same only if x=y.\n";
    
    //Exits Program
    return 0;
}

