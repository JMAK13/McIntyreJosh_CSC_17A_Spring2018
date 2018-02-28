/* Author: Josh McIntyre
 * Purpose: CSC17A 2/21/18 Lab, converting bases by hand 
 * Date: 2/21/18 1:38PM
 */

//System Libraries
#include <iostream>
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes

//Main Function
int main(int argc, char** argv) {
    
    int binary1=0b101010111100,octal1=05274,hex1=0xABC,dec1=2748;
    cout<<"Binary  = "<<binary1<<endl;
    cout<<"Octal   = "<<octal1<<endl;
    cout<<"Hex     = "<<hex1<<endl;
    cout<<"Decimal = "<<dec1<<endl;
    
    cout<<endl;
    
    int binary2=0b11001111000,octal2=03170,hex2=0x678,dec2=1656;
    cout<<"Binary  = "<<binary2<<endl;
    cout<<"Octal   = "<<octal2<<endl;
    cout<<"Hex     = "<<hex2<<endl;
    cout<<"Decimal = "<<dec2<<endl;
    
    cout<<endl;
    
    int binary3=0b1010100110,octal3=01246,hex3=0x2A6,dec3=678;
    cout<<"Binary  = "<<binary3<<endl;
    cout<<"Octal   = "<<octal3<<endl;
    cout<<"Hex     = "<<hex3<<endl;
    cout<<"Decimal = "<<dec3<<endl;
    
    cout<<endl;
    
    int binary4=0b10010,octal4=022,hex4=0x12,dec4=18;
    cout<<"Binary  = "<<binary4<<endl;
    cout<<"Octal   = "<<octal4<<endl;
    cout<<"Hex     = "<<hex4<<endl;
    cout<<"Decimal = "<<dec4<<endl;

    //Exits Program
    return 0;
}

