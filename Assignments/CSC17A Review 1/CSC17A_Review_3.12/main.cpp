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
    char letter;
    
    //Prompt User
    cout<<"Please input a character: ";
    cin>>letter;
    
    //Display Output
    cout<<"You input letter "<<letter<<endl;
    cout<<"The ASCII code for letter "<<letter<<" is "<<static_cast<int>(letter)<<endl;
    
    //Exits Program
    return 0;
}

