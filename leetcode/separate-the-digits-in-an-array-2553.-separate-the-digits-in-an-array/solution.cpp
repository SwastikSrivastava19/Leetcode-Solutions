// Problem: 2553. Separate the Digits in an Array
// URL: https://leetcode.com/problems/separate-the-digits-in-an-array/
// Language: cpp
class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> ans;

        for(int i=0; i<nums.size(); i++){
            string s = to_string(nums[i]);

            for(auto ch : s) ans.push_back(ch - '0');
        }
        return ans;
    }
};
