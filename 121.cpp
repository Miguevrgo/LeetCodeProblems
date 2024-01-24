#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = prices[0];
        int maxProf = 0;

        for(int i=1;i<prices.size();++i){
            maxProf = max(maxProf,prices[i]-minPrice);
            minPrice = min(prices[i],minPrice);
        }

        return maxProf;
    }
};

int main (){
    vector<int> test = {2,10,1,3,6,4};
    Solution solution;
    cout << solution.maxProfit(test);

    return 0;
}

