#include "include.h"

class Solution {
public:
    long long minOperations(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();   
        unordered_map<int, int> m;   
        long long inc = 0, dec = 0;
        for (int i = 0; i < n; i++) {
            if(nums1[i] != nums2[i]) {
                int diff = nums1[i] - nums2[i];
                if(k == 0 || abs(diff) % k != 0)
                    return -1;
                
                inc += max(0, (nums1[i] - nums2[i]) / k);
                dec += max(0, (nums2[i] - nums1[i]) / k);
            }              
        }
    
        return inc == dec ? inc : -1;
    }
};