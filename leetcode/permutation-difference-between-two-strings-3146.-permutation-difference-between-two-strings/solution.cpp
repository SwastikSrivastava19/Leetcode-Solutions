// Problem: 3146. Permutation Difference between Two Strings
// URL: https://leetcode.com/problems/permutation-difference-between-two-strings/
// Language: cpp
// Submission ID: dom-1780221332063
// Submitted At: 2026-05-31T09:55:32.075Z
class Solution {
public:
    char findTheDifference(string s, string t) {
        int asum = 0;
        int bsum = 0;
        for(auto ch : s){
            asum += ch;
        }
        for(auto it : t) bsum += it;

        int diff = abs(asum - bsum);

        return diff;
    }
};
