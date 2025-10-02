#include "include.h"

class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
        int sum = 0;
        for (int num : nums) {
            sum += num;
        }
        int digitSum = 0;
        for(int num : nums) {
            while (num > 0) {
                digitSum += num % 10;
                num /= 10;
            }
        }
        return abs(digitSum - sum);
    }
};