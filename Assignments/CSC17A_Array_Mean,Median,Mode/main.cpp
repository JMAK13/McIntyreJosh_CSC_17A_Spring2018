/* 
 * File:   main.cpp
 * Author: joshr
 *
 * Created on March 5, 2018, 12:36 PM
 */

//System Libraries
#include <iostream>
#include <cstdlib>
#include <ctime>

//User Libraries

//Global Constants

//Function Prototypes
int prntAry(int [], const int &);
int fillAry(int [], const int &);
void sortAry(int [], const int &);
int median(int [], const int &);
float mean(int [], const int &);

using namespace std;

//Main Function
int main(int argc, char** argv) {

    //Seed the Random Function with Time
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variables
    const int SIZE=40;
    int array[SIZE]={};
    int modes=0;
    
    //Fill, Sort, and Display Random Integer Array
    fillAry(array, SIZE);
    sortAry(array, SIZE);
    cout<<"Array of Random Integers:"<<endl;
    prntAry(array, SIZE);
    
    //Output Median and Mean
    cout<<"\n\nMedian = "<<median(array, SIZE)<<endl;
    cout<<"Mean = "<<mean(array, SIZE)<<endl;
    
    //Calculate Number of Modes
    int tmp;
    for(int i=0; i<SIZE; i++) {
        tmp=array[i];
        if(array[i+1]!=tmp) {
            modes++;
        }
    }
    
    //Output Number of Modes
    cout<<"Number of Modes = "<<modes<<endl;
    
    //Define New Arrays
    int modeAry[modes]={};
    int modeFrq[modes]={};
    int tmp1,index=0,freq=1;
    
    //Calculate Individual Modes
    for(int i=0; i<SIZE; i++) {
        tmp1=array[i];
        if(array[i+1]!=tmp1) {
            modeAry[index]=tmp1;
            index++;
        }
    }
    
    //Calculate Frequencies
    index=0;
    for(int i=0; i<SIZE; i++) {
        tmp1=array[i];
        if(tmp1!=array[i+1]) {
            modeFrq[index]=freq;
            index++;
            freq=1;
        } else freq++;
    }
    
    //Print Frequencies and Modes
    cout<<"Individual Modes:"<<endl;
    prntAry(modeAry, modes);
    cout<<endl;
    cout<<"Mode Frequencies:"<<endl;
    prntAry(modeFrq, modes);
    
    //Exits Program
    return 0;
}

int prntAry(int array[], const int &SIZE) {
    int perLine=10;
    for(int i=0; i<SIZE; i++) {
        cout<<array[i]<<", ";
        if(i%perLine==0&&i>0) {
            cout<<endl;
        }
            
    }
}

int fillAry(int array[], const int &SIZE) {
    
    for(int i=0; i<SIZE; i++) {
        array[i]=rand()%100+1;
    }
    
    return array[SIZE];
}

void sortAry(int array[], const int &SIZE) {
    bool swap;
    int temp;
    do {
        swap = false;
        for (int i=0; i<(SIZE-1); i++) {
            if (array[i]>array[i+1]) {
                temp=array[i];
                array[i]=array[i+1];
                array[i+1]=temp;
                swap = true;
            }
        }
    } while (swap);
}

int median(int array[], const int &SIZE) {
    
    return (array[static_cast<int>(SIZE/2)]);
}

float mean(int array[], const int &SIZE) {
    
    float mean=0;
    
    for(int i=0; i<SIZE; i++) {
        mean+=array[i];
    }
    
    return (mean=mean/SIZE);
}

