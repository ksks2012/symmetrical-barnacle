#include "include.h"

class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        int left = 0, right = 10000000;
        while(left < right) {
            // mid -> number of candies to be distributed
            long long mid = (left + right + 1) / 2, count = 0;
            // calculate the number of candies that can be distributed
            for (int i = 0; i < candies.size() && count < k; ++i)
                count += candies[i] / mid;
            // update the left and right pointers
            if (count >= k)
                left = mid;
            else
                right = mid - 1;
        }
        return left;
    }
};