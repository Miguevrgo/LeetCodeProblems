#include <string>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if ( x<0 || ( x%10 == 0 && x !=0 )) return false;

        string pile = to_string(x);
        unsigned int length = pile.length();

        for (unsigned int i = 0; i < length / 2; ++i) {
            if (pile[i] != pile[length - i - 1]) {
                return false;
            }
        }
        return true;
    }
};