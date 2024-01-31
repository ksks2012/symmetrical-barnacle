#include "include.h"

// Sliding window
// Time Complexity: O(n)
// Space Complexity: O(1)
class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int n = answerKey.size();
        vector<int> tmp(n, 0);
        for(int i = 0; i < n; i++) {
            if(answerKey[i] == 'T') {
                tmp[i] = 1;
            } else {
                tmp[i] = 0;
            }
        }

        int left = 0;
        int cur[2] = {0};
        int maxi = 0;
        for(int right = 0; right < n; ++right) {
            cur[tmp[right]]++;
            maxi = max(maxi, cur[tmp[right]]);          
            if (left - maxi < k)
                left++;
            else
                cur[tmp[right - left]]--;
        }

        return left;
    }
};