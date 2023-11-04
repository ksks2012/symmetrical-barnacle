#include "../include.h"

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// Time: O(n), Space: O(n)
class Solution {
public:
    void inorder(TreeNode* node, int level, int &max_level) {
        if(node == nullptr)
            return;
        max_level = max(level, max_level);

        if(node->left != nullptr) {
            inorder(node->left, level + 1, max_level);
        }
        if(node->right != nullptr) {
            inorder(node->right, level + 1, max_level);
        }
    }
    
    int maxDepth(TreeNode* root) {
        int ans = 0;
        inorder(root, 1, ans);
        return ans;
    }
};