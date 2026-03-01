#include <vector>

class Solution {
  public:
    long long subArrayRanges(std::vector<int> &nums) {
        long long result{0};

        std::vector<size_t> stack;
        stack.reserve(nums.size());

        for (size_t i = 0; i <= nums.size(); ++i) {
            while (!stack.empty() && (i == nums.size() || nums[stack.back()] >= nums[i])) {
                const auto MID = stack.back();
                stack.pop_back();

                const auto LEFT_B = stack.empty() ? -1LL : static_cast<long long>(stack.back());
                const auto RIGHT_B = static_cast<long long>(i);
                const auto MID_POS = static_cast<long long>(MID);

                const auto CONTRIB = (MID_POS - LEFT_B) * (RIGHT_B - MID_POS);
                result -= static_cast<long long>(nums[MID]) * static_cast<long long>(CONTRIB);
            }

            if (i < nums.size()) {
                stack.emplace_back(i);
            }
        }

        stack.clear();

        for (size_t i = 0; i <= nums.size(); ++i) {
            while (!stack.empty() && (i == nums.size() || nums[stack.back()] <= nums[i])) {
                const auto MID = stack.back();
                stack.pop_back();

                const auto LEFT_B = stack.empty() ? -1LL : static_cast<long long>(stack.back());
                const auto RIGHT_B = static_cast<long long>(i);
                const auto MID_POS = static_cast<long long>(MID);

                const auto CONTRIB = (MID_POS - LEFT_B) * (RIGHT_B - MID_POS);
                result += static_cast<long long>(nums[MID]) * static_cast<long long>(CONTRIB);
            }

            if (i < nums.size()) {
                stack.emplace_back(i);
            }
        }

        return result;
    }
};
