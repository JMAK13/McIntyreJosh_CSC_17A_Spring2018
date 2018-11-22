/* 
 * File:   Employee.h
 * Author: Josh McIntyre
 * Created on June 3, 2018, 12:41 PM
 */

#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>
using namespace std;

class Employee {
        public:
		Employee(string,string,float);  //Constructor
		float  CalculatePay(float,int); //Procedure
		float  getGrossPay(float,int);  //Procedure
		float  getNetPay(float);        //Procedure
		void   toString();              //Procedure
		int    setHoursWorked(int);     //Procedure
		float  setHourlyRate(float);    //Procedure
	private:
		double Tax(float);      //Utility Procedure
		string   MyName;      //Property
		string   JobTitle;    //Property
		float  HourlyRate;      //Property
		int    HoursWorked;     //Property
		float  GrossPay;        //Property
		float  NetPay;          //Property
};

#endif /* EMPLOYEE_H */

