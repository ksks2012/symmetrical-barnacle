#include "include.h"

class Solution {
public:
    int minElements(vector<int>& nums, int limit, int goal) {
        long long sum = 0;
        for (int num : nums) {
            sum += num;
        }
        long long diff = abs(goal - sum);
        return (diff + limit - 1) / limit;
    }
};

// Vlad
class Solution {
public:
    int minElements(vector<int>& nums, int limit, int goal) {
        return ((abs(accumulate(begin(nums), end(nums), 0l) - goal) + limit - 1) / limit);
    }
};
