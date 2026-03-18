// Problem: 2958. Length of Longest Subarray With at Most K Frequency
// URL: https://leetcode.com/problems/length-of-longest-subarray-with-at-most-k-frequency/
// Language: cpp
class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int l = 0 , r = 0 , maxL = 0;
        unordered_map<int , int> freq;

        while(r < nums.size()){
            freq[nums[r]]++;

            while(freq[nums[r]] > k){
                freq[nums[l]]--;
                l++;
            }
            maxL = max(maxL , r - l + 1);
            r++;
        }
        return maxL;
    }
};
