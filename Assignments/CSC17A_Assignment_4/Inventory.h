/* 
 * File:   Inventory.h
 * Author: Josh McIntyre
 * Purpose: Number 6
 * Created on April 4, 2018, 10:52 PM
 */

#ifndef INVENTORY_H
#define INVENTORY_H

class Inventory {
    private:
        int num;
        int quantity;
        float cost;
        float totCost;
    public:
        Inventory();
        Inventory(int,float,int);
        ~Inventory();
        int getNum()const{return num;}
        int getQuant()const{return quantity;}
        float getCost()const{return cost;}
        float getCostTot()const{return totCost;}
        void setNum(int);
        void setQuant(int);
        void setCost(float);
        void setCostTot(float);
};

#endif /* INVENTORY_H */

