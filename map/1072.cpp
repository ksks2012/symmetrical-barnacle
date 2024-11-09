#include "include.h"

class Solution {
public:
    int maxEqualRowsAfterFlips(const vector<vector<int>>& A) {
        unordered_map<string, int> pattern_count;
        
        for (const auto& row : A) {
            string pattern;
            int first = row[0];
            
            for (int x : row) {
                pattern += (x ^ first) ? '1' : '0';  // XOR with the first element to normalize
            }
            
            pattern_count[pattern]++;
        }
        
        int res = 0;
        for (const auto& p : pattern_count) {
            res = max(res, p.second);
        }
        
        return res;
    }
};