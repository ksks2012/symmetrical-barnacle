#include "include.h"

class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> graph(n);
        for (vector<int>& d : dislikes) {
            graph[d[0] - 1].push_back(d[1] - 1);
            graph[d[1] - 1].push_back(d[0] - 1);
        }

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