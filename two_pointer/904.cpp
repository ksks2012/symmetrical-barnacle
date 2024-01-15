#include "include.h"

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> m;
        int ans = 0;

        int n = fruits.size();
        int unique = 0;
        int left = 0;
        for(int i = 0; i < n; i++) {
            m[fruits[i]]++;
            if(m[fruits[i]] == 1) {
                unique++;
            }
            while(unique > 2) {
                m[fruits[left]]--;
                if(m[fruits[left]] == 0) {
                    unique--;
                }
                left++;
            }
            if(unique <= 2) {
                ans = max(ans, i - left + 1);
            }
        }
        return ans;
    }
};