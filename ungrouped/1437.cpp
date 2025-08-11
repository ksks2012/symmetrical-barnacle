#include "include.h"

class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int last = -1;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) {
                if (last != -1 && i - last <= k) {
                    return false; // Found two 1's too close together
                }
                last = i; // Update the position of the last 1 found
            }
        }

        return true;
    }
};