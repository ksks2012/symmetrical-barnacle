#include "../include.h"

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> m;
        for(int i = 0; i < nums1.size(); ++i) {
            m[nums1[i]]++;
        }
        vector<int> ans;

        for(int i = 0; i < nums2.size(); ++i) {
            if(m[nums2[i]] > 0) {
                m[nums2[i]]--;
                ans.push_back(nums2[i]);
            }
        }

        return ans;
    }
};

// Solution: Binary search
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        //sort nums1 and nums2
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        for(int i = 0; i < nums2.size(); i++) {
            int s = 0, e = nums1.size() - 1, mid, index = e;
            //binary serach to found lower bound
            while(s <= e) {
                mid = s + (e - s) / 2;
                if(nums1[mid] >= nums2[i]) {
                    index = mid;
                    e = mid - 1;
                } else {
                    s = mid + 1;
                }
            }
            //update lower bound element if found
            if(nums1[index] == nums2[i]) {
                ans.push_back(nums2[i]);
                index == 0 ? nums1[index] = -1 : nums1[index] = nums1[index - 1];
            }
        }
        return ans;
    }
};