#include "include.h"

// DFS
// Time Complexity: O(2^M)
// Space Complexity: O(M)
class Solution {
public:
    bool is_unique(const string& str) {
        unordered_set<char> s;
        for(char c: str) {
            if(s.count(c)) {
                return false;
            }
            s.insert(c);
        }
        return true;
    }

    void DFS(const vector<string>& arr, const string& path, int idx, int& res) {
        // Update result
        if (is_unique(path)) {
            res = max(res, static_cast<int>(path.length()));
        }

        // Termination Conditions
        if (idx == arr.size() || !is_unique(path)) {
            return;
        }

        // Find next string
        for (int i = idx; i < arr.size(); i++) {
            DFS(arr, path + arr[i], i + 1, res);
        }
    }

    int maxLength(vector<string>& arr) {
        int res = 0;
        DFS(arr, "", 0, res);
        return res;
    }
};

// Bit Operation
// lancertech6
// Time Complexity: O(N * M)
// Space Complexity: O(2^M)
class Solution {
public:
    int maxLength(vector<string>& arr) {
        vector<int> dp = {0};
        int res = 0;
        
        for (const string& s : arr) {
            int a = 0, dup = 0;
            for (char c : s) {
                dup |= a & (1 << (c - 'a'));
                a |= 1 << (c - 'a');
            }
            
            if (dup > 0)
                continue;
            
            for (int i = dp.size() - 1; i >= 0; i--) {
                if ((dp[i] & a) > 0)
                    continue;
                dp.push_back(dp[i] | a);
                res = max(res, __builtin_popcount(dp[i] | a));
            }
        }
        
        return res;
    }
};