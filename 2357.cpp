#include <ranges>
#include <unordered_set>
#include <vector>

class Solution {
  public:
    int minimumOperations(std::vector<int> &nums) {
        const auto UNIQUE_NON_ZEROS =
            nums | std::views::filter([](const auto VAL) { return VAL > 0; }) |
            std::ranges::to<std::unordered_set>();

        return static_cast<int>(UNIQUE_NON_ZEROS.size());
    }
};
