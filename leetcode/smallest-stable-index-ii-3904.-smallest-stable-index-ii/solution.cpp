// Problem: 3904. Smallest Stable Index II
// URL: https://leetcode.com/problems/smallest-stable-index-ii/
// Language: cpp
class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
         int n = nums.size();
        int ans = INT_MAX;

        vector<int> suffixMin(n);
        suffixMin[n - 1] = nums[n-1];

        for(int i=n-2; i>=0; i--){
            suffixMin[i] = min(nums[i] , suffixMin[i + 1]);
        }

        vector<int> prefixMax(n);
        prefixMax[0] = nums[0];

        for(int i=1; i<n; i++){
            prefixMax[i] = max(nums[i] , prefixMax[i - 1]);
        }

        for(int i=0; i<n; i++){
            if(prefixMax[i] - suffixMin[i] <= k) return i;

        }
        return -1;
    }
};
