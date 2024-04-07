#include "include.h"

class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        int left = 0, right = 10000000;
        while(left < right) {
            long long mid = (left + right + 1) / 2, cnt = 0;
            for (int i = 0; i < candies.size() && cnt < k; ++i)
                cnt += candies[i] / mid;
            if (cnt >= k)
                left = mid;
            else
                right = mid - 1;
        }
        return left;
    }
};