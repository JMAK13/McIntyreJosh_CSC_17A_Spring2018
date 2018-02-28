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
int timesTen(int);

//Main Function
int main(int argc, char** argv) {
    
    //Call Function
    int num=5;
    cout<<"Original Number: "<<num<<endl;
    cout<<"New Number: "<<timesTen(num)<<endl;
    
    //Exits Program
    return 0;
}

int timesTen(int a) {
    return (a*10);
}