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

// 2 DFS
class Solution {
public:
    int max_depth;
    int deepestLeavesSum(TreeNode* root) {
        max_depth = find_deep(root);
        return sum_deep(root, 0);
    }
    
    int sum_deep(TreeNode* root, int depth) {
        if(!root) return 0;
        if(depth==max_depth-1) return root->val;
        return sum_deep(root->left, depth+1) +
            sum_deep(root->right, depth+1);
    
    }

    int find_deep(TreeNode* root) {
        if(!root) return 0;
        return max(1 + find_deep(root->left), 1 + find_deep(root->right));
    }
};

class Solution {
public:
    map<int, int> layer_sum;
    int deepestLeavesSum(TreeNode* root) {
        sum_layer(root, 0);

        int ans = 0;
        for(auto m : layer_sum) {
            ans = m.second;
        }
        return ans;
    }

    void sum_layer(TreeNode* root, int level) {
        if(root == nullptr) 
            return;
        layer_sum[level] += root->val;
        sum_layer(root->left, level + 1);
        sum_layer(root->right, level + 1);        
    }
};