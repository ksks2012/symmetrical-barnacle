#include "../include.h"

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> idx(nums1.size(), 0);
        for(int i = 0; i < nums1.size(); i++) {
            idx[i] = find(nums2.begin(), nums2.end(), nums1[i]) - nums2.begin();
        }

        vector<int> res(nums1.size(), -1);
        for(int i = 0; i < nums1.size(); i++) {
            for(int j = idx[i]; j < nums2.size(); j++) {
                if(nums2[j] > nums2[idx[i]]) {
                    res[i] = j;
                    break;
                }
            }
        }

        return res;
    }
};

// Time: O(N)
// Space: O(N)
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> s;
        unordered_map<int, int> m;
        for (int n : nums2) {
            while (s.size() && s.top() < n) {
                m[s.top()] = n;
                s.pop();
            }
            s.push(n);
        }
        vector<int> res;
        for (int n : nums1) 
            res.push_back(m.count(n) ? m[n] : -1);
        return res;
    }
};