/* 
 * File:   Array.cpp
 * Author: Josh McIntyre
 * Created on March 27, 2018, 9:50 PM
 */

#include "Array.h"
#include <cstdlib>
#include <ctime>

using namespace std;

Array::Array(int r, int c){
    if(r<=1) rows=2;
    else if(r>1000) rows=1000;
    else rows=r;
    if(c<=1) cols=2;
    else if(c>1000) cols=1000;
    else cols=c;
    
    data = new int*[rows];
    for(int i=0; i<rows; i++) {
        data[i]=new int[cols];
        for(int j=0; j<cols; j++) {
            data[i][j]=rand()%90+10;
        }
    }
}

Array::getData(int row, int col)const{
    if( (row>=0&&row<rows) & (col>=0&&col<cols) ) return data[row][col];
    else return data[0][0];
}

Array::~Array() {
    if(data) {
        for(int row=0;row<rows;row++){
            delete [] data[row];
        }
        delete data;
    }
//    delete a;
}
//void Array::setRows(int row) {
//    if(row<0) return;
//    else rows=row;
//}
//
//void Array::setCols(int col) {
//    if(col<0) return;
//    else cols=col;
//}

