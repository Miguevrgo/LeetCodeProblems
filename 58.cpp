#include "includeDir.h"


class Solution {
public:
    int lengthOfLastWord(string s) {
        int length = 0;
        int pos = s.size() -1;
        while (isspace(s[pos])){
            pos--;
        }
        while (pos >= 0 && !isspace(s[pos])){
            length++;
            pos--;
        }
        return length;
    }
};