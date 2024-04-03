#include "include.h"

// MLE
class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        vector<vector<int>> tmp(n, vector<int>());

        for(int i = 0; i < reservedSeats.size(); i++) {
            tmp[reservedSeats[i][0] - 1].push_back(reservedSeats[i][1]);
        }

        int res = 0;
        for(int i = 0; i < n; i++) {
            if(tmp[i].size() == 0) {
                res += 2;
            } else {
                sort(tmp[i].begin(), tmp[i].end());
                int left = 0;
                int mid = 0;
                int right = 0;
                for(int j = 0; j < tmp[i].size(); j++) {
                    if(tmp[i][j] >= 2 && tmp[i][j] <= 5) {
                        left = 1;
                    }
                    if(tmp[i][j] >= 4 && tmp[i][j] <= 7) {
                        mid = 1;
                    }
                    if(tmp[i][j] >= 6 && tmp[i][j] <= 9) {
                        right = 1;
                    }
                }
                res += (2 - left - right) + (mid == 0 ? 1 : 0);
            }
        }

        return res;
    }
};

class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        sort(reservedSeats.begin(), reservedSeats.end());
        int res = n * 2;
        int cur = 1;

        vector<int> tmp;
        for(int i = 0; i < reservedSeats.size(); i++) {
            tmp.push_back(reservedSeats[i][1]);
            if(i == reservedSeats.size() - 1 || reservedSeats[i][0] != reservedSeats[i + 1][0]) {
                int left = 0;
                int mid = 0;
                int right = 0;
                for(int j = 0; j < tmp.size(); j++) {
                    if(tmp[j] >= 2 && tmp[j] <= 5) {
                        left = 1;
                    }
                    if(tmp[j] >= 4 && tmp[j] <= 7) {
                        mid = 1;
                    }
                    if(tmp[j] >= 6 && tmp[j] <= 9) {
                        right = 1;
                    }
                }

                if(left == 1 && mid == 1 && right == 1) {
                    res -= 2;
                } else if(left == 1 || right == 1) {
                    res -= 1;
                }

                tmp = vector<int>();
                cur++;
            }
        }

        return res;
    }
};

class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        int res = n * 2;
            
        unordered_map<int, char> m;
            
        for (auto r : reservedSeats)
            if (r[1] > 1 && r[1] < 10)
                m[r[0]] |= 1 <<(r[1] - 2);
            
        for (auto [row, seats] : m) {  
            bool left  = seats & 0b11110000;
            bool mid   = seats & 0b00111100;
            bool right = seats & 0b00001111;
                
            res -= left && mid && right ? 2 : 1;
        }
            
        return res;
    }
};