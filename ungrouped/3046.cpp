#include "include.h"

class Solution {
public:
    bool isPossibleToSplit(vector<int>& nums) {
        unordered_map<int, int> freq;

        for(int i = 0; i < nums.size(); i++) {
            freq[nums[i]]++;
        }

        for(auto m : freq) {
            if(m.second >= 3) {
                return false;
            }
        }  

        return true;
    }
};