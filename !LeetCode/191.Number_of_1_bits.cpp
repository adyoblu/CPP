/*!LeetCode Number of 1 Bits */

#include <iostream>
#include <vector>
#define FOR(n) for(int i = 0; i < n; ++i)

using namespace std;

class Solution {
public:
    vector<int> decToBinary(uint32_t n)
    {
    vector<int> binaryNum(32, 0);
    int i = 0;
    while (n > 0) {
        binaryNum[i] = n % 2;
        n /= 2;
        i++;
    }
    vector<int> binaryRev(32);
    int k = 0;

    for (int j = i - 1; j >= 0; j--)
        {binaryRev[k] = binaryNum[j];
         k++;}
        return binaryRev;
    }

    void hammingWeight(uint32_t n) {
        uint32_t sum = 0;
        vector <int> a(32);
        fill_n(a.begin(), 32, 0);
        a = decToBinary(n);
        FOR(32){
            sum += a[i];
        }
        cout<<sum;
    }
};

int main(){
    unsigned long n;
    Solution a;
    cin>>n;
    a.hammingWeight(n-2);
    return 0;
}