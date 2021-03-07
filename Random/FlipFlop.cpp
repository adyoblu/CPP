#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
//1. Write a program that simulates a coin flip. Run it many timesâ€”do the results look random to you?
// Flip coin

int randRange(int min, int max){
    //int x = rand();
    //cout<< x<<endl;
    return rand() % (max - min) + min ;
}

int main(){
    int seed = time(NULL);
    cout<< seed<< endl;
    srand(seed);
    int x = randRange(1,3);
    cout<<x<<endl;
    switch(x)
    {
        case 1: cout<<"Ai dat cu banul si a iesit ban!"; break;
        case 2: cout<<"Ai dat cu banul si a iesit pajura!"; break;
    }

    return 0;
}
