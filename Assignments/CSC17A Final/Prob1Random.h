/* 
 * File:   Random.h
 * Author: Josh McIntyre
 * Problem 1
 * Created on June 1, 2018, 8:49 AM
 */

#ifndef PROB1RANDOM_H
#define PROB1RANDOM_H

template <class T>
class Prob1Random
{
	private:
		T *set;               //The set of numbers to draw random numbers from
		char nset;            //The number of variables in the sequence
		int *freq;            //Frequency of all the random numbers returned
		int numRand;   //The total number of times the random number function is called
	public:
		Prob1Random(const char,const T *);              //Constructor
		~Prob1Random(void);                             //Destructor
		T randFromSet(void);                            //Returns a random number from the set
		int *getFreq(void) const {return freq;}         //Returns the frequency histogram
		T *getSet(void) const {return set;}             //Returns the set used
		int getNumRand(void) const {return numRand;}    //Gets the number of times randFromSet has been called
};

template <class T>
Prob1Random<T>::Prob1Random(const char size, const T *array){
    set=new T[size];
    freq=new int[size];
    nset=size;
    numRand=0;
    for(int i=0; i<size; i++){
        set[i]=array[i];
        freq[i]=0;
    }
}

template <class T>
Prob1Random<T>::~Prob1Random(){
    delete []set;
    delete[]freq;
}

template <class T>
T Prob1Random<T>::randFromSet(){
    int i=rand()%nset;
    freq[i]++;
    numRand++;
    return set[i];
}

#endif /* PROB1RANDOM_H */

