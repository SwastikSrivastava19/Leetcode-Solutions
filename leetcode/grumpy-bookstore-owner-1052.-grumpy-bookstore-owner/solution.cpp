// Problem: 1052. Grumpy Bookstore Owner
// URL: https://leetcode.com/problems/grumpy-bookstore-owner/
// Language: cpp
class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
         int sum1 = 0;
        int n = customers.size();
         for(int i=0; i<customers.size(); i++){
             if(grumpy[i] == 0) sum1 += customers[i];
         }

        int l = 0 , r = 0 , sum = 0 , ext = 0;

        int ans = 0;

        while(r < n){
            // sum += customers[r];
            if(grumpy[r] == 1) ext += customers[r];

            if(r - l + 1 > minutes){
                if(grumpy[l] == 1)
                ext -= customers[l];
                l++;
            }
            ans = max(ans , ext);
            r++;
        }
        return ans + sum1;
    }
};
