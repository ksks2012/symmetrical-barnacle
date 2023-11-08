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
    void DFS(TreeNode* root, int &count, int max_prev) {
        if(root == nullptr)
            return;

        if(root->val >= max_prev) {
            count++;
        }

        max_prev = max(max_prev, root->val);
        DFS(root->left, count, max_prev);
        DFS(root->right, count, max_prev);
    }

    int goodNodes(TreeNode* root) {
        int count = 0;
        DFS(root, count, -10001);
        return count;
    }
};