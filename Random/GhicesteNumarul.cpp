#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
//2. Write a program that picks a number between 1 and 100, and then lets the user guess what the number is.
//The program should tell the user if their guess is too high, too low, or just right.

int randRange(int min, int max){
    //int x = rand();
    //cout<< x<<endl;
    return rand() % (max - min) + min ;
}

void Limitless(int x){
    int n;
    cout<<"Hint: "<<x<<endl<< "Am generat un numar intre 1 si 100. Ai incercari nelimitate pentru a-l ghici!"<<endl;
    while(1){
        cout<<"Introdu un numar:";
        cin>>n;
        if( n < x ) cout<< "Numarul generat > numarul introdus"<<endl;
        else if( n > x ) cout<< "Numarul generat < numarul introdus"<<endl;
        else if ( n == x) {cout<< "Felicitari !!! Ai ghicit numarul :D"<<endl; break;}
    }
}

void ThreeAttempts(int x){
    int n, j = 3;
    cout<<"Hint: "<<x<<endl<< "Am generat un numar intre 1 si 100. Ai 3 incercari pentru a-l ghici!"<<endl;
    while(j--){
        cout<<"Introdu un numar:";
        cin>>n;
        if( n < x ) cout<< "Numarul generat > numarul introdus"<<endl;
        else if( n > x ) cout<< "Numarul generat < numarul introdus"<<endl;
        else if ( n == x) {cout<< "Felicitari !!! Ai ghicit numarul :D"<<endl; break;}
    }
}
int main(){
    // The time() FUNCTION returns the time from 1 january 1970 in seconds. In 2038 that integer will overflow the 32 bits and will start from 0.
    int seed = time(NULL);
    cout<<"The time seed from 1 jan 1970: "<< seed<< endl;
    srand(seed);
    int x = randRange(1,100);
    cout<<"Alegeti una dintre cele 2 optiuni: "<<endl;
    cout<<"1.Numar de 3 incercari"<<endl<<"2.Numar nelimitat de incercari"<<endl;
    int c;
    cin>>c;
    cout<<"---------------------------------------------------------------------"<<endl;
    switch(c){
        case 1: ThreeAttempts(x); break;
        case 2: Limitless(x); break;
    }
    return 0;
}
