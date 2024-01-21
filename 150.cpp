#include <vector>
using namespace std;

int removeDuplicates(vector<int>& nums) {
    int currentPos = 1;
    if(nums.size() <=2){
        return nums.size();
    }

    for (auto it = nums.begin()+2; it != nums.end(); ++it){
         if (*it != nums[currentPos-1]){
             nums[++currentPos] = *it;
         }
    }
    return ++currentPos;
}
