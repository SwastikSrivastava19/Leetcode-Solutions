// Problem: 3871. Count Commas in Range II
// URL: https://leetcode.com/problems/count-commas-in-range-ii/
// Language: cpp
class Solution {
public:
    long long countCommas(long long n) {
        if(n < 1000) return 0;
        // if(n < 100)
        // if()
        // else return (n - 1000 + 1);

        long long ans = 0;
        long long start = 1000;
        int commas = 1;

        while(start <= n){
            long long last = start * 1000 - 1;
            long long cnt = min(n , last) - start + 1;
            ans += cnt * commas;

            start *= 1000;
            commas++;
        }

        return ans;
    }
};

