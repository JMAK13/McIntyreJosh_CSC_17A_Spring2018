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
    float intRate=.08,balance=25.0f;
    
    //Performs Calculations
    if (intRate > .07) {
        cout << "This account earns a $10 bonus.  Balance: $"<<balance<<"\n";
        balance += 10.0;
    }
    
    //Display Output
    cout<<"The original if statement does not contain braces which means that the balance would add 10.0 to itself \nno matter what because it is not inside the if statement."<<endl;
    cout<<"By putting braces around both lines of code, both lines of code are inside the if \nstatement block and both will only be run if the conditional in the if statement is true."<<endl;
    
    //Exits Program
    return 0;
}

