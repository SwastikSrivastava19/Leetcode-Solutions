// Problem: 3742. Maximum Path Score in a Grid
// URL: https://leetcode.com/problems/maximum-path-score-in-a-grid/
// Language: cpp
class Solution {
    int n, m;

    int go(int i, int j, int k, vector<vector<vector<int>>>& dp, vector<vector<int>>& grid){
        if (k < 0) return -1e9;
        if(i == n - 1 && j == m - 1) return (k - (grid[i][j] > 0) >= 0) ? grid[i][j] : -1e9;

        int &ret = dp[i][j][k];
        if(~ret) return ret;

        ret = -1e9;
        if(i + 1 < n) ret = max(ret, go(i + 1, j, k - (grid[i][j] > 0), dp, grid) + grid[i][j]);
        if(j + 1 < m) ret = max(ret, go(i, j + 1, k - (grid[i][j] > 0), dp, grid) + grid[i][j]);

        return ret;
    }
public:
    int maxPathScore(vector<vector<int>>& grid, int k) {
        n = grid.size();
        m = grid[0].size();

        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(k + 1, -1)));
        int ans = go(0, 0, k, dp, grid);
        return ans < 0 ? -1 : ans;
    }
};
