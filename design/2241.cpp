#include "../include.h"

class ATM {
public:
    int n = 5;
    vector<int> deno = {20, 50, 100, 200, 500};
    vector<int> count = {0, 0, 0, 0, 0};
    ATM() {
        
    }
    
    void deposit(vector<int> banknotesCount) {
        for(int i = 0; i < banknotesCount.size(); i++) {
            count[i] += banknotesCount[i];
        }
    }
    
    vector<int> withdraw(int amount) {
        vector<int> tmp(n, 0);
        for(int i = n - 1; i >= 0; i--) {
            tmp[i] = min(amount / deno[i], count[i]);
            amount -= tmp[i] * deno[i];
        }
        if(amount == 0) {
            for(int i = 0; i < n; i++) {
                count[i] -= tmp[i];
            }
            return tmp;
        }
        return {-1};
    }
};

/**
 * Your ATM object will be instantiated and called as such:
 * ATM* obj = new ATM();
 * obj->deposit(banknotesCount);
 * vector<int> param_2 = obj->withdraw(amount);
 */