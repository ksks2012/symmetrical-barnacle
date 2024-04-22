#include "include.h"

class Solution {
public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
        queue<int> q;

        q.push(id);
        vector<int> visited(watchedVideos.size(), 0);
        visited[id] = 1;
        while(!q.empty() && level--) {
            int size = q.size();
            for(int i = 0; i < size; ++i) {
                int top = q.front();
                q.pop();
                
                for(int j = 0; j < friends[top].size(); ++j) {
                    int tmp = friends[top][j];
                    if(visited[tmp] == 1)
                        continue;
                    visited[tmp] = 1;
                    q.push(tmp);
                }
            }
        }
        unordered_map<string, int> freq;
        while(!q.empty()) {
            int top = q.front();
            q.pop();
            for(int i = 0; i < watchedVideos[top].size(); ++i) {
                freq[watchedVideos[top][i]]++;
            }
        }
        vector<pair<int, string>> v;
        for(auto it = freq.begin(); it != freq.end(); it++) {
            v.push_back({it->second, it->first});
        }
        sort(v.begin(), v.end());
        vector<string> res;
        for(int i = 0; i < v.size(); ++i) {
            res.push_back(v[i].second);
        }

        return res;
    }
};