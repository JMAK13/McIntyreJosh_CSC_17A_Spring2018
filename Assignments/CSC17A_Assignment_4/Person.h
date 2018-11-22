/* 
 * File:   Person.h
 * Author: Josh McIntyre
 * Purpose: Number 4
 * Created on April 4, 2018, 10:32 PM
 */

#ifndef PERSON_H
#define PERSON_H

#include <string>
using namespace std;

class Person {
    private:
        string name;
        string address;
        int age;
        string phone;
        
    public:
        Person(string,string,int,string);
        ~Person();
        string getName()const{return name;}
        string getAdd()const{return address;}
        int getAge()const{return age;}
        string getPhone()const{return phone;}
        void setName(string);
        void setAdd(string);
        void setAge(int);
        void setPhone(string);
};

#endif /* PERSON_H */

