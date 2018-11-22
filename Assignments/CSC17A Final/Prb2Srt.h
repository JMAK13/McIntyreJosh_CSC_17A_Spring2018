/* 
 * File:   Prb2Srt.h
 * Author: Josh McIntyre
 * Created on June 2, 2018, 4:44 PM
 */

#ifndef PRB2SRT_H
#define PRB2SRT_H

#include <iostream>
using namespace std;

template<class T>
class Prb2Srt
{
	private:
		int *index;                              //Index that is utilized in the sort
	public:
		Prb2Srt(){index=nullptr;}                //Constructor
		~Prb2Srt(){delete []index;}              //Destructor
		T *srtArry(const T*,int,bool);           //Sorts a single column array
		T *srtArry(const T*,int,int,int,bool);   //Sorts a 2 dimensional array represented as a 1 dim array
};

template <class T>
T* Prb2Srt<T>::srtArry(const T *val, int r, bool ascending){
    bool swap;
    T temp;
    
    T *array=new T[r];
    array=val;
    for(int i=1; i<r; i++)
        index[i]=i;
    
    do{
        swap = false;
        for (int count = 0; count < (r-1); count++){
            if (array[count] > array[count + 1]){
                temp = array[count];
                array[count] = array[count + 1];
                array[count + 1] = temp;
                swap = true;
            }
        }
    }while(swap);
    
    return array;
}

template <class T>
T* Prb2Srt<T>::srtArry(const T *val, int r, int c, int column, bool ascending){
    bool swap;
    T temp;
    
    index=new int[r];
    index[0]=0;
    for(int i=1; i<r; i++)
        index[i]=index[i-1]+(c-1);
    int *ind=new int[r];
    ind[0]=column-1;
    for(int i=1; i<r; i++)
        ind[i]=ind[i-1]+(c-1);
    
    T *array=new T[r*c];
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++)
            array[i*c+j]=val[i*c+j];
    }
    
    do{
        swap = false;
            for (int i = 0; i < (r-1); i++){
                index[0]=0;
                for(int t=1; t<r; t++)
                    index[t]=index[t-1]+(c-1);
                
                if(ascending){
                    if (array[ind[i]] > array[ind[i]+(c-1)]){
                        for(int j=0; j<(c-1); j++){
                            temp = array[index[i]];
                            array[index[i]] = array[index[i]+(c-1)];
                            array[index[i]+(c-1)] = temp;
                            index[i]++;
                        }
                        swap = true;
                    }
                }else{
                   if (array[ind[i]] < array[ind[i]+(c-1)]){
                        for(int j=0; j<(c-1); j++){
                            temp = array[index[i]];
                            array[index[i]] = array[index[i]+(c-1)];
                            array[index[i]+(c-1)] = temp;
                            index[i]++;
                        }
                        swap = true;
                    } 
                }
            }
    }while(swap);
    
    return array;
}
#endif /* PRB2SRT_H */

