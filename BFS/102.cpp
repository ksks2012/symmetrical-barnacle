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
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        vector<vector<int>> ans;
        
        if(!root)
            return ans;
        
        queue<TreeNode *> q;
        
        q.push(root);
        
        while(!q.empty()) {
            int n = q.size();
            
            vector<int> tmp_ans;
            for(int i = 0; i < n; i++) {
                TreeNode* tmp = q.front();
                q.pop();
                tmp_ans.push_back(tmp->val);
                if(tmp->left)
                    q.push(tmp->left);
                if(tmp->right)
                    q.push(tmp->right);
            }
            ans.push_back(tmp_ans);
        }
        return ans;
    }
};

class Solution {
public:
    // vector<vector<int>> ans;
    void DFS(TreeNode* root, int level, vector<vector<int>> &ans) {
        if(root == nullptr)
            return;
        if(level == ans.size()) {
            ans.push_back({});
        }
        ans[level].push_back(root->val);
        DFS(root->left, level + 1, ans);
        DFS(root->right, level + 1, ans);
    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        DFS(root, 0, ans);
        return ans;
        
    }
};