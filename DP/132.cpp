#include "include.h"


class Solution {
public:
    string s;
    int n;
    void isPalindrome(int start, int end, vector<vector<bool>> &pali_memo){
        if(start < 0 || end >= s.size()) 
            return;
        if(s[start] == s[end]) {
            pali_memo[start][end] = 1;
            isPalindrome(start - 1,end + 1, pali_memo);
        }
    }

    int DFS(int i, vector<vector<bool>> &pali_memo, vector<int> &memo) {
        if(i == n)
            return 0;

        int &res = memo[i];
        if(res != -1)
            return res;

        int tmp = INT_MAX;
        for(int k = i; k < n; k++) {
            if(pali_memo[i][k])
                tmp = min(tmp, DFS(k + 1, pali_memo, memo) + 1);
        }

        return res = tmp;
    }

    int minCut(string s) {
        n = s.size();
        this->s = s; 
        vector<vector<bool>> pali_memo(n, vector<bool>(n, false));
        for(int i = 0; i < n; i++){
            isPalindrome(i, i, pali_memo);
            isPalindrome(i, i + 1, pali_memo);
        }
        vector<int> memo(n + 1, -1);
        return DFS(0, pali_memo, memo) - 1;
    }
};