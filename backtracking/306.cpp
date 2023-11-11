#include "include.h"

class Solution {
public:
    void backtracking(bool &ans, string& s, int cur_idx, vector<unsigned long long> res) {
        int m = res.size();
        if(cur_idx > s.size())
            return;
        if(ans == true) {
            return;
        }
        if(cur_idx == s.size() && m >= 3) {
            ans = true;
            return;
        }
    
        for(int i = 1; i <= s.size(); i++) {
            // Check remain size
            if(cur_idx + i > s.size())
                return;
            if(m == 0 && i > s.size() / 3 + 1)
                return;
            if(m == 1 && i > (s.size() - cur_idx) / 2)
                return;
            string tmp = s.substr(cur_idx, i);
            if(tmp.size() > 1 && tmp[0] == '0')
                continue;
            auto tmp_num = stoull(tmp);

            if(m >= 2) {
                if(tmp_num == res[m - 1] + res[m - 2]) {
                    res.push_back(tmp_num);
                    backtracking(ans, s, cur_idx + i, res);
                    res.pop_back();
                } else if (tmp_num > res[m - 1] + res[m - 2]) {
                    return;
                }
            } 
            else {
                res.push_back(tmp_num);
                backtracking(ans, s, cur_idx + i, res);
                res.pop_back();
            }    
        }
    }

    bool isAdditiveNumber(string num) {
        bool ans = false;
        backtracking(ans, num, 0, vector<unsigned long long>());
        return ans;
    }
};