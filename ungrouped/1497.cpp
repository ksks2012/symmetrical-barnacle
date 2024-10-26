#include "include.h"

class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        unordered_map<int, int> mp;

        for (int num : arr) {
            int mod = num % k;
            if (mod < 0) {
                mod += k;
            }
            mp[mod]++;
        }

        for (auto [mod, cnt] : mp) {
            if (mod == 0) {
                if (cnt % 2 != 0) {
                    return false;
                }
            } else if (mod * 2 == k) {
                if (cnt % 2 != 0) {
                    return false;
                }
            } else {
                if (mp[mod] != mp[k - mod]) {
                    return false;
                }
            }
        }

        return true;
    }
};

// Sorting and Two-Pointers
class Solution {
public:
    // Custom comparator to sort based on mod values.
    struct Comparator {
        int k;
        Comparator(int k) { this->k = k; }
        bool operator()(int i, int j) {
            return (k + i % k) % k < (k + j % k) % k;
        }
    };

    bool canArrange(vector<int>& arr, int k) {
        sort(arr.begin(), arr.end(), Comparator(k));

        int start = 0, end = arr.size() - 1;
        while (start < end) {
            if (arr[start] % k != 0) 
                break;
            if (arr[start + 1] % k != 0) 
                return false;
            start = start + 2;
        }

        while (start < end) {
            if ((arr[start] + arr[end]) % k != 0) 
                return false;
                
            start++;
            end--;
        }
        return true;
    }
};