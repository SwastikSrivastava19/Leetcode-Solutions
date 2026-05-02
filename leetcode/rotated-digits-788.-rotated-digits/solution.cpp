// Problem: 788. Rotated Digits
// URL: https://leetcode.com/problems/rotated-digits/
// Language: cpp
class Solution {
public:
    bool goodhai(int n){
        bool changed = false;

        while(n > 0){
            int dig = n % 10;

            if(dig == 3 || dig == 4 || dig == 7) return false;

            if(dig == 2 || dig == 5 || dig == 6 || dig == 9) changed = true;

            n /= 10;
        }
        return changed;
    }
    int rotatedDigits(int n) {
        // digit dp
        // phle brute

        // change ho skti h -> 2 , 5 , 6 , 9
        // invalid          -> 3 , 4 , 7
        int ans = 0;
        for(int i=1; i<=n; i++){
            if(goodhai(i)) ans ++;
        }
        return ans;
    }
};
