#include "include.h"

class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        int n = cards.size();

        unordered_map<int, int> m;
        int ans = INT_MAX;
        int left = 0;

        for(int i = 0; i < n; i++) {
            m[cards[i]]++;
            while(m[cards[i]] > 1) {
                ans = min(ans, i - left + 1);
                m[cards[left]]--;
                left++;
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};