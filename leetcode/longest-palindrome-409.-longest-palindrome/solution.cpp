// Problem: 409. Longest Palindrome
// URL: https://leetcode.com/problems/longest-palindrome/
// Language: cpp
// Submission ID: dom-1780311551369
// Submitted At: 2026-06-01T10:59:11.503Z
class Solution {
public:
    int longestPalindrome(string s) {
        // a -> 1
        // b -> 1
        // c -> 4
        // d -> 2

        int oddCount = 0;
        unordered_map<char, int> ump;
        for(char ch : s) {
            ump[ch]++;
            if (ump[ch] % 2 == 1)
                oddCount++;
            else    
                oddCount--;
        }
        if(oddCount > 1)
            return s.length() - oddCount + 1;
        return s.length();
    }
};
