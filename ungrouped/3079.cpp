#include "include.h"

class Solution {
public:
    int maxi_digit(int n) {
        int max_digit = 0;
        while (n > 0) {
            max_digit = max(max_digit, n % 10);
            n /= 10;
        }
        return max_digit;
    }

    int trans_num(int num, int maxi) {
        int result = 0;
        int multiplier = 1;
        while (num > 0) {
            result += maxi * multiplier;
            multiplier *= 10;
            num /= 10;
        }
        return result;
    }

    int sumOfEncryptedInt(vector<int>& nums) {
        // find maxi digit of each number in nums
        for (int i = 0; i < nums.size(); i++) {
            // replace each number with its maxi digit
            int maxi = maxi_digit(nums[i]);
            // replace numbers with their maxi digit
            nums[i] = trans_num(nums[i], maxi);
        }
        
        // return sum of all numbers in nums
        return accumulate(nums.begin(), nums.end(), 0);
    }
};