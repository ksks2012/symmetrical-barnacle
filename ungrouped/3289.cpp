#include "../include.h"
 
class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        vector<int> res;
        int n = nums.size();

        unordered_set<int> seen;

        for(int num : nums) {
            if (seen.count(num) == 0) {
                seen.insert(num);
            } else {
                res.push_back(num);
            }
        }

        return res;
    }
};