#include "include.h"

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> res;
        unordered_set<int> s;
        for (int i = 0; i < nums.size(); i++) {
            if (s.find(nums[i]) != s.end()) {
                res.push_back(nums[i]);
            } else {
                s.insert(nums[i]);
            }
        }
        return res;           
    }
};

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> res;
        // nums[i] < n
        for(int i = 0; i < nums.size(); i++) {
            if(nums[abs(nums[i]) - 1] < 0) {
                res.push_back(abs(nums[i]));
            } else {
                nums[abs(nums[i]) - 1] *= -1;
            }
            for(int j = 0; j < nums.size(); j++) {
                cout << nums[j] << " ";
            }
            cout << endl;
        }
        return res;
    }
};