#include <algorithm>
#include <iterator>
#include <vector>

class Solution {
  private:
    template <typename Iterator> void quick_sort(Iterator begin, Iterator end) {
        if (begin == end) {
            return;
        }

        const auto PIVOT = *std::next(begin, std::distance(begin, end) / 2);

        auto first = std::partition(begin, end, [PIVOT](const auto &elem) { return elem < PIVOT; });

        auto second =
            std::partition(first, end, [PIVOT](const auto &elem) { return !(PIVOT < elem); });

        quick_sort(begin, first);
        quick_sort(second, end);
    }

  public:
    std::vector<int> sortArray(std::vector<int> &nums) {
        quick_sort(nums.begin(), nums.end());
        return nums;
    }
};
