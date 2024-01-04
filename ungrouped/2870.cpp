#include "../include.h"

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int res = 0;
        unordered_map<int, int> m;

        for(auto n : nums) {
            m[n]++;
        }

        for(auto &tmp : m) {
            if(tmp.second == 1)
                return -1;
            res += tmp.second / 3;
            if(tmp.second % 3 > 0)
                res++;
        }

        return res;
    }
};