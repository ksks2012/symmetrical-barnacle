#include "include.h"

// votrubac
class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& divs) {
        sort(begin(nums), end(nums));
        int div = reduce(begin(divs), end(divs), divs[0], [](int a, int b) { 
            return gcd(a, b); 
        });
        for (int i = 0; i < nums.size(); ++i)
            if (div % nums[i] == 0)
                return i;
        return -1;
    }
};

// without sorting
class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& divs) {
        int div = reduce(begin(divs), end(divs), divs[0], [](int a, int b) { 
            return gcd(a, b); 
        });
        int mini = INT_MAX;
        for (int n : nums)
            mini = min(mini, div % n == 0 ? n : INT_MAX);
        return mini == INT_MAX ? -1 : count_if(begin(nums), end(nums), [&](int n) { 
            return n < mini; 
        });
    }
};