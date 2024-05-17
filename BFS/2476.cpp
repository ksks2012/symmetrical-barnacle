#include "../include.h"

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> val;
    void traverse(TreeNode* root) {
        if (root != nullptr) {
            traverse(root->left);
            if (val.empty() || val.back() < root->val)
                val.push_back(root->val);
            traverse(root->right);
        }
    }
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        vector<vector<int>> res;
        // tree -> vector
        traverse(root);
        for (int q : queries) {
            // binary search
            auto it = lower_bound(begin(val), end(val), q); 
            if (it != end(val) && *it == q)
                res.push_back({q, q});
            else
                res.push_back({it == begin(val) ? -1 : *prev(it), it == end(val) ? -1 : *it});
        }
        return res;
    }
};
