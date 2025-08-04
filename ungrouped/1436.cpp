#include "include.h"

class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string, string> mp;
        for(const auto& path : paths) {
            mp[path[0]] = path[1];
        }
        // find the destination city
        for(const auto& path : paths) {
            if(mp.find(path[1]) == mp.end()) {
                return path[1];
            }
        }
        return "";
    }
};