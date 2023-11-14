#include "../include.h"

class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        queue<int> q;
        vector<bool> visited(n, false);
        
        q.push(start);
    
        while(!q.empty()) {
            int q_size = q.size();
            for(int i = 0; i < q_size; i++) {
                int tmp = q.front();
                q.pop();
                vector<int> next = {tmp - arr[tmp], tmp + arr[tmp]};
                for(auto ne : next) {
                    if(ne >= 0 && ne < n && !visited[ne]) {
                        if(arr[ne] == 0) {
                            return true;
                        } else {
                            q.push(ne);
                            visited[ne] = true;
                        }
                    }
                } 
            }
        }
        return false;
    }
};

class Solution {
public:
    unordered_set<int> visited;
    bool canReach(vector<int>& arr, int start) {
        if (start >= 0 && start < arr.size() && visited.insert(start).second) {
            return arr[start] == 0 ||
                canReach(arr, start + arr[start]) || canReach(arr, start - arr[start]);
        }
        return false;
    }
};