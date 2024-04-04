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
    
    
    bool DFS(TreeNode* root, string &s, int& target) {
        if(root->val == target) {
            return true;
        }
        if(root->left && DFS(root->left, s, target)) {
            s.push_back('L');
        } else if(root->right && DFS(root->right, s, target)) {
            s.push_back('R');
        }

        return !s.empty();
    }
    
    string getDirections(TreeNode* root, int startValue, int destValue) {
        string start = "";
        string dest = "";
        DFS(root, start, startValue);
        DFS(root, dest, destValue); 

        while (!start.empty() && !dest.empty() && start.back() == dest.back()) {
            start.pop_back();
            dest.pop_back();
        }
        string res = "";
        res += string(start.size(), 'U');
        res += string(rbegin(dest), rend(dest));

        return res;    
    }
};