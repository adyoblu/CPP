#include <iostream>
#include <vector>
#define FOR(n) for(int i = 0; i < n; ++i)
#include <cstring>
using namespace std;

bool isVowel(char ch) {
    if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u')
         return true;
//    else
        return false;
}

int main() {
    char s[101];
    bool ok = false;
    vector<int> a, b;
    int t;
    unsigned int strl=0, sizz = 0;
    cin>>t;

    while(t--){
        cin>>s;
        if(strlen(s) <= 3) {
            printf("1\n");
            goto stop;
        //            continue;
        }
        ok = false;
        a.clear();
        b.clear();
        strl = strlen(s);
        for(unsigned int i = 0;  i < strl; ++i){
            if(isVowel(s[i]) == true || s[i] == '?') a.push_back(i); // vocale in a
            if(isVowel(s[i]) == false || s[i] == '?') b.push_back(i); // consoane in b
        }

        sizz = a.size();
        for(unsigned int i = 0; i < sizz; i++){
            //cout<<"a[i]="<<a[i]<<" ";
            if(a[i]+1 == a[i+1] && a[i]+2 == a[i+2] && a[i]+3 == a[i+3] && a[i]+4 == a[i+4] && a[i]+5 == a[i+5])
                {printf("0\n"); ok = true; break;}
        }
        if(ok == true)  goto stop;

        sizz = b.size();
        for(unsigned int i = 0; i < sizz; i++){
            //cout<<"b["<<i<<"]="<<b[i]<<" ";
            if(b[i]+1 == b[i+1] && b[i]+2 == b[i+2] && b[i]+3 == b[i+3])
                {printf("0\n"); ok = true; break;}
        }

        if(ok == false)  printf("1\n");

        stop: continue;
    }
	return 0;
}