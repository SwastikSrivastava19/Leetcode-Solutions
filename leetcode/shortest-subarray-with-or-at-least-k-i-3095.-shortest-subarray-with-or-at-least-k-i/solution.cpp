// Problem: 3095. Shortest Subarray With OR at Least K I
// URL: https://leetcode.com/problems/shortest-subarray-with-or-at-least-k-i/
// Language: cpp
class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size() , ans = INT_MAX;
        for(int i = 0; i<n; i++){
            int op = 0;
            for(int j = i; j<n; j++){
                if(nums[j] >= k)
                return 1;

                op = op | nums[j];
                if(op >= k)
                ans = min(ans , j - i + 1);
            }
        }

        return ans==INT_MAX?-1:ans;
    }
};
