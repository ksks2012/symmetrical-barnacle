#include "../include.h"

class Solution {
public:
    int averageValue(vector<int>& nums) {
        int sum = 0;
        int count = 0;
        
        for (int num : nums) {
            if (num % 6 == 0) {
                sum += num;
                count++;
            }
        }
        return count == 0 ? 0 : sum / count;
    }
};