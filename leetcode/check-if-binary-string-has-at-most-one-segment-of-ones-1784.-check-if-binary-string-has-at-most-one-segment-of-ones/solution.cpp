// Problem: 1784. Check if Binary String Has at Most One Segment of Ones
// URL: https://leetcode.com/problems/check-if-binary-string-has-at-most-one-segment-of-ones/
// Language: cpp
class Solution {
public:
    bool checkOnesSegment(string s) {
        int i = s.length()-1;
        while(s[i]=='0' && i>=0) i--;
        while(i>=0){
            if(s[i]=='0') return false;
            i--;
        }
        return true;
    }
};
