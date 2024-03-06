#include "include.h"

// Backtracking
class Solution {
public:
    int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
        int ans = 0;
        int n = students.size();
        vector<int> tmp;
        for(int i = 0; i < n; i++) 
            tmp.push_back(i);

        do {
            int curr = 0;
            for(int i = 0; i < n; i++)
                for(int j = 0; j < students[tmp[i]].size(); j++)
                    curr += (students[tmp[i]][j] == mentors[i][j]);
            ans = max(ans, curr);
        } while(next_permutation(tmp.begin(), tmp.end()));
        return ans;
    }
};