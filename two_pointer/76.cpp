#include "include.h"

class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.length();
        int m = t.length();
        if (n < m) return "";

        // 1. Count the frequency of each character required in string t
        vector<int> target_cnt(128, 0);
        for (char c : t) {
            target_cnt[c]++;
        }

        // 2. Initialize sliding window variables
        vector<int> window_cnt(128, 0);
        int left = 0;
        int match_count = 0; // Number of unique characters that meet the required frequency in the current window
        
        int min_len = INT_MAX;
        int start_idx = 0;   // Track the start index of the minimum window to avoid frequent substr() calls

        // Count how many unique characters in t need to be matched
        int required_unique = 0;
        for (int i = 0; i < 128; i++) {
            if (target_cnt[i] > 0) required_unique++;
        }

        // 3. Start sliding the window
        for (int right = 0; right < n; right++) {
            char r_char = s[right];
            window_cnt[r_char]++;

            // If the current character's count matches the required frequency in t, mark it as fully matched
            if (target_cnt[r_char] > 0 && window_cnt[r_char] == target_cnt[r_char]) {
                match_count++;
            }

            // When all unique characters meet the requirement, try to shrink the left boundary
            while (match_count == required_unique) {
                // Update the minimum window information
                if (right - left + 1 < min_len) {
                    min_len = right - left + 1;
                    start_idx = left;
                }

                char l_char = s[left];
                // If the left character is a required character and removing it causes the frequency to drop below requirement
                if (target_cnt[l_char] > 0 && window_cnt[l_char] == target_cnt[l_char]) {
                    match_count--;
                }
                window_cnt[l_char]--;
                left++; // Shrink the window from the left
            }
        }

        return min_len == INT_MAX ? "" : s.substr(start_idx, min_len);
    }
};