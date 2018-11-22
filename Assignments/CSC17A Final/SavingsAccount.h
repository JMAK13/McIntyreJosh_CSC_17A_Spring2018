/* 
 * File:   SavingsAccount.h
 * Author: Josh McIntyre
 * Created on June 3, 2018, 2:32 PM
 */

#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H

#include <iostream>
#include <cmath>
using namespace std;

class SavingsAccount {
        public:
		SavingsAccount(float);               //Constructor
		void  Transaction(float);            //Procedure
		float Total(float=0,int=0);	     //Savings Procedure
		float TotalRecursive(float=0,int=0);
		void  toString();                    //Output Properties
	private:
		float Withdraw(float);               //Utility Procedure
		float Deposit(float);                //Utility Procedure
		float Balance;                       //Property
		int   FreqWithDraw;                  //Property
		int   FreqDeposit;                   //Property
};

#endif /* SAVINGSACCOUNT_H */

