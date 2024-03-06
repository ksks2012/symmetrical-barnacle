#include "include.h"

// votrubac
class Solution {
public:
    vector<int> colorTheArray(int n, vector<vector<int>>& queries) {
        int color[100003] = {}, adj = 0;
        vector<int> ans;

        for(auto q : queries) {
            int i = q[0] + 1, i_color = q[1];
            if(color[i] != 0) {
                // repeat -> not repeat after color change
                adj -= (color[i - 1] == color[i]) + (color[i + 1] == color[i]);
            }
            color[i] = i_color;
            // not repeat -> repeat after color change
            adj += (color[i - 1] == color[i]) + (color[i + 1] == color[i]);
            ans.push_back(adj);

        }

        return ans;
    }
};