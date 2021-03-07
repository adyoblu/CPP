#include <iostream>
#include <vector>
#define FOR(n) for(int i = 0; i < n; ++i)
#include <string>
using namespace std;

//Conceptele OOP
//OOP este o paradigma de programare pentru a rezolva anumite tipuri de probleme.
//Pentru a da viata unor anumite lucruri din realitatea in care traim sa le putem explica unui calculator.
//Clasele cuprind IDENTITY(numele unic), ATTRIBUTES(campurile), BEHAVIOUR(metodele).



//Abstraction - ascunderea unor elemente care stau in spatele functionalitatii
class Getpromotion{
    //pure virtual function care trebuie definita de orice clasa care o semneaza.
    virtual void canigetapromotion()= 0;
};

class Employee: Getpromotion{
    //Incapsularea presupune ascunderea elementelor clasei prin punerea atributelor clasei private si neacesibile.
protected:
    string Name;
    string Company;
    int Age;
public:
    Employee(string name, string company, int age){
        Name = name;
        Company = company;
        Age = age;
    }
    void setName(string name){
        Name = name;
    }
    string getName(){
        return Name;
    }
    void setCompany(string company){
        Company = company;
    }
    string getCompany(){
        return Company;
    }
    void setAge(int age){
        Age = age;
    }
    int getAge(){
        return Age;
    }
    void introduceyourself(){
        cout<<"My name is "<<Name<<", i have "<<Age<<" and i work to the company called "<<Company<<"."<<endl;
    }

    //implementare pentru metoda virtuala din clasa abstracta
    void canigetapromotion(){
        if(Age > 30)
            cout<<Name<<" got promoted!"<<endl;
        else
            cout<<Name<<", sorry NO promotion for you!"<< endl;
    }

    //Polymorphism -- facand aceasta metoda virtuala cand creem obiecte de tipul Employee
    virtual void work(){
        cout<<Name<<" is writing at the age of "<<Age<<" an article for the company "<<Company<<endl;
    }
};
//Inheritance --- facand clasa Employee public in Developer mosteneste metodele si campurile din Employee.
class Developer : public Employee{
public:
    string FavouriteProgrammingLanguage;
    Developer(string name, string company, int age, string favouriteprogramminglanguage) : Employee(name, company, age){
        FavouriteProgrammingLanguage = favouriteprogramminglanguage;
    }

    void fixBug(){
        cout<<Name<<" is fixing bugs using "<<FavouriteProgrammingLanguage<<endl;
    }
    //Polymorphism
    void work(){
        cout<<Name<<" is writing code at the age of "<<Age<<" and his favourite programming language is "<<FavouriteProgrammingLanguage<<endl;
    }

};

class Writer: public Employee{
    string Subject;
public:
    Writer(string name, string company, int age, string subject):Employee(name, company, age){
        Subject = subject;
    }
    void preparebook(){
        cout<<Name<<" is prepare a book with the subject "<<Subject<<"."<<endl;
    }
    //Polymorphism
    void work(){
        cout<<Name<<" is writing a book now on "<<Subject<<"."<<endl;
    }
};

int main(){

    Employee e("Adrian", "Adobe", 23);
    e.introduceyourself();
    Developer d("Saldina", "Individual", 25, "C++");
    d.introduceyourself();
    d.fixBug();
    Writer w("Jack", "School", 39, "History");
    w.introduceyourself();
    w.preparebook();

    //Abstraction
    e.canigetapromotion();
    d.canigetapromotion();
    w.canigetapromotion();

    //Polymorphism
    Employee *a = &w;
    Employee *b = &d;
    a->work();
    b->work();



    return 0;
}