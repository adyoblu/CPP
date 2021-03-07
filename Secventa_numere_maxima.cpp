#include <iostream>
#include <limits>
using namespace std;
//secventa de suma maxima complexitate O(n)
int main()
{
    int n;
    int a[100];
    int scrt = 0;
    int sum = INT_MIN;
    cout<<"n=";
    cin>>n;
    for(int i = 0; i <=n-1; i++){
        cout<<"a["<<i<<"]=";
        cin>>a[i];
    }
    for(int i = 0; i <= n-1; i++)
    {
        if(scrt < 0)
            {scrt = a[i];}
        else
            { scrt += a[i];}
        if(scrt > sum) sum = scrt;
    }
//secventa de suma maxima complexitate O(n^2)
    int smax = a[0];
    int scr;
    for(int i=0;i<=n-1;i++)
    {
        scr = 0;
        for(int j = i;j<= n-1;j++)
        {
            scr += a[j];
            if(smax <= scr) smax = scr;
        }
    }
    cout<<"Secventa suma maxima complexitate o(n) este : "<<sum<<endl;
    cout<<"Secventa suma maxima complexitate o(n^2) este : "<<smax;
    return 0;
}
