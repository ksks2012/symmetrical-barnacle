#include "include.h"

class Solution {
public:
    int countDistinctIntegers(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        for (int num : nums) {
            int rev = 0, n = num;
            while (n) {
                rev = rev * 10 + n % 10;
                n /= 10;
            }
            s.insert(rev);
        }
        return s.size();
    }
};