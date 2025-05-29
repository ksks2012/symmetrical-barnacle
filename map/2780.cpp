#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        unordered_map<int, int> count;
        for (int num : nums) count[num]++;
        int mode = nums[0], total = 0;
        for (auto& [num, cnt] : count) {
            if (cnt > total) {
                mode = num;
                total = cnt;
            }
        }
        int freq1 = 0, n = nums.size();
        for (int i = 0; i < n; ++i) {
            freq1 += (nums[i] == mode);
            if (freq1 * 2 > i + 1 && (total - freq1) * 2 > n - i - 1)
                return i;
        }
        return -1;
    }
};
