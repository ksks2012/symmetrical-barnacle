#include "include.h"

class Solution {
public:
    int maxOperations(vector<int>& nums) {
        int ans = 0;

        int i = 2;
        int target = 0;
        int maxi = 0;
        for(int j = 0; j < i; j++) {
            target += nums[j];
        }
        for(int j = 0; j < nums.size(); j += i) {
            int tmp = 0;
            if(j + i > nums.size())
                break;
            for(int k = j; k < j + i; k++) {
                tmp += nums[k];
            }
            if(tmp == target) {
                maxi++;
            } else {
                break;
            }
        }
        ans = max(maxi, ans);

        return ans;
    }
};

class Solution {
public:
    int maxOperations(vector<int>& nums) {
        int n = nums.size();
        int target = nums[0] + nums[1];
        int ans = 0;
        for(int i = 0;i < n - 1; i += 2){
            if(target == (nums[i] + nums[i + 1])) 
                ans++;
            else 
                break;
        }
        return ans;
    }
};