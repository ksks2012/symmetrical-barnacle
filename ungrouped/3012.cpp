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

// lee
class Solution {
public:
    int minimumArrayLength(vector<int>& nums) {
        int v = *min_element(nums.begin(), nums.end());
        for (int x : nums)
            if (x % v > 0)
                return 1;
        int tmp = count(nums.begin(), nums.end(), v);
        return (tmp + 1) / 2;
    }
};