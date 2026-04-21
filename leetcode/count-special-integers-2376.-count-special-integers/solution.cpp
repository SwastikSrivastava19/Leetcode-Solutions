// Problem: 2376. Count Special Integers
// URL: https://leetcode.com/problems/count-special-integers/
// Language: cpp
class Solution {
public:
    int f(string &s , int ind , bool tight , int mask , int lz){
        if(ind == s.size()) return lz == 0;

        int lb = 0 , ub = (tight ? s[ind] - '0' : 9);
        int res = 0;

        for(int dig=lb; dig<=ub; dig++){
            if(lz && dig == 0){
                res += f(s , ind + 1 , (tight && dig == ub) , mask , 1);
            }
        
            else {
                if(mask & (1 << dig)) continue;
                res += f(s , ind + 1 , (tight && dig == ub) , mask | (1 << dig) , 0);
            }
        }
        return res;
    }

    int countSpecialNumbers(int n) {
        string s = to_string(n);
        return f(s , 0 , 1 , 0 , 1);
    }
};
