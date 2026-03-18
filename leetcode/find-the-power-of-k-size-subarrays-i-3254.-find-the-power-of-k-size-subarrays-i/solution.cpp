// Problem: 3254. Find the Power of K-Size Subarrays I
// URL: https://leetcode.com/problems/find-the-power-of-k-size-subarrays-i/
// Language: cpp
class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        vector<int> res;
        int l = 0, r = 0;

        while(r < nums.size()){
            if(r - l + 1 < k) r++;

            else if(r - l + 1 == k){
                bool valid = true;

                for(int i = l + 1; i <= r; i++){
                    if(nums[i] - nums[i - 1] != 1){
                        valid = false;
                        break;
                    }
                }

                if (valid) res.push_back(nums[r]);
                else res.push_back(-1);

                l++;
                r++;
            }
        }
        return res;
    }
};
