#include <algorithm>
#include <vector>

class Solution {
  public:
    int maximumUnits(std::vector<std::vector<int>> &boxTypes, int truckSize) {
        std::ranges::sort(boxTypes, std::greater{},
                          [](const auto &elem) { return elem[1]; });

        int amount{0};
        for (const auto &elem : boxTypes) {
            amount += elem[1] * std::min(elem[0], truckSize);
            truckSize -= elem[0];
            if (truckSize <= 0) {
                break;
            }
        }

        return amount;
    }
};
