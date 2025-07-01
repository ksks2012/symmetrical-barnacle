#include "../include.h"

class Solution {
public:
    int findMaxK(vector<int>& nums) {
        int res = -1;
        unordered_set<int> seen;
        for (int num : nums) {
            if (seen.count(-num)) {
                res = max(-num, max(res, num));
            }
            seen.insert(num);
        }
        return res;
    }
};