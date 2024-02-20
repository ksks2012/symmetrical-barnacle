#include "include.h"

// endlesscheng
// KMP algorithm
class Solution {
public:
    int countMatchingSubarrays(vector<int> &nums, vector<int> &pattern) {
        int m = pattern.size();
        vector<int> pi(m);
        int cnt = 0;
        for (int i = 1; i < m; i++) {
            int v = pattern[i];
            while (cnt && pattern[cnt] != v) {
                cnt = pi[cnt - 1];
            }
            if (pattern[cnt] == v) {
                cnt++;
            }
            pi[i] = cnt;
        }

        int ans = 0;
        cnt = 0;
        for (int i = 1; i < nums.size(); i++) {
            int x = nums[i - 1], y = nums[i];
            int v = (y > x) - (y < x);
            while (cnt && pattern[cnt] != v) {
                cnt = pi[cnt - 1];
            }
            if (pattern[cnt] == v) {
                cnt++;
            }
            if (cnt == m) {
                ans++;
                cnt = pi[cnt - 1];
            }
        }
        return ans;
    }
};

// endlesscheng
// Z-function
class Solution {
public:
    int countMatchingSubarrays(vector<int> &nums, vector<int> &pattern) {
        int m = pattern.size();
        pattern.push_back(2);
        for (int i = 1; i < nums.size(); i++) {
            int x = nums[i - 1], y = nums[i];
            pattern.push_back((y > x) - (y < x));
        }

        int n = pattern.size();
        vector<int> z(n);
        int l = 0, r = 0;
        for (int i = 1; i < n; i++) {
            if (i <= r) {
                z[i] = min(z[i - l], r - i + 1);
            }
            while (i + z[i] < n && pattern[z[i]] == pattern[i + z[i]]) {
                l = i;
                r = i + z[i];
                z[i]++;
            }
        }

        int ans = 0;
        for (int i = m + 1; i < n; i++) {
            ans += z[i] == m;
        }
        return ans;
    }
};

// TLE
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