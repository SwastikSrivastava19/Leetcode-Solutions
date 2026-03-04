// Problem: 1582. Special Positions in a Binary Matrix
// URL: https://leetcode.com/problems/special-positions-in-a-binary-matrix/
// Language: cpp
class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();

        vector<int> rowSum(m,0);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                rowSum[i]+=mat[i][j];
            }
        }

        vector<int> colSum(n,0);
        for(int j=0;j<n;j++){
            for(int i=0;i<m;i++){
                colSum[j]+=mat[i][j];
            }
        }

        int ans = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==1 && rowSum[i]==1 && colSum[j]==1) ans++;
            }
        }
        return ans;
    }
};
