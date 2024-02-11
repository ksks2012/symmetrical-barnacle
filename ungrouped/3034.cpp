#include "include.h"

class Solution {
public:
    int countMatchingSubarrays(vector<int>& nums, vector<int>& pattern) {
        int m = nums.size();
        int n = pattern.size();
        vector<int> tmp(m, 0);

        for(int i = 1; i < m; i++) {
            if(nums[i] > nums[i - 1]) {
                tmp[i] = 1;
            } else if(nums[i] < nums[i - 1]) {
                tmp[i] = -1;
            }   
        }

        int ans = 0;

        for(int i = 0; i < m - n; i++) {
            int flag = true;
            for(int j = 0; j < n && i + j + 1 < m; j++) {
                if(tmp[i + j + 1] != pattern[j]) {
                    flag = false;
                    break;
                }
            }
            if(flag)
                ans++;
        }

        return ans;
    }
};

static const int _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
class Solution {
public:
    int countMatchingSubarrays(vector<int>& nums, vector<int>& pattern) {
        int m = nums.size();
        int n = pattern.size();

        string s;
        unordered_map<string, int> ma;
        string p;
        for(int i = 0; i < n; i++) {
            if(pattern[i] == 1) {
                p += '2';
            } else if(pattern[i] == -1) {
                p += '0';
            } else {
                p += '1';
            }
        }
        ma[p] = 0;

        int ans = 0;
        for(int i = 1; i < m; i++) {
            if(nums[i] > nums[i - 1]) {
                s += '2';
            } else if(nums[i] < nums[i - 1]) {
                s += '0';
            } else {
                s += '1';
            }
            if(s.size() > n) {
                s = s.substr(1, n);
            }
            if(s.size() == n) {
                if(ma.find(s) != ma.end())
                    ma[s]++;
            }
        }

        return ma[p];
    }
};