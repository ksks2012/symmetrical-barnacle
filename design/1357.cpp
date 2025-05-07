#include "include.h"

class Cashier {
public:
    unordered_map<int, int> price_list;
    int count, mod;
    double percent;
    
    Cashier(int n, int discount, vector<int>& products, vector<int>& prices) {
        count = 0;
        mod = n;
        percent = (100.0 - discount) / 100.0;
        for (int i = 0; i < products.size(); ++i)
            price_list[products[i]] = prices[i];
    }
    
    double getBill(vector<int> product, vector<int> amount) {
        count++;
        double res = 0.0;
        for (int i = 0; i < product.size(); ++i)
            res += price_list[product[i]] * amount[i];
        return count % mod ? res : res * percent;
    }
};

/**
 * Your Cashier object will be instantiated and called as such:
 * Cashier* obj = new Cashier(n, discount, products, prices);
 * double param_1 = obj->getBill(product,amount);
 */