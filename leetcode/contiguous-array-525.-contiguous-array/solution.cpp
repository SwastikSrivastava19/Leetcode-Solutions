// Problem: 525. Contiguous Array
// URL: https://leetcode.com/problems/contiguous-array/
// Language: cpp
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        // [0  1  1 1 1 1  0  0]
        // [-1 1  1 1 1 1 -1 -1]

        unordered_map<int , int>mp;
        int ans = 0;
        mp[0] = -1;
        int sum = 0;

        for(int i=0; i<nums.size(); i++){
            if(nums[i] == 0) sum += -1;
            else sum += 1;

            if(mp.find(sum) != mp.end()) ans = max(ans , i - mp[sum]);
            else mp[sum] = i;
        }
        return ans;
    }

};
