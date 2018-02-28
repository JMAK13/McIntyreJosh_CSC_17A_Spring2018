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
    float sales,comRate,bonus;
    
    //Prompt User
    do {
        cout<<"Please input the sales: ";
        cin>>sales;
    } while(sales<=0);
    
    //Performs Calculations
    if(sales>50000) {
        cout<<"Sales was "<<sales<<" which makes the commission rate "<<comRate<<" and the bonus variable "<<bonus<<endl;
    }
    else {
        cout<<"Sales was "<<sales<<" which leaves the commission rate and bonus variables unchanged"<<endl;
    }
    
    //Exits Program
    return 0;
}

