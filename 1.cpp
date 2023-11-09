#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

// Descomentar para la solución eficiente
// #define EFFICIENCY 

#ifndef EFFICIENCY
/**
 * @brief Resuelve el problema con eficiencia O(n²) que no es lo mejor, sin embargo dado mi conocimiento actual, la implementacion
 * con el arbol es desconocida
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> used;
        for (auto it = nums.begin(); it != nums.end(); ++it) {
            int current = *it;
            int dist = target - current;

            auto pos = find(used.begin(), used.end(), dist);
            if (pos != used.end()) {
                vector<int> solution;
                solution.push_back(distance(nums.begin(), it));
                solution.push_back(distance(used.begin(), pos));
                return solution;
            }
            used.push_back(current);
        }
        return vector<int>();
    }
};

#endif
#ifdef EFFICIENCY

/**
 * @brief Esta es la implementacion O(n)
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> numToIndex;
        for (int i = 0; i < nums.size(); ++i) {
            int complement = target - nums[i];
            if (numToIndex.find(complement) != numToIndex.end()) {
                return {numToIndex[complement], i};
            }
            numToIndex[nums[i]] = i;
        }
        return {}; // En caso de no encontrar la suma deseada.
    }
};

#endif