// Problem: 3212. Count Submatrices With Equal Frequency of X and Y
// URL: https://leetcode.com/problems/count-submatrices-with-equal-frequency-of-x-and-y/
// Language: cpp
class Solution {
public:
    // vector<vector<int>> pre;

    int numberOfSubmatrices(vector<vector<char>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> cumSumX(m , vector<int>(n , 0));
        vector<vector<int>> cumSumY(m , vector<int>(n , 0));


        int ans = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cumSumX[i][j] = (grid[i][j] == 'X');
                cumSumY[i][j] = (grid[i][j] == 'Y');

                if (i > 0) {
                    cumSumX[i][j] += cumSumX[i - 1][j];
                    cumSumY[i][j] += cumSumY[i - 1][j];
                }

                if (j > 0) {
                    cumSumX[i][j] += cumSumX[i][j - 1];
                    cumSumY[i][j] += cumSumY[i][j - 1];
                }

                if (i > 0 && j > 0) {
                    cumSumX[i][j] -= cumSumX[i - 1][j - 1];
                    cumSumY[i][j] -= cumSumY[i - 1][j - 1];
                }

                if (cumSumX[i][j] == cumSumY[i][j] && cumSumX[i][j] > 0 && cumSumY[i][j] > 0) {
                    ans++;
                }
            }
        }
        return ans;
    }
};
