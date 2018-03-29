/* 
 * File:   Array.h
 * Author: Josh McIntyre
 * Created on March 27, 2018, 9:50 PM
 */

#ifndef ARRAY_H
#define ARRAY_H

class Array{
    private:
        int rows;
        int cols;
        int **data;
    public:
        Array(int,int);
        ~Array();
        int getData(int,int)const;
        int getRows()const{return rows;}
        int getCols()const{return cols;}
//        void setRows(int);
//        void setCols(int);
};

#endif /* ARRAY_H */

