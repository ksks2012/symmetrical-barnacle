#include "../include.h"

class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int res = 0;
        int n = nums.size();

        for(int right = 0, k = 0; right < n; k++) {
            int left = right;
            while(right < n && nums[right] == nums[left]) {
                right++;
            }
            res += (right - left) * k;
        }

        return res;
    }
};

class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        //分组循环
        sort(nums.begin(),nums.end());
        int ans=0,k=0,n=nums.size(),i=0;
        while(i<n){
            int j=i;
            while(i<n&&nums[i]==nums[j])    i++;
            ans+=(i-j)*k;
            k++;
        }
        return ans;
    }
};