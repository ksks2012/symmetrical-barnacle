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
    bool is_palindromic(int *tmp) {
        int odd = 0;

        for(int i = 0; i < 10; i++) {
            if(tmp[i] % 2 != 0)
                odd++;
        }

        return odd <= 1;
    }

    void DFS(TreeNode* root, int *tmp, int &count) {
        if(root == nullptr)
            return;

        tmp[root->val]++;

        if(root->left == nullptr && root->right == nullptr) {
            if(is_palindromic(tmp))
                count++;
        }

        DFS(root->left, tmp, count);
        DFS(root->right, tmp, count);
        tmp[root->val]--;
    }

    int pseudoPalindromicPaths (TreeNode* root) {
        int tmp[10] = { 0 };
        int count = 0;
        DFS(root, tmp, count);
        return count;
    }
};