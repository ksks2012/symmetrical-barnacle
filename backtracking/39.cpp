#include "include.h"

class Solution {
public:
    void back_tracking(vector<int>& candidates, int target, int start, vector<int> path, vector<vector<int>>& res) {
        if (target == 0) {
            res.push_back(path);
            return;
        }
        for(int i = start; i < candidates.size(); i++) {
            if(candidates[i] > target) 
                break;
            path.push_back(candidates[i]);
            back_tracking(candidates, target - candidates[i], i, path, res);
            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        sort(candidates.begin(), candidates.end());
        back_tracking(candidates, target, 0, vector<int>(), res);
        return res;
    }
};