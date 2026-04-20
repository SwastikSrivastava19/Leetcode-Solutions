// Problem: 233. Number of Digit One
// URL: https://leetcode.com/problems/number-of-digit-one/
// Language: cpp
class Solution {
public:
int dp[11][2][11];
    int f(string &s , int ind , bool tight , int cnt1){
        if(ind == s.size()) return cnt1;

        if(dp[ind][tight][cnt1] != -1) return dp[ind][tight][cnt1];

        int lb = 0;
        int ub = (tight == true) ? s[ind] - '0' : 9;
        int res = 0;

        for(int dig=lb; dig <= ub; dig++){
            res += f(s , ind + 1 , (tight && dig == ub) , cnt1 + (dig == 1));
        }
        return dp[ind][tight][cnt1] = res;
    }
    int countDigitOne(int n) {
        string s = to_string(n);
        memset(dp , -1 , sizeof(dp));

        return f(s , 0 , 1 , 0);
    }
};
