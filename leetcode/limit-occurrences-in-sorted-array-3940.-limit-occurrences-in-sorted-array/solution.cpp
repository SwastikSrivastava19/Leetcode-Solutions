// Problem: 3940. Limit Occurrences in Sorted Array
// URL: https://leetcode.com/problems/limit-occurrences-in-sorted-array/
// Language: cpp
// Submission ID: dom-1779635267082
// Submitted At: 2026-05-24T15:07:47.178Z
class Solution {
public:
    vector<int> limitOccurrences(vector<int>& nums, int k) {
        unordered_map<int , int> freq;
        for(auto x : nums) freq[x]++;

        vector<int> ans(nums.size());
        for(int i=0; i<nums.size(); i++){
            if(freq[nums[i]] >= k){
                for(int j=0; j<k; j++) ans[j] = nums[i];
                continue;
            }
            // ans.push_back(nums[i]);
        }
        return ans;
    }
};
