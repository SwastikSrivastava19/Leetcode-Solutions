// Problem: 209. Minimum Size Subarray Sum
// URL: https://leetcode.com/problems/minimum-size-subarray-sum/
// Language: cpp
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        // int l=0;
        // int r=0;
        // int sum=0;
        // int mini = INT_MAX;

        // while(r < nums.size()){
        //     sum += nums[r];
        //     while(sum >= target){
        //         // sum -= nums[i];
        //         mini = min(r-l+1 , mini);
        //         sum -= nums[l];
        //         l++;
        //     }
        //     r++;
        // }
        // if(mini == INT_MAX) return 0;

        // return mini;














        int l = 0 , r = 0;
        int sum = 0;
        int minL = INT_MAX;

        while(r < nums.size()){
            sum += nums[r];

            while(sum >= target){
                sum -= nums[l];
                minL = min(minL , r-l+1);
                l++;
            }
            r++;
        }
        if(minL == INT_MAX) return 0;
        return minL;
        
    }
};





