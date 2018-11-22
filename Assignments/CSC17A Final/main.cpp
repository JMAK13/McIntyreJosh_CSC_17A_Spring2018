/* 
 * File:   main.cpp
 * Author: Josh McIntyre
 * CSC17A Final
 * Created on June 1, 2018, 8:37 AM
 */

//Global Constants

//System Libraries
#include <iostream> //cout,cin
#include <cctype>   //isdigit()
#include <ctime>    //time()
#include <cstdlib>  //rand(),srand()
#include <fstream>
using namespace std;

//User Libraries
#include "Prob1Random.h"
#include "Prb2Srt.h"
#include "Prb3Tab.h"
#include "SavingsAccount.h"
#include "Employee.h"

//Function Prototypes

//Main Function
int main(int argc, char** argv) {
    
    //Seeds Random Function With Time
    srand(static_cast<unsigned int>(time(0)));
    
    //Menu Variables
    bool menu=false,menu2=false,check=false;
    char problem,program;
    int probNum;
    
    //Prompt User With Menu and Validate Input
    cout<<"Welcome to Josh McIntyre's CSC17A Final\n";
    do{
        do{
            cout<<"Please input the problem number you would like to solve[1-6]: ";
            cin>>problem;
            if(isdigit(problem)&&problem>'0'&&problem<'7') {menu=true; probNum=problem-'0';}
            else cout<<"Incorrect problem number, input a nunmber between 1 and 6.";
        }while(!menu);
        cout<<"\nLoading Problem "<<probNum<<"...\n\n";

        //Executes Inputted Problem Number
        switch(probNum){

            //Problem 1
            case 1:{

                cout<<"Problem 1 the probability problem";
                char n=5;
                char rndseq[]={16,33,56,77,126};
                int ntimes=100000;
                Prob1Random<char> a(n,rndseq);
                for(int i=1;i<=ntimes;i++)
                        a.randFromSet();
                int *x=a.getFreq();
                char *y=a.getSet();
                for(int i=0;i<n;i++)
                        cout<<int(y[i])<<" occured "<<x[i]<<" times"<<endl;
                cout<<"The total number of random numbers is "<<a.getNumRand()<<endl;

                break;
            }

            //Problem 2
            case 2:{
                
                cout<<"The start of Problem 2, the sorting problem"<<endl;
                Prb2Srt<char> rc;
                bool ascending=true;
                ifstream infile;
                infile.open("Problem2.txt",ios::in);
                char *ch2=new char[10*16];
                char *ch2p=ch2;
                int index=0;
                while(!infile.eof()){
                    infile >> ch2[index];
                    cout<<ch2[index];
                    if((index+1)%15==0) cout<<endl;
                    index++;
                }
                infile.close();
                cout<<endl;
                cout<<"Sorting on which column: ";
                int column;
                cin>>column;
                char *zc=rc.srtArry(ch2p,10,16,column,ascending);
                for(int i=0;i<10;i++){
                    for(int j=0;j<16;j++){
                        cout<<zc[i*16+j];
                        int ind=i*16+j;
                        if((ind+1)%15==0) cout<<endl;
                    }
                }
                delete []zc;
                delete []ch2p;
                delete []ch2;
                cout<<endl;

                break;
            }

            //Problem 3
            case 3:{
                cout<<"Entering problem number 3"<<endl;
                int rows=5;
                int cols=6;
                string str="Problem3.txt";
                Prb3TbI<int> tab(str,rows,cols);
                const int *naugT=tab.getTab();
                for(int i=0;i<rows;i++){
                        for(int j=0;j<cols;j++){
                            cout<<naugT[i*cols+j]<<" ";
                        }
                        cout<<endl;
                }
                cout<<endl;
                const int *augT=tab.getAugT();
                for(int i=0;i<=rows;i++){
                        for(int j=0;j<=cols;j++){
                            cout<<augT[i*(cols+1)+j]<<" ";
                        }
                        cout<<endl;
                }
                
                break;
            }

            //Problem 4
            case 4:{
                
                SavingsAccount mine(-300);

                for(int i=1;i<=10;i++){
                    mine.Transaction((float)(rand()%500)*(rand()%3-1));
                }
                mine.toString();
                cout<<"Balance after 7 years given 10% interest = "<<mine.Total((float)(0.10),7)<<endl;
                cout<<"Balance after 7 years given 10% interest = "<<mine.TotalRecursive((float)(0.10),7)<<" Recursive Calculation "<<endl;

                break;
            }

            //Problem 5
            case 5:{
                
                Employee Mark("Mark","Boss",215.50);
                Mark.setHoursWorked(-3);
                Mark.toString();
                Mark.CalculatePay(Mark.setHourlyRate(20.0),
                        Mark.setHoursWorked(25));
                Mark.toString();
                Mark.CalculatePay(Mark.setHourlyRate(40.0),
                        Mark.setHoursWorked(25));
                Mark.toString();
                Mark.CalculatePay(Mark.setHourlyRate(60.0),
                        Mark.setHoursWorked(25));
                Mark.toString();

                Employee Mary("Mary","VP",50.0);
                Mary.toString();
                Mary.CalculatePay(Mary.setHourlyRate(50.0),
                        Mary.setHoursWorked(40));
                Mary.toString();
                Mary.CalculatePay(Mary.setHourlyRate(50.0),
                        Mary.setHoursWorked(50));
                Mary.toString();
                Mary.CalculatePay(Mary.setHourlyRate(50.0),
                        Mary.setHoursWorked(60));
                Mary.toString();

                break;
            }

            //Problem 6
            case 6:{
                
                //Part 1
                cout<<"1)\n";
                cout<<"3.75 in hex is 3.C\n3.75 in octal is 3.6\n3.75 in binary is 11.11\n\n";
                cout<<"0.7 in hex is 0.B33\n0.7 in octal is 0.5463\n0.7 in binary is 0.10110011\n\n";
                cout<<"89.9 in hex is 59.E66\n89.9 in octal is 131.7146314\n89.9 in binary is 1011001.11100110011\n\n";
                
                //Part 2
                cout<<"2)\n";
                cout<<"3.75 -> 40700000\n0.7 -> 3F333333\n89.9 -> 42B3CCCD\n\n";
                
                //Parts 3 & 4
                cout<<"3 & 4)\n";
                cout<<"Integer Binary of 3.75 is 00000011\nMultiplied by 7 yields 00010101=21\n";
                cout<<"Integer Binary of 0.7 is 00000000 00000000\nMultipled by 7 yields 00000000 00000000=0\n";
                cout<<"Integer Binary of 89.9 is 00000000 00000000 01011001\nMultiplied by 7 yields 00000000 00000010 01101111=623\n\n";
                
                //Part 5
                cout<<"5)\n";
                cout<<"21 in IEEE 754 is 0100 0001 1010 1000 0000 0000 0000 0000=41A80000\n";
                cout<<"0 in IEEE 754 is 0000 0000 0000 0000 0000 0000 0000 0000=0\n";
                cout<<"623 in IEEE 754 is 0100 0100 0001 1011 1100 0000 0000 0000=441BC000\n";

                break;
            }
        }
        
        //Prompt Whether to Exit or Return to Menu
        cout<<endl;
        do{
            cout<<"Press 0 to go to Main Menu or 1 to Exit: \n";
            cin>>program;
            if(isdigit(program)&&(program=='0'||program=='1')) check=true;
        }while(!check);
        
        if(program=='1') menu2=true;
    }while(!menu2);
    
    cout<<"\nGoodbye!\n";

    //Exits Program
    return 0;
}

