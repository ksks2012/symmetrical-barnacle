#include "include.h"

class Solution {
public:
    double minimumAverage(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        double res = INT_MAX;

        for(int i = 0; i < n / 2; i++) {
            double avg = double(nums[i] + nums[n - i - 1]) / 2;
            res = min(res, avg);
            cout << avg << endl;
        }

        return res;
    }
};