#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
    //        int num = nums.size();
    //        k %= num;
    //        stack<int> aux;
    //        for (int i = num-1; i>=num-k; --i){
    //            aux.emplace(nums[i]);
    //        }
    //        for (int i = num-1; i >= k; --i){
    //            nums[i] = nums[i-k];
    //        }
    //        for (int i = 0;i<k;++i){
    //            nums[i] = aux.top();
    //            aux.pop();
    //        }
    int n = nums.size();
    k %= n;
    reverse(nums.begin(),nums.begin()+(n-k));
    reverse(nums.begin()+(n-k),nums.end());
    reverse(nums.begin(),nums.end());
    }
};