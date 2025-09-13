#include "include.h"

class Solution {
public:
    bool check(string &a, string &b) {
        int m = a.size();
        int n = b.size();
        
        return a == b.substr(0, m) && a == b.substr(n - m);
    }

    int countPrefixSuffixPairs(vector<string>& words) {
        int n = words.size();

        int ans = 0;
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                if(check(words[i], words[j])) {
                    ans++;
                }
            }
        }
        
        return ans;
    }
};

// Trie solution
struct TrieNode {
    TrieNode* next[26];
    int count = 0;

    TrieNode() { 
        fill(next, next+26, (TrieNode*)NULL); 
    }
};

class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        TrieNode root = TrieNode();
        int ans = 0;
        for (string& s : words) {
            TrieNode* Node = &root;
            int n = s.size();
            for (int i = 0; i < n; i++) {
                // "ac"->(ac)(ca) "acbac"->(ac)(ca)(bb)(ac)(ca)
                int index = s[i] - 'a';
                if (Node->next[index] == 0)
                    Node->next[index] = new TrieNode();
                Node = Node->next[index];

                index = s[n - 1 - i] - 'a';
                if (Node->next[index] == 0)
                    Node->next[index] = new TrieNode();
                Node = Node->next[index];
                ans += Node->count;
            }
            Node->count++;
        }
        return ans;
    }
};