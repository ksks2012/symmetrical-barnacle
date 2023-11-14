#include "../include.h"

class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        int count = 0;
        for(auto e : edges)
        {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<bool> visited(n, false);
        for(int i = 0; i < n; i++) {
            int vertex_count = 0;
            int edge_count = 0;
            if(!visited[i]) {
                stack<int> s;
                s.push(i);
                visited[i] = 1;
                vertex_count = 1;
                while(s.size() != 0) {
                    int len = s.size();
                    for(int j = 0; j < len; j++) {
                        int top = s.top();
                        s.pop();
                        for(int k : adj[top]) {
                            if(!visited[k]) {
                                s.push(k);
                                visited[k] = 1;  
                                vertex_count++;
                            }
                            edge_count++;
                        }
                    }
                }
                // Process repeated edges
                edge_count /= 2;
                if(vertex_count * (vertex_count - 1) / 2 == edge_count) {
                    count++;
                }
            }  
        }
        return count;
    }
};