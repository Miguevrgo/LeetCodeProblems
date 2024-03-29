#include <limits>

class Solution {                      
public:
    int reverse(int x) {
        int reverse = 0;
        
        while(x) {
            if (reverse > numeric_limits<int>::max() / 10 || reverse < numeric_limits<int>::min() / 10) {
                return 0;
            }

            reverse = reverse*10+x%10;
            x /= 10;
        } 
        return reverse;
    }
}; 