#include "include.h"

class Solution {
public:
    int longestBeautifulSubstring(string word) {
        int n = word.size();

        int count = 1;
        int tmp = 1;
        int ans = 0;
        for (int i = 1; i != n; ++i) {
            if (word[i - 1] == word[i]) {
                ++tmp;
            } else if (word[i - 1] < word[i]) {
                ++tmp;
                ++count;
            } else {
                count = 1;
                tmp = 1;
            }
            
            if (count == 5) {
                ans = max(ans, tmp);
            }
        }
        return ans;
    }
};