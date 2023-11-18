#include "../include.h"

class Solution {
private:
    int DFS(int manager, vector<int>& informTime, unordered_map<int, vector<int>>& adjList) {
        int maxTime = 0;
        if (adjList.find(manager) != adjList.end()) {
            for (int subordinate : adjList[manager]) {
                maxTime = max(maxTime, DFS(subordinate, informTime, adjList));
            }
        }
        return maxTime + informTime[manager];
    }

public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        unordered_map<int, vector<int>> tmp;
        for (int i = 0; i < n; i++) {
            if (manager[i] != -1) {
                tmp[manager[i]].push_back(i);
            }
        }

        return DFS(headID, informTime, tmp);
    }
};