#include <iostream>
#include <string>
#include <cstdlib>
#include <cstring>
#include <cstdio>
using namespace std;

/*
1. Write a program that lets the user fill in a single structure with the name, address,
and phone number of a single person
3. Create an address book program that builds on problem #1—this time, the user should be able to not just fill out
 a single structure, but should be able to add new entries, each with a separate name and phone number.
 Let the user add as many entries as he or she wants—is this easy to do? It is even possible?
 Add the ability to display all, or some of the entries, letting the user browse the list of entries.
*/
#define n 1000

struct Contact{
    char name[20];
    char adress[30];
    char phone_number[20];
};

int CountNo(char *nr);

Contact Citire(){
    Contact c;
    bool check = false;
    cout<<"Enter the name: ";
    cin>>c.name;
    cout<<"Enter the e-mail address: ";
    cin>>c.adress;

    char d[11] = "@yahoo.com";
    while (check == false){
        string x = c.adress;
        size_t found = x.find(d);
        if(found != string::npos){
            check = true;
            cout<<"Email accepted" <<endl;
        }
        else
        {
            cin.clear();
            cin.ignore(256,'\n');
            cout<<"Email rejected. It must be like *******@yahoo.com" <<endl;
            cout<<"Enter the e-mail address: ";
            cin>>c.adress;
        }
    }
    check = false;
    int k;
    cout<<"Enter your phone number: ";
    cin>>c.phone_number;
    while(check == false){
        k = CountNo(c.phone_number);
        if(k == 10){
            cout<<"Number accepted\n";
            check = true;
        }
        else
        {
            cin.clear();
            cin.ignore(256,'\n');
            cout<<"Number rejected"<<endl;
            cout<<"Enter your phone number: ";
            cin>>c.phone_number;
        }
    }
    return c;
}

int CountNo(char *nr){
    int y = 0;
    for(unsigned int i = 0; i <= strlen(nr); i++){
        if(nr[i] >= '0' && nr[i] <= '9') y++;
    }
    return y;
}
int main(){
    Contact c[n];
    char ch;
    cout<<"Complete this form\n";
    for(int i = 0; i < n; i++){
        c[i] = Citire();
        cout<<"Do you want to add another contact?\n"<<"Y/n\n";
        cin>>ch;
        if(ch == 'y' || ch == 'Y') continue;
        else{
            int j = i;
            while(j >= 0)
            {
                cout<<"These are your contacts: \n";
                cout<<"{"<<c[j].name<<", "<<c[j].adress<<", "<<c[j].phone_number<<"}"<<endl;
                j--;
            }
            return 0;
        }
    }
    return 0;
}
