#include "include.h"

class Solution {
public:
    int maximumSetSize(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s1, s2, u;
        //s1 = set(nums1)  and  s2 = set(nums2)
        //u= s1 union s2

        int n = nums1.size() / 2;   // number of elements to be choosen from each array
        for(auto x:nums1) {
            s1.insert(x);
            u.insert(x);
        }
        for(auto x:nums2) {
            s2.insert(x);
            u.insert(x);
        }
        int common = s1.size() + s2.size() - u.size();   // size of s1 intersection s2
        int n1 = s1.size();
        int n2 = s2.size();

        int ans = 0;
        ans += min(n, n1 - common);   // take all elements from s1-s2  [maximum n elements]
        ans += min(n, n2 - common);   // take all elements from s2-s1
        ans += common;               // now take common elements
        ans = min(ans, n * 2);       // if nukber of elements taken are more than 2*n make the answer 2*n
        return ans;
    }
};

// WA
class Solution {
public:
    int maximumSetSize(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> m1;
        unordered_map<int, int> m2;

        int n = nums1.size();

        for(int i = 0; i < n; i++) {
            m1[nums1[i]]++;
            m2[nums2[i]]++;
        }

        int ans = 0;
            
        cout << m1.size() << " " << m2.size() << endl;
        if(m1.size() > m2.size()) {
            swap(m1, m2);
            swap(nums1, nums2);
        }
        cout << m1.size() << " " << m2.size() << endl;

        int target = n / 2;
        int a1 = 0, a2 = 0;
        for(auto m: m1) {
            cout << m.first << " " << m.second << endl;
            if(m2.find(m.first) != m2.end()) {
                m2[m.first] = 0;
                a1++;
            } else {
                a1++;
            }
            if(a1 == target)
                break;
        }

        for(auto m: m2) {
            cout << m.first << " " << m.second << endl;
            if(m.second != 0)
                a2++;
            if(a2 == target)
                break;
        }

        return a1 + a2;
    }
};

// WA
class Solution {
public:
    vector<int> nums1, nums2;
    set<int> visited;
    int target;
    int DFS(int i, int j, int r1, int r2) {
        if(r1 < 0) {
            while(r2 >= 0) {
                if(visited.find(nums2[j]) != visited.end()) {
                    j--;
                    continue;
                }
                r2--;
            }
            return target - r2;
        }

        if(r2 < 0) {
            while(r1 >= 0) {
                if(visited.find(nums1[i]) != visited.end()) {
                    i--;
                    continue;
                }
                r1--;
            }
            return target - r1;
        }

        if(visited.find(nums2[j]) != visited.end())
            return DFS(i - 1, j, r1, r2);

        if(visited.find(nums1[i]) != visited.end())
            return DFS(i, j - 1, r1, r2);

        if(nums1[i] == nums2[j]) {

        }
    }

    int maximumSetSize(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> m1;
        unordered_map<int, int> m2;
    
        int n = nums1.size();

        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        this->nums1 = nums1;
        this->nums2 = nums2;
        target = n / 2;

        return DFS(n - 1, n - 1, n / 2, n / 2);
    }
};