#include "include.h"

// Time complexity: O(n)
// Space complexity: O(n)
class Solution {
public:
    int trap(vector<int>& height) {
        int res = 0;
        int n = height.size();

        vector<int> prefix_max(n, 0);
        prefix_max[0] = height[0];
        for(int i = 1; i < n; i++) {
            prefix_max[i] = max(prefix_max[i - 1], height[i]);
        }

        vector<int> surfix_max(n, 0);
        surfix_max[n - 1] = height[n - 1];
        for(int i = n - 2; i >= 0; i--) {
            surfix_max[i] = max(surfix_max[i + 1], height[i]);
        }

        for(int i = 0; i < n; i++) {
            res += min(prefix_max[i], surfix_max[i]) - height[i];
        }

        return res;
    }
};

// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
public:
    int trap(vector<int>& height) {
        int res = 0;
        int n = height.size();

        int left = 0;
        int right = n - 1;
        int pre_max = 0;
        int suf_max = 0;

        while(left <= right) {
            pre_max = max(pre_max, height[left]);
            suf_max = max(suf_max, height[right]);

            if(pre_max < suf_max) {
                res += pre_max - height[left];
                left++;
            } else {
                res += suf_max - height[right];
                right--;
            }
        }

        return res;
    }
};

// endlesscheng
class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0;
        stack<int> st;
        for (int i = 0; i < height.size(); i++) {
            while (!st.empty() && height[i] >= height[st.top()]) {
                int bottom_h = height[st.top()];
                st.pop();
                if (st.empty()) {
                    break;
                }
                int left = st.top();
                int dh = min(height[left], height[i]) - bottom_h; // height of area
                ans += dh * (i - left - 1);
            }
            st.push(i);
        }
        return ans;
    }
};