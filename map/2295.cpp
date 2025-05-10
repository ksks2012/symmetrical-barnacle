#include "include.h"

class Solution {
  public:
    vector<int> arrayChange(vector<int> &nums, vector<vector<int>> &operations) {
        unordered_map<int, int> m;

        for (int i = 0; i < nums.size(); i++) {
            m[nums[i]] = i;
        }

        for (auto op : operations) {
            int a = op[0];
            int b = op[1];
            int idx = m[a];
            nums[idx] = b;
            m[b] = idx;
        }

        return nums;
    }
};