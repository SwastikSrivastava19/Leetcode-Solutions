// Problem: 788. Rotated Digits
// URL: https://leetcode.com/problems/rotated-digits/
// Language: cpp
// class Solution {
// public:
//     bool goodhai(int n){
//         bool changed = false;

//         while(n > 0){
//             int dig = n % 10;

//             if(dig == 3 || dig == 4 || dig == 7) return false;

//             if(dig == 2 || dig == 5 || dig == 6 || dig == 9) changed = true;

//             n /= 10;
//         }
//         return changed;
//     }
//     int rotatedDigits(int n) {
//         // digit dp
//         // phle brute

//         // change ho skti h -> 2 , 5 , 6 , 9
//         // invalid          -> 3 , 4 , 7
//         int ans = 0;
//         for(int i=1; i<=n; i++){
//             if(goodhai(i)) ans ++;
//         }
//         return ans;
//     }
// };


class Solution {
public:
    int f(string s , int ind , bool tight , bool changed){
        if(ind == s.size()){
            return changed ? 1 : 0;
        }

        int lb = 0 , ub = tight ? s[ind] - '0' : 9;
        int ans = 0;

        for(int i=lb; i<=ub; i++){
            if(i == 3 || i == 4 || i == 7) continue;

            ans += f(s , ind + 1 , tight && i == ub , changed || i == 2 || i == 5 || i == 6 || i == 9);
        }
        return ans;
    }

    int rotatedDigits(int n) {
        // digit dp
        string s = to_string(n);
        return f(s , 0 , 1 , 0);
     
    }
};
