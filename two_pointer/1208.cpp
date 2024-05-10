#include "include.h"

class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.size();
        vector<int> tmp(n, 0);

        // calculate cost
        for(int i = 0; i < n; i++) {
            tmp[i] = abs(t[i] - s[i]);
        } 
        
        int left = 0;
        int cur = 0;
        int ans = 0;
        for(int right = 0; right < n; right++) {
            cur += tmp[right];
            while(cur > maxCost) {
                cur -= tmp[left++];
            }
            ans = max(ans, right -left + 1);
        }
        return ans;
    }
};