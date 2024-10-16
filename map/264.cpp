#include "include.h"

class Solution {
public:
    int nthUglyNumber(int n) {
        set<long> ugly_set;  
        ugly_set.insert(1);  

        long cur = 1;
        for (int i = 0; i < n; i++) {
            cur = *ugly_set.begin();
            ugly_set.erase(ugly_set.begin());

            // Insert the next potential ugly numbers
            ugly_set.insert(cur * 2);
            ugly_set.insert(cur * 3);
            ugly_set.insert(cur * 5);
        }

        return static_cast<int>(cur);
    }
};

class Solution {
public:
    int nthUglyNumber(int n) 
    {
        vector<int> dp(n+1);
        dp[1] = 1;
        int p2 = 1, p3 = 1, p5 = 1;
        for(int i = 2; i <= n; i++)
        {
            int num2 = dp[p2] * 2, num3 = dp[p3] * 3, num5 = dp[p5] * 5;
            dp[i] = min(min(num2, num3), num5);
            if(dp[i] == num2)
                p2++;
            if(dp[i] == num3)
                p3++;
            if(dp[i] == num5)
                p5++;
        }

        return dp[n];
    }
};