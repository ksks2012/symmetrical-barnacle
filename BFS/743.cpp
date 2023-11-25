#include "../include.h"

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int start) {
        int ans = 0;

        // start_node <end_node, time>
        vector<vector<pair<int, int>>> tmp(n + 1, vector<pair<int,int>>(0));

        for(int i = 0; i < n; i++) {
            tmp[times[i][0]].push_back(pair<int, int>(times[i][1], times[i][2]));
        }

        unordered_set<int> visited;

        queue<pair<int, int>> q;
        q.push(pair<int, int>(start, 0));
        visited.insert(start);

        while(!q.empty()) {
            int q_size = q.size();
            for(int i = 0; i < q_size; i++) {
                auto [node, cur_time] = q.front();
                q.pop();
                for(int j = 0; j < tmp[node].size(); i++) {
                    int next_time = cur_time + tmp[node][j].second;
                    q.push(pair<int, int>(tmp[node][j].first, next_time));
                    ans = max(ans, next_time);
                    visited.insert(node);
                }
            }
        }

        if(visited.size() != n) {
            return -1;
        }

        return ans;
    }
};

class Solution {
public:
    // Using Priority queue (Min-heap)
    int networkDelayTime(vector<vector<int>>& times, int n, int start) {
        vector<vector<pair<int, int>>> g(n + 1);
        for(int i = 0; i < times.size(); i++)
            g[times[i][0]].push_back(make_pair(times[i][1], times[i][2]));

        vector<int> dist(n + 1, 1e9);
        dist[start] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>> , greater<pair<int,int>>> q;
        q.push(make_pair(0, start));
        vector<bool> visited(n + 1);
        while(!q.empty()) {
            pair<int, int> tmp = q.top();
            q.pop();
            int u = tmp.second;
            visited[u] = true;
            for(int i = 0; i < g[u].size(); i++) {
                int v = g[u][i].first;
                int weight = g[u][i].second;
                if(visited[v] == false && dist[v] > dist[u] + weight){
                    dist[v] = dist[u] + weight;
                    q.push(make_pair(dist[v], v));
                }
            }
        }

        int ans = 0;
        for(int i = 1; i < dist.size(); i++) {
            ans = max(ans, dist[i]);
        }

        if(ans == 1e9) 
            return -1;
        return ans;
    }
};

class Solution {
public:
    int networkDelayTime(vector<vector<int>> &times, int n, int k) {
        const int inf = INT_MAX / 2;

        // Update neighbors edges in storage
        vector<vector<int>> g(n, vector<int>(n, inf));
        for (auto &t : times) {
            int x = t[0] - 1, y = t[1] - 1;
            g[x][y] = t[2];
        }

        // From start node to other nodes
        vector<int> dist(n, inf);
        // Start from k-th node
        dist[k - 1] = 0;

        // Node is updated
        vector<bool> used(n);

        for (int i = 0; i < n; ++i) {
            // Found minimize distance between unknown nodes
            int x = -1;
            for (int y = 0; y < n; ++y) {
                if (!used[y] && (x == -1 || dist[y] < dist[x])) {
                    x = y;
                }
            }

            // Update all distances of other nodes by selected node
            used[x] = true;
            for (int y = 0; y < n; ++y) {
                dist[y] = min(dist[y], dist[x] + g[x][y]);
            }
        }

        // Found farest distance between start and node
        int ans = *max_element(dist.begin(), dist.end());
        return ans == inf ? -1 : ans;
    }
};