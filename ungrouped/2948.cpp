#include "../include.h"

// Solving
class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int m = nums.size();
        int i = 0;
        int j = 0;
        bool swapped = true;
        while(swapped) {
            swapped = false;
            for(i = 0; i < m; i++) {
                for(j = i; j < m; j++) {
                    if(nums[i] > nums[j] && abs(nums[i] - nums[j]) <= limit) {
                        swap(nums[i], nums[j]);
                        swapped = true;
                    }
                }
            }
            cout << i << " " << j << endl;
        }
            
        return nums;
    }
};

// Solving
class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int m = nums.size();
        // int i = 0;
        // int j = 0;
        bool swapped = true;

        vector<vector<int>> bak;
        vector<int> c(m, -1);

        for(int i = 0; i < m; i++) {
            int idx = -1;
            for(int j = 0; j < bak.size(); j++) {
                cout << i << " " << bak[j][0] - limit << " " << bak[j].back() + limit << endl;
                if(bak[j][0] - limit < nums[i] && bak[j].back() + limit > nums[i]) {
                    // cout << "in" << endl;
                    int finded = 0;
                    for(int k = 0; k < bak[j].size(); k++) {
                        if(nums[i] < bak[j][k]) {
                            bak[j].insert(bak[j].begin() + k, nums[i]);
                            // finded = 1;
                            idx = j;
                            j == -1;
                            break;
                        }
                        if(j != -1 && k == bak[j].size() - 1) {
                            bak[j].push_back(nums[i]);
                            idx = j;
                            j == -1;
                        }
                    }
                    if(j == -1) {
                        // bak[idx].push_back(nums[i]);
                        break;
                    }
                }
            }
            if(idx == -1) {
                vector<int> tmp;
                tmp.push_back(nums[i]);
                bak.push_back(tmp);
                c[i] = bak.size() - 1;
            } else {
                c[i] = idx;
            }
        }

        for(int i = 0; i < bak.size(); i++) {
            for(int j = 0; j < bak[i].size(); j++) {
                cout << i << " " << j << " " << bak[i][j] << endl;
            }
        }

        for(int i = 0; i < m; i++) {
            cout << "c " << c[i] << endl;
        }

        vector<int> idx(m, 0);

        for(int i = 0; i < m; i++) {
            cout << i << " " << c[i] << " " << idx[c[i]] << endl;
            nums[i] = bak[c[i]][idx[c[i]]];
            idx[c[i]]++;
        }
            
        return nums;
    }
};

class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<pair<int, int>> nums2(n);
        for (int i = 0; i < n; i++) {
            nums2[i] = {nums[i], i};
        }
        sort(nums2.begin(), nums2.end());
        vector<vector<int>> indices;
        for (int i = 0; i < n; i++) {
            if (i == 0 || nums2[i].first - nums2[i - 1].first > limit) {
                indices.push_back({});
            }
            indices.back().push_back(nums2[i].second);
        }
        vector<int> result(n);
        for (auto& index: indices) {
            vector<int> sortedIndex(index);
            sort(sortedIndex.begin(), sortedIndex.end());
            for (int j = 0; j < index.size(); j++) {
                result[sortedIndex[j]] = nums[index[j]];
            }
        }
        return result;
    }
};