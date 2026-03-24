// Problem: 3818. Minimum Prefix Removal to Make Array Strictly Increasing
// URL: https://leetcode.com/problems/minimum-prefix-removal-to-make-array-strictly-increasing/
// Language: cpp
class Solution {
public:
    int minimumPrefixLength(vector<int>& nums) {
        int i = nums.size() - 1;
        while(i > 0 && nums[i - 1] < nums[i])  i--;
        return i;
    }
};
