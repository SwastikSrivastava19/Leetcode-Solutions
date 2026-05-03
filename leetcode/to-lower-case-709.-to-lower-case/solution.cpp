// Problem: 709. To Lower Case
// URL: https://leetcode.com/problems/to-lower-case/
// Language: cpp
class Solution 
{
public:
    string toLowerCase(string s) {
        string b = "";
        for(char a : s){
            a = tolower(a);
            b += a;
        }
        return b;
    }
};
