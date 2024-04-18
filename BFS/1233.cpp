#include "include.h"

// Using Trie
struct Node{    // data structure for node of trie
    bool is_end = false;
    unordered_map<string, Node*> children;
};
class Trie {
public:
    Node* root;  // root of the tree
    vector<vector<string>> restore;
    Trie() {
        root = new Node();
    }
    
    void insert(vector<string> words) {
        Node* tmp = root;
        for(int i = 0; i < words.size(); i++) {
            string idx = words[i];
            if(tmp->children.find(idx) == tmp->children.end()) {
                tmp->children[idx] = new Node();
            } else if(tmp->children[idx]->is_end == true) {
                return;
            }
            tmp = tmp->children[idx];
        }
        tmp->is_end = true;
        restore.push_back(words);
    }
};
class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        vector<string> res;
        sort(folder.begin(),folder.end());

        Trie *trie = new Trie();

        for(int i = 0; i < folder.size(); i++) {
            vector<string> tmp;
            stringstream ss(folder[i]);
            while (ss.good()) {
                string substr;
                getline(ss, substr, '/');
                tmp.push_back(substr);
            }
            trie->insert(tmp);
        }

        for(int i = 0; i < trie->restore.size(); i++) {
            string tmp = "";
            for(int j = 1; j < trie->restore[i].size(); j++) {
                tmp += "/" + trie->restore[i][j];
            }
            res.push_back(tmp);
        }

        return res;
    }
};


class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(),folder.end());
        vector<string> result;
        for(string &s:folder)
            if(result.empty()                          // Check if 1. This is the first string, 
                || result.back().compare(0, result.back().length(), s, 0, result.back().length()) != 0 // 2. parent at back is not the parent of `s` by comparing.
                || s[result.back().length()] != '/')    // 3. If the entire parent matches `s` check if last folder name in parent does not match the folder of same depth in `s`. for cases like `/a/b, /a/bc`.
                result.push_back(s);                                  
        return result;
    }
};