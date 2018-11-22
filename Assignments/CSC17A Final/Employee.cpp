/* 
 * File:   Employee.cpp
 * Author: Josh McIntyre
 * Created on June 3, 2018, 12:41 PM
 */

#include "Employee.h"

Employee::Employee(string name, string title, float hrlyRt){
    MyName=name;
    JobTitle=title;
    HourlyRate=setHourlyRate(hrlyRt);
    HoursWorked=0;
    GrossPay=0;
    NetPay=0;
}

double Employee::Tax(float val){
    float tax=0;
    float tmp=val;
    if(val>=0&&val<=500) return (0.1*tmp);
    else if(val>500&&val<=1000){
        tax+=(.1*500);
        tax+=(.2*(val-500));
        return tax;
    }
    else if(val>1000){
        tax+=(.1*500);
        tax+=(.2*500);
        tmp-=1000;
        tax+=(.3*tmp);
        return tax;
    }
}

int Employee::setHoursWorked(int val){
    if(val<0||val>84) {cout<<"Unacceptable Hours Worked\n"; return 0;}
    else HoursWorked=val;
    return val;
}

float Employee::setHourlyRate(float val){
    if(val<0||val>200) {cout<<"Unacceptable Hourly Rate\n"; return 0;}
    else HourlyRate=val;
    return val;
}

void Employee::toString(){
    cout<<"Name = "<<MyName<<"\nJob Title = "<<JobTitle<<"\nHourly Rate = "<<HourlyRate<<"\nHoursWorked = "<<HoursWorked<<"\nGrossPay = "<<GrossPay<<"\nNetPay = "<<NetPay<<"\n\n";
}

float Employee::getGrossPay(float rate, int worked){
    GrossPay=0;
    HourlyRate=setHourlyRate(rate);
    HoursWorked=setHoursWorked(worked);
    if(worked>=0&&worked<=40){
        GrossPay=setHourlyRate(rate)*setHoursWorked(worked);
        return GrossPay;
    }
    else if(worked>40&&worked<=50){
        GrossPay+=(40*rate);
        GrossPay+=((worked-40)*rate*1.5);
        
        return GrossPay;
    }
    else if(worked>50){
        GrossPay+=(40*rate);
        GrossPay+=(10*rate*1.5);
        cout<<GrossPay<<endl;
        GrossPay+=((worked-50)*rate*2);
        return GrossPay;
    }
}

float Employee::getNetPay(float gross){
    NetPay=gross-Tax(gross);
    return NetPay;
}

float Employee::CalculatePay(float rate, int hours){
    return getNetPay(getGrossPay(setHourlyRate(rate), setHoursWorked(hours)));
}

