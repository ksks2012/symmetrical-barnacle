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

    bool DFS(TreeNode* root, int targetSum, int cur_sum) {
        if(root == nullptr) 
            return false;
        if(root == nullptr && cur_sum != targetSum) 
            return false;
        if(root->left == nullptr && root->right == nullptr && cur_sum + root->val == targetSum)
            return true;

        return DFS(root->left, targetSum, cur_sum + root->val) || DFS(root->right, targetSum, cur_sum + root->val);
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == nullptr)
            return false;
        return DFS(root, targetSum, 0);
    }
};

// Minimize
class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == nullptr)
            return false;
        if(root->left == nullptr && root->right == nullptr && targetSum - root->val == 0)
            return true;
        return hasPathSum(root->left, targetSum - root->val) || hasPathSum(root->right, targetSum - root->val);
    }
};