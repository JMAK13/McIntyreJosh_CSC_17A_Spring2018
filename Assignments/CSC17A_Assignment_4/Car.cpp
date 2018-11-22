/* 
 * File:   Car.cpp
 * Author: Josh McIntyre
 * Purpose: Number 3
 * Created on April 4, 2018, 10:19 PM
 */

#include "Car.h"

Car::Car(int y, string m) {
    if(y>0) year=y;
    else year=0;
    make=m;
    speed=0;
}

void Car::setYear(int y) {
    if(y>0) year=y;
    else year=0;
}

void Car::setMake(string m) {
    make=m;
}

void Car::setSpeed(int s) {
    if(s>0) speed=s;
    else speed=0;
}

void Car::accelerate() {
    speed+=5;
}

void Car::brake() {
    if(speed>5)speed-=5;
    else speed=0;
}

Car::~Car() {
    
}

