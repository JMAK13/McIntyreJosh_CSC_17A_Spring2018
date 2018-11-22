/* 
 * File:   Inventory.cpp
 * Author: Josh McIntyre
 * Purpose: Number 6
 * Created on April 4, 2018, 10:52 PM
 */

#include "Inventory.h"

Inventory::Inventory() {
    num=0;
    quantity=0;
    cost=0.0f;
    totCost=0.0f;
}

Inventory::Inventory(int n,float c,int q) {
    if(n>0)num=n;
    else num=0;
    if(c>0)cost=c;
    else cost=0;
    if(q>0)quantity=q;
    else quantity=0;
    totCost=quantity*cost;
}

void Inventory::setNum(int n) {
    if(n>0)num=n;
    else num=0;
}

void Inventory::setQuant(int q) {
    if(q>0)quantity=q;
    else quantity=0;
}

void Inventory::setCost(float c) {
    if(c>0)cost=c;
    else cost=0;
}

void Inventory::setCostTot(float t) {
    if(t>0)totCost=t;
    else totCost=0;
}

Inventory::~Inventory() {
    
}

