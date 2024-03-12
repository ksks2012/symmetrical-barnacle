#include "../include.h"

// Time Complexity: O(n^2)
// Space Complexity: O(1)
class Solution {
public:
    int beautySum(string s) {
        int ans = 0;
        for (auto i = 0; i < s.size(); ++i) {
            int count[26] = {}, maxi = 0, mini = 0;
            for (auto j = i; j < s.size(); ++j) {
                int idx = s[j] - 'a';
                maxi = max(maxi, ++count[idx]);
                if (mini >= count[idx] - 1) {
                    mini = count[idx];
                    for (int k = 0; k < 26; ++k)
                        mini = min(mini, count[k] == 0 ? INT_MAX : count[k]);
                }
                ans += maxi - mini;
            }
        }
        return ans;
    }
};