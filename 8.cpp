#include <limits>
#include <string_view>

class Solution {
  public:
    int myAtoi(std::string_view s) {
        if (s.empty()) {
            return 0;
        }

        std::size_t pos{0};
        const std::size_t LENGTH{s.length()};

        while (pos < LENGTH && s[pos] == ' ') {
            ++pos;
        }

        if (pos == LENGTH) {
            return 0;
        }

        int sign{1};
        if (s[pos] == '+') {
            ++pos;
        } else if (s[pos] == '-') {
            sign = -1;
            ++pos;
        }

        long result{0};
        constexpr long INT_MIN_VAL{std::numeric_limits<int>::min()};
        constexpr long INT_MAX_VAL{std::numeric_limits<int>::max()};

        while (pos < LENGTH && std::isdigit(s[pos])) {
            result = (result * 10) + (s[pos] - '0');

            if (sign == 1 && result > INT_MAX_VAL) {
                return static_cast<int>(INT_MAX_VAL);
            }
            if (sign == -1 && -result < INT_MIN_VAL) {
                return static_cast<int>(INT_MIN_VAL);
            }
            ++pos;
        }

        return static_cast<int>(result * sign);
    }
};
