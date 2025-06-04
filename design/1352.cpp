#include "include.h"

class ProductOfNumbers {
    vector<long long> products = {1}; // Store cumulative products
public:
    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        if (num == 0) {
            products = {1};
        } else {
            products.push_back(products.back() * num);
        }
    }
    
    int getProduct(int k) {
         // If k is larger than the number of products, return 0
        if (k >= products.size()) 
            return 0;
        // Return the product of the last k numbers
        return products.back() / products[products.size() - k - 1];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */
