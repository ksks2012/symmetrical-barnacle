#include "include.h"

class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int sum = 0;
        int queryCount = queries.size();
        int n = nums.size();
        vector<int> res(queryCount, 0);
        for (int i = 0; i < n; i++) {
            if (nums[i] % 2 == 0) {
                sum += nums[i];
            }
        }
        
        for (int i = 0; i < queryCount; i++) {
            int val = queries[i][0];
            int index = queries[i][1];
            if (nums[index] % 2 == 0) {
                sum -= nums[index];
            }
            nums[index] += val;
            if (nums[index] % 2 == 0) {
                sum += nums[index];
            }
            res[i] = sum;
        }
        return res;
    }
};