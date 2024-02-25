#include "include.h"

// Prefix sum
class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {

        int tmp[1000005] = {};
        int maxi = -1;

        for(auto &e : intervals) {
            int start = e[0], end = e[1];
            tmp[start] += 1;
            tmp[end + 1] -= 1;
        }

        for(int i = 1; i < 1000001; i++) {
            tmp[i] += tmp[i - 1];
            maxi = max(maxi, tmp[i]);
        }

        return maxi;
    }
};

// Heap
class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        priority_queue<int, vector<int>, greater<int>> pq;
        for (const auto &i : intervals) {
            if (!pq.empty() && pq.top() < i[0])
                pq.pop();
            pq.push(i[1]);
        }
        return pq.size();
    }
};