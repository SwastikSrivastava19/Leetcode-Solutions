// Problem: 1208. Get Equal Substrings Within Budget
// URL: https://leetcode.com/problems/get-equal-substrings-within-budget/
// Language: cpp
class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int l = 0 , r = 0;
        int sum = 0 , ans = 0;

        while( r < s.size()){
            sum += abs(s[r] - t[r]);

            while(sum > maxCost){
                sum -= abs(s[l] - t[l]);
                l++;
            }
            ans = max(ans , r-l+1);
            r++;
        }
        return ans;
    }
};
