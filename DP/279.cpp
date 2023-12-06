#include "include.h"

// TLE
class Solution {
public:
    int DFS(int target, int i) {
        if(i <= 0) {
            if(target == 0)
                return 0;
            else
                return INT_MAX / 2; 
        }
        if(i * i > target) {
            return DFS(target, i - 1);
        }
        return min(DFS(target, i - 1), DFS(target - i * i, i) + 1);
    }

    int numSquares(int n) {
        if (n <= 0) {
            return 0;
        } else if(n == 1) {
            return 1;
        }
        
        int cur = n / 2;
        int ans = DFS(n, cur);
        if(ans > INT_MAX / 2) {
            return 0;
        }
        return ans;
    }
};

// MLE
class Solution {
public:
    int DFS(int target, int i, vector<vector<int>>& memo) {
        if(i <= 0) {
            if(target == 0)
                return 0;
            else
                return INT_MAX / 2; 
        }
        int &res = memo[target][i];
        if(res != -1) {
            return res;
        }
        if(i * i > target) {
            return res = DFS(target, i - 1, memo);
        }
        return res = min(DFS(target, i - 1, memo), DFS(target - i * i, i, memo) + 1);
    }

    int numSquares(int n) {
        if (n <= 0) {
            return 0;
        } else if(n == 1) {
            return 1;
        }
        
        int cur = n / 2;
        vector<vector<int>> memo(n + 1, vector<int>(cur + 1, -1));
        int ans = DFS(n, cur, memo);
        if(ans > INT_MAX / 2) {
            return 0;
        }
        return ans;
    }
};

// DP
class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j * j <= i; j++) {
                dp[i] = min(dp[i], dp[i - j * j] + 1);
            }
        }
        return dp[n];
    }
};

// BFS Solution
class Solution {
public:
    int numSquares(int n) {
        if (n <= 0) {
            return 0;
        }
        
        // perfect_squares contain all perfect square numbers which 
        // are smaller than or equal to n.
        vector<int> perfect_squares;
        // count[i - 1] = the least number of perfect 
        // square numbers which sum to i.
        vector<int> count(n);
        
        // Get all the perfect square numbers which are smaller than 
        // or equal to n.
        for (int i = 1; i * i <= n; i++) {
            perfect_squares.push_back(i * i);
            count[i * i - 1] = 1;
        }
        
        // If n is a perfect square number, return 1 immediately.
        if (perfect_squares.back() == n) {
            return 1;
        }
        
        // Consider a graph which consists of number 0, 1,...,n as
        // its nodes. Node j is connected to node i via an edge if  
        // and only if either j = i + (a perfect square number) or 
        // i = j + (a perfect square number). Starting from node 0, 
        // do the breadth-first search. If we reach node n at step 
        // m, then the least number of perfect square numbers which 
        // sum to n is m. Here since we have already obtained the 
        // perfect square numbers, we have actually finished the 
        // search at step 1.
        queue<int> q;
        for (auto& i : perfect_squares) {
            q.push(i);
        }
        
        int cur_count = 1;
        while (!q.empty()) {
            cur_count++;
            
            int q_size = q.size();
            for (int i = 0; i < q_size; i++) {
                int tmp = q.front();
                // Check the neighbors of node tmp which are the sum 
                // of tmp and a perfect square number.
                for (auto& j : perfect_squares) {
                    if (tmp + j == n) {
                        // We have reached node n.
                        return cur_count;
                    } else if ((tmp + j < n) && (count[tmp + j - 1] == 0)) {
                        // If count[tmp + j - 1] > 0, this is not 
                        // the first time that we visit this node and we should 
                        // skip the node (tmp + j).
                        count[tmp + j - 1] = cur_count;
                        q.push(tmp + j);
                    } else if (tmp + j > n) {
                        // We don't need to consider the nodes which are greater ]
                        // than n.
                        break;
                    }
                }
                
                q.pop();
            }
        }
        
        return 0;
    }
};