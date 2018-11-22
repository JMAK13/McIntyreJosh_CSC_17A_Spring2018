/* 
 * File:   main.cpp
 * Author: Josh McIntyre
 * Created on May 21, 2018, 11:30 PM
 */

#include <cstdlib>
#include <iostream>
using namespace std;


//Implement the class Box  
//l,b,h are integers representing the dimensions of the box

// The class should have the following functions : 

// Constructors: 
// Box();
// Box(int,int,int);
// Box(Box);


// int getLength(); // Return box's length
// int getBreadth (); // Return box's breadth
// int getHeight ();  //Return box's height
// long long CalculateVolume(); // Return the volume of the box

//Overload operator < as specified
//bool operator<(Box& b)

//Overload operator << as specified
//ostream& operator<<(ostream& out, Box& B)

class Box{
    private:
        int l;
        int b;
        int h;
    public:
        Box();
    
        Box(int,int,int);
    
        Box(Box &);
    
        ~Box();
    
        int getLength()const{return l;}
    
        int getBreadth()const{return b;}
    
        int getHeight()const{return h;}
    
        long long CalculateVolume(){return static_cast<long long>(l*b*h);}
    
        bool operator<(Box& box){
            if(this->l<=box.l||this->b<=box.b&&this->l==box.l || 
                this->h<=box.h&&this->l==box.l&&this->b==box.b) return true;
            return false;
        }
    
        friend ostream& operator<<(ostream &out, const Box &B);

};
         ostream& operator<<(ostream  &out, const Box &B){
             out<< B.l<<" "<< B.b<< " " << B.h;
         return out;
    }

Box::Box(){
    l=1;
    b=1;
    h=1;
}

Box::Box(int length, int breadth, int height){
    if(length>=1 && length<=100000)this->l=length;
    if(breadth>=1 && breadth<=100000)this->b=breadth;
    if(height>=1 && height<=100000)this->h=height;
}

Box::Box(Box &box){
    this->l=box.l;
    this->b=box.b;
    this->h=box.h;
}

Box::~Box(){
}

int main(int argc, char** argv) {
    
    cout<<"See HackerRank for main() function, text cannot be copied.\n";

    return 0;
}

