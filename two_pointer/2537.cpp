#include "include.h"

class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> m;

        long long ans = 0;
        long long left = 0;
        int cur = 0;
        for(int i = 0; i < n; i++) {
            k -= m[nums[i]]++;
            while(k <= 0) {
                m[nums[left]]--;
                k += m[nums[left]]; 
                left++;
            }
            ans += left;
        }
        return ans;
    }
};