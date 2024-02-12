#include "include.h"

class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int n = garbage.size();
        int ans = 0;
        unordered_set<char> s;
        for (int i = n - 1; i >= 0 ; i--) {
            for (const char & c : garbage[i]) {
                if (s.find(c) == s.end()) {
                    s.insert(c);
                }
            }
            // each garbage need 1 min
            ans += garbage[i].size();
            // had class of garbage
            ans += i > 0 ? s.size() * travel[i - 1] : 0;
        }
        return ans;
    }
};