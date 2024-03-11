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
    vector<int> DFS(TreeNode* root) {
        if (!root) 
            return { -1, -1, -1};
        vector<int> left = DFS(root->left), right = DFS(root->right);
        int res = max(max(left[1], right[0]) + 1, max(left[2], right[2]));
        return {left[1] + 1, right[0] + 1, res};
    }

    int longestZigZag(TreeNode* root) {
        return DFS(root)[2];
    }
};