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
    
    //Display Output
    cout<<"The binary search performs n searches on a number where n is an exponent that makes 2^n greater than or equal to the array's number of elements.\n";
    cout<<"Therefore, with an array of 20,000 elements, the binary search will perform 15 maximum searches \n";
    cout<<"because 15 is the smallest exponent 2 can have that makes 2^n greater than 20,000.\n";
    
    //Exits Program
    return 0;
}