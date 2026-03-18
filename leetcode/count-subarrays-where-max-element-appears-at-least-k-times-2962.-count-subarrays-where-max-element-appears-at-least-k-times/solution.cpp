// Problem: 2962. Count Subarrays Where Max Element Appears at Least K Times
// URL: https://leetcode.com/problems/count-subarrays-where-max-element-appears-at-least-k-times/
// Language: cpp
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long l = 0 , r = 0 , ans = 0;
        int max = *max_element(nums.begin() , nums.end());
        int count = 0;

        while(r < nums.size()){
            if(nums[r] == max) count++;

            while(count >= k){
                ans += nums.size() - r;

                if(nums[l] == max){
                    count--;
                    // ans++;
                    // l++;
                }
                l++;
            }
            r++;
        }
        return ans;
    }
};
