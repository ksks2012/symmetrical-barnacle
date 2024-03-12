#include "include.h"

class Solution {
public:
    void DFS(const vector<int>& edges, int idx, vector<int>& dis) {
        int tmp = 0;
        while(idx != -1 && dis[idx] == -1) {
            dis[idx] = tmp++;
            idx = edges[idx];
        }
    }

    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int res = -1;

        int n = edges.size();
        vector<int> dis1(n, -1);
        vector<int> dis2(n, -1);

        DFS(edges, node1, dis1);
        DFS(edges, node2, dis2);

        int mini = INT_MAX;
        for(int i = 0; i < n; i++) {
            if(min(dis1[i], dis2[i]) >= 0 && max(dis1[i], dis2[i]) < mini) {
                mini = max(dis1[i], dis2[i]);
                res = i;
            }
        }
        return res;
    }
};