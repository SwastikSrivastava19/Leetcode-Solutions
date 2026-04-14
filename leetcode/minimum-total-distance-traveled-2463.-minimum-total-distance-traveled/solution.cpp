// Problem: 2463. Minimum Total Distance Traveled
// URL: https://leetcode.com/problems/minimum-total-distance-traveled/
// Language: cpp
class Solution {
public:
    long long INF = 1e18;

    long long solve(int i, int j, vector<int>& robot, vector<int>& slots, vector<vector<long long>>& dp) {
        if(i >= robot.size()) return 0;
        if(j >= slots.size()) return INF;

        if(dp[i][j] != -1) return dp[i][j];

        long long take = abs(robot[i] - slots[j]) + solve(i+1, j+1, robot, slots, dp);
        long long ntake = solve(i, j+1, robot, slots, dp);

        return dp[i][j] = min(take, ntake);
    }

    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());

        vector<int> slots;

        for(auto &f : factory) {
            int pos = f[0], cap = f[1];
            while(cap--) {
                slots.push_back(pos);
            }
        }

        vector<vector<long long>> dp(robot.size()+1, vector<long long>(slots.size()+1, -1));

        return solve(0, 0, robot, slots, dp);
    }
};
