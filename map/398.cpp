#include "include.h"

class Solution {
public:
    vector<int> tmp;

    Solution(vector<int>& nums) {
        this->tmp = nums;
    }
    
    int pick(int target) {
        int res = -1;
        int count = 0;
        for (int i = 0; i < tmp.size(); i++) {
            if (tmp[i] == target) {
                count++;
                if (rand() % count == 0) {
                    res = i;
                }
            }
        }
        return res;
    }
};

class Solution {
public:
    vector<int> tmp;

    Solution(vector<int>& nums) {
        srand(time(NULL));
        tmp = nums;
    }
    
    int pick(int target) {
        int n = tmp.size();
        int k = rand() % n;
        if(tmp[k] == target) 
            return k;
        return pick(target);
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */