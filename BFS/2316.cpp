#include "include.h"

class Solution {
public:
    void DFS(vector<vector<int>> &graph, int cur, vector<bool> &visited, long &count) {
        if(visited[cur])
            return;

        visited[cur] = true;
        count++;

        for(auto i : graph[cur]) {
            if(!visited[i])
                DFS(graph, i, visited, count);
        }
    }

    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        for(auto ele:edges){
            graph[ele[0]].push_back(ele[1]);
            graph[ele[1]].push_back(ele[0]);
        }
        long long ans = 0;
        vector<bool> visited(n,false);
        vector<long> tmp;
        for(int i = 0; i < n; i++){
            if(!visited[i]) {
                long count = 0;
                DFS(graph, i, visited, count);
               tmp.push_back(count);
            }
        }
        int total = 0;
        for(int i = 0; i < tmp.size(); i++){
            ans += tmp[i] * (n - total - tmp[i]);
            total += tmp[i];
        }
        return ans;
    }
};