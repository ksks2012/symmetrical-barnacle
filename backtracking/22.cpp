#include "include.h"

class Solution {
public:

    void backtracing(vector<string> &ans, int left, int right, string cur) {
        if(left == 0 && right == 0) {
            ans.push_back(cur);
        }
        
        if(left != 0) {
            backtracing(ans, left - 1, right, cur + '(');
        }
        if(right != 0 && left < right) {
            backtracing(ans, left, right - 1, cur + ')');
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;

        int left = n;
        int right = n;

        backtracing(ans, left - 1, right, "(");
        
        return ans;
    }
};

//dp[0] = ""
//dp[i]='('+ dp[k]+')'+dp[i-1-k],k=0..i-i
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector< vector<string> > dp(n + 1, vector<string>());
        dp[0].push_back("");
        for(int i = 1; i <= n; ++i){
            for(int k = 0; k < i; ++k){
                for(string s1: dp[k]){
                    for(string s2: dp[i - 1 - k])
                        dp[i].push_back("(" + s1 + ")" + s2);
                }
            }
        }
        return dp[n];
    }
};