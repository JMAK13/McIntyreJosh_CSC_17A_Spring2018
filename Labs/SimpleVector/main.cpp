/* 
 * File:   main.cpp
 * Author: Josh McIntyre
 * Created on May 14, 2018, 1:52 PM
 */

//System Libraries
#include <iostream>
using namespace std;

//User Libraries
#include "SimpleVector.h"

//Main Function
int main(int argc, char** argv) {
    
    //Initialize Simple Vector
    SimpleVector<int> vs(9);
    
    //Display Default Vector Values
    cout<<"Initial Vector: "<<endl;
    for(int i=0; i<vs.size(); i++){
        cout<<i+1<<") "<<vs.getElementAt(i)<<endl;
    }
    cout<<endl;
    
    //Display Values After Removing Last Vector Element
    cout<<"Vector After Calling pop_back(): "<<endl;
    
    vs.pop_back();
    
    for(int i=0; i<vs.size(); i++){
        cout<<i+1<<") "<<vs.getElementAt(i)<<endl;
    }
    cout<<endl;
    
    //Display Values After Pushing an Element to the Front of the Vector
    cout<<"Vector After Calling push_back(T val): "<<endl;
    
    vs.push_back(12);
    
    for(int i=0; i<vs.size(); i++){
        cout<<i+1<<") "<<vs.getElementAt(i)<<endl;
    }

    //Exit Program
    return 0;
}

