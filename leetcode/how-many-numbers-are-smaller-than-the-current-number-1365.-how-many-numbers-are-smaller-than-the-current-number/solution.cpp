// Problem: 1365. How Many Numbers Are Smaller Than the Current Number
// URL: https://leetcode.com/problems/how-many-numbers-are-smaller-than-the-current-number/
// Language: cpp
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();

        for(int i=0; i<n; i++){
            int count = 0;
            for(int j=0; j<n; j++){
                if(nums[j] < nums[i]) count++;
            }
            ans.push_back(count);
        }
        return ans;
    }
};
