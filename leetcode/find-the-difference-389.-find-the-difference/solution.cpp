// Problem: 389. Find the Difference
// URL: https://leetcode.com/problems/find-the-difference/
// Language: cpp
// Submission ID: dom-1780221270109
// Submitted At: 2026-05-31T09:54:30.174Z
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
