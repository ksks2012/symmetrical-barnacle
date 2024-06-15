#include "include.h"

// priority queue.
class Solution {
public:
    vector<int> maxSubsequence(vector<int> &nums, int k) {
        priority_queue<int, vector<int>, greater<int> > pq;

        for (int &num : nums) {
            pq.push(num);
            if (pq.size() > k)
                pq.pop();
        }
        unordered_map<int, int> m;
        vector<int> ret;
        while (!pq.empty()) {
            m[pq.top()]++;
            pq.pop();
        }

        for (int &num : nums) {
            if (m.find(num) != m.end() && m[num]-- > 0)
                ret.push_back(num);
        }

        return ret;
    }
};