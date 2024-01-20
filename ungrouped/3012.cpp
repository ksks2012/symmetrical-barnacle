#include "include.h"

class Solution {
public:
    int minimumArrayLength(vector<int>& nums) {
        int com = 0;
        for(int x: nums)
            com = gcd(com, x);
        int ans = 0;
        for(int x: nums)
            ans += x == com;
        ans = (max(ans, 1) + 1) / 2;
        return ans;
    }
};
