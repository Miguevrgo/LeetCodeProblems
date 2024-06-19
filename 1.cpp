#include <bits/stdc++.h>
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> need;
        for (int i = 0; i < nums.size(); ++i) {
            auto it = need.find(nums[i]);
            if (it != need.end()) {
                return {it->second, i};
            }
            need[target - nums[i]] = i;
        }

        return {};
    }
};
