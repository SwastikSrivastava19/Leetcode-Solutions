// Problem: 3870. Count Commas in Range
// URL: https://leetcode.com/problems/count-commas-in-range/
// Language: java
class Solution {
    public int countCommas(int n) {
        int ans=0;
        for (int i = 1; i <= n; i++) {
            int count = 0;
            int a = i;
            while (a > 0) {
                count++;
                a = a/ 10;
            }
            if(count>=4)
            ans+=(count-1)/3;

        }

        return ans;
    }
}

