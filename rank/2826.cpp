#include "../include.h"

// endlesscheng
// Time Complexity: O(nlogn)
// Space Complexity: O(n)
class Solution {
public:
    int minimumOperations(vector<int> &nums) {
        vector<int> tmp;
        for (int x : nums) {
            auto it = upper_bound(tmp.begin(), tmp.end(), x);
            if (it == tmp.end()) 
                tmp.push_back(x);
            else *it = x;
        }
        return nums.size() - tmp.size();
    }
};