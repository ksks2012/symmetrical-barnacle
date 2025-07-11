#include "include.h"

class Solution {
public:
    int minElement(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            int tmp = nums[i];
            int count = 0;
            while(tmp > 0) {
                int digit = tmp % 10;
                count += digit;
                tmp /= 10;
            }
            nums[i] = count; // Update the number with only valid digits
        }
     
        return *min_element(nums.begin(), nums.end());
    }
};