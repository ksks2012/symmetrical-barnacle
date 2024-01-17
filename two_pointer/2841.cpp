#include "include.h"

class Solution {
public:
    long long maxSum(vector<int>& nums, int m, int k) {
        long long maxi = 0;
        long long cur  = 0;
        int n = nums.size();

        unordered_map<int, int> tmp;
        int unique = 0;
        int left = 0;
        for(int i = 0; i < n; i++) {
            tmp[nums[i]]++;
            cur += nums[i];
            if(tmp[nums[i]] == 1) {
                unique++;
            }
            while(i - left + 1 > k) {
                tmp[nums[left]]--;
                cur -= nums[left];
                if(tmp[nums[left]] == 0) {
                    unique--;
                }
                left++;
            }
            if(unique > m) {
                maxi = max(maxi, cur);
            }
        }
        return maxi;
    }
};