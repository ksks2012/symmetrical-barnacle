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

// Vlad
class Solution {
public:
    vector<int> findIntersectionValues(vector<int>& n1, vector<int>& n2) {
        unordered_set<int> s1(begin(n1), end(n1)), s2(begin(n2), end(n2));
        return {
            (int)count_if(begin(n1), end(n1), [&](int n){ return s2.count(n); }),
            (int)count_if(begin(n2), end(n2), [&](int n){ return s1.count(n); })
        };
    }
};