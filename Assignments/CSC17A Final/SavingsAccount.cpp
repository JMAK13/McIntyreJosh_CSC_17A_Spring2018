/* 
 * File:   SavingsAccount.cpp
 * Author: Josh McIntyre
 * Created on June 3, 2018, 2:32 PM
 */

#include "SavingsAccount.h"

SavingsAccount::SavingsAccount(float bal) {
    bal>0?Balance=bal:Balance=0;
    FreqWithDraw=0;
    FreqDeposit=0;
    
}

void SavingsAccount::Transaction(float amt){
    if(amt<0) Balance=Withdraw(amt);
    else Balance=Deposit(amt);
}

float SavingsAccount::Withdraw(float amt){
    amt*=-1;
    if(Balance>amt) {
        Balance-=amt;
        FreqWithDraw++;
    }
    else cout<<"WithDraw not Allowed\n";
    return Balance;
}

float SavingsAccount::Deposit(float amt){
    Balance+=amt;
    FreqDeposit++;
    return Balance;
}

void SavingsAccount::toString(){
    cout<<"Balance = $"<<Balance<<endl;
    cout<<"WithDraws: "<<FreqWithDraw<<endl;
    cout<<"Deposits: "<<FreqDeposit<<endl;
}

float SavingsAccount::Total(float savint, int time){
    Balance=1056.0f;
    float tmp=(1+savint),tmp2=(1+savint);
    for(int i=1; i<time; i++){
        tmp*=tmp2;
    }
    tmp*=Balance;
    return tmp;
}

float SavingsAccount::TotalRecursive(float savint, int time){
   if ( time == 0 ){
      return Balance;
   }

   float interest = Balance * savint;
   Balance+=interest;
   return TotalRecursive(savint, time-1);
}