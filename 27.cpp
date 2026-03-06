#include <vector>
using namespace std;

class Solution {
  public:
    int removeElement(vector<int> &nums, int val) {
        size_t valid_index = 0;
        for (size_t i = 0; i < nums.size(); ++i) {
            if (nums[i] != val) {
                nums[valid_index] = nums[i];
                ++valid_index;
            }
        }
        return static_cast<int>(valid_index);
    }
};
