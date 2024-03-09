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
    int pre_order(TreeNode* root, int &moves) {
        if(root == nullptr) 
            return 0;

        int left = pre_order(root->left, moves);
        int right = pre_order(root->right, moves);
        moves += abs(left) + abs(right);
        return root->val + left + right - 1;
    }

    int distributeCoins(TreeNode* root) {
        int moves = 0;
        pre_order(root, moves);
        return moves;
    }
};

// lee
class Solution {
public:
    int distributeCoins(TreeNode* root, TreeNode* parent = nullptr) {
        if (root == nullptr) 
            return 0;
        int res = distributeCoins(root->left, root) + distributeCoins(root->right, root);
        if (parent != nullptr) 
            parent->val += root->val - 1;
        return res + abs(root->val - 1);
    }
};