// Problem: 523. Continuous Subarray Sum
// URL: https://leetcode.com/problems/continuous-subarray-sum/
// Language: cpp
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int , int> mp;
        mp[0] = -1;
        int sum = 0;

        for(int i=0; i<nums.size(); i++){
            sum += nums[i];
            int rem = sum % k;
            // int rem = ((sum % k) + k) % k;

            if(mp.find(rem) != mp.end()){
                if((i - mp[rem]) >= 2){
                    return true;
                }
                // else mp[rem] = i;
            }
            else mp[rem] = i;

            // mp[rem]++;
        }
        return false;
    }
};
