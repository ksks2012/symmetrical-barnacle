#include "include.h"

class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int size = arr.size(), left = 0, right, sum = 0, minSumOfLens = INT_MAX;
        vector<int> dp(size + 1, 0);
        // means shortest length between [0, i) with sum as target
        dp[0] = size + 1;

        for (right = 0; right < size; ++right) {
            // Find the sum of subarrays equal/smaller to the target
            sum += arr[right];

            while (sum > target) {
                sum -= arr[left++];
            }

            // Check length of subarray
            if (sum == target) {
                int len = right - left + 1;
                minSumOfLens = min(minSumOfLens, len + dp[left]);
                // update dp
                dp[right + 1] = min(dp[right], len);
            } else {
                dp[right + 1] = dp[right];
            }
        }

        return minSumOfLens > size ? -1 : minSumOfLens;
    }
};

// WA
class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();

        int cur = 0;
        int left = 0;
        vector<int> tmp;
        for(int i = 0; i < n; i++) {
            cur += arr[i];
            while(cur > target) {
                cur -= arr[left];
                left++;
            }
            if(cur == target) {
                tmp.push_back(i - left + 1);
            }
        }

        if(tmp.size() < 2) {
            return -1;
        }
        sort(tmp.begin(), tmp.end());
        

        return tmp[0] + tmp[1];
    }
};