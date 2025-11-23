#include <print>
#include <vector>

int singleNumber(std::vector<int> &nums) {
    int number{0};
    for (size_t i = 0; i < 8 * sizeof(int); ++i) {
        int count{0};
        for (const auto &elem : nums) {
            count += (elem & (1 << i)) >> i;
        }

        number = (number | (count % 3 << i));
    }

    return number;
}

int main() {
    std::vector<int> example = {2, 2, 3, 2};
    std::println("{}", singleNumber(example));
    return 0;
}
