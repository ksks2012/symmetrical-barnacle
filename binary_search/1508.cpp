#include "../include.h"


#define MOD 1000000007
class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        int m = nums.size();
        vector<long long> sum;
        for(int i = 0; i < m; i++) {
            long long tmp = nums[i];
            sum.push_back(tmp);
            for(int j = i + 1; j < m; j++) {
                tmp += nums[j];
                sum.push_back(tmp);
            }
        }

        sort(sum.begin(), sum.end());
        long long res = 0;
        for(int i = left - 1; i < right && i < (int)sum.size(); i++) {
            res = (res + (sum[i] % MOD)) % MOD;
        }

        return (int)res;
    }
};

// Optimize by heap
class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> mqueue;
        for (int i = 0; i < n; i++)
            // {nums[i] + ... + nums[j], j + 1}
            mqueue.push(make_pair((long long)nums[i], i + 1));

        long long res = 0;
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
        return (int)res;
    }
};