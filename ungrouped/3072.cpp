#include "include.h"
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

typedef
tree<
  int,
  int,
  less<int>,
  rb_tree_tag,
  tree_order_statistics_node_update>
map_t;


// WA: can't solve repeat value
class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        map_t arr_t1, arr_t2;
        vector<int> arr1;
        vector<int> arr2;
        
        unordered_map<int, int> m1;
        unordered_map<int, int> m2;

        arr_t1.insert({nums[0], 1});
        m1[nums[0]]++;
        arr1.push_back(nums[0]);

        arr_t2.insert({nums[1], 1});
        arr2.push_back(nums[1]);
        m2[nums[1]]++;


        for(int i = 2; i < nums.size(); i++) {
            int rank1 = arr_t1.order_of_key(nums[i]);
            int rank1_sum = 0;
            for(int i = rank1; i < arr_t1.size(); i++) {
                // add value of arr_t1
                rank1_sum += m1[arr_t1.find_by_order(i)->first];
            }
            int rank2 = arr_t2.order_of_key(nums[i]);
            int rank2_sum = 0;
            for(int i = rank2; i < arr_t2.size(); i++) {
                // add value of arr_t1
                rank2_sum += m2[arr_t1.find_by_order(i)->second];
            }
            if(rank1_sum > rank2_sum) {
                arr_t1.insert({nums[i], 0});
                arr1.push_back(nums[i]);
                m1[nums[i]]++;
            } else if(rank1_sum == rank2_sum) {
                if(arr1.size() > arr2.size()) {
                    arr_t2.insert({nums[i], 0});
                    arr2.push_back(nums[i]);
                    m2[nums[i]]++;
                } else {
                    arr_t1.insert({nums[i], 0});
                    arr1.push_back(nums[i]);
                    m1[nums[i]]++;
                }
            } else {
                arr2.push_back(nums[i]);
                arr_t2.insert({nums[i], 0});
                m2[nums[i]]++;
            }
                
        }

        vector<int> ans;
        ans.insert(ans.end(), arr1.begin(), arr1.end());
        ans.insert(ans.end(), arr2.begin(), arr2.end());

        return ans;
    }
};


class Solution {
public:
    int greaterCount(vector<int>& arr, int val) {
        return arr.end() - upper_bound(arr.begin(), arr.end(), val);
    }

    vector<int> resultArray(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> order_left, order_right, left, right;
        order_left.push_back(nums[0]);
        order_right.push_back(nums[1]);
        left.push_back(nums[0]);
        right.push_back(nums[1]);
        
        int l = 0, r = 0;
        
        for (int i = 2; i < n; i++) {
            int x = greaterCount(order_left, nums[i]);
            int y = greaterCount(order_right, nums[i]);
            
            if (x > y) {
                
                order_left.insert(order_left.end() - x , nums[i]);
                left.push_back(nums[i]);
                l++;
            } else if (x < y) {
                
                order_right.insert(order_right.end() - y, nums[i]);
                right.push_back(nums[i]);
                r++;
            } else {
                if (l <= r) {
                    
                    order_left.insert(order_left.end() - x, nums[i]);
                    left.push_back(nums[i]);
                    l++;
                } else {
                    
                    order_right.insert(order_right.end() - y, nums[i]);
                    right.push_back(nums[i]);
                    r++;
                }
            }
        }
        
        
        left.insert(left.end(), right.begin(), right.end());
        return left;
    }
};

// endlesscheng
// Fenwick
class Fenwick {
    vector<int> tree;

public:
    Fenwick(int n) : tree(n) {}

    // add i value by 1
    void add(int i) {
        while (i < tree.size()) {
            tree[i] += 1;
            i += i & -i;
        }
    }

    // return sum of [1, i]
    int pre(int i) {
        int res = 0;
        while (i > 0) {
            res += tree[i];
            i &= i - 1;
        }
        return res;
    }
};

class Solution {
public:
    vector<int> resultArray(vector<int> &nums) {
        auto sorted = nums;
        ranges::sort(sorted);
        sorted.erase(unique(sorted.begin(), sorted.end()), sorted.end());
        int m = sorted.size();

        vector<int> a{nums[0]}, b{nums[1]};
        Fenwick t1(m + 1), t2(m + 1);
        t1.add(ranges::lower_bound(sorted, nums[0]) - sorted.begin() + 1);
        t2.add(ranges::lower_bound(sorted, nums[1]) - sorted.begin() + 1);
        for (int i = 2; i < nums.size(); i++) {
            int x = nums[i];
            int v = ranges::lower_bound(sorted, x) - sorted.begin() + 1;
            int gc1 = a.size() - t1.pre(v); // greaterCount(a, v)
            int gc2 = b.size() - t2.pre(v); // greaterCount(b, v)
            if (gc1 > gc2 || gc1 == gc2 && a.size() <= b.size()) {
                a.push_back(x);
                t1.add(v);
            } else {
                b.push_back(x);
                t2.add(v);
            }
        }
        a.insert(a.end(), b.begin(), b.end());
        return a;
    }
};