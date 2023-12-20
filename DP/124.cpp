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
    int ans = INT_MIN;
    int DFS(TreeNode *node) {
        if(node == nullptr)
            return 0;

        int l_len = DFS(node->left);
        int r_len = DFS(node->right);

        ans = max(ans, l_len + r_len + node->val);
        return max(max(l_len, r_len) + node->val, 0);
    }

    int maxPathSum(TreeNode* root) {
        DFS(root);
        return ans;
    }
};