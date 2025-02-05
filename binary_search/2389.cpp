#include "include.h"

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int res = -1;
        int left = 0;
        int right = nums.size() - 1;
        while(left <= right) {
            int mid = left + (right - left) / 2;
            if(nums[mid] == target) {
                return mid + 1;
            }
            if(nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return left;
    }

    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        vector<int> ps(n, 0);
        int tmp = 0;
        for(int i = 0; i < n; i++) {
            tmp += nums[i];
            ps[i] = tmp;
        }

        vector<int> ans;
        for(int i = 0; i < queries.size(); i++) {
            ans.push_back(search(ps, queries[i]));
        }

        return ans;      
    }
};


class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        vector<int> ps(n, 0);
        int tmp = 0;
        for(int i = 0; i < n; i++) {
            tmp += nums[i];
            ps[i] = tmp;
        }

        vector<int> ans;
        for(int i = 0; i < queries.size(); i++) {
            ans.push_back(upper_bound(ps.begin(), ps.end(), queries[i]) - ps.begin());
        }

        return ans;      
    }
};