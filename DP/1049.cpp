#include "include.h"

class Solution {
public:
    int lastStoneWeightII(vector<int> stones) {
        bitset<1501> dp = {1};
        int ans = 0;
        for (int stone : stones) {
            ans += stone;
            for (int i = min(1500, ans); i >= stone; --i)
                dp[i] = dp[i] + dp[i - stone];
        }
        for (int i = ans / 2; i >= 0; --i)
            if (dp[i]) 
                return ans - i - i;
        return 0;
    }
};

class Solution {
public:
    short dp[30][6000] = {};
    int lastStoneWeightII(vector<int>& stones, int s = 0, int i = 0) {
        // cur equals to 0, must add stone[i]
        if (i == stones.size()) 
            return s < 0 ? 100 : s;
        if (dp[i][s + 3000] == 0) 
            dp[i][s + 3000] = 1 + min(lastStoneWeightII(stones, s + stones[i], i + 1),
                lastStoneWeightII(stones, s - stones[i], i + 1));
        return dp[i][s + 3000] - 1;
    }
};

class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        unordered_set<int> s1 = { 0 };
        for (auto i : stones) {
            unordered_set<int> s2;
            for (auto j : s1) 
                s2.insert({ j - i, j + i });
            swap(s1, s2);
        }
        return abs(*min_element(begin(s1), end(s1), [](int i, int j) { return abs(i) < abs(j); }));
    }
};