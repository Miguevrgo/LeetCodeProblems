#include <unordered_map>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    static bool canConstruct(const string& ransomNote, const string& magazine) {
        unordered_map<char, int> mp;
        for (char c : ransomNote) {
            mp[c]++;
        }
        for (char c : magazine) {
            if (mp[c] > 0) {
                mp[c]--;
            }
        }
        return all_of(mp.begin(), mp.end(), [](const auto& pair) {
            return pair.second <= 0;
        });
    }
    //    static inline bool canConstruct(const string& ransomNote, const string& magazine) {
    //        constexpr char offset = 'a';
    //        std::array<int, 'z' -'a' + 1> char_arr{0};
    //        for (int i : magazine) {
    //            ++char_arr[(i-offset)];
    //        }
    //
    //        for (int i : ransomNote) {
    //            if (--char_arr[i-offset] < 0) {
    //                return false;
    //            }
    //        }
    //        return true;
    //    }
};

int main (){
    string magazine = "ab";
    string ransomNote = "aa";

    Solution solution;
    cout << solution.canConstruct(ransomNote,magazine);
}

