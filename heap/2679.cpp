#include "include.h"

// heap
class Solution {
public:
    int matrixSum(vector<vector<int>>& nums) {
        int n = nums.size();
        int m = nums[0].size();
        priority_queue<int> pq[n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                pq[i].push(nums[i][j]);
            }
        }
        int ans = 0;
        for (int k = 0; k < m; k++) {
            int maxi = 0;
            for(int i = 0; i < n; i++){
                maxi = max(maxi, pq[i].top());
                pq[i].pop();
            }
            ans += maxi;
        }
        return ans;
    }
};