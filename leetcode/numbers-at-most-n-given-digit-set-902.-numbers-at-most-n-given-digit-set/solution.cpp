// Problem: 902. Numbers At Most N Given Digit Set
// URL: https://leetcode.com/problems/numbers-at-most-n-given-digit-set/
// Language: cpp
class Solution {
public:
int dp[11][2][2][1032];

    int f(string &s , int ind , bool tight , bool lz , int mask){
        if(ind == s.size()) return 1;

        if(dp[ind][tight][lz][mask] != -1) return dp[ind][tight][lz][mask];

        int lb = 0 , ub = (tight ? s[ind] - '0' : 9);
        int res = 0;

        for(int dig=lb; dig<=ub; dig++){
            if(lz && dig == 0){
                res += f(s , ind + 1 , tight && dig == ub , 1 , mask);
            }
            else{
                if(!(mask & (1 << dig))) continue; // agar masked nhi h then continue
                res += f(s , ind + 1 , tight && dig == ub , 0 , mask);
            }
        }
        return dp[ind][tight][lz][mask] = res;
    }

    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        int mask = 0;
        for(auto d : digits){
            int num = d[0] - '0';   // convert char --->>> int
            mask |= (1 << num);     // mask krdo , set that bit
        }
        string s = to_string(n);
        memset(dp , -1 , sizeof(dp));

        return f(s , 0 , 1 , 1 , mask) - 1;
    }
};
