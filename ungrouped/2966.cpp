#include "include.h"

class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;

        int tmp = 0;
        int prev = -1;

        vector<int> tmp_ans;
        for(int i = 0; i < nums.size(); ++i) {
            tmp += nums[i];
            tmp_ans.push_back(nums[i]);
            if((i + 1) % 3 == 0) {
                if(prev == -1) {
                    prev = tmp;
                    tmp = 0;
                    tmp_ans = vector<int>();
                    continue;
                }
                if(prev >= 0 && tmp - prev >= k) {
                    ans.push_back(tmp_ans);
                    prev = tmp;
                    tmp = 0;
                    tmp_ans = vector<int>();
                } else {
                    return vector<vector<int>>();
                }
            }
        }
        return ans;
    }
};

class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;

        int tmp = 0;
        int prev = -1;
        
        for(int i = 0; i < nums.size() / 3; ++i) {
            if(nums[3 * i + 2] - nums[3 * i] > k) {
                return vector<vector<int>>();
            } else {
                vector<int> tmp_ans;
                tmp_ans.push_back(nums[3 * i]);
                tmp_ans.push_back(nums[3 * i + 1]);
                tmp_ans.push_back(nums[3 * i + 2] );
                ans.push_back(tmp_ans);
            }
        }
        return ans;
    }
};