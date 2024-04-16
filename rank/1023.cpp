#include "include.h"

// Trie
class Trie {
public:
    Trie* child[58];
    bool isEnd;
    Trie() {
        isEnd = false;
        for(int i = 0; i < 58; i++)
            child[i]=NULL;
    }
};
class Solution {
public:
    void insert_trie(Trie *trie, const string &s) {
        Trie *ptr = trie;
        int n = s.size();

        for(int i = 0; i < n; i++) {
            int idx = s[i] - 'A';
            if(ptr->child[idx] == NULL)
                ptr->child[idx] = new Trie();
            ptr = ptr->child[idx];
        }
        ptr->isEnd = true;
    }

    bool find_trie(Trie *trie, const string &s) {
        Trie *ptr = trie;
        int n = s.size();
        for(int i = 0; i < n; i++) {
            int idx = s[i] - 'A';
            if(s[i] >= 'A' && s[i]<= 'Z' && ptr->child[idx] == NULL) {
                return false;
            } else if (ptr->child[idx] != NULL) {
                ptr = ptr->child[idx];
            }
        }
        return ptr->isEnd;
    }

    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        Trie *trie = new Trie();
        insert_trie(trie, pattern);

        vector<bool> res(queries.size(), false);
        for(int i = 0; i < queries.size(); i++) {
            res[i] = find_trie(trie, queries[i]);
        }

        return res;
    }
};

// Two points
class Solution {
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector<bool> res(queries.size());
        for(int i = 0; i < queries.size(); i++) {
            string query = queries[i];
            int j = 0;
            bool flag = true;
            for(int k = 0; k < query.size(); k++) {
                if(j < pattern.size() && query[k] == pattern[j]) {
                    j++;
                } else if(query[k] >= 'A' && query[k] <= 'Z') {
                    flag = false;
                    break;
                }
            }
            if(j < pattern.size()) {
                flag = false;
            }
            res[i] = flag;
        }

        return res;
    }
};