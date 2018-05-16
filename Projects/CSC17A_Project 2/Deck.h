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
        int nCards;
        int delt;
    public:
        //Constructor Taking Number of Cards as Parameter
        Deck(int);
        
        //Destructor
        ~Deck();
        
        //Deal Member Function
        int *deal(int);
        
        //Shuffle Member Function
        shuffle();
};

template <class T>
Deck<T>::Deck(int numCard){
    //Sets Default Variable Values
    delt=0;
    numCard>0?nCards=numCard:nCards=52;
    card=new T*[nCards];
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
int *Deck<T>::deal(int numCard){
    int *hand=new int[numCard];
    for(int i=delt; i<numCard+delt; i++){
        hand[i-delt]=index[i]+1;
    }
    delt+=numCard;
    return hand;
}

template<class T>
Deck<T>::shuffle(){
    for(int j=0;j<nCards;j++){
        //Random Index Variable
        int random=rand()%nCards;
        //Temporary Swap Variable
        int temp=index[j];
        //Swaps Original Value With Random Index Value
        index[j]=index[random];
        index[random]=temp; 
    }
}

#endif /* DECK_H */

