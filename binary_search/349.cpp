#include "include.h"

class Solution {
public:
    bool search(vector<int> nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        while(left <= right) {
            int mid = left + (right - left) / 2;
            if(target == nums[mid]) {
                return true;
            } else if(target < nums[mid]) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return false;
    }

    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());

        unordered_set<int> tmp;
        for(int i = 0; i < nums2.size(); i++) {
            cout << search(nums1, nums2[i]) << endl;
            if(search(nums1, nums2[i])) {
                tmp.insert(nums2[i]);
            }
        }

        return vector<int>(tmp.begin(), tmp.end());
    }
};

// set
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> m(nums1.begin(), nums1.end());
        vector<int> res;
        for (auto a : nums2)
            if (m.count(a)) {
                res.push_back(a);
                m.erase(a);
            }
        return res;
    }
};