/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Date.cpp
 * Author: Josh McIntyre
 * Purpose: Number 1
 * Created on April 4, 2018, 9:24 PM
 */

#include <iostream>
#include "Date.h"

Date::Date(int m, int d, int y) {
    if(m<=0||d<=0||y<=0||m>12||d>31) {
        std::cout<<"Invalid Date"<<std::endl;
    }else {
        month=m;
        day=d;
        year=y;
    }
}

void Date::setDay(int d) {
    if(d>0&&d<=31) day=d;
    else d=0;
}

void Date::setMonth(int m) {
    if(m>0&&m<=12) month=m;
    else m=0;
}

void Date::setYear(int y) {
    if(y>0) year=y;
    else y=0;
}

Date::~Date() {
    
}

