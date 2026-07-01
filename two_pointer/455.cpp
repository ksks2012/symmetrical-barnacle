#include "../include.h"

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int g_idx = 0;
        int s_idx = 0;

        while(g_idx < g.size() && s_idx < s.size()) {
            if(s[s_idx] >= g[g_idx]) {
                g_idx++;
            }
            s_idx++;
        }

        return g_idx;
    }
};