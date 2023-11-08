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
    int deepestLeavesSum(TreeNode* root) {
        queue<TreeNode *> q;
        int ans = 0;
        if(root == nullptr)
            return ans;
        q.push(root);

        while(!q.empty()) {
            ans = 0;
            int q_size = q.size();
            for(int i = 0; i < q_size; i++) {
                TreeNode *top = q.front();
                ans += top->val;
                q.pop();
                if(top->left != nullptr) {
                    q.push(top->left);
                }
                if(top->right != nullptr) {
                    q.push(top->right);
                }
            }
        }
        return ans;
    }
};