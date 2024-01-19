#include "include.h"

class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> m;

        long long ans = 0;
        int left = 0;
        long long cur = 0;
        for(int i = 0; i < nums.size(); i++) {
            cur += nums[i];
            m[nums[i]]++;
            while(m[nums[i]] > 1 || i - left + 1 > k) {
                m[nums[left]]--;
                cur -= nums[left];
                left++;
            }
            if(i - left + 1 == k) {
                cout << i << " " << left << endl;
                ans = max(ans, cur);
            }
        }
        return ans;
    }
};