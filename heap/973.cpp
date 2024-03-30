#include "../include.h"

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> res;

        priority_queue<pair<int, vector<int>>> pq;

        for(auto& point : points) {
            int x = point[0];
            int y = point[1];
            int dist = x * x + y * y;
            pq.push({dist, point});
            if(pq.size() > k) {
                pq.pop();
            }
        }

        for(int i = 0; i < k; i++) {
            res.push_back(pq.top().second);
            pq.pop();
        }

        return res; 
    }
};

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        sort(points.begin(), points.end(), [](vector<int>& a, vector<int>& b) {
            return a[0] * a[0] + a[1] * a[1] < b[0] * b[0] + b[1] * b[1];
        });
        return vector<vector<int>>(points.begin(), points.begin() + k);
    }
};