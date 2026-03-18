// Problem: 3070. Count Submatrices with Top-Left Element and Sum Less Than k
// URL: https://leetcode.com/problems/count-submatrices-with-top-left-element-and-sum-less-than-k/
// Language: cpp
class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;

        for (int i = 1; i < m; i++) {
            for (int j = 0; j < n; j++) {
                grid[i][j] += grid[i-1][j];
            }
        }

        for (int i = 0; i < m; i++) {
            int s = 0;
            for (int j = 0; j < n; j++) {
                s += grid[i][j];
                if (s > k) break;
                ans++;
            }
        }

        return ans;
    }
};
