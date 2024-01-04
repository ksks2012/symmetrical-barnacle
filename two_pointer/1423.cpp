#include "../include.h"

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int sum = 0;
        int n = cardPoints.size();

        for(auto p : cardPoints) {
            sum += p;
        }

        int mini = INT_MAX;
        int target = n - k;
        int cur = 0;
        int left = 0;
        for(int i = 0; i < n; i++) {
            cur += cardPoints[i];
            while(i - left + 1 > target) {
                cur -= cardPoints[left];
                left++;
            }
            if(i - left + 1 == target) {
                mini = min(mini, cur);
            }
        }

        return sum - mini;
    }
};