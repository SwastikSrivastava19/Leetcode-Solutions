// Problem: 2302. Count Subarrays With Score Less Than K
// URL: https://leetcode.com/problems/count-subarrays-with-score-less-than-k/
// Language: cpp
class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int l = 0 , r = 0;
        long long score = 0 , sum = 0 , ans = 0;
        while(r < nums.size()){
            sum += nums[r];
            score = sum * (r - l + 1);

            while(score >= k){
                sum -= nums[l];
                score = sum * (r - l);
                l++;
            }
            ans += (r - l + 1);
            r++;

        }
        return ans;
    }
};
