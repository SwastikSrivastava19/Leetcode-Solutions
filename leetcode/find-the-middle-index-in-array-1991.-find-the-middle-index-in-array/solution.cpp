// Problem: 1991. Find the Middle Index in Array
// URL: https://leetcode.com/problems/find-the-middle-index-in-array/
// Language: cpp
class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int sum = accumulate(nums.begin() , nums.end() , 0);
        int lsum = 0;

        for(int i=0; i<nums.size(); i++){
            lsum += nums[i];

            if(lsum == sum){
                return i;
            }
            sum -= nums[i];
        }
        return -1;
    }
};
