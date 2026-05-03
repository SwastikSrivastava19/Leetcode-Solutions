// Problem: 1920. Build Array from Permutation
// URL: https://leetcode.com/problems/build-array-from-permutation/
// Language: cpp
class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        vector<int> ans;
        for(int i=0; i<nums.size(); i++){
            ans.push_back(nums[nums[i]]);
        }
        return ans;
    }
};
