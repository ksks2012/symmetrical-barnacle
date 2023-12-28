#include "../include.h"

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();

        int left = 0, right = n - 1;
        vector<int> ans;

        while(left < right) {
            if(numbers[left] + numbers[right] > target)
                right--;
            else if(numbers[left] + numbers[right] < target)
                left++;
            else {
                ans.push_back(left + 1);
                ans.push_back(right + 1);
                return ans;
            }
        }
        
        return numbers;    // won't be reached due to constraints
    }
};

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();

        int left = 0, right = n - 1;
        vector<int> ans;

        while(left < right) {
            if(numbers[left] + numbers[right] > target)
                right--;
            else if(numbers[left] + numbers[right] < target)
                left++;
            else {
                break;
            }
        }
        
        return {left + 1, right + 1};
    }
};