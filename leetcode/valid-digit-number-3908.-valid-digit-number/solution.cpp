// Problem: 3908. Valid Digit Number
// URL: https://leetcode.com/problems/valid-digit-number/
// Language: cpp
class Solution {
public:
    bool validDigit(int n, int x) {
        string s = to_string(n);
        // string 
        if(s[0] != x + '0' && s.find(x + '0') != string::npos) return true;
        return false;
    }
};
