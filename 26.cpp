#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int currentPos = 0;
        for (int i = 0;i<nums.size();++i){
            if (nums[i] != nums[currentPos]){
                nums[currentPos] = nums[i];
                ++currentPos;
            }
        }
        return currentPos;
    }
};