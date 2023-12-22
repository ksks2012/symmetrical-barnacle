#include "../include.h"

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        long long result = 0;
        int mo = *max_element(nums.begin(), nums.end());

        vector<int> tmp;

        for(int i = 0; i < n; ++i) {
            if(nums[i] == mo) {
                tmp.push_back(i);
            }
        }
        
        if(tmp.size() < k)
            return 0;

        long long tag = 0;
        for(int i = 0; i < tmp.size() - k + 1; ++i) {
            if(i + k - 1 < n)
                result += (tmp[i] - tag + 1) * (n - tmp[i + k - 1]);
            tag = tmp[i] + 1;
        }
        return result;
    }
};

// Lee's Solution
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int a = *max_element(nums.begin(), nums.end()), n = nums.size(), cur = 0, i = 0;
        long long res = 0;
        for (int j = 0; j < n; ++j) {
            cur += nums[j] == a;
            while (cur >= k)
                cur -= nums[i++] == a;
            res += i;
        }
        return res;
    }
};