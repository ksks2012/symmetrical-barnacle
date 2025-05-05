#include "include.h"

class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool> res(l.size(), false);

        for (int i = 0; i < l.size(); ++i) {
            int start = l[i];
            int end = r[i];
            vector<int> subArray(nums.begin() + start, nums.begin() + end + 1);
            sort(subArray.begin(), subArray.end());
            int diff = subArray[1] - subArray[0];
            bool isArithmetic = true;
            for (int j = 2; j < subArray.size(); ++j) {
                if (subArray[j] - subArray[j - 1] != diff) {
                    isArithmetic = false;
                    break;
                }
            }
            res[i] = isArithmetic;
        }

        return res;
    }
};