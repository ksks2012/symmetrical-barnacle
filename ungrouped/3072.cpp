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
