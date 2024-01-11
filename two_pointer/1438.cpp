#include "include.h"

class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        priority_queue<int> pq_dec;
        priority_queue<int, greater<int>> pq_inc;

        int ans = 0;
        int left = 0;
        for(int i = 0; i < nums.size(); i++) {
            pq_dec.push(nums[i]);
            pq_inc.push(nums[i]);
            while(pq_dec.top() - pq_inc.top() > limit) {
                // pq_dec.pop();
                left++;
            }
            ans = max(i - left + 1, ans);
        }
        return ans;
    }
};

// lee
class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int i = 0, j;
        multiset<int> m;
        for (j = 0; j < nums.size(); ++j) {
            m.insert(nums[j]);
            if (*m.rbegin() - *m.begin() > limit)
                m.erase(m.find(nums[i++]));
        }
        return j - i;
    }
};