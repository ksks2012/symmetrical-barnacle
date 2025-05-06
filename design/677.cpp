#include "../include.h"

class MapSum {
public:
    unordered_map<string,int> mp;
    MapSum() {
        mp["0"] = {};
    }
    
    void insert(string key, int val) {
        mp[key] = val;
    }
    
    int sum(string prefix) {
        int res = 0;
        for(auto i : mp){
            if(prefix.compare(i.first.substr(0,prefix.size())) == 0)
                res += i.second;
        }
        return res;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */

class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    int value;
    bool isEnd;

    TrieNode() : value(0), isEnd(false) {}
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode();
    }

    void insert(const string& key, int val) {
        TrieNode* node = root;
        for (char ch : key) {
            if (!node->children.count(ch)) {
                node->children[ch] = new TrieNode();
            }
            node = node->children[ch];
        }
        node->isEnd = true;
        node->value = val;
    }

    int sum(const string& prefix) {
        TrieNode* node = root;
        for (char ch : prefix) {
            if (!node->children.count(ch)) {
                return 0; // Prefix not found
            }
            node = node->children[ch];
        }
        return dfs(node);
    }

    int dfs(TrieNode* node) {
        int total = node->value;
        for (auto& pair : node->children) {
            total += dfs(pair.second);
        }
        return total;
    }
};

class MapSum {
public:
    Trie *root;
    MapSum() {
        root = nullptr;
    }
    
    void insert(string key, int val) {
        if(root == nullptr) {
            root = new Trie();
        }
        root->insert(key, val);
    }
    
    int sum(string prefix) {
        int res = 0;
        if(root == nullptr) {
            return res;
        }
        res = root->sum(prefix);
        return res;
    }
};
