#include "include.h"

class Solution {
public:
    vector<int> resultsArray(vector<vector<int>>& queries, int k) {
        vector<int> res;

        priority_queue<int, vector<int>> pq;

        for (int i = 0; i < queries.size(); i++) {
            pq.push(abs(queries[i][0]) + abs(queries[i][1]));
        
            if (pq.size() > k) {
                pq.pop();
            } else if (pq.size() < k) {
                res.push_back(-1);
                continue;
            }
            res.push_back(pq.top());
        }

        return res;
    }
};