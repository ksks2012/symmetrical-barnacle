#include "include.h"

class Solution {
public:
    using ll=long long int;
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int maxlen = 0;        
        vector<int> dp(nums2.size() + 1,0);
        
        //Iterate through first 
        for(int i = 0; i < nums1.size(); i++) {
            //Temporary to track the state of this level.
            vector<int> tmp(nums2.size() + 1, 0);
            
            for(int j = 1; j <= nums2.size(); j++) {
                
                //Only if current numbers are matching.
                if(nums1[i] == nums2[j - 1]) {                    
                    tmp[j] = dp[j - 1] + 1;   // + 1 for current and anything we got from prev state.
                    maxlen = max(maxlen, tmp[j]);
                }                
            }             
            //Make the temp state as new state for next level.
            dp = tmp;
        }
        return maxlen;
    }
};

class Solution {
public:
    int maxLen(vector<int>& nums1, int i, vector<int>& nums2, int j, int len) {
        int count = 0, maxi = 0;

        for(int k = 0; k < len; k++) {
            if(nums1[i + k] == nums2[j + k]) {
                count++;
            } else if(count > 0) {
                maxi = max(maxi, count);
                count = 0;
            }
        }
        return count > 0 ? max(maxi, count) : maxi;
    }

    int findMax(vector<int>& nums1, vector<int>& nums2) {
        int maxi = 0;
        int m = nums1.size();
        int n = nums2.size();

        /*
        A:           |*|*|*|*|
        B: |*|*|*|*|*|*|
                 ↓
        A:       |*|*|*|*|
        B: |*|*|*|*|*|*|
         */
        for(int i = 1; i <= m; i++) {
            maxi = max(maxi, maxLen(nums1, 0, nums2, n - i, i));
        }

         /*
        A:     |*|*|*|*|
        B: |*|*|*|*|*|*|
                 ↓
        A: |*|*|*|*|
        B: |*|*|*|*|*|*|
         */
        for(int j = n - m; j >= 0; j--) {
            maxi = max(maxi, maxLen(nums1, 0, nums2, j, m));
        }

        /*
        A: |*|*|*|*|
        B:   |*|*|*|*|*|*|
                 ↓
        A: |*|*|*|*|
        B:       |*|*|*|*|*|*|
         */
        for(int i = 1; i < m; i++) {
            maxi = max(maxi, maxLen(nums1, i, nums2, 0, m - i));
        }

        return maxi;
    }

    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();

        return m < n ? findMax(nums1, nums2): findMax(nums2, nums1);
    }
};