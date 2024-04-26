#include "../include.h"

class Solution {
public:
    unordered_map<TreeNode*, TreeNode*> parentMap;
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        parentMap = unordered_map<TreeNode*, TreeNode*>();
        DFS(root, NULL);
        
        vector<int> res;
        queue<TreeNode*> q;
        unordered_set<TreeNode*> visited;
        q.push(target);
        int cur_dist = 0;
        while(!q.empty()) {
        
            int q_size = q.size();
            for(int i = 0; i < q_size; ++i) {
                TreeNode* curr = q.front(); q.pop();
                if(cur_dist == K)
                    res.push_back(curr->val);

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
            if(cur_dist > K)
                break;
        }
        return res;
    }
    
    void DFS(TreeNode* root, TreeNode* prev) {
        if(root != NULL) {
            parentMap[root] = prev;
            DFS(root->left, root);
            DFS(root->right, root);
        }
    }
};