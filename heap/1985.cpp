#include "include.h"

class Solution {
public:
    struct cmp {
        bool operator() (string& a, string& b) {
            if(a.size() == b.size())
                return a > b;
            else
                return a.size() > b.size();
        }
    };
    
    string kthLargestNumber(vector<string>& nums, int k) {
        priority_queue<string, vector<string>, cmp> pq;

        for (string& num : nums) {
            pq.push(num);
            if (pq.size() > k) {
                pq.pop();
            }
        }

        return pq.top();
    }
};

class Solution {
public:
    static bool cmp(string &a, string &b) {
        if(a.size() == b.size()) {
            return a < b;
        }
        return a.size() < b.size();
    }

    string kthLargestNumber(vector<string>& nums, int k) {
        sort(nums.begin(), nums.end(), cmp);
        int n = nums.size();
        return nums[n - k];
    }
};