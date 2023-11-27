#include "include.h"

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if(rowIndex == 0)
            return {1};
        vector<vector<int>> ret;
        ret.push_back(vector<int>(1, 1));
        
        for (int i = 1; i < rowIndex + 1; i++) {
            vector<int> row(i + 1, 1);
            for (int j = 1; j < i; j++) {
                row[j] = ret[i - 1][j] + ret[i - 1][j - 1];
            }
            ret.push_back(row);
        }
        return ret[ret.size() - 1];
    }
};

class Solution {
public:
    std::vector<int> getRow(int rowIndex) {
        std::vector<int> res(1, 1);
        long long prev = 1;
        for(int k = 1; k <= rowIndex; k++) {
            long long next_val = prev * (rowIndex - k + 1) / k;
            res.push_back(next_val);
            prev = next_val;
        }
        return res;
    }
};