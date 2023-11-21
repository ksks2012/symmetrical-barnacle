#include "../include.h"

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> colour(n, 0);

        for(int node = 0; node < n; node++){
            if(colour[node] != 0) 
                continue;

            queue<int> q;
            q.push(node);
            colour[node] = 1;

            while(!q.empty()){
                int cur = q.front();
                q.pop();

                for(int ne : graph[cur]){
                    if(colour[ne] == 0){
                        colour[ne] = -colour[cur];
                        q.push(ne);
                    } else if(colour[ne] != -colour[cur]){
                        return false;
                    }
                }
            }
        }

        return true;
    }
};