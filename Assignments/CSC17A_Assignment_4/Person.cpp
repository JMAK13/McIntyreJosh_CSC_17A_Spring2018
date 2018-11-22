/* 
 * File:   Person.cpp
 * Author: Josh McIntyre
 * Purpose: Number 4
 * Created on April 4, 2018, 10:32 PM
 */

#include "Person.h"

Person::Person(string n,string ad,int a,string p) {
    name=n;
    address=ad;
    if(a>0)age=a;
    else age=0;
    phone=p;
}

void Person::setName(string n) {
    name=n;
}

void Person::setAdd(string ad) {
    address=ad;
}

void Person::setAge(int a) {
    if(a>0)age=a;
    else age=0;
}

void Person::setPhone(string p) {
    phone=p;
}

Person::~Person() {
    
}

