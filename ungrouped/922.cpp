#include "../include.h"

class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {  
        vector<int> odd;
        vector<int> even;
        
        
        for(int num : nums) {
            if(num % 2 == 0)
                even.push_back(num);
            else
                odd.push_back(num);
        }
        
        
        int x = 0;
        int y = 0;
        
        for(int i = 0; i < nums.size(); i++)
            if(i % 2 == 1) {
                nums[i] = odd[x];
                x++;
            } else {
                nums[i] = even[y];
                y++;
            }
                
        return nums;
    }
};

class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int n = nums.size();
        for(int odd = 0, even = 1; odd < n && even < n; ) {
            while(odd < n && nums[odd] % 2 == 0) 
                odd += 2;
            while(even < n && nums[even] % 2 == 1) 
                even += 2;
            if(odd < n && even < n) {
                swap(nums[odd], nums[even]);
            }
        }

        return nums;
    }
};