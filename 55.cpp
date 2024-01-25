#include <vector>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int size = nums.size();
        int canJump = size - 1;
        if (size == 0){ return false;}
        for (int i = size -2; i>=0;--i){
            if (canJump - i <= canJump){
                canJump = i;
            }
        }
        return canJump == 0;
    }
};