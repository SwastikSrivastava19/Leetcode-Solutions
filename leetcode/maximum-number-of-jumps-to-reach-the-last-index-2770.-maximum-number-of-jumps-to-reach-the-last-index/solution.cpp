// Problem: 2770. Maximum Number of Jumps to Reach the Last Index
// URL: https://leetcode.com/problems/maximum-number-of-jumps-to-reach-the-last-index/
// Language: cpp
class Solution {
public:

// resolve this after 6 days
    
    int solve(int i, vector<int>& nums, int target, vector<int>& dp) {
        int n = nums.size();

        // reached last index
        if (i == n - 1)
            return 0;

        // already computed
        if (dp[i] != -2)
            return dp[i];

        int ans = -1;

        // try all possible jumps
        for (int j = i + 1; j < n; j++) {

            if (abs(nums[j] - nums[i]) <= target) {

                int temp = solve(j, nums, target, dp);

                // if reachable
                if (temp != -1)
                    ans = max(ans, 1 + temp);
            }
        }

        return dp[i] = ans;
    }

    int maximumJumps(vector<int>& nums, int target) {

        int n = nums.size();

        // -2 means not calculated yet
        vector<int> dp(n, -2);

        return solve(0, nums, target, dp);
    }
};
