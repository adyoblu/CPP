#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
//3. Make a "slot machine" game that randomly displays the results of a slot machine to a playerâ€”have 3 (or more)
//possible values for each wheel of the slot machine. Don't worry about displaying the text "spinning" by.
//Just choose the results and display them and print out the winnings (choose your own winning combinations).

enum Wheel{banane, struguri, mere, lamuie};

int randRange(int min, int max){
    //int x = rand();
    //cout<< x<<endl;
    return rand() % (max - min) + min ;
}

Wheel Verifica(int x, Wheel c);

void slotMachine(int &sum){
    Wheel c = banane;
    do
    {
        cout << '\n' << "Apasa ENTER pentru a juca la SlotMachine...";
    } while (cin.get() != '\n');
    int x = randRange(1, 4);
    int y = randRange(1, 4);
    int z = randRange(1, 4);
    cout<<x<<" "<<y<<" "<<z<<endl;
    //Optional cu obiectele din enumeratie
    //Wheel a = Verifica(x, c);
    //Wheel b = Verifica(y, c);
    //Wheel d = Verifica(z, c);
    //cout<<a<<" "<<b<<" "<<d<<endl;
    if(x == 4 && y == 4 && z == 4) {sum += 10000; cout<<"Felicitari! Ai castigat la slot machine 10.000$."<<endl<<"Suma ta: "<<sum<<endl;}
    else if( x == 1 && y == 1 && z == 1) {sum += 500; cout<<"Ai castigat 500$."<<endl<<"Suma ta: "<<sum<<endl;}
    else if( x == 2 && y == 2 && z == 2) {sum += 1000; cout<<"Ai castigat 1000$."<<endl<<"Suma ta: "<<sum<<endl;}
    else if( x == 3 && y == 3 && z == 3) {sum += 3000; cout<<"Ai castigat 3000$."<<endl<<"Suma ta: "<<sum<<endl;}
    else {sum -=50; cout<<"Mai incearca!"<<endl<<"Suma ta: "<<sum<<endl; }
}

int main(){
    // The time() FUNCTION returns the time from 1 january 1970 in seconds. In 2038 that integer will overflow the 32 bits and will start from 0.
    int seed = time(NULL);
    int sum = 300;
    cout<<"The time seed from 1 jan 1970: "<< seed<< endl;
    srand(seed);
    cout<<"Incepi cu suma de "<<sum<<"$ si pierzi 50$ la fiecare incercare."<<endl;
    while(sum > 0){
        slotMachine(sum);
    }
    return 0;
}

Wheel Verifica(int x, Wheel c){
    switch(x){
        case 1: c = banane; return c;
        case 2: c = struguri; return c;
        case 3: c = mere; return c;
        case 4: c = lamuie; return c;
    }
}
