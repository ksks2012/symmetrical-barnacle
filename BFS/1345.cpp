#include "include.h"

class Solution {
public:
    int minJumps(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, vector<int>> m;
        for (int i = 0; i < n; i++) {
            if (m.count(nums[i]) == 0) {
                m[nums[i]] = vector<int>();
            }
            m[nums[i]].push_back(i);
        }

        int res = 0;
        queue<int> q;
        q.push(0);
        // restore visited nodes
        vector<bool> visited(n, false);
        while(!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                int cur = q.front();
                q.pop();
                if (cur == n - 1) {
                    return res;
                }
                // i - 1
                if (cur - 1 >= 0 && !visited[cur - 1]) {
                    q.push(cur - 1);
                    visited[cur - 1] = true;
                }
                // i + 1
                if (cur + 1 < n && !visited[cur + 1]) {
                    q.push(cur + 1);
                    visited[cur + 1] = true;
                }
                // nodes with same value
                if (m.count(nums[cur]) > 0) {
                    for (int j : m[nums[cur]]) {
                        if (!visited[j]) {
                            q.push(j);
                            visited[j] = true;
                        }
                    }
                    m.erase(nums[cur]);
                }
            }
            res++;
        }

        return res;
    }
};