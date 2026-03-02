// Problem: 1536. Minimum Swaps to Arrange a Binary Grid
// URL: https://leetcode.com/problems/minimum-swaps-to-arrange-a-binary-grid/
// Language: cpp
class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> endingZeros(n , 0);

        for(int i=0; i<n; i++){
            int cnt = 0;
            for(int j=n-1; j>=0 && grid[i][j] == 0; j--){
                cnt++;
            }
            endingZeros[i] = cnt;
        }
        int swaps = 0;

        for(int i=0; i<n; i++){
            int need = n - i - 1;

            int j = i;
            while(j < n && endingZeros[j] < need){
                j++;
            }
            if(j == n) return -1;

            swaps += j - i;

            while(j > i){
                swap(endingZeros[j] , endingZeros[j-1]);
                j--;
            }
        }
        return swaps;
    }
};
