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
    vector<TreeNode*> sorted_arr;
    TreeNode* balanceBST(TreeNode* root) {
        inorder(root);
        return sorted_array_to_BST(0, sorted_arr.size() - 1);
    }
    void inorder(TreeNode* root) {
        if (root == NULL) return;
        inorder(root->left);
        sorted_arr.push_back(root);
        inorder(root->right);
    }
    TreeNode* sorted_array_to_BST(int start, int end) {
        if (start > end) return NULL;
        int mid = (start + end) / 2;
        TreeNode* root = sorted_arr[mid];
        root->left = sorted_array_to_BST(start, mid - 1);
        root->right = sorted_array_to_BST(mid + 1, end);
        return root;
    }
};