/* 
 * File:   Employee.h
 * Author: Josh McIntyre
 * Purpose: Number 2
 * Created on April 4, 2018, 9:40 PM
 */

#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
using namespace std;

class Employee {
    private:
        string name;
        int id;
        string depart;
        string position;
        
    public:
        Employee(string,int,string,string);
        ~Employee();
        string getName()const{return name;}
        int getId()const{return id;}
        string getDep()const{return depart;}
        string getPos()const{return position;}
        void setName(string);
        void setId(int);
        void setDep(string);
        void setPos(string);
};

#endif /* EMPLOYEE_H */

