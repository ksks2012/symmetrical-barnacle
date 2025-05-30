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

class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool> res;
        
        // Iterate over each query (given by corresponding l[i] and r[i])
        for (auto i = 0, j = 0; i < l.size(); ++i) {
            
            // Find the minimum and maximum values in the subarray nums[l[i]..r[i]]
            auto [p_min, p_max] = minmax_element(begin(nums) + l[i], begin(nums) + r[i] + 1);
            
            int len = r[i] - l[i] + 1;                     // Length of the subarray
            int d = (*p_max - *p_min) / (len - 1);         // Expected common difference

            // Case 1: All elements are equal ⇒ trivially an arithmetic sequence
            if (*p_max == *p_min) {
                res.push_back(true);
            }
            // Case 2: Max - Min not divisible by (length - 1) ⇒ can't form arithmetic sequence
            else if ((*p_max - *p_min) % (len - 1)) {
                res.push_back(false);
            }
            else {
                // Track which positions the values should occupy in an arithmetic sequence
                vector<bool> n(len);

                // Iterate through the subarray to validate arithmetic positions
                for (j = l[i]; j <= r[i]; ++j) {
                    int offset = nums[j] - *p_min;

                    // Check:
                    // 1. Offset must be divisible by d
                    // 2. Each calculated index must be unique (not already seen)
                    if (offset % d != 0 || n[offset / d]) break;

                    // Mark that this position in the sequence is filled
                    n[offset / d] = true;
                }

                // If the loop completes without breaking, subarray is arithmetic
                res.push_back(j > r[i]);
            }
        }

        return res;
    }
};
