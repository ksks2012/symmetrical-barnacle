#include "include.h"

struct CompareHeapElements {
    bool operator()(pair<int,int> const& p1, pair<int,int> const& p2)
    {
        if(p1.first < p2.first){
            return true;
        }
        else if(p1.first == p2.first && p1.second < p2.second){
            return true;
        }
        return false;
    }
};
class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        priority_queue<pair<int,int>, vector<pair<int,int>>,CompareHeapElements> pq;

        int m = mat.size();
        int n = mat[0].size();

        for(int i = 0; i < m; i++) {
            int tmp = 0;
            for(int j = 0; j < n; j++) {
                tmp += mat[i][j];
            }
            pq.push({tmp, i});
            if(pq.size() > k){
                pq.pop();
            }
        }

        vector<int> ans(k, 0);

        for(int i = 0; i < k; i++) {
            ans[i] = pq.top().second;
            pq.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

struct CompareHeapElements {
    bool operator()(pair<int,int> const& p1, pair<int,int> const& p2)
    {
        if(p1.first < p2.first){
            return true;
        }
        else if(p1.first == p2.first && p1.second < p2.second){
            return true;
        }
        return false;
    }
};
class Solution {
public:
    // Binary Search
    int count(vector<int> &nums) {
        int left = 0;
        int right = nums.size() - 1;
        while(left <= right) {
            int mid = left + (right - left) / 2;
            if(nums[mid] == 0) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return left;
    }

    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        priority_queue<pair<int,int>, vector<pair<int,int>>,CompareHeapElements> pq;

        int m = mat.size();
        int n = mat[0].size();

        for(int i = 0; i < m; i++) {
            int tmp = count(mat[i]);
            pq.push({tmp, i});
            if(pq.size() > k){
                pq.pop();
            }
        }

        vector<int> ans(k, 0);

        for(int i = 0; i < k; i++) {
            ans[i] = pq.top().second;
            pq.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int n = mat[0].size();
        for(int i=0; i< mat.size(); i++) {
            mat[i].push_back(i);
        }
        sort(mat.begin(), mat.end());
        vector<int> ans(k);
        for(int i=0; i < k; i++) {
            ans[i] = mat[i][n];            
        }
        return ans;
    }
};