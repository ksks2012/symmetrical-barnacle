#include "include.h"

class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int n = chalk.size();
        vector<long> sum(n + 1, 0);
        for(int i = 1; i <= n; i++) {
            sum[i] = sum[i - 1] + chalk[i - 1];
        }

        k = long(k % sum[n]);

        for (int i = 0; i < chalk.size(); ++i) {
            if ((k -= chalk[i]) < 0)
                return i;
        }

        return 0;
    }
};

// Optimization
class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int n = chalk.size();
        long sum = 0;
        for(int i = 0; i < n; i++) {
            sum += chalk[i];
        }
        k = long(k % sum);

        for (int i = 0; i < chalk.size(); ++i) {
            if ((k -= chalk[i]) < 0)
                return i;
        }

        return 0;
    }
};