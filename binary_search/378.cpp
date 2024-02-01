#include "include.h"

// Binary search
class Solution {
public:
    int m, n;
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        m = matrix.size(), n = matrix[0].size();
        int left = matrix[0][0], right = matrix[m - 1][n - 1], ans = -1;
        while (left <= right) {
            int mid = (left + right) >> 1;
            if (countLessOrEqual(matrix, mid) >= k) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return ans;
    }

    int countLessOrEqual(vector<vector<int>>& matrix, int x) {
        int count = 0;
        int j = n - 1;
        for (int i = 0; i < m; ++i) {
            while (j >= 0 && matrix[i][j] > x) 
                --j; 
            count += (j + 1);
        }
        return count;
    }
};

// heap
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int m = matrix.size();
        int n = matrix[0].size();

        int ans = 0;
        priority_queue<vector<int>, vector<vector<int>>, greater<>> heap;

        for(int i = 0; i < min(m, k); i++) {
            heap.push({matrix[i][0], i, 0});
        }

        for(int i = 1; i <= k; i++) {
            auto top = heap.top();
            heap.pop();
            int r = top[1], c = top[2];
            ans = top[0];
            if(c + 1 < n) {
                heap.push({matrix[r][c + 1], r, c + 1});
            }
        }

        return ans;
    }
};