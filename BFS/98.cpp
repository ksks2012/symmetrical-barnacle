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
// preorder
class Solution {
public:
    bool isValidBST(TreeNode* root, long left=LONG_MIN, long right=LONG_MAX) {
        if(root == nullptr)
            return true;
        int x = root->val;
        return left < x && x < right && isValidBST(root->left, left, x) && isValidBST(root->right, x, right);
    }
};

// inorder 
class Solution {
public:
    long pre = LONG_MIN;
    bool isValidBST(TreeNode* root) {
        if(root == nullptr)
            return true;
        if(!isValidBST(root->left))
            return false;
        if(root->val < pre)
            return false;
        pre = root->val;
        return isValidBST(root->right);
    }
};

// postorder 
class Solution {
public:
    pair<long, long> DFS(TreeNode* root) {
        if(root == nullptr)
            return {LONG_MAX, LONG_MIN};
        auto[left_min, left_max] = DFS(root->left);
        auto[right_min, right_max] = DFS(root->right);
        long x = root->val;
        if (x <= left_max || x >= right_min)
            return {LONG_MIN, LONG_MAX};
        return {min(left_min, x), max(right_max, x)};
    }

    bool isValidBST(TreeNode* root) {
        return DFS(root).second != LONG_MAX;
    }
};