#include "include.h"

class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> m;
        int maxi = 0;
        int res = 0;
        for(int i = 0; i < nums.size(); i++) {
            m[nums[i]]++;
            maxi = max(maxi, m[nums[i]]);
        }

        for(auto i : m) {
            if(i.second == maxi)
                res += maxi;
        }

        return res;
    }
};