#include "../include.h"

class Solution {
public:
    int search(std::vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        while(left <= right) {
            int mid = left + (right - left) / 2;
            if(target == nums[mid]) {
                return mid;
            } else if(target < nums[mid]) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return -1;
    }

    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
        int m = aliceSizes.size();
        int n = bobSizes.size();
        vector<int> ans(2, 0);

        int a_sum = 0;
        for(int i = 0; i < m; i++) {
            a_sum += aliceSizes[i];
        }
        int b_sum = 0;
        for(int i = 0; i < n; i++) {
            b_sum += bobSizes[i];
        }
        
        int target = (a_sum - b_sum) / 2;
        sort(aliceSizes.begin(), aliceSizes.end());
        for(int i = 0; i < n; i++) {
            int tmp = search(aliceSizes, bobSizes[i] + target);
            if(tmp != -1) {
                return {aliceSizes[tmp], bobSizes[i]};
            }
        }


        return ans;
    }
};

// lee
class Solution {
public:
    vector<int> fairCandySwap(vector<int> A, vector<int> B) {
        int dif = (accumulate(A.begin(), A.end(), 0) - accumulate(B.begin(), B.end(), 0)) / 2;
        unordered_set<int> S(A.begin(), A.end());
        for (int b: B)
            if (S.count(b + dif))
                return {b + dif, b};
    }
};
