/* 
 * File:   Date.h
 * Author: Josh McIntyre
 * Purpose: Number 1
 * Created on April 4, 2018, 9:24 PM
 */

#ifndef DATE_H
#define DATE_H

class Date{
    private:
        int month;
        int day;
        int year;
        
    public:
        Date(int,int,int);
        ~Date();
        int getMonth()const{return month;}
        int getDay()const{return day;}
        int getYear()const{return year;}
        void setMonth(int);
        void setDay(int);
        void setYear(int);
};

#endif /* DATE_H */

