#include "include.h"

class Solution {
public:

    bool DFS(vector<vector<int>>& graph, vector<int> &visited, int cur) {
        if(visited[cur] == -1)
            return false;
        if(visited[cur] == 1)
            return true;

        visited[cur] = -1;
        for (auto i : graph[cur]) {
            if(!DFS(graph, visited, i))
                return false;
        }
        visited[cur] = 1;
        return true;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        for(auto pre: prerequisites){
            graph[pre[1]].push_back(pre[0]);
        }

        vector<int> visited(numCourses);
        for(int i = 0; i < numCourses; i++) {
            if(!DFS(graph, visited, i))
                return false;
        }

        return true;
    }
};

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses, vector<int>());
        vector<int> visit(numCourses);
        for (auto a : prerequisites) {
            graph[a[1]].push_back(a[0]);
        }
        for (int i = 0; i < numCourses; ++i) {
            if (!canFinishDFS(graph, visit, i)) return false;
        }
        return true;
    }
    bool canFinishDFS(vector<vector<int>>& graph, vector<int>& visit, int i) {
        if (visit[i] == -1) return false;
        if (visit[i] == 1) return true;
        visit[i] = -1;
        for (auto a : graph[i]) {
            if (!canFinishDFS(graph, visit, a)) return false;
        }
        visit[i] = 1;
        return true;
    }
};