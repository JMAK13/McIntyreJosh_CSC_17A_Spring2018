/* 
 * File:   Deck.h
 * Author: Josh McIntyre
 * Created on May 14, 2018, 6:15 PM
 */

#ifndef DECK_H
#define DECK_H

template <class T>
class Deck{
    private:
        T **card;
        int *index;
        static const int nCards=52;
        int delt;
    public:
        //Constructor Taking Number of Cards as Parameter
        Deck();
        
        //Destructor
        ~Deck();
        
        //Card Accessor Member Function
        T *getCard(int i)const{return card[i];}
        
        //Card Index Accessor Member Function
        int getI(int i)const{return index[i];}
        
        //Card Index Mutator Member Function
        void setI(int,int);
        
        //Gets Number of Cards in Deck
        int numCards()const{return nCards;}
        
        //Delt Accessor Member Function
        int getDelt()const{return delt;}
        
        //Delt Mutator Member Function
        void setDelt(int);
};

template <class T>
Deck<T>::Deck(){
    //Sets Default Variable Values
    card=new T*[nCards];
    delt=0;
    //Allocates Memory for Cards
    index=new int[nCards];
    for(int i=0; i<nCards; i++){
        card[i]=new T(i+1);
        index[i]=i;
    }
}

template <class T>
Deck<T>::~Deck(){
    //Deallocates Memory
    for(int i=0; i<nCards; i++){
        delete card[i];
        
    }
    delete []card;
}

template <class T>
void Deck<T>::setI(int i, int v){
    if(i>=0) index[i]=v;
    //else throw invalid index exception
}

template <class T>
void Deck<T>::setDelt(int i){
    if(i>=0) delt=i;
}
#endif /* DECK_H */

