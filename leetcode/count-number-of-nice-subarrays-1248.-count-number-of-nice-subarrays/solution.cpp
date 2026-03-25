// Problem: 1248. Count Number of Nice Subarrays
// URL: https://leetcode.com/problems/count-number-of-nice-subarrays/
// Language: cpp
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        unordered_map<int , int> mp;
        int sum = 0;
        int ans = 0;
        mp[0] = 1;

        for(int i=0; i<nums.size(); i++){
            if(nums[i] % 2 == 0) sum += 0;
            else sum += 1;

            if(mp.find(sum - k) != mp.end()){
                ans += mp[sum - k];
            }
            mp[sum]++;
        }
        return ans;
    }
};
