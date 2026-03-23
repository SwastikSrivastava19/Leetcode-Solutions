// Problem: 3876. Construct Uniform Parity Array II
// URL: https://leetcode.com/problems/construct-uniform-parity-array-ii/
// Language: cpp
class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        sort(nums1.begin() , nums1.end());
        // Find the smallest odd number
        // Check if any even number is smaller than this odd
        // If yes → return false
        // Otherwise → return true

        int mini = 0;
        for(int i=0; i<nums1.size(); i++){
            if(nums1[i] % 2 != 0){
                mini = nums1[i];
                break;
            }
        }

        for(int i=0; i<nums1.size(); i++){
            if(nums1[i] % 2 == 0 && nums1[i] <= mini) return false;
        }
        return true;
    }
};
