#include "../include.h"


#define MOD 1000000007
class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        int m = nums.size();
        vector<int> sum;
        for(int i = 0; i < m; i++) {
            int tmp = nums[i];
            sum.push_back(tmp);
            for(int j = i + 1; j < m; j++) {
                tmp += nums[j];
                sum.push_back(tmp);
            }
        }

        sort(sum.begin(), sum.end());
        int res = 0;
        for(int i = left - 1; i < right && i < sum.size(); i++) {
            res += sum[i] % MOD;
        }

        return res;
    }
};

// Optimize by heap
class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> mqueue;
        for (int i = 0; i < n; i++)
            mqueue.push({nums[i], i + 1});

        int res = 0;
        for (int i = 1; i <= right; i++) {
            auto top = mqueue.top();
            mqueue.pop();
            if (i >= left)
                res = (res + top.first) % MOD;
            if (top.second < n) {
                top.first += nums[top.second++];
                mqueue.push(top);
            }
        }
        return res;
    }
};