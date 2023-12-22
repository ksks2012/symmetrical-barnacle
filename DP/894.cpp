#include "include.h"

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    unordered_map<int, vector<TreeNode*>> storage;
    vector<TreeNode*> allPossibleFBT(int n) {
        if (n % 2 == 0) 
            return {};
        if (n == 1) 
            return { new TreeNode(0) };
        if (storage.count(n)) 
            return storage[n];

        vector<TreeNode*> res;
        for (int i = 1; i < n; i += 2) {
            vector<TreeNode*> left = allPossibleFBT(i), right = allPossibleFBT(n - i - 1);
            for (auto a : left) {
                for (auto b : right) {
                    TreeNode *cur = new TreeNode(0);
                    cur->left = a;
                    cur->right = b;
                    res.push_back(cur);
                }
            }
        }
        return storage[n] = res;
    }
};