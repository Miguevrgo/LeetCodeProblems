#include <vector>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int validIndex = 0;
        for (int i = 0;i<nums.size();++i){
            if (nums[i] != val){
                nums[validIndex] = nums[i];
                ++validIndex;
            }
        }
        return validIndex;
    }
};