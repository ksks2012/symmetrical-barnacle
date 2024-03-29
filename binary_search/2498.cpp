#include "include.h"

class Solution {
public:
    int maxJump(vector<int>& stones) {
        int res = stones[1] - stones[0]; // store max difference
        for(int i = 3; i < stones.size(); i+=2) 
            res = max(res, stones[i] - stones[i - 2]); // odd path
        for(int i = 2; i < stones.size(); i+=2) 
            res = max(res, stones[i] - stones[i - 2]); // even path
        return res;
    }
};

// lee
class Solution {
public:
    int maxJump(vector<int>& stones) {
        int res = stones[1] - stones[0], n = stones.size();
        for (int i = 2; i < n; ++i)
            res = max(res, stones[i] - stones[i - 2]);
        return res;
    }
};

