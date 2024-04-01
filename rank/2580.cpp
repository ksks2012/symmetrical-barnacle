#include "include.h"

class Solution {
public:
    #define MOD 1000000007
    vector<vector<int>> merge(vector<vector<int>>& interval) {
        vector<vector<int>> result;
        //base case when threr are no intervals
        if(interval.size() == 0)
            return result;
        //sort takes O(nlogn) time
        sort(interval.begin(), interval.end());
        //insert the the the first interval in the result
        result.push_back(interval[0]);
        int j = 0;
        //Traverse the whole vector .Takes O(n) time
        for(int i = 1; i < interval.size(); i++) {
            //if intevals are overlapping
            if(result[j][1] >= interval[i][0]) 
                result[j][1] = max(result[j][1], interval[i][1]);
            //else they are not overlapping
            else {
                j++;
                result.push_back(interval[i]);
            }
        }
        return result;
    }

    int countWays(vector<vector<int>>& ranges) {
        // merge interval
        vector<vector<int>> merged_ranges = merge(ranges);
        int res = 1;
        int n = merged_ranges.size();

        for(int i = 0; i < n; i++) {
            res = res * 2 % MOD;
        }

        return res;
    }
};

// lee
class Solution {
public:
    #define MOD 1000000007
    int countWays(vector<vector<int>>& ranges) {
        int res = 1, last = -1;
        sort(ranges.begin(), ranges.end());
        for (auto r: ranges) {  
            // identity iterval 
            if (last < r[0])
                res = res * 2 % MOD;
            last = max(last, r[1]);
        }
        return res;
    }
};