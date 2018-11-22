/* 
 * File:   main.cpp
 * Author: Josh McIntyre
 * Created on May 21, 2018, 11:30 PM
 */

#include <cstdlib>
#include <iostream>
using namespace std;

class Student {
    private:
        int scores[5];
        int total;
    public:
        void input() {
            for(int i=0; i<5; i++) {
                do {
                    cin>>scores[i];
                } while(scores[i]<0||scores[i]>50);
            }
        }
    
        int calculateTotalScore() {
            for(int i=0; i<5; i++) {
                if(scores[i]>=0&&scores[i]<=50) total+=scores[i];
            }
            return total;
        }
};

int main(int argc, char** argv) {
    
    cout<<"See HackerRank for main() function, the text cannot be copied.\n"

    return 0;
}

