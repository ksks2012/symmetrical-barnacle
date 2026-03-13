#include "include.h"

class Solution {
private:
    const vector<string> digitToLetters = {
        "",    "",    "abc",  "def", "ghi",
        "jkl", "mno", "pqrs", "tuv", "wxyz"
    };

public:
    void backtrack(const string& digits, int index, string& path, vector<string>& res) {
        if (index == digits.size()) {
            res.emplace_back(path);
            return;
        }

        char digit = digits[index];
        int d = digit - '0';

        if (d < 2 || d > 9) {
            backtrack(digits, index + 1, path, res);
            return;
        }

        for (char c : digitToLetters[d]) {
            path.push_back(c);
            backtrack(digits, index + 1, path, res);
            path.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if (digits.empty()) return res;

        string path = "";
        backtrack(digits, 0, path, res);
        return res;
    }
};