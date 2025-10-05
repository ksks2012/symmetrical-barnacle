#include "include.h"

class Solution {
public:
    bool divideArray(vector<int>& nums) {
        unordered_map<int, int> mp;
        for (int num : nums) {
            mp[num]++;
        }
        
        for (const auto& [_, count] : mp) {
            if (count % 2 != 0) {
                return false;
            }
        }
        
        return true;
    }
};