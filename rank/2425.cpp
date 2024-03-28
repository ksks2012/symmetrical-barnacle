#include "include.h"

// MLE
class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        
        vector<int> tmp;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                tmp.push_back(nums1[i] ^ nums2[j]);
            }
        }


        int res = tmp[0];
        for(int i = 1; i < tmp.size(); i++) {
            res ^= tmp[i];
        }
        return res;
    }
};

class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        int x = 0, y = 0;
        for (int a : nums1)
            x ^= a;
        for (int b : nums2)
            y ^= b;
        return (m % 2 * y) ^ (n % 2 * x);
    }
};

