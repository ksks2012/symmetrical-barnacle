#include "../include.h"

// DisjointSet
class DisjointSet{
public:
    vector<int> parent,size;

    DisjointSet(int n){
        parent.resize(n + 1);
        size.resize(n + 1);
        for(int i= 0 ;i <= n ; i++){
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findP(int x){
        if (x == parent[x]) 
            return x;

        return parent[x] = findP(parent[x]);
    }

    void unionBySize(int u, int v){
        int pu = findP(u);
        int pv = findP(v);

        if (pu == pv ) 
            return;

        if (size[pu] > size[pv]){
            parent[pv] = pu;
            size[pu] += size[pv];
        }
        else {
            parent[pu] = pv;
            size[pv] += size[pu];
        }
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        unordered_map<string,int> mp;
        DisjointSet dis(n);
        // 1 comment
        for(int i = 0; i < n; i++){
            for(int j = 1; j < accounts[i].size(); j++){
                string mail = accounts[i][j];
                if (mp.find(mail) == mp.end()){
                    mp[mail] = i;
                }
                else {
                    dis.unionBySize(i, mp[mail]);
                }
            }
        }
        // 2 comment
        vector<string> mailp[n];
        for(auto it: mp){
            string mail = it.first;
            int node = dis.findP(it.second);
            mailp[node].push_back(mail);
        }

        vector<vector<string>> res;
        // 3 comment
        for(int i = 0; i < n; i++){
            if (mailp[i].size() == 0) continue;
            string name = accounts[i][0];
            vector<string> temp;
            temp.push_back(name);
            sort(mailp[i].begin(), mailp[i].end());
            for(auto it: mailp[i]){
                temp.push_back(it);
            }
            res.push_back(temp);
        }

        return res;
    }
};

// DFS
class Solution {
public:
    unordered_set<string> visited;
    unordered_map<string, vector<string>> adjacent;
    
    void DFS(vector<string>& mergedAccount, string& email) {
        visited.insert(email);
        mergedAccount.push_back(email);
        
        for (string& neighbor : adjacent[email]) {
            if (visited.find(neighbor) == visited.end()) {
                DFS(mergedAccount, neighbor);
            }
        }
    }
    
    vector<vector<string>> accountsMerge(vector<vector<string>>& accountList) {        
         for (vector<string>& account : accountList) {
            int accountSize = account.size();
            
            // Adding edge between first email to all other emails in the account
            string first_mail = account[1];
            for (int j = 2; j < accountSize; j++) {
                string email = account[j];
                adjacent[first_mail].push_back(email);
                adjacent[email].push_back(first_mail);
            }
        }
        
        // Traverse over all th accounts to store components
        vector<vector<string>> res;
        for (vector<string>& account : accountList) {
            string account_name = account[0];
            string first_mail = account[1];
            
            // If email is visited, then it's a part of different component
            if (visited.find(first_mail) == visited.end()) {
                vector<string> mergedAccount;
                // Adding account name at the 0th index
                mergedAccount.push_back(account_name);
                DFS(mergedAccount, first_mail);
                sort(mergedAccount.begin() + 1, mergedAccount.end());
                res.push_back(mergedAccount);
            }
        }
        
        return res;
    }
};