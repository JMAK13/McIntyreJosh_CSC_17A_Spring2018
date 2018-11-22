/* 
 * File:   Car.h
 * Author: Josh McIntyre
 * Purpose:  Number 3
 * Created on April 4, 2018, 10:19 PM
 */

#ifndef CAR_H
#define CAR_H

#include <string>
using namespace std;

class Car {
    private:
        int year;
        string make;
        int speed;
        
    public:
        Car(int,string);
        ~Car();
        int getYear()const{return year;}
        string getMake()const{return make;}
        int getSpeed()const{return speed;}
        void setYear(int);
        void setMake(string);
        void setSpeed(int);
        void accelerate();
        void brake();

};

#endif /* CAR_H */

