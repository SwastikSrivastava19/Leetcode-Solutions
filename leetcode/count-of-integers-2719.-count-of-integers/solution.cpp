// Problem: 2719. Count of Integers
// URL: https://leetcode.com/problems/count-of-integers/
// Language: cpp
class Solution {

public:
     int minSum;
     int maxSum;
     int dp[24][2][200];
     int MOD = 1e9 + 7;

    string subtractOne(string s){
    int n = s.length();
    int i = n - 1;

    while (i >= 0) {
        if(s[i] > '0'){
            s[i]--; 
            break;
        } 
        else{
            s[i] = '9';
            i--;
        }
    }

    size_t first = s.find_first_not_of('0');
    if(string::npos == first) return "0";
    return s.substr(first);
}

    int f(string &s , int ind , bool tight , int sum ){
        if(ind == s.size()){
            return (sum >= minSum && sum <= maxSum);
        }

        if(dp[ind][tight][sum] != -1) return dp[ind][tight][sum];

        int lb = 0 , ub = tight ? s[ind] - '0' : 9;
        int res = 0;

        for(int dig=lb; dig<=ub; dig++){
            res += f(s , ind + 1 , tight && dig == ub , sum + dig );
            res %= MOD;
        }
        return dp[ind][tight][sum] = res % MOD;
    }

    int count(string num1, string num2, int min_sum, int max_sum) {
        num1 = subtractOne(num1);
        minSum=min_sum;
        maxSum=max_sum;
        memset(dp , -1 , sizeof(dp));
        int ans1 = f(num2 , 0 , 1 , 0 );
        memset(dp , -1 , sizeof(dp));
        int ans2 = f(num1 , 0 , 1 , 0 );

        return ((ans1 - ans2) + MOD) % MOD;
    }
};
