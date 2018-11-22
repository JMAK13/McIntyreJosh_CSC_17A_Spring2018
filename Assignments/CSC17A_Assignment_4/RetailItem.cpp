/* 
 * File:   RetailItem.cpp
 * Author: Josh McIntyre
 * Purpose: Number 5
 * Created on April 4, 2018, 10:43 PM
 */

#include "RetailItem.h"

RetailItem::RetailItem(string d, int u, float p) {
    desc=d;
    if(u>0)units=u;
    else u=0;
    if(p>0)price=p;
    else p=0.0f;
}

void RetailItem::setDesc(string d) {
    desc=d;
}

void RetailItem::setUnits(int u) {
    if(u>0)units=u;
    else u=0;
}

void RetailItem::setPrice(float p) {
    if(p>0)price=p;
    else p=0.0f;
}

RetailItem::~RetailItem() {
    
}

