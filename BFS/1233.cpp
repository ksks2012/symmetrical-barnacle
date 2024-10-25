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
        vector<string> res;
        for(string &s:folder)
            if(res.empty()                          // Check if 1. This is the first string, 
                || res.back().compare(0, res.back().length(), s, 0, res.back().length()) != 0 // 2. parent at back is not the parent of `s` by comparing.
                || s[res.back().length()] != '/')    // 3. If the entire parent matches `s` check if last folder name in parent does not match the folder of same depth in `s`. for cases like `/a/b, /a/bc`.
                res.push_back(s);                                  
        return res;
    }
};

// Set
class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        unordered_set<string> folderSet(folder.begin(), folder.end());
        vector<string> res;

        for (string& f : folder) {
            bool is_sub_folder = false;
            string prefix = f;

            // Check all prefixes of the current folder path
            while (!prefix.empty()) {
                size_t pos = prefix.find_last_of('/');
                if (pos == string::npos) 
                    break;

                // Reduce the prefix to its parent folder
                prefix = prefix.substr(0, pos);

                // If the parent folder exists in the set, mark as sub-folder
                if (folderSet.count(prefix)) {
                    is_sub_folder = true;
                    break;
                }
            }

            // If not a sub-folder, add it to the res
            if (!is_sub_folder) {
                res.push_back(f);
            }
        }

        return res;
    }
};