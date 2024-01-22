#include <vector>
#include <unordered_map>

using namespace std;

int majorityElement(const vector<int>& nums) {
    int majority = nums.size()/2;
    unordered_map<int,int> freq;
    for (auto elem : nums){
        freq[nums[elem]]++;
        if (freq[nums[elem]] > majority) return nums[elem];

    }
    return 0;
}