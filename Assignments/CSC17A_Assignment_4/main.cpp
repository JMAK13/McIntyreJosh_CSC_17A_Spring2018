/* 
 * File:   main.cpp
 * Author: Josh McIntyre
 * CSC17A Assignment 4
 * Created on April 2, 2018, 10:15 AM
 */

//Global Constants

//System Libraries
#include <iostream>
#include <cctype>
#include <cstring>
#include "Date.h"       //Number 1
#include "Employee.h"   //Number 2
#include "Car.h"
#include "Person.h"
#include "RetailItem.h"
#include "Inventory.h"        //Number 3
using namespace std;

//User Libraries

//Function Prototypes

//Main Function
int main(int argc, char** argv) {
    
    //Declare Variables
    char number;
    int problem;
    bool valid=false;
    
    //Problem Menu
    cout<<"Please input a problem number 1-6: ";
    do{
        cin>>number;
        if(isdigit(number)&&number-48>0&&number-48<7) {
            cout<<"Loading Problem "<<number<<"..."<<endl<<endl;
            valid=true;
        }else {
            cout<<"Invalid problem number!"<<endl;
        }
        
    }while(!valid);
    
    //Initialize Problem Variable
    problem=number-48;
    
    switch(problem) {
        //Problem 1
        case 1:{
            //Declare Variables
            int day,month,year;
            string monStr;
            
            //Prompt for Input
            cout<<"Please enter a valid month: ";
            cin>>month;
            cout<<"Please enter a valid day: ";
            cin>>day;
            cout<<"Please enter a valid year: ";
            cin>>year;
            
            //Initializes Date Object
            Date date(month,day,year);
            
            //Initializes monStr String Variable
            switch(month){
                case 1: {monStr="January";break;}
                case 2: {monStr="February";break;}
                case 3: {monStr="March";break;}
                case 4: {monStr="April";break;}
                case 5: {monStr="May";break;}
                case 6: {monStr="June";break;}
                case 7: {monStr="July";break;}
                case 8: {monStr="August";break;}
                case 9: {monStr="September";break;}
                case 10: {monStr="October";break;}
                case 11: {monStr="November";break;}
                case 12: {monStr="December";break;}
            }
            
            //Displays Output
            cout<<date.getMonth()<<"/"<<date.getDay()<<"/"<<date.getYear()<<endl;
            cout<<monStr<<" "<<date.getDay()<<", "<<date.getYear()<<endl;
            cout<<date.getDay()<<" "<<monStr<<" "<<date.getYear()<<endl;
            
            //Exits problem
            break;
        }
        
        //Problem 2
        case 2:{
            //Declare Variables
            Employee susan("Susan Meyers",47899,"Accounting","Vice President");
            Employee mark("Mark Jones",39119, "IT","Programmer");
            Employee joy("Joy Rogers",81774,"Manufacturing","Engineer");
            
            //Display Output
            cout<<"Name: "<<susan.getName()<<" | ID: "<<susan.getId()<<"   | Department: "<<susan.getDep()<<"      | Position: "<<susan.getPos()<<endl;
            cout<<"Name: "<<mark.getName()<<"   | ID: "<<mark.getId()<<"   | Department: "<<mark.getDep()<<"              | Position: "<<mark.getPos()<<endl;
            cout<<"Name: "<<joy.getName()<<"   | ID: "<<joy.getId()<<"   | Department: "<<joy.getDep()<<"   | Position: "<<joy.getPos()<<endl;
            
            //Exits problem
            break;
        }
        
        //Problem 3
        case 3:{
            //Declare Variables
            int year;
            string make;
            
            //Prompt User for Input
            cout<<"Please enter a valid model year: ";
            cin>>year;
            cout<<"Please enter a valid car make: ";
            cin>>make;
            
            //Create Instance of Car
            Car car(year,make);
            
            //Perform Calculations and Display Output
            for(int i=0; i<5; i++) {
                car.accelerate();
                cout<<"Speed = "<<car.getSpeed()<<endl;
            }
            for(int i=0; i<5; i++) {
                car.brake();
                cout<<"Speed = "<<car.getSpeed()<<endl;
            }
            
            //Exits problem
            break;
        }
        
        //Problem 4
        case 4:{
            //Declare Variables
            Person p1("John Doe","1234 Hipppo Ln.",23,"909-434-5443");
            Person p2("Juan Doe","4325 Kermit Dr.",32,"909-874-8974");
            Person p3("Jane Doe","9838 Street St.",15,"909-387-9873");
            Person p4("Jeff Doe","7831 Canada Rd.",64,"909-738-4309");
            
            //Display Output
            cout<<"Name: "<<p1.getName()<<" | Address: "<<p1.getAdd()<<" | Age: "<<p1.getAge()<<" | Phone: "<<p1.getPhone()<<endl;
            cout<<"Name: "<<p2.getName()<<" | Address: "<<p2.getAdd()<<" | Age: "<<p2.getAge()<<" | Phone: "<<p2.getPhone()<<endl;
            cout<<"Name: "<<p3.getName()<<" | Address: "<<p3.getAdd()<<" | Age: "<<p3.getAge()<<" | Phone: "<<p3.getPhone()<<endl;
            cout<<"Name: "<<p4.getName()<<" | Address: "<<p4.getAdd()<<" | Age: "<<p4.getAge()<<" | Phone: "<<p4.getPhone()<<endl;
            
            //Exits problem
            break;
        }
        
        //Problem 5
        case 5:{
            //Declare Variables
            RetailItem jacket("Jacket",12,59.95);
            RetailItem jeans("Designer Jeans",40,34.95);
            RetailItem shirt("Shirt",20,24.95);
            
            //Display Output
            cout<<"Description: "<<jacket.getDesc()<<"         | Units: "<<jacket.getUnits()<<" | Price: $"<<jacket.getPrice()<<endl;
            cout<<"Description: "<<jeans.getDesc()<<" | Units: "<<jeans.getUnits()<<" | Price: $"<<jeans.getPrice()<<endl;
            cout<<"Description: "<<shirt.getDesc()<<"          | Units: "<<shirt.getUnits()<<" | Price: $"<<shirt.getPrice()<<endl;
            
            //Exits problem
            break;
        }
        
        //Problem 6
        case 6:{
            //Declare Variables
            Inventory i(43425,24.95,45);
            
            //Display Output
            cout<<"Item Number: "<<i.getNum()<<" | Cost: $"<<i.getCost()<<" | Quantity: "<<i.getQuant()<<" | Total Cost: $"<<i.getCostTot()<<endl;
            
            //Exits problem
            break;
        }
    }

    //Exits Program
    return 0;
}

