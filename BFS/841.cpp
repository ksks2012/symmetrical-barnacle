#include "../include.h"

class Solution {
public:
    void DFS(vector<vector<int>>& rooms, vector<int> &tmp, int cur_idx, int &count) {
        int key_size = rooms[cur_idx].size();

        if(tmp[cur_idx] == 1) {
            return;
        }
        tmp[cur_idx] = 1;
        count++;
        if(key_size == 0)
            return;
        for(int i = 0; i < key_size; i++) {
            DFS(rooms, tmp, rooms[cur_idx][i], count);
        }
    }

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<int> tmp(1001, 0);
        int count = 0;

        DFS(rooms, tmp, 0, count);
        
        return count == rooms.size();
    }
};