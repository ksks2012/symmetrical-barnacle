#include "include.h"

class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        set<string> st(dictionary.begin(), dictionary.end());
        string word, res;
        stringstream ss(sentence);
        while(ss >> word) {
            string str;
            bool flag = false;
            for(char ch : word) {
                str += ch;
                if(st.count(str)) {
                    flag = true;
                    break;
                }
            }
            res += (flag ? str : word);
            res += " ";
        }
        res.pop_back();
        return res;
    }
};


// Trie
struct Node{    // data structure for node of trie
    bool isEnd = false;
    Node* children[26] = {NULL};
};

class Trie {
public:
    Node* root;  // root of the tree
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* tmp = root;
        for(int i = 0; i < word.size(); i++) {
            int idx = word[i] - 'a';
            if(tmp->children[idx] == NULL) {
                tmp->children[idx] = new Node();
            }
            tmp = tmp->children[idx];
        }
        tmp->isEnd = true;
    }

    string replace(const string& word) {
        Node* tmp = root;
        string res = "";
        for (char c : word) {
            cout << c << endl;
            if (tmp->children[c - 'a'] == NULL)
                return word;
            tmp = tmp->children[c - 'a'];
            res += c;
            if (tmp->isEnd == true)
                return res;
        }
        return word;
    }
};

class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        Trie trie;
        for(string word : dictionary) {
            trie.insert(word);
        }

        string res = "";
        istringstream iss(sentence);
        string word;
        while (iss >> word) {
            if (!res.empty()) 
                res += " ";
            res += trie.replace(word);
        }
        
        return res;
    }
};
