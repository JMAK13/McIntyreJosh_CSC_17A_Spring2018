/* 
 * File:   RetailItem.h
 * Author: Josh McIntyre
 * Purpose: Number 5
 * Created on April 4, 2018, 10:43 PM
 */

#ifndef RETAILITEM_H
#define RETAILITEM_H

#include <string>
using namespace std;

class RetailItem {
    private:
        string desc;
        int units;
        float price;
    public:
        RetailItem(string,int,float);
        ~RetailItem();
        string getDesc()const{return desc;}
        int getUnits()const{return units;}
        float getPrice()const{return price;}
        void setDesc(string);
        void setUnits(int);
        void setPrice(float);
};

#endif /* RETAILITEM_H */

