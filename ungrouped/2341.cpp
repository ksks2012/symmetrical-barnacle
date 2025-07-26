#include "include.h"

class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        unordered_map<int, int> mp;
        for (int num : nums) {
            mp[num]++;
        }

        int pairs = 0;
        int leftovers = 0;

        for (const auto& entry : mp) {
            pairs += entry.second / 2;
            leftovers += entry.second % 2;
        }

        return {pairs, leftovers};
    }
};