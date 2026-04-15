// Problem: 213. House Robber II
// URL: https://leetcode.com/problems/house-robber-ii/
// Language: cpp
class Solution {
public:
    int f(vector<int> &dp , vector<int> &nums , int n , int start){
        // if(n < 0) return 0;
        // if(n == 0) return nums[0];
        if(n < start) return 0;
        // if(n == 1) return nums[1];

        if(dp[n] != -1) return dp[n];

        int take = nums[n] + f(dp , nums , n - 2 , start);
        int notTake = f(dp , nums , n - 1 , start);

        return dp[n] = max(take , notTake);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp1(n , -1);
        vector<int> dp2(n , -1);
        if(n == 1) return nums[0];
        return max(f(dp1 , nums , n-1 , 1) , f(dp2 , nums , n-2 , 0));
    }
};
