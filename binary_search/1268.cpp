#include "include.h"

// lee
class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(), products.end());
        int n = searchWord.size();
        vector<vector<string>> ans;

        string cur = "";
        auto it = products.begin();
        for(int i = 0; i < n; i++) {
            cur += searchWord[i];
            vector<string> tmp;
            it = lower_bound(it, products.end(), cur);
            for(int i = 0; i < 3 && it + i != products.end(); i++) {
                string &s = *(it + i);
                if(s.find(cur))
                    break;
                tmp.push_back(s);
            }

            ans.push_back(tmp);
        }

        return ans;
    }
};

// Using Trie
struct Trie {
    unordered_map<char, Trie*> children;
    // Lexographically sorted suggestion till each char 
    vector<string> suggestions;
};

class Solution {
public:

    void insert_trie(Trie* root, string word) {
        for(const char& c: word) {
            if(root->children.find(c) == root->children.end())
                root->children[c] = new Trie();
            root = root->children[c];
            
            // Limit the suggestions to 3
            if(root->suggestions.size() < 3)
                root->suggestions.emplace_back(word);
        }
    }
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        vector<vector<string>> result(searchWord.size());
        sort(begin(products), end(products));
        
        // Create the Trie, since the words are sorted
        // so the suggestions are also lexographically sorted
        Trie *root = new Trie();
        for(const string &word: products)
            insert_trie(root, word);
        
        string prefix;
        for(int i = 0; i < searchWord.size(); i++) {
            auto it = root->children.find(searchWord[i]);
            if(it != root->children.end()) {
                root = it->second;
            }
            else
                break;
            // add suggestions if any for the current char
            result[i] = root->suggestions;
        }
        return result;
    }
};