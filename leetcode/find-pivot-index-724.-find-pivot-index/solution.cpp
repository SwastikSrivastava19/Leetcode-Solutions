// Problem: 724. Find Pivot Index
// URL: https://leetcode.com/problems/find-pivot-index/
// Language: cpp
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
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
