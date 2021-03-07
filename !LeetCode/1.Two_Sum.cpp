#include <iostream>
#include <vector>
#define FOR(n) for(int i = 0; i < n; ++i)
#include <string>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> x(2);
         for(uint32_t i = 0; i < nums.size(); ++i){
            for(uint32_t j = 0; j < nums.size(); ++j){
                if(nums[i] + nums[j] == target) {x[1] = i; x[0] = j; break;}
            }
        }
        return x;
    }
};

int main(){
    int target;
    vector<int> nums(4), rez(2);
    Solution a;
    for(auto i = nums.begin(); i != nums.end(); ++i){
        cin>>*i;
    }
    cout<<"Target: ";
    cin>>target;
    rez = a.twoSum(nums, target);
    FOR(2){
    cout<<rez[i];
    }
    return 0;
}