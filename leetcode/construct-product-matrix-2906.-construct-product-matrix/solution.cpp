// Problem: 2906. Construct Product Matrix
// URL: https://leetcode.com/problems/construct-product-matrix/
// Language: cpp
class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        const int MOD = 12345;

        vector<int> nums(n * m);

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                // 2D -> 1D mapping
                nums[i * m + j] = grid[i][j];
            }
        }

        vector<int> pref(n * m), suff(n * m);
        int sz = n * m;

        pref[0] = 1;
        for(int i = 1; i<sz; i++){
            pref[i] = (1LL * pref[i - 1] * nums[i - 1]) % MOD;
        }

        suff[sz - 1] = 1;
        for(int i=sz - 2;i>=0; i--){
            suff[i] = (1LL * suff[i + 1] * nums[i + 1]) % MOD;
        }

        vector<vector<int>> ans(n, vector<int>(m));

        for(int i = 0; i < sz; i++){
            // 1D -> 2D Mapping
            ans[i / m][i % m] = (1LL * pref[i] * suff[i]) % MOD;
        }

        return ans;

        // [1][1] = [2]
        // [0]
        // [0]

        // int zeroCount = 0;
        // long long prod = 1;

        // for(auto x : nums){
        //     if(x == 0) zeroCount++;
        //     else prod *= x;
        // }

        // if(zeroCount > 1) return ans; // sab already 0 hain
        

        // if(zeroCount == 1){
        //     for(int i = 0; i < n; i++){
        //         for(int j = 0; j < m; j++){
        //             if(grid[i][j] == 0)  ans[i][j] = prod;
                    
        //             else ans[i][j] = 0;
        //         }
        //     }
        // } 

        // else{
        //     for(int i = 0; i < n; i++){
        //         for(int j = 0; j < m; j++){
        //             ans[i][j] = (prod / grid[i][j]) % 12345;
        //         }
        //     }
        // }

        // return ans;
    }
};
