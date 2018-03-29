/* 
 * File:   main.cpp
 * Author: Josh McIntyre
 * Created on March 27, 2018, 9:31 PM
 */

//System Libraries
#include <iostream>  //I/O Library
#include <cstdlib>   //srand, rand
#include <ctime>

#include "Array.h"     //Time
using namespace std;

//User Libraries

//Global Constants - Math, Science, Conversions, 2D Array Sizes

//Function Prototypes
//Array *fillAry(int,int);
void prntAry(Array *);
//void destroy(Array *);

//Executions Begin Here!
int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare and allocate memory for the array
    int row=10,col=20;
//    Array *array=fillAry(row,col);
    Array array(row,col);
    //Print the random 2-Digit array
    prntAry(&array);
    
    //Deallocate memory
//    destroy(array);

    return 0;
}

void prntAry(Array *a){
    cout<<endl;
    for(int row=0;row<a->getRows();row++){
        for(int col=0;col<a->getCols();col++){
            cout<<a->getData(row,col)<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

//void destroy(Array *a){
//    if(!a)return;
//    for(int row=0;row<a->getRows();row++){
//        delete []a->getData(row);
//    }
//    delete []a->getData(row);
//    delete a;
//}

//Array *fillAry(int rows,int cols){
//    //Is the size parameter valid
//    if(rows<=0)return 0;
//    if(cols<=0)return 0;
//    
//    //Allocate memory
//    Array *array=new Array();
//    array->setRows(rows);
//    array->setCols(cols);
//    array->getData(rows)=new int[rows];
//    
//    //Fill with 2 digit random numbers
//    for(int row=0;row<rows;row++){
//        for(int col=0;col<cols;col++){
//            array->getData(row)=rand()%90+10;
//        }
//    }
//    
//    //Return the array
//    return array;
//}

