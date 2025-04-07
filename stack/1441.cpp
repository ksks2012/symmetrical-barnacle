#include "include.h"

class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        
        vector<string> ans;
        int idx = 0;
        for (size_t i = 1; i <= n; i++)
        {
            if(idx >= target.size())
                break;
            if(target[idx] == i) {
                ans.push_back("Push");
                idx++;
            } else {
                ans.push_back("Push");
                ans.push_back("Pop");
            }
        }

        return ans;
        
    }
};