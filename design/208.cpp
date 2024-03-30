#include "include.h"

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
    }
    
    bool search(string word) {
        Node* tmp = root;
        for(int i = 0; i < word.size(); i++) {
            int idx = word[i] - 'a';
            if(tmp->children[idx] == NULL) {
                return false;
            }
            tmp = tmp->children[idx];
        }
        return true;
    }
    
    bool startsWith(string prefix) {
        Node* tmp = root;
        for(int i = 0; i < prefix.size(); i++) {
            int idx = prefix[i] - 'a';
            if(tmp->children[idx] == NULL) {
                return false;
            }
            tmp = tmp->children[idx];
        }

        return tmp != NULL;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */