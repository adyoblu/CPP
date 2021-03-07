#include <iostream>
#include <cstdlib>
#include <ctime>

//1. Write code for insertionSort that works for any sized array.
//2. Write a program that takes in 50 values and prints out the highest, the lowest,
//the average and then all 50 input values, one per line.
//3. Write a program that detects if a list is sorted or not, and if it is not sorted, sort it.

using namespace std;

int findSmallestNo(int a[], int length, int index);

void swapNo(int a[], int No1, int No2);

void sortare(int *a, int length);

void afisare(int *a, int length){
    cout<<"{";
    for(int i = 0; i < length; i++)
    {
        if(i != 0) cout<<", ";
        cout<<a[i];
    }
    cout<<"}";
}

void swapNo(int *a, int i1, int i2){
    int temp = a[i1];
    a[i1] = a[i2];
    a[i2] = temp;
}

int findSmallestNo(int *a, int length, int index){
    int index_smallest = index;
    for(int i = index + 1; i < length; i++){
        if (a[index_smallest] > a[i])
        {
            index_smallest = i;
        }
    }
    return index_smallest;
}

void sortare(int *a, int length){
    for(int i = 0; i < length; i++){
        int x = findSmallestNo(a, length, i);
        swapNo(a, i, x);
    }
}

void printHSA(int *a, int length){
    cout<<"The highest value: "<<*(a+length-1)<<endl;
    cout<<"The lowest value: "<<*a<<endl;
    //int x = floor(length/2);
    double sum = 0;
    for(int i = 0; i < length; i++){
            sum += a[i];
    }
    cout<<"The average: "<<double(sum/length)<<endl;
    for(int i = 0; i < length; i++){
            cout<<a[i]<<endl;
    }
}

void IsSorted(int *a, int length){
    for(int i = 0; i < length; i++){
        if(i == findSmallestNo(a, length, i)) continue;
        else {sortare(a, length); afisare(a, length);}
    }
}
int main(){
    srand(time(NULL));
    int *a, n;
    a = new int[n];
    cout<<"Introduceti lungimea: ";
    cin>>n;
    //afisare(a, n);
    for(int i = 0; i < n; i++){
        a[i] = rand() % 100;
    }
    afisare(a, n);
    cout<<endl;
    IsSorted(a, n);
    //sortare(a, n);
    printHSA(a, n);
    return 0;
}
