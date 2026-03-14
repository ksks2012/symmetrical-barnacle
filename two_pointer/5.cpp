#include "../include.h"

class Solution {
public:
    string longestPalindrome(string s) {
        int start = 0;
        int maxLength = 1;
        for (int i = 0; i < s.size(); i++) {
            // Check for odd-length palindromes
            int left = i;
            int right = i;
            while (left >= 0 && right < s.size() && s[left] == s[right]) {
                if (right - left + 1 > maxLength) {
                    start = left;
                    maxLength = right - left + 1;
                }
                left--;
                right++;
            }
            // Check for even-length palindromes
            left = i;
            right = i + 1;
            while (left >= 0 && right < s.size() && s[left] == s[right]) {
                if (right - left + 1 > maxLength) {
                    start = left;
                    maxLength = right - left + 1;
                }
                left--;
                right++;
            }
        }
        return s.substr(start, maxLength);
    }
};