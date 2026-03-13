#include "include.h"

class Solution {
private:
    unordered_map<char, string> digitToLetters = {
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"}
    };

public:
    void backtrack(string digits, int index, string current, vector<string>& res) {
        if (index == digits.size()) {
            res.push_back(current);
            return;
        }
        char digit = digits[index];
        if (digitToLetters.count(digit)) {
            for (char letter : digitToLetters[digit]) {
                backtrack(digits, index + 1, current + letter, res);
            }
        }
    }

    vector<string> letterCombinations(string digits) {

        vector<string> res;

        backtrack(digits, 0, "", res);

        return res;
    }
};