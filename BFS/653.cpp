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
    bool findTarget(TreeNode* root, int k) {
        if(root == nullptr)
            return false;
        if(root->left == nullptr && root->right == nullptr)
            return false;

        map<int, int> m;
        queue <TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            int len = q.size();
            for (int i = 0; i < len; i++) {
                TreeNode *top = q.front();
                m[top->val] = 1;
                q.pop();
                if(top->left != nullptr) {
                    q.push(top->left);
                }
                if(top->right != nullptr) {
                    q.push(top->right);
                }
            }
        }
        for(auto i : m) {
            if (k != i.first * 2 && m.count(k - i.first) != 0)
                return true;
        }
        return false;
    }
};

class Solution {
    bool doesExist(TreeNode* root, int &target){
        if (!root) return false;
        if (root->val == target) return true;
        if (root->val > target) return doesExist(root->left, target);
        else return doesExist(root->right, target);
    }
    bool find(TreeNode* root, TreeNode* cur, int &k) {
        if (!cur) return false;
        int target = k - cur->val;
        if (target != cur->val && doesExist(root, target)) return true;
        return find(root, cur->left, k) || find(root, cur->right, k);
    }
public:
    bool findTarget(TreeNode* root, int k) {
        return find(root, root, k);
    }
};