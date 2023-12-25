#include <cmath>

class Solution {
public:
    int uniquePaths(int m, int n) {
        int k = m-1;
        int t = (k) + (n-1);
        if ((k) > t) return 0;
        if ((k) == 0 || t == (k)) return 1;
        double result = 0;
        for (int i = 0; i < (k); ++i) {
            result += log(t-i) - log(i+1);
        }
        return (int)round(exp(result));
    }
};