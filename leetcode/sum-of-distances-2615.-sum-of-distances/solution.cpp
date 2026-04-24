// Problem: 2615. Sum of Distances
// URL: https://leetcode.com/problems/sum-of-distances/
// Language: cpp
class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        // int n = nums.size();
        // unordered_map<int, vector<int>> elementIndices;

        // for(int i=0; i<n; i++){
        //     elementIndices[nums[i]].push_back(i);
        // }

        // vector<long long> ans(n , 0);
        // for(auto &it : elementIndices){
        //     vector<int> &v = it.second;
        //     int m = v.size();

        //     if(m <= 1) ans.push_back(0);
        //     int sum = 0;
        //     for(int j=0; j<n; j++){
        //         sum += abs(v[i] - v[j]);
        //     }
        //     ans.push_back(sum);
        // }
        // return ans;

        // for(int i=0; i<n; i++){
        //     long long sum = 0;
        //     for(int j=0; j<n; j++){
        //         if(nums[i] == nums[j]){
        //             sum += abs(i - j);
        //         }
        //     }
        //     ans[i] = sum;
        // }
        // return ans;



        int n = nums.size();
        vector<long long> ans(n);

        unordered_map<int, vector<int>> mp;

        for(int i=0; i<n; i++) mp[nums[i]].push_back(i);

        for(auto &it : mp){
            auto &pos = it.second;

            long long sum = 0;
            for(int x : pos) sum += x;

            long long leftSum = 0;
            int m = pos.size();

            for(int i=0; i<m; i++){
                long long rightSum = sum - leftSum - pos[i];

                long long left  = 1LL * pos[i] * i - leftSum;
                long long right = rightSum - 1LL * pos[i] * (m-i-1);

                ans[pos[i]] = left + right;

                leftSum += pos[i];
            }
        }

        return ans;
    }
};
