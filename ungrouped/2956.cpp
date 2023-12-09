#include "include.h"

class Solution {
public:
    vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {
        std::unordered_set<int> set1(nums1.begin(), nums1.end());
        std::unordered_set<int> set2(nums2.begin(), nums2.end());

        // Count occurrences of elements from nums1 in nums2
        int count1_in_2 = 0;
        for (int num : nums1) {
            if (set2.count(num) > 0) {
                count1_in_2++;
            }
        }

        // Count occurrences of elements from nums2 in nums1
        int count2_in_1 = 0;
        for (int num : nums2) {
            if (set1.count(num) > 0) {
                count2_in_1++;
            }
        }

        return {count1_in_2, count2_in_1};

    }
};