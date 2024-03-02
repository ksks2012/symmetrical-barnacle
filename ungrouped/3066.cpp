#include "include.h"

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long long, vector<long long>, greater<long long> > pq;

        for(int i = 0; i < nums.size(); i++) {
            pq.push(nums[i]);
        }

        int ans = 0;

        while(pq.size() > 1) {
            auto first = pq.top();
            if(first >= k) {
                return ans;
            }
            pq.pop();
            auto second = pq.top();
            if(second >= k) {
                return ans + 1;
            }
            pq.pop();

            pq.push(first * 2 + second);
            ans++;
        }

        return ans;
    }
};