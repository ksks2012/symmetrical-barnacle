#include "include.h"

// TLE
//Dijkstra’s Algorithm
class Solution {
public:
    vector<int> minimumTime(int n, vector<vector<int>>& edges, vector<int>& disappear) {
        vector<vector<pair<int, int>>> graph(n, vector<pair<int, int>>());
        for(int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            graph[u].push_back({v, w});
            graph[v].push_back({u, w});
        }

        vector<int> res(n, -1);
        // Start from 0
        res[0] = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, 0});
        while(!pq.empty()) {
            auto [dist, node] = pq.top();
            pq.pop();
            
            if(disappear[node] <= dist) {
                continue;
            }

            for(auto [next, weight] : graph[node]) {
                if(disappear[next] <= dist + weight) {
                    continue;
                }

                if(res[next] == -1 || res[next] > dist + weight) {
                    res[next] = dist + weight;
                    pq.push({dist + weight, next});
                }
            }
        }
        return res;
    }
};

// Dijkstra’s Algorithm + memory
class Solution {
public:
    vector<int> minimumTime(int n, vector<vector<int>>& edges, vector<int>& disappear) {
        vector<vector<pair<int, int>>> graph(n, vector<pair<int, int>>());
        for(int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            graph[u].push_back({v, w});
            graph[v].push_back({u, w});
        }

        vector<int> res(n, -1);
        // Start from 0
        res[0] = 0;
        vector<int> visited(n, 0);

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, 0});
        while(!pq.empty()) {
            auto [dist, node] = pq.top();
            pq.pop();
            
            // disappear or visited
            if(disappear[node] <= dist || visited[node]) {
                continue;
            }

            visited[node] = 1;

            for(auto [next, weight] : graph[node]) {
                if(disappear[next] <= dist + weight || visited[next]) {
                    continue;
                }
                
                if(res[next] == -1 || res[next] > dist + weight) {
                    // update neighbors
                    res[next] = dist + weight;
                    pq.push({dist + weight, next});
                }
            }
        }
        return res;
    }
};