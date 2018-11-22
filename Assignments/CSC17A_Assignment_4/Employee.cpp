/* 
 * File:   Employee.cpp
 * Author: Josh McIntyre
 * Purpose: Number 2
 * Created on April 4, 2018, 9:40 PM
 */

#include "Employee.h"

Employee::Employee(string n, int i, string d, string p){
    name=n;
    if(i>0) id=i;
    else id=0;
    depart=d;
    position=p;
}

void Employee::setName(string n){
    name=n;
}

void Employee::setId(int i){
    if(id>0) id=i;
    else id=0;
}

void Employee::setDep(string d){
    depart=d;
}

void Employee::setPos(string p){
    position=p;
}

Employee::~Employee(){
    
}

