// Problem: 3898. Find the Degree of Each Vertex
// URL: https://leetcode.com/problems/find-the-degree-of-each-vertex/
// Language: cpp
class Solution {
public:
    vector<int> findDegrees(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<int> ans(n , 0);
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(matrix[i][j] == 1){
                    ans[i]++;
                    ans[j]++;
                }
            }
        }
        for(auto &it : ans) it /= 2;
        return ans;
    }
};
