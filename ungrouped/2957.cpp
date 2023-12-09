#include "include.h"

class Solution {
public:
    // string word;

    int DFS(string word, int i) {
        if(i < 0)
            return 0;
        if(abs(word[i] - word[i + 1]) <= 1) {
            word[i] = '#';
            return DFS(word, i - 1) + 1;
        }
        return DFS(word, i - 1);
    }

    int removeAlmostEqualCharacters(string word) {
        int m = word.length();
        return DFS(word, m - 2);
    }
};