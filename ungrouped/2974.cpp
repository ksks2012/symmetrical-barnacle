#include "include.h"

class Solution {
public:
    vector<int> numberGame(vector<int>& nums) {
        queue<int> a, b;

        vector<int> ans;

        sort(nums.begin(), nums.end());

        for(int i = 0; i < nums.size(); i+=2) {
            a.push(nums[i]);
            b.push(nums[i + 1]);
        }

        for(int i = 0; i < nums.size(); i+= 2) {
            ans.push_back(b.front());
            b.pop();
            ans.push_back(a.front());
            a.pop();
        }

        return ans;
    }
};