// Problem: 198. House Robber
// URL: https://leetcode.com/problems/house-robber/
// Language: cpp
// class Solution {
// public:
//     int solve(vector<int>& nums , int n){
//         if(n < 0) return 0;
//         if(n == 0) return nums[0];

//         return max(solve(nums , n-2) + nums[n] , solve(nums , n-1));
//     }


//     int rob(vector<int>& nums) {
//         int n = nums.size();
//         int ans = solve(nums , n-1);
//         return ans;
        
//     }
// };






// Memoisation---->



class Solution {
public:
    int f(vector<int> &dp , vector<int>& nums , int n ){
        if(n < 0) return 0;
        if(n == 0) return nums[0];
        if(dp[n] != -1) return dp[n];

        int take = nums[n] + f(dp , nums , n - 2);
        int notTake = f(dp , nums , n - 1);

        return dp[n] = max(take , notTake);
        
    }


    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n , -1);
        return f(dp , nums , n-1);
    }
};






// Tabulation ---->



// class Solution {
// public:
     
//      int solve(vector<int> &nums){
//         int n = nums.size();
//         vector<int> dp(n , 0);
//         dp[0] = nums[0];
//         for(int i = 1;i<n;i++){
//             int pick = nums[i];
//             if (i > 1)
//             pick += dp[i - 2];
//             int notPick = dp[i-1] + 0;

//             dp[i] = max(pick , notPick);
//         }
//         return dp[n-1];
//      }

//     int rob(vector<int>& nums) {
//         return solve(nums);   
//         }
//     };





// Space Optimisation ---->



// class Solution {
// public:

//     int rob(vector<int>& nums) {
//         int n = nums.size();
//         int prev = nums[0];
//         int prev2 = 0;

//         for(int i=1;i<n;i++){
//             int pick = nums[i];
//             if (i > 1)
//             pick += prev2;
//             int notPick = prev + 0;

//             int cur_i = max(pick , notPick);
//             prev2 = prev;
//             prev = cur_i;
//         }
//         return prev;
          
//         }
//     };
