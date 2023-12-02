#include "include.h"
class Solution {
private:
    int DFS(unordered_set<string> &words, unordered_map<string, int> &memo, string currentWord) {
        // If the word is encountered previously we just return its value present in the map (memoization).
        if (memo.find(currentWord) != memo.end()) {
            return memo[currentWord];
        }
        // This stores the maximum length of word sequence possible with the 'currentWord' as the
        int maxLength = 1;

        // creating all possible strings taking out one character at a time from the `currentWord`
        for (int i = 0; i < currentWord.length(); i++) {
            string newWord = currentWord.substr(0, i) + currentWord.substr(i + 1);
            // If the new word formed is present in the list, we do a dfs search with this newWord.
            if (words.find(newWord) != words.end()) {
                int currentLength = 1 + DFS(words, memo, newWord);
                maxLength = max(maxLength, currentLength);
            }
        }
        memo[currentWord] = maxLength;

        return maxLength;
    }

public :
    int longestStrChain(vector<string> &words) {
        unordered_map<string, int> memo;
        unordered_set<string> wordsPresent;
        for (const string &word : words) {
            wordsPresent.insert(word);
        }
        int ans = 0;
        for (const string &word : words) {
            ans = max(ans, DFS(wordsPresent, memo, word));
        }
        return ans;
    }
};


class Solution {

public :

    int longestStrChain(vector<string> &words) {
        unordered_map<string, int> dp;

        // Sorting the list in terms of the word length.
        sort(words.begin(), words.end(), [](const string &word1, const string &word2) {
            return word1.size() < word2.size();
        });

        int ans = 1;

        for (const string &word : words) {
            int tmp = 1;
            // Find all possible predecessors for the current word by removing one letter at a time.
            for (int i = 0; i < word.length(); i++) {
                string predecessor = word.substr(0, i) + word.substr(i + 1, word.length() + 1);
                if (dp.find(predecessor) != dp.end()) {
                    int previousLength = dp[predecessor];
                    tmp = max(tmp, previousLength + 1);
                }
            }
            dp[word] = tmp;
            ans = max(ans, tmp);
        }
        return ans;
    }
};

