#include "include.h"

class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        int m = nums.size();
        sort(nums.begin(), nums.end());
        
        unordered_set<int> visited;
        unordered_set<int> tmp;
        for(int i = 0; i < m; i++) {
            tmp.insert(nums[i]);
        }

        int res = 0;
        for(int i = 0; i < m; i++) {
            long long next = (long long)nums[i] * nums[i];
            int cur = 1;
            visited.insert(nums[i]);
            while(visited.find(next) == visited.end() && tmp.find(next) != tmp.end()) {
                cur++;
                visited.insert(next);
                next = next * next;
            }
            res = max(res, cur);
        }


        return res < 2 ? -1 : res;
    }
};

// Binary Search
class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        set<int> processedNumbers;

        int longestStreak = 0;

        for (int current : nums) {
            if (processedNumbers.find(current) != processedNumbers.end())
                continue;

            int streak = current;
            int streakLength = 1;

            while (true) {
                if ((long long)streak * (long long)streak > 1e5) break;

                if (binarySearch(nums, streak * streak)) {
                    streak *= streak;
                    processedNumbers.insert(streak);
                    streakLength++;
                } else {
                    break;
                }
            }

            // Update the longest streak if necessary
            longestStreak = max(longestStreak, streakLength);
        }

        return longestStreak < 2 ? -1 : longestStreak;
    }

private:
    bool binarySearch(vector<int>& nums, int target) {
        if (target < 0) return false;

        int left = 0;
        int right = nums.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) return true;
            if (nums[mid] > target)
                right = mid - 1;
            else
                left = mid + 1;
        }

        return false;
    }
};