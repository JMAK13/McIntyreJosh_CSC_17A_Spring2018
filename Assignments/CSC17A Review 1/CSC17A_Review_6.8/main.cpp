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
void showDouble(int);

//Main Function
int main(int argc, char** argv) {
    
    //Declare Variables
    int num;
    
    //Perform Calculations
    for (num = 0; num < 10; num++)
        showDouble(num);
    
    cout<<"\nThe program outputs the numbers 1 through nine on the left, and then their values doubled to the right of them."<<endl;
    
    //Exits Program
    return 0;
}

// Definition of function showDouble.
void showDouble(int value) {
    cout << value << "\t" << (value * 2) << endl;
}