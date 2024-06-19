#include <bits/stdc++.h>
class Solution {
public:
  int lengthOfLongestSubstring(std::string s) {
    if (s.size() == 1) {return 1;}
    std::unordered_map<char, int> found;
    int maximum_length = 0;
    int start = 0;

    for (int end = 0; end < s.size(); ++end) {
      char elem = s[end];
      if (found.find(elem) != found.end() && found[elem] >= start) {
        start = found[elem] + 1;
      }
      found[elem] = end;
      maximum_length = std::max(maximum_length, end - start + 1);
    }

    return maximum_length;
  }
};

