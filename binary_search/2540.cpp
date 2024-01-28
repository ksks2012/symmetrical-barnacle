#include "../include.h"

class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        set<int> s;

        for(auto n : nums1) {
            s.insert(n);
        }
        for(auto n : nums2) {
            if(s.find(n) != s.end())
                return n;
        }

        return -1;
    }
};

class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int p1 = 0, p2 = 0;
        while(p1 < size(nums1) && p2 < size(nums2)) {
            if(nums1[p1] < nums2[p2])
                p1++;
            else if(nums1[p1] > nums2[p2]) 
                p2++;
            else 
                return nums1[p1];
        }
        return -1;
    }
};

// TLE
class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        for(auto n : nums2) {
            vector<int>::iterator it = find(nums1.begin(), nums1.end(), n);
            if (it != nums1.end())
                return n;
        }

        return -1;
    }
};