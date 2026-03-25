// Problem: 974. Subarray Sums Divisible by K
// URL: https://leetcode.com/problems/subarray-sums-divisible-by-k/
// Language: cpp
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int , int> mp;
        int ans = 0 , sum = 0;

        mp[0] = 1;

        for(int i=0; i<nums.size(); i++){
            sum += nums[i];

            int rem = ((sum % k) + k) % k;

            if(mp.find(rem) != mp.end()){
                ans += mp[rem];
            }
            mp[rem]++;
        }
        return ans;
    }
};
