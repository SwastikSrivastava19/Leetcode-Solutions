// Problem: 1695. Maximum Erasure Value
// URL: https://leetcode.com/problems/maximum-erasure-value/
// Language: cpp
class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int l , r = 0;
        long long sum = 0;
        unordered_set<int> st;
        long long ans = 0;

        while(r < nums.size()){

            while(st.count(nums[r])){
                st.erase(nums[l]);
                sum -= nums[l];
                l++;
            }
            sum += nums[r];
            st.insert(nums[r]);
            ans = max(ans , sum);
            r++;
        }
        return ans;
    }
};
