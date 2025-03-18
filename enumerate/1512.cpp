#include "include.h"

class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int res = 0;
        unordered_map<int, int> cnt;
        for (int x : nums) {
            res += cnt[x];
            cnt[x]++;
        }
        return res;        
    }
};