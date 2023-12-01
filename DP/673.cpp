#include "include.h"

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) 
            return 0;

        vector<int> lengths(n, 1); 
        vector<int> counts(n, 1); 

        int max_length = 1; 

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] > nums[j]) {
                    if (lengths[j] + 1 > lengths[i]) {
                        lengths[i] = lengths[j] + 1;
                        counts[i] = counts[j];
                    } else if (lengths[j] + 1 == lengths[i]) {
                        counts[i] += counts[j];
                    }
                }
            }
            max_length = max(max_length, lengths[i]);
        }

        int result = 0;
        for (int i = 0; i < n; ++i) {
            cout << lengths[i] << " " << counts[i] << endl;
            if (lengths[i] == max_length) {
                result += counts[i];
            }
        }

        return result;
    }
};

class Solution {
public:
    int findNumberOfLIS(std::vector<int>& nums) {
        int n = nums.size();
        vector<int> length(n, 0);
        vector<int> count(n, 0);

        function<void(int)> calculateDP = [&](int i) {
            if (length[i] != 0)
                return;

            length[i] = 1;
            count[i] = 1;
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    calculateDP(j);
                    if (length[j] + 1 > length[i]) {
                        length[i] = length[j] + 1;
                        count[i] = 0;
                    }
                    if (length[j] + 1 == length[i]) {
                        count[i] += count[j];
                    }
                }
            }
        };

	int maxLength = 0;
        int result = 0;
        for (int i = 0; i < n; i++) {
            calculateDP(i);
            if (length[i] > maxLength)
                maxLength = length[i];
        }

        for (int i = 0; i < n; i++) {
            if (length[i] == maxLength)
                result += count[i];
        }

        return result;
    }
};