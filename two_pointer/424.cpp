#include "../include.h"

class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int left = 0, right = 0, tmp = 0;
        unordered_map<char, int> m;
        int ans = -1;
        while(right < n) {
            m[s[right]]++;
            tmp = max(tmp, m[s[right]]);
            if((right - left + 1) - tmp > k){
                m[s[left]]--;
                left++;
            }
            ans = max(ans, (right - left + 1));
            right++;   
        }
        return ans;
    }
};