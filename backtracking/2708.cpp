#include "include.h"

class Solution {
public:
    long long maxStrength(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        long long ans = 1;
        int count = 0;

        int n = nums.size();
        if(nums[0] == 0 && nums[n - 1] == 0) {
            return 0;
        }

        // bool neg = true; 
        int i = 0;
        for(i = 0; i < nums.size(); i++) {
            if (nums[i] < 0) {
                ans *= nums[i];
                count++;
            } else {
                break;
            }
        }
        return ans;
    }
};

class Solution {
public:
    long long maxStrength(vector<int>& nums) {
        sort(begin(nums), end(nums));
        long long res = 1, sz = nums.size(), cnt = 0;
        for (int i = 0; i < sz; ++i)
            if (res * nums[i] > 0 || (i + 1 < sz && nums[i + 1] < 0)) {
                res *= nums[i];
                ++cnt;
            }
        return cnt ? res : nums.back();
    }
};

class Solution {
public:
    long long maxStrength(vector<int>& nums) {
        long long res = 1, sz = nums.size(), cnt = 0;
        int m = -10;
        int mx = 10;
        for (int i = 0; i < sz; ++i) {
            if(nums[i] == 0)
                continue;
            res *= nums[i];
            ++cnt;
            if(nums[i] < 0)
                m = max(m, nums[i]);
            if(nums[i] >= 0)
                mx = min(mx, nums[i]);
            // }
        }

        if(res < 0 && cnt >= 3 && m != -10) {
            res /= m;
        }
        if(cnt == 0 && mx != 10) {
            res = mx;
        }

        return res;
    }
};

class Solution {
public:
    long long maxStrength(vector<int>& nums) {
        long long prod = 1;
        int largestNegative = INT_MIN, largest = INT_MIN, negCount = 0;
        for(auto n: nums) {
            if(n) 
                prod *= n;
            if(n < 0) { 
                largestNegative = max(largestNegative, n); 
                negCount++; 
            }
            largest = max(largest, n);
        }

        if(largest == 0 && negCount < 2) 
            return 0;
        if(largest < 0 && negCount == 1) 
            return largestNegative;
        if(prod > 0) 
            return prod;
        return prod / largestNegative;
    } 
};