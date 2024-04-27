#include "include.h"

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
    long res = 0, total = 0, sub;
    int maxProduct(TreeNode* root) {
        total = sum(root), sum(root);
        return res % (int)(1e9 + 7);
    }

    int sum(TreeNode* root) {
        if (!root) 
            return 0;
            
        sub = root->val + sum(root->left) + sum(root->right);
        res = max(res, sub * (total - sub));
        return sub;
    }
};