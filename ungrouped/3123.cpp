#include "include.h"

// Dijkstra's algorithm + backtracking
class Solution {
public:
    vector<bool> findAnswer(int n, vector<vector<int>>& edges) {
        vector<bool> res(edges.size());
        vector<vector<array<int, 2>>> al(n);
        for (int i = 0; i < edges.size(); ++i) {
            const auto &e = edges[i];
            al[e[0]].push_back({e[1], i});
            al[e[1]].push_back({e[0], i});
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        vector<int> path(n, INT_MAX);    
        pq.push({0, 0});
        path[0] = 0;
        // Dijkstra's algorithm
        while(!pq.empty()) {
            auto [len, i] = pq.top(); pq.pop();
            if (len == path[i])
                for (auto [j, e] : al[i])
                    if (len + edges[e][2] < path[j]) {
                        path[j] = len + edges[e][2];
                        pq.push({path[j], j});
                    }
        }
        pq.push({path[n - 1], n - 1}); 
        // backtrack
        while (!pq.empty()) {
            auto [len, i] = pq.top(); pq.pop();
            for (auto [j, e] : al[i])
                if (len - edges[e][2] == path[j]) {
                    res[e] = true;
                    pq.push({path[j], j});
                }
            }
        return res;
    }
};

// Dijkstra's algorithm with two directions
#define ll long long
class Solution {
public:
    vector<bool> findAnswer(int n, vector<vector<int>>& edges) {
        vector<vector<pair<ll, ll>>> adj;
        adj.resize(n);
        
        pair<ll, ll> p;
        vector<bool> res(edges.size(), false);
        
        
        for(int i = 0; i < edges.size(); ++i) {
            int u = edges[i][0];
            int v = edges[i][1];
            
            int wt = edges[i][2];
            
            adj[u].push_back({v,wt});
            adj[v].push_back({u, wt});
        }
        
        vector<ll> d1(n, 1e12);
        vector<ll> d2(n, 1e12);
        
        priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<>> pq1;
        priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<>> pq2;
        
        pq1.push({0, 0});
        d1[0] = 0;

        // Dijkstra's from vertex 0
        while(!pq1.empty()) {
            p = pq1.top(); pq1.pop();
            ll curr = p.second;
            ll dist = p.first;

            if(dist > d1[curr])
                continue;

            for(int i = 0; i < adj[curr].size(); ++i) {
                ll next = adj[curr][i].first;
                ll wt = adj[curr][i].second;

                if(dist + wt < d1[next]) {
                    d1[next] = dist + wt;
                    pq1.push({d1[next], next});
                }
            }
        }
        
        pq2.push({0, n - 1});
        d2[n-1] = 0;
        
        // Dijkstra's from vertex N-1
        while(!pq2.empty()) {
            p = pq2.top(); 
            pq2.pop();
            ll curr = p.second;
            ll dist = p.first;

            if(dist > d2[curr])
                continue;

            for(int i = 0; i < adj[curr].size(); ++i) {
                ll next = adj[curr][i].first;
                ll wt = adj[curr][i].second;

                if(dist + wt < d2[next]) {
                    d2[next] = dist + wt;
                    pq2.push({d2[next], next});
                }
            }
        }
        
        // checking the condition for each edge
        for(int i = 0; i < edges.size(); ++i) {
            int u = edges[i][0];
            int v = edges[i][1];
            
            int wt = edges[i][2];
            
            if(d1[u] + d2[v] + wt == d1[n - 1])
                res[i] = true;
            
            if(d1[v] + d2[u] + wt == d1[n - 1])
                res[i] = true;
        }
        
        return res;
    }
};