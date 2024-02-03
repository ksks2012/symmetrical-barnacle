#include "include.h"

class Solution {
public:
    string triangleType(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int a = nums[0];
        int b = nums[1];
        int c = nums[2];
        if(a + b > c)
            if(a == b && b == c) {
                return "equilateral";
            } else if(a == b || b == c || c == a) {
                return "isosceles";
            } else {
                return "scalene";
            }


        return "none";
    }
};