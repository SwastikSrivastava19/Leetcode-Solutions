// Problem: 600. Non-negative Integers without Consecutive Ones
// URL: https://leetcode.com/problems/non-negative-integers-without-consecutive-ones/
// Language: cpp
class Solution {
public:
int dp[32][2][2];
    int f(string &s , int ind , bool tight , bool prev){
        if(ind == s.size()) return 1;

        if(dp[ind][tight][prev] != -1) return dp[ind][tight][prev];

        int lb = 0 , ub = (tight == 1 ? s[ind] - '0' : 1);
        int res = 0;

        for(int dig=lb; dig<=ub; dig++){
            if(dig == 1 && prev) continue;

            res += f(s , ind + 1 , (tight && dig == ub) , dig == 1);
        }
        return dp[ind][tight][prev] = res;
    }

    int findIntegers(int n) {
        string s = bitset<32>(n).to_string();
        int phla_one = s.find('1');
        s = s.substr(phla_one);
        memset(dp , -1 , sizeof(dp));
        return f(s , 0 , 1 , 0);
    }
};
