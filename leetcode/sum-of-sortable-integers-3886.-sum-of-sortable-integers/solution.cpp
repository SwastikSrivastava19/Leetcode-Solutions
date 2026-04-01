// Problem: 3886. Sum of Sortable Integers
// URL: https://leetcode.com/problems/sum-of-sortable-integers/
// Language: cpp
class Solution {
public:
    bool isValid(vector<int>& nums , int k){
        int n = nums.size();
        int prevMax = INT_MIN;

        for(int i=0; i<n; i+=k){
            int drops = 0;
            int currMin = nums[i];
            int currMax = nums[i];

            for(int j=i; j<i+k-1; j++){
                if(nums[j] > nums[j+1]) drops++;

                currMin = min(currMin , nums[j + 1]);

                currMax = max(currMax , nums[j + 1]);

                
            }
            // circular check(gpt)
            if(nums[i+k-1] > nums[i]) drops++;

            if(drops > 1 || currMin < prevMax) return false;

            prevMax = currMax;
        }
        return true;
    }
    
    int sortableIntegers(vector<int>& nums) {
        // Im cooked.....
            // Byeeeee
        int n = nums.size();
        int ans = 0;

        for(int k=1; k*k<=n; k++){
            if(n%k == 0){
                if(isValid(nums , k)) ans += k;

                if(k*k != n) if(isValid(nums , n/k)) ans += (n/k);
            }
        }
        // cout << ans;
        return ans;
    }
};
