#define FOR(n) for(int i = n-1; i >= 0; --i)
#include <vector>
class Solution{
public:
    string complement(string bi){
        int sum = 0, i, j, complement = 2048;
        vector<int> v(bi.size(), 0);
        string s;
        s.resize(bi.size());
        for(i=bi.size()-1, j = 0; i>=0; --i, ++j)
         {
            v[i] = bi[i] - '0';
            sum += v[i] * pow(2,j);
         }
        complement -= sum;
        i=0;
        while(complement > 0 && i < v.size()){
            v[i] = complement % 2;
            complement /= 2;
            ++i;
        }
        j=0;
        FOR(s.size()){
            s[j] = v[i] + '0';
            ++j;
        }
        return s;
    }
};
