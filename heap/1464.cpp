#include "../include.h"

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        priority_queue<int> pq;
        for(int i = 0; i < nums.size(); i++) {
            pq.push(nums[i]);
        }

        int res = pq.top();
        pq.pop();

        return (res - 1) * (pq.top() - 1);
    }
};