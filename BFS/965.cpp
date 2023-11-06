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
// Time: O(n), Space: O(n)
class Solution {
public:
    vector<int> values;
    void DFS(TreeNode *root) {
        if(root != nullptr) {
            values.push_back(root->val);
            DFS(root->left);
            DFS(root->right);
        }
    }

    bool isUnivalTree(TreeNode* root) {
        DFS(root);
        for(auto &v : values) {
            if(v != root->val) {
                return false;
            }
        }
        return true;
    }
};

// Time: O(n), Space: O(n)
class Solution {
public:
    bool isUnivalTree(TreeNode* root) {
        queue<TreeNode *> q;
        if(root == nullptr)
            return true;
        q.push(root);

        while(!q.empty()) {
            int q_size = q.size();
            for(int i = 0; i < q_size; i++) {
                TreeNode *top = q.front();
                q.pop();
                if(top->val != root->val)
                    return false;
                if(top->left != nullptr) {
                    q.push(top->left);
                }
                if(top->right != nullptr) {
                    q.push(top->right);
                }
            }
        }
        
        return true;
    }
};

// Solution
// Time: O(n), Space: O(n)
class Solution {
public:
    bool isUnivalTree(TreeNode* root, int val = -1) {
        if (!root) return true;
        if (val < 0) val = root->val;
        return root->val == val && isUnivalTree(root->left, val) && isUnivalTree(root->right, val);
    }
};