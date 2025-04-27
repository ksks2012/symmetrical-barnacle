#include "include.h"

class Solution {
public:
    string longestWord(vector<string>& words) {
        string res = "";
        int maxi_len = 0;
        unordered_set<string> s(words.begin(), words.end());
        queue<string> q;
        for (string word : words) {
            if (word.size() == 1) q.push(word);
        }
        while (!q.empty()) {
            string tmp = q.front(); q.pop();
            if (tmp.size() > maxi_len) {
                maxi_len = tmp.size();
                res = tmp;
            } else if (tmp.size() == maxi_len) {
                res = min(res, tmp);
            }
            for (char c = 'a'; c <= 'z'; ++c) {
                tmp.push_back(c);
                if (s.count(tmp)) q.push(tmp);
                tmp.pop_back();
            }
        }
        return res;
    }
};

// Trie
class TrieNode{
public:
    unordered_map<char, TrieNode*> children;
    bool isWord = false;
    char val;
    
    TrieNode(){}
    
    TrieNode(char v){ this->val = v; }
};

class Trie{
private:
    TrieNode* root;
public:
    Trie(){
        root = new TrieNode();
    }
    
    void insert(string word){
        TrieNode* temp = root;
        
        for(char ch : word){
            if(temp->children.find(ch) == temp->children.end()){
                temp->children[ch] = new TrieNode(ch);
            }
            temp = temp->children[ch];
        }
        
        temp->isWord = true;
    }
    
    bool isOrdered(string word){
        TrieNode* temp = root;
        
        for(char ch : word){
            if(temp == root || temp->isWord){
                temp = temp->children[ch];
                continue;
            }
            return false;
        }
        
        return true;
    }
};

class Solution {
public:
    string longestWord(vector<string>& words) {
        Trie* search = new Trie();
        string res = "";
        int size = 0;
        
        for(string str : words){
            search->insert(str);
        }
        
        for(string str : words){
            if(search->isOrdered(str) && size <= str.size()){
                res = (size == str.size()) ? min(res, str) : str;
                size = str.size();
            }
        }
        
        return res;
    }
};