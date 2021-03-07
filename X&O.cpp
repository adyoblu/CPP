#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
/*
4. Write a small tic-tac-toe program that allows two players to play tic-tac-toe competitively.
Your program should check to see if either player has won, or if the board is filled completely
(with the game ending in a tie).
Bonus: can you make your program detect if the game cannot be won by either side before the entire grid is filled?
5. Make your tic-tac-toe game into a version of connect-4 that allow boards bigger than 3 by 3 but requires 4-in-a-row to win.
Allow the players to specify the size of the board while the program is running.
(Hint: right now, you have to define your board to be a fixed size at compile time, so you may need to limit
 the maximum size of the board.)
*/
using namespace std;
bool Used(char **a, int row, int column);
void populare(char **a, int length){

    for(int i = 0; i < length; i++)
    {
        for(int j = 0; j < length; j++)
        {
            a[i][j] = '-';
        }
    }
}
void afisareBoard(char **a, int length){
    if(length == 3)
    cout << "    " << 0 << "  " << 1 << "  " << 2 << "\n";
    else
    cout << "    " << 0 << "  " << 1 << "  " << 2 <<"  "<< 3 << "\n";
    for(int i = 0; i < length; i++)
    {
        cout<<"r"<<i<<" ";
        for(int j = 0; j < length; j++)
        {
            cout<<" "<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}

void citire(unsigned char &row, unsigned char &column, int length){
    bool check = true;
    while(check == true){
        cout<<"row(0, 1, 2): ";
        cin>>row;
        cout<<"column(0, 1, 2): ";
        cin>>column;
        row = row - '0';
        column = column - '0';
        if (length == 3 && row >= 0 && row <= 2 && column >= 0 && column <= 2) check = false;
            else if (length == 4 && row >= 0 && row <= 3 && column >= 0 && column <= 3) check = false;
            else {cout << "Invalid inputs. Retry!\n";}
    }
}

void Turn(char **a, char player, int n){
    bool check = true;
    unsigned char row = '0', column = '0';
    cout <<"\n"<< player << ": Jucati !. \n";

    while(check == true){
        citire(row, column, n);
        if(!Used(a, row, column)){
            check = false;
        }
        else{
            cout<<"Pozitie deja folosita. Incearca din nou. \n";
        }
    }
    a[row][column] = player;
    cout<<"\n\n";
}

bool Used(char **a, int row, int column){
    if(a[row][column] == '-')
        return false;
    else
        return true;
}

bool Win(char **a, char player, int length){
    for(int i = 0; i < length; i++){
            for(int j = 0; j  < length; j++){
                if(length == 3){
                    //randuri
                    if(a[i][0] == player && a[i][1] == player && a[i][2] == player){
                        return true;
                    }
                    //coloane
                    if(a[0][j] == player && a[1][j] == player && a[2][j] == player){
                        return true;
                    }
                }
                    if(length == 4){
                    //randuri
                    if(a[i][0] == player && a[i][1] == player && a[i][2] == player && a[i][3] == player){
                        return true;
                    }
                    //coloane
                    if(a[0][j] == player && a[1][j] == player && a[2][j] == player && a[3][j] == player){
                        return true;
                    }
                    }
            }
    }
    if(length == 3){
    //diagonala principala
    if(a[0][0] == player && a[1][1] == player && a[2][2] == player){
                    return true;
                }
    //diagonala secundara
    if(a[0][2] == player && a[1][1] == player && a[2][0] == player){
        return true;
    }
    }else if(length == 4)
    {
        //diagonala principala
        if(a[0][0] == player && a[1][1] == player && a[2][2] == player && a[3][3] == player){
                return true;
        }
        //diagonala secundara
        if(a[3][0] == player && a[2][1] == player && a[1][2] == player && a[0][3] == player){
                return true;
        }
    }
    return false;
}

int VerificareFinal(char **a, char player, int length){
        int s = 0;
        for(int i = 0; i < length; i++)
        {
            for(int j = 0; j < length; j++)
            {
                if(a[i][j] != '-') s++;
                if(length == 3 && s >= 7 && Win(a, player, length) == false) {afisareBoard(a, length); cout<<"\n\nJocul s-a sfarsit! Egalitate intre jucatori :D\n"; return 0;}
                if(length == 4 && s >= 10 && Win(a, player, length) == false) {afisareBoard(a, length); cout<<"\n\nJocul s-a sfarsit! Egalitate intre jucatori :D\n"; return 0;}
            }
        }
        return 1;
}

int alegereBoard(){
    int n;
    cout<<"Meniu"<<endl<<"1 pentru 3x3"<<endl<<"2 pentru 4x4"<<endl;
    cin>>n;
    while(cin.fail()) {
        cout<<"Introdu o optiune valida 1 sau 2: ";
        cin.clear();
        cin.ignore(256,'\n');
        cin >> n;
    }
    switch(n){
        case 1: return 3;
        case 2: return 4;
        default : cout<<"\nO optiune valida dintre 1 si 2\n\n"; alegereBoard();
    }
}

int main(){
    int n = alegereBoard();
    system("CLS");
    char **a = new char*[n];
    for(int i = 0; i < n; i++)
        a[i] = new char[n];
    populare(a, n);
    while(1){
        afisareBoard(a, n);
        Turn(a, 'X', n);
        if(Win(a, 'X', n)){
            system("CLS");
            afisareBoard(a, n);
            cout<< "\n X este castigator. Are o bere! \n";
            break;
        }
        system("CLS");
        afisareBoard(a, n);
        if(VerificareFinal(a, 'X', n) == 0) return 0;
        Turn(a,'O', n);
        if(Win(a, 'O', n)){
            system("CLS");
            afisareBoard(a, n);
            cout<< "\n 0 este castigator. Are o bere! \n";
            break;
        }
        system("CLS");
        if(VerificareFinal(a, 'O', n) == 0) return 0;
    }
    for (int i = 0; i < n; i++)
    delete [] a[i];
        delete [] a;
    return 0;
}