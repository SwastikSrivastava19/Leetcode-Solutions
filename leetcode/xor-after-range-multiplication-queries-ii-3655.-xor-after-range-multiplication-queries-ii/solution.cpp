// Problem: 3655. XOR After Range Multiplication Queries II
// URL: https://leetcode.com/problems/xor-after-range-multiplication-queries-ii/
// Language: cpp
// class Solution {
// public:
//     int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
//         int n=nums.size();
//         int mod=1e9+7;
//         for(auto &q:queries){
//             int idx=q[0];
//             while(idx<=q[1] && idx<n){
//                 nums[idx] = (int)(((long long)nums[idx] * q[3]) % mod);
//                 idx+=q[2];
//             }
//         }
//         int ans=0;
//         for(int i=0;i<n;i++){
//             ans=ans ^ nums[i];
//         }
//         return ans;
//     }
// };


// optimal wali app



class Solution {
public:
    const int MOD = 1000000007;

    long long modExp(long long base, long long exp) {
        if (exp == 0) return 1;

        long long half = modExp(base, exp / 2);
        long long result = (half * half) % MOD;

        if (exp % 2) result = (result * base) % MOD;

        return result;
    }

    int xorAfterQueries(vector<int>& arr, vector<vector<int>>& ops) {
        int len = arr.size();

        int block = sqrt(len) + 1;

        // grouping queries based on k
        vector<vector<vector<int>>> buckets(block);

        for (auto &query : ops) {
            int left = query[0];
            int right = query[1];
            int step = query[2];
            int val = query[3];

            if (step < block) {
                buckets[step].push_back(query);
            } else {
                // direct updates for large step
                for (int pos = left; pos <= right; pos += step) {
                    arr[pos] = (1LL * arr[pos] * val) % MOD;
                }
            }
        }

        // process small step values
        for (int step = 1; step < block; step++) {
            if (buckets[step].empty()) continue;

            vector<long long> multiplier(len + step + 5, 1);

            for (auto &query : buckets[step]) {
                int left = query[0];
                int right = query[1];
                int val = query[3];

                int lastIndex = left + ((right - left) / step) * step;
                int stop = lastIndex + step;

                multiplier[left] = (multiplier[left] * val) % MOD;

                long long invVal = modExp(val, MOD - 2);
                multiplier[stop] = (multiplier[stop] * invVal) % MOD;
            }

            // propagate values along step chains
            for (int i = 0; i < len; i++) {
                if (i - step >= 0) {
                    multiplier[i] = (multiplier[i] * multiplier[i - step]) % MOD;
                }
            }

            // apply to original array
            for (int i = 0; i < len; i++) {
                arr[i] = (1LL * arr[i] * multiplier[i]) % MOD;
            }
        }

        // compute final XOR
        int ans = 0;
        for (int value : arr) {
            ans ^= value;
        }

        return ans;
    }
};
