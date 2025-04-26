#include "include.h"

// Using Trie to solve the problem
class TrieNode {
public:
    TrieNode* children[26];
    int count;

    TrieNode() {
        count = 0;
        for (int i = 0; i < 26; ++i)
            children[i] = nullptr;
    }
};
class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode();
    }

    void insert(const string& word) {
        TrieNode* node = root;
        for (char ch : word) {
            int idx = ch - 'a';
            if (!node->children[idx])
                node->children[idx] = new TrieNode();
            node = node->children[idx];
            node->count++;
        }
    }

    string getCommonPrefix(int totalWords) {
        string prefix;
        TrieNode* node = root;
        while (true) {
            int next = -1;
            for (int i = 0; i < 26; ++i) {
                if (node->children[i]) {
                    if (node->children[i]->count == totalWords) {
                        next = i;
                        break;
                    } else {
                        return prefix;
                    }
                }
            }
            if (next == -1) break;
            prefix += (char)(next + 'a');
            node = node->children[next];
        }
        return prefix;
    }
};
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";

        Trie trie;
        for (const string& word : strs) {
            trie.insert(word);
        }

        return trie.getCommonPrefix(strs.size());
    }
};
    
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string& tmp = strs[0];
        for (int j = 0; j < tmp.size(); j++) {
            for (string& s : strs) {
                if (j == s.size() || s[j] != tmp[j]) {
                    return tmp.substr(0, j);
                }
            }
        }
        return tmp;
    }
};