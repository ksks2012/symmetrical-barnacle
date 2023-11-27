#include "include.h"

class Solution {
public:
    vector<long long> backtracking(long long finalSum, long long cur, vector<long long> result, set<long long> s) {
        s.insert(cur);
        int tmp = cur;
        while(cur < finalSum || s.find(cur) != s.end())
            tmp += 2;

        if(s.find(finalSum - cur) != s.end())
            backtracking(finalSum - cur, tmp, result, s);

        return result;
    }

    vector<long long> maximumEvenSplit(long long finalSum) {
        set<long long> s;
        vector<long long> result; 
        if(finalSum % 2 != 0) {
            return result;
        }
        result = backtracking(finalSum, 2, result, s);
        return result;
    }
};

class Solution {
public:
    vector<long long> maximumEvenSplit(long long sum) {
        vector<long long> res;
        for (int cur = 2; sum % 2 == 0 && sum > 0; cur += 2) {
            if (sum - cur < cur + 2)
                res.push_back(sum);
            else
                res.push_back(cur);        
            sum -= res.back();
        }
        return res;
    }
};