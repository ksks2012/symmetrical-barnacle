#include "include.h"

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> indegree(numCourses, 0);
        for(auto pre: prerequisites){
            graph[pre[1]].push_back(pre[0]);
            indegree[pre[0]]++;
        }

        vector<int> ans;
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                q.push(i);
                ans.push_back(i);
            }
        }

        while(!q.empty()) {
            int top = q.front();
            q.pop();
            for(int i = 0; i < graph[top].size(); i++) {
                indegree[graph[top][i]]--;
                if(indegree[graph[top][i]] == 0) {
                    q.push(graph[top][i]);
                    ans.push_back(graph[top][i]);
                }
            }
        }
        if(ans.size() != numCourses) {
            return vector<int>();
        }
        return ans;
    }
};