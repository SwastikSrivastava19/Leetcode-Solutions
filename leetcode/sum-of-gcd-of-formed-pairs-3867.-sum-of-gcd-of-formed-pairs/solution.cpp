// Problem: 3867. Sum of GCD of Formed Pairs
// URL: https://leetcode.com/problems/sum-of-gcd-of-formed-pairs/
// Language: cpp
class Solution {
public:
    long long gcdSum(vector<int>& nums) {

            int n = nums.size();
            vector<int> prefix(n);

            int mx = nums[0];
            prefix[0] = nums[0]; 

            for(int i = 1; i < n; i++){
                mx = max(mx, nums[i]);
                prefix[i] = __gcd(nums[i], mx);
            }
            sort(prefix.rbegin() , prefix.rend());
            long long sum = 0;

            int l = 0 , r = n - 1;
            while(l < r){
                sum += __gcd(prefix[l] , prefix[r]);
                l++;
                r--;
            }
            return sum;
    }
};
