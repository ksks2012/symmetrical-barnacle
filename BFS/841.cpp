#include "../include.h"

class Solution {
public:
    void DFS(vector<vector<int>>& rooms, vector<int> &visited, int cur_idx, int &count) {
        int key_size = rooms[cur_idx].size();

        if(visited[cur_idx] == 1) {
            return;
        }
        visited[cur_idx] = 1;
        count++;
        if(key_size == 0)
            return;
        for(int i = 0; i < key_size; i++) {
            DFS(rooms, visited, rooms[cur_idx][i], count);
        }
    }

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<int> visited(1001, 0);
        int count = 0;

        DFS(rooms, visited, 0, count);
        
        return count == rooms.size();
    }
};