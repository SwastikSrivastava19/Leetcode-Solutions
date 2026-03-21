// Problem: 3643. Flip Square Submatrix Vertically
// URL: https://leetcode.com/problems/flip-square-submatrix-vertically/
// Language: cpp
class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        for(int i=0;i<k/2;i++){
            for(int j=0;j<k;j++){
                swap(grid[x+i][y+j] , grid[x+k-1-i][y+j]);
            }
        }
        return grid;
        
    }
};
