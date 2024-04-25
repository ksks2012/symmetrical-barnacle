#include "include.h"

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        deque<int> q;
        for (int i = 0; i < nums.size(); i++) {
            // 1. input
            while (!q.empty() && nums[q.back()] <= nums[i]) {
                q.pop_back();
            }
            q.push_back(i);
            // 2. output
            // front had removed from window
            if (i - q.front() >= k) { 
                q.pop_front();
            }
            // 3. record
            if (i >= k - 1) {
                // decrease -> front is largest
                res.push_back(nums[q.front()]);
            }
        }
        return res;
    }
};