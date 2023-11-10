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
    int maxLevelSum(TreeNode* root) {
          int ans = -1;
          int level = 0;
          int maxSum = INT_MIN;
          queue<TreeNode*> q;

          q.push(root);

          while(!q.empty()){
                level++;
                int q_size = q.size();
                int temp = 0;

                // finding the sum of node values at the current level
                for(int i=  0; i < q_size; i++){
                    TreeNode* top = q.front();
                    q.pop();
                    temp += top->val;
                    if(top->left)
                        q.push(top->left);

                    if(top->right)
                        q.push(top->right); 
                }

                if(temp > maxSum){
                    ans = level;
                    maxSum = temp;
                }
          }
        
        return ans;
    }
};