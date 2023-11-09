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
    pair<int, TreeNode*> DFS(TreeNode* root) {
        if (!root) return {0, NULL};
        // <level, root>
        pair<int, TreeNode*> l = DFS(root->left);
        pair<int, TreeNode*> r = DFS(root->right);

        int level_left = l.first, level_right = r.first;

        TreeNode *ans;
        if(level_left == level_right)
            ans = root;
        else if (level_left > level_right)
            ans = l.second;
        else
            ans = r.second;

        return {max(level_left, level_right) + 1, ans};
    }

    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        return DFS(root).second;
    }
};