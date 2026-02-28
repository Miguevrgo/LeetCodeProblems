#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>

class Solution {
  public:
    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string> &strs) {
        std::unordered_map<std::string, std::vector<std::string>> anagrams{};

        for (const auto &str : strs) {
            auto key = str;
            std::ranges::sort(key);
            anagrams[key].emplace_back(str);
        }

        std::vector<std::vector<std::string>> result{};
        result.reserve(anagrams.size());

        for (auto &[key, group] : anagrams) {
            result.emplace_back(std::move(group));
        }

        return result;
    }
};
