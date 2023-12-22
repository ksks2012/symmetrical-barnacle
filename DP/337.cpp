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

    pair<int, int> DFS(TreeNode *root) {
        if(root == nullptr)
            return {0, 0};

        auto [l_rob, l_not_rob] = DFS(root->left);
        auto [r_rob, r_not_rob] = DFS(root->right);
        int rob = l_not_rob + r_not_rob + root->val;
        int not_rob = max(l_rob, l_not_rob) + max(r_rob, r_not_rob);
        return {rob, not_rob};
    }

    int rob(TreeNode* root) {
        auto [root_rob, root_not_rob] = DFS(root);
        return max(root_rob, root_not_rob);
    }
};