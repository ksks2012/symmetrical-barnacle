#include "../include.h"

class Solution {
public:
    // Function to check if 't' is a subsequence of 's'
    bool isSubsequence(string s, string t) {
        int n = s.size(), m = t.size();
        
        // If the length of 't' is greater than 's', it cannot be a subsequence
        if(m > n) 
            return false;

        // Track the current position in 's' that matches characters in 't'
        int i = 0;
        for(char ch : t) {
            // Move 'i' forward in 's' until we find a match for 'ch' or reach the end
            while(i < n && s[i] != ch) 
                i++;

            // If we reach the end of 's' without finding a match, return false
            if(i >= n) 
                return false;

            // At this point, s[i] == ch, so move to the next position in 's'
            i++;
        }

        // If all characters in 't' are matched in 's', return true
        return true;
    }

    // Function to find the longest word in the dictionary that is a subsequence of 's'
    string findLongestWord(string s, vector<string>& dictionary) {
        // Sort the dictionary: longer words first, and lexicographically smaller words first if lengths are equal
        sort(dictionary.begin(), dictionary.end(), [&](string &a, string &b) {
            if(a.size() == b.size()) 
                return a < b;
            return a.size() > b.size();
        });

        // Check each word in the sorted dictionary
        for(string &t : dictionary) {
            // If the word is a subsequence of 's', return it as the result
            if(isSubsequence(s, t)) 
                return t;
        }

        // If no word is found, return an empty string
        return "";
    }
};
