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
    unordered_map<TreeNode*, TreeNode*> parentMap;
    TreeNode *start_node;
    void DFS(TreeNode* root, TreeNode* prev, int start) {
        if(root!=NULL) {
            if(root->val == start) {
                start_node = root;
            }
            parentMap[root] = prev;
            DFS(root->left, root, start);
            DFS(root->right, root, start);
        }
    }

    int amountOfTime(TreeNode* root, int start) {
        parentMap = unordered_map<TreeNode*, TreeNode*>();
        DFS(root, NULL, start);
        
        queue<TreeNode*> q;
        unordered_set<TreeNode*> visited;
        q.push(start_node);
        int cur_dist = 0;
        while(!q.empty()) {
        
            int q_size = q.size();
            for(int i = 0; i < q_size; ++i) {
                TreeNode* curr = q.front(); q.pop();
                visited.insert(curr);
                if(curr->left != NULL && visited.find(curr->left) == visited.end())
                    q.push(curr->left);
                if(curr->right != NULL && visited.find(curr->right) == visited.end())
                    q.push(curr->right);
                // search for parent
                if(parentMap[curr]!=NULL && visited.find(parentMap[curr]) == visited.end())
                    q.push(parentMap[curr]);
            }
            cur_dist++;
        }
        return cur_dist - 1;
    }
};