// Problem: 3909. Compare Sums of Bitonic Parts
// URL: https://leetcode.com/problems/compare-sums-of-bitonic-parts/
// Language: cpp
class Solution {
public:
    int compareBitonicSums(vector<int>& nums) {
        int n = nums.size();

        int peak = max_element(nums.begin(), nums.end()) - nums.begin();

        long long suml = 0, sumr = 0;

        for(int i = 0; i <= peak; i++) suml += nums[i];
        for(int i = peak; i < n; i++) sumr += nums[i];

        if(suml > sumr) return 0;
        else if(suml < sumr) return 1;
        else return -1; 
    }
};
