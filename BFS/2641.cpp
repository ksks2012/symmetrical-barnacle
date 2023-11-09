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
    vector<int> layer_sum;
    void update_sum(TreeNode* root, int sib_sum, int level = 0) {
        if (root == nullptr)
            return;
        root->val = layer_sum[level] - sib_sum;
        sib_sum = 0;
        if(root->left != nullptr)
            sib_sum += root->left->val;
        if(root->right != nullptr)
            sib_sum += root->right->val;
        update_sum(root->left, sib_sum, level + 1);
        update_sum(root->right, sib_sum, level + 1);
    }

    TreeNode* replaceValueInTree(TreeNode* root) {
        // vector<pair<int, TreeNode *>> tmp;
        
        queue<TreeNode *> q;
        int ans = 0;
        if(root == nullptr)
            return root;
        q.push(root);

        while(!q.empty()) {
            int q_size = q.size();
            int tmp = 0;
            for(int i = 0; i < q_size; i++) {
                TreeNode *top = q.front();
                q.pop();
                
                tmp += top->val;
                if(top->left != nullptr) {
                    q.push(top->left);
                }
                if(top->right != nullptr) {
                    q.push(top->right);
                }
            }
            layer_sum.push_back(tmp);
        }

        update_sum(root, root->val);

        return root;
    }
};

class Solution {
public:
    vector<int> layer_sum;
    void level_sum(TreeNode* root, int level = 0) {
        if (root == nullptr)
            return;
        layer_sum.resize(max((int)layer_sum.size(), level + 1));
        layer_sum[level] += root->val;
        level_sum(root->left, level + 1);
        level_sum(root->right, level + 1);
    }

    void update_sum(TreeNode* root, int sib_sum, int level = 0) {
        if (root == nullptr)
            return;
        root->val = layer_sum[level] - sib_sum;
        sib_sum = 0;
        if(root->left != nullptr)
            sib_sum += root->left->val;
        if(root->right != nullptr)
            sib_sum += root->right->val;
        update_sum(root->left, sib_sum, level + 1);
        update_sum(root->right, sib_sum, level + 1);
    }

    TreeNode* replaceValueInTree(TreeNode* root) {        
        level_sum(root);

        update_sum(root, root->val);

        return root;
    }
};