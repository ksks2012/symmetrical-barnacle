#include "../include.h"

class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        int len = connections.size();
        if(len<n-1) return -1;
        vector<vector<int>> adj(n);
        vector<vector<int>> pre_adj(n);
        for(auto v : connections)
        {
            adj[v[0]].push_back(v[1]);
            pre_adj[v[1]].push_back(v[0]);
        }

        vector<bool> visited(n, false);
        int ans = 0;
        stack<int> s;
        visited[0] = 1;
        s.push(0);
        while(s.size() != 0) {
            int len = s.size();
            for(int i = 0; i < len; i++) {
                int top = s.top();
                s.pop();
                for(int j : adj[top]){
                    if(!visited[j]) {
                        s.push(j);
                        ans++;
                        visited[j] = 1;
                    }
                }
                for(int j : pre_adj[top]){
                    if(!visited[j]) {
                        s.push(j);
                        visited[j] = 1;
                    }
                }
            }
        }
        return ans;
    }
};

// Solution
class Solution {
public:
    int DFS(vector<vector<int>> &al, vector<bool> &visited, int from) {
        auto change = 0;
        visited[from] = true;
        for (auto to : al[from])
            if (!visited[abs(to)])
                change += DFS(al, visited, abs(to)) + (to > 0);
        return change;        
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<int>> al(n);
        for (auto &c : connections) {
            al[c[0]].push_back(c[1]);
            al[c[1]].push_back(-c[0]);
        }
        return DFS(al, vector<bool>(n) = {}, 0);
    }
};