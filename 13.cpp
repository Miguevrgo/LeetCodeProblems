#include <string>
using namespace std;

class Solution {
public:
    const enum RomanSymbol {
        I = 1,
        V = 5,
        X = 10,
        L = 50,
        C = 100,
        D = 500,
        M = 1000
    };
    
    int romanToInt(string s) {
        int result = 0;
        int prevValue = 0;
        
        for (int i = s.length() - 1; i >= 0; i--) {
            int currentVal = 0;
            switch (s[i]) {
                case 'I':
                    currentVal = I;
                    break;
                case 'V':
                    currentVal = V;
                    break;
                case 'X':
                    currentVal = X;
                    break;
                case 'L':
                    currentVal = L;
                    break;
                case 'C':
                    currentVal = C;
                    break;
                case 'D':
                    currentVal = D;
                    break;
                case 'M':
                    currentVal = M;
                    break;
            }
            
            if (currentVal < prevValue) {
                result -= currentVal;
            } else {
                result += currentVal;
            }
            
            prevValue = currentVal;
        }
        
        return result;
    }
};
