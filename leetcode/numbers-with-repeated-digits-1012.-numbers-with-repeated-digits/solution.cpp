// Problem: 1012. Numbers With Repeated Digits
// URL: https://leetcode.com/problems/numbers-with-repeated-digits/
// Language: cpp
class Solution {
public:
int dp[11][2][2][2][1024];
    int f(string &s , int ind , bool tight , bool rep , bool lz , int mask){
        if(ind == s.size()) return rep == 0 ? 0 : 1;
        // if(ind == s.size()) return rep ? 1 : 0;
        if(dp[ind][tight][rep][lz][mask] != -1) return dp[ind][tight][rep][lz][mask];

        int lb = 0;
        int ub = (tight == 1) ? s[ind] - '0' : 9;
        int res = 0;

        for(int dig=lb; dig<=ub; dig++){
            if(lz && dig == 0){ // still lz hain , no masking req.
                res += f(s , ind + 1 , (tight && dig == ub) , 0 , 1 , mask);
            }

            else{
                // check repetitions
                // if(mask & (1 << dig)) continue; // agar rep hain , to aage bdho.
                // mark digit as used -> mask | (1 << dig);
                res += f(s , ind + 1 , (tight && dig == ub) , (rep || (mask & (1 << dig))) , 0 , mask | (1 << dig));
            }
        }
        return dp[ind][tight][rep][lz][mask] = res;

    }
    int numDupDigitsAtMostN(int n) {
        string s = to_string(n);
        memset(dp , -1 , sizeof(dp));
        return f(s , 0 , 1 , 0 , 1 , 0);
    }
};
