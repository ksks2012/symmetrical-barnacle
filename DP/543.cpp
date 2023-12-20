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
    int ans = 0;
    int DFS(TreeNode *node) {
        if(node == nullptr)
            return -1;

        int l_len = DFS(node->left) + 1;
        int r_len = DFS(node->right) + 1;

        ans = max(ans, l_len + r_len);
        return max(l_len, r_len);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        DFS(root);
        return ans;
    }
};