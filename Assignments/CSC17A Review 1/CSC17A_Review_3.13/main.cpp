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
    int integer1, integer2;
    double result;
    
    //Performs Calculations
    integer1=19;
    integer2=2;
    result=integer1/integer2;
    cout<<"Integer Division Result: "<<result << endl;
    result=static_cast<double>(integer1) / integer2;
    cout<<"Double/Integer Division Result: "<<result<<endl;
    result=static_cast<double>(integer1 / integer2);
    cout<<"Double/Double Division Result: "<<result<<endl;
    
    //Exits Program
    return 0;
}

