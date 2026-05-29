// Problem: 1945. Sum of Digits of String After Convert
// URL: https://leetcode.com/problems/sum-of-digits-of-string-after-convert/
// Language: cpp
// Submission ID: dom-1780046510535
// Submitted At: 2026-05-29T09:21:50.607Z
class Solution {
public:
    int sumofval(int a){
        string s = to_string(a);
        int sum = 0;
        for(auto ch : s){
            sum += ch - '0';
        }
        return sum;
    }
    int minElement(vector<int>& nums) {
        int ans = INT_MAX;
        for(int i=0; i<nums.size(); i++){
            ans = min(ans , sumofval(nums[i]));
        }
        return ans;
    }
};
