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
    vector<int> largestValues(TreeNode* root) {
        vector<int> ans;
        
        if(root == NULL)
            return ans;
        
        queue<TreeNode*> q;
        
        q.push(root);

        while(!q.empty()) {
            int n = q.size();
            int maxR = INT_MIN;
            
            for(int i = 0; i < n; i++) {  
                TreeNode *tmp = q.front();
                q.pop();
                if(tmp->left)
                    q.push(tmp->left);
                if(tmp->right)
                    q.push(tmp->right);
                maxR = max(maxR, tmp->val);
            }
            ans.push_back(maxR);
        }
        return ans;
    }
};

class Solution {
public:
    void DFS(TreeNode* root, int level, vector<int> &ans) {
        if(root == nullptr) 
            return;
        
        if(level == ans.size()) 
            ans.push_back(root -> val);
        ans[level] = max(ans[level], root -> val);
        
        DFS(root -> left, level + 1, ans);
        DFS(root -> right, level + 1, ans);
    }
    
    vector<int> largestValues(TreeNode* root) {
        vector<int> ans;
        DFS(root, 0, ans);
        return ans;
    }
};
