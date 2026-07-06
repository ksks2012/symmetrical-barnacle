#include "../include.h"

class Solution {
public:
    long long validSubstringCount(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();
        if (n < m) return 0;

        long long res = 0;

        vector<int> target_cnt(128, 0);
        for (char c : word2) {
            target_cnt[c]++;
        }
        
        int required_unique = 0;
        for (int i = 0; i < 128; i++) {
            if (target_cnt[i] > 0) {
                required_unique++;
            }
        }

        vector<int> window_cnt(128, 0);
        int left = 0;
        int match_count = 0;
        for (int right = 0; right < n; right++) {
            char r_char = word1[right];
            window_cnt[r_char]++;

            if (target_cnt[r_char] > 0 && window_cnt[r_char] == target_cnt[r_char]) {
                match_count++;
            }

            while (match_count == required_unique) {
                char l_char = word1[left];
                if (target_cnt[l_char] > 0 && window_cnt[l_char] == target_cnt[l_char]) {
                    match_count--;
                }
                window_cnt[l_char]--;
                left++;
            }
            res += left;
        }
        return res;
    }
};