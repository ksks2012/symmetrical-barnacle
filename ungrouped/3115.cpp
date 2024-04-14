#include "include.h"

// fast multiplication
long long mod_mul(long long a, long long b, long long n) {
    long long result = 0;
    while (b > 0) {
        if (b & 1)
            result = (result + a) % n;
        a = (a + a) % n;
        b = b >> 1;
    }
    return result;
}

// fast exponentiation
long long mod_exp(long long a, long long b, long long n) {
    long long result = 1;
    while (b > 0) {
        if ((b & 1) > 0)
            result = mod_mul(result, a, n);
        a = mod_mul(a, a, n);
        b = b >> 1;
    }
    return result;
}

bool isprime(long long n) {
    if(n == 1)
        return false;
    long long k = 0;
    long long p = n - 1;
    // is odd number
    while ((p & 1) == 0) {
        p = p >> 1;
        k++;
    }
    for (int i = 0; i < 6; i++) {
        long long a = rand() % (n - 1 - 1 + 1) + 1;
        long long b = mod_exp(a, p, n);
        bool flag = false;
        if (b == 1)
            continue;
        for (int j = 0; j < k; j++)
            if ((b + 1) % n == 0) {
                flag = true;
                break;
            }
            else
                b = (b * b) % n;
        if (flag)
            continue;
        return false;
    }
    return true;
}

class Solution {
public:
    int maximumPrimeDifference(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;

        while(left <= right) {
            if(isprime(nums[left]) && isprime(nums[right])) {
                return right - left;
            }
            if(!isprime(nums[left])) {
                left++;
            }
            if(!isprime(nums[right])) {
                right--;
            }
        }
        
        return left - right;
    }
};