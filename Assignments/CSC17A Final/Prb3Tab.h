/* 
 * File:   Prb3Tab.h
 * Author: Josh McIntyre
 * Created on June 2, 2018, 7:30 PM
*/

#ifndef PRB3TAB_H
#define PRB3TAB_H

#include <string>
#include <fstream>
#include <iostream>
using namespace std;

template<class T>
class Prb3Tab
{
	protected:
		int rows;                                 //Number of rows in the table
		int cols;                                 //Number of cols in the table
		T *table;                                 //Table array
		T grndTot;                                //Grand total
	public:
                Prb3Tab<T>(){};
		Prb3Tab(string,int,int);                  //Constructor then Destructor
		virtual ~Prb3Tab(){delete []table;}
		const T *getTab(void){return table;}
		T getGdTot(void){return grndTot;}
};

template <class T>
Prb3Tab<T>::Prb3Tab(string s, int r, int c){
    rows=r;
    cols=c;
    grndTot=0;
    
    table=new T[r*c];
    ifstream file(s);

    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            file >> table[i*c+j];
        }
    }
    file.close();
}

template<class T>
class Prb3TbI : public Prb3Tab<T>                           //Problem 3 Inherited Table
{
	protected:
		T *augTab;                                  //Augmented Table with sums
	public:
		Prb3TbI(string,int,int);                    //Constructor
		~Prb3TbI(){delete []augTab;}                //Destructor
		const T *getAugT(void){return augTab;} 
};

template <class T>
Prb3TbI<T>::Prb3TbI(string s, int r, int c){
    
    //Declare Variables
    int augR=r+1;
    int augC=c+1;
    this->rows=r;
    this->cols=c;
    this->grndTot=0;
    augTab=new T[augR*augC];
    T array[augR][augC]={};
    T rSum[r]={};
    T cSum[c]={};
    this->table=new T[r*c];
    
    //Read in data from file
    ifstream file(s);

    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            file >> this->table[i*c+j];
        }
    }
    file.close();
    
    //Turn Into 2D Array
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            array[i][j]=this->table[i*c+j];
        }
    }
    
    //Sum Up Rows
    for(int i=0; i<r; i++){
        int sum=0;
        for(int j=0; j<c; j++){
            sum+=array[i][j];
        }
        rSum[i]=sum;
        this->grndTot+=sum;
    }
    
    //Sum Up Columns
    for(int i=0; i<c; i++){
        int sum=0;
        for(int j=0; j<r; j++){
            sum+=array[j][i];
        }
        cSum[i]=sum;
    }
    
    //Insert Row Sums
    for(int i=0; i<r; i++){
        array[i][c]=rSum[i];
    }
    
    //Insert Col Sums
    for(int j=0; j<c; j++){
        array[r][j]=cSum[j];
    }
    
    //Insert Table Sum
    array[r][c]=this->getGdTot();
    
    //Transfer Back to 1D Array
    for(int i=0; i<=r; i++){
        for(int j=0; j<=c; j++){
            augTab[i*(c+1)+j]=array[i][j];
        }
    }
}

#endif /* PRB3TAB_H */

