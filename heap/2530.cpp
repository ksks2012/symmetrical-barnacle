#include "include.h"

class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int> pq(nums.begin(), nums.end());

        long long res = 0;
        while (k--) {
            int tmp = pq.top();
            res += tmp;
            pq.pop();
            pq.push(ceil(tmp / 3.0));
        }

        return res;
    }
};