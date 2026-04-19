// Problem: 1855. Maximum Distance Between a Pair of Values
// URL: https://leetcode.com/problems/maximum-distance-between-a-pair-of-values/
// Language: cpp
class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int i = 0, j = 0, maxDist = 0;

        while(i < nums1.size() && j < nums2.size()){
            if(nums1[i] <= nums2[j]){
                maxDist = max(maxDist, j - i);
                j++;
            } 
            else i++; 
        }

        return maxDist;
    }
};

