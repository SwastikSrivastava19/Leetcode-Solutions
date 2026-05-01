// Problem: 2574. Left and Right Sum Differences
// URL: https://leetcode.com/problems/left-and-right-sum-differences/
// Language: cpp
class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans;
        vector<int>leftsum(n);
        leftsum[0]=0; 
        for(int i=1;i<=n-1;i++){
            leftsum[i]=leftsum[i-1]+nums[i-1];
        }
        vector<int>rightsum(n);
        // [ 10 , 4 , 8 , 3 ]
        rightsum[n-1]=0;
        for(int i=n-2;i>=0;i--){
            rightsum[i]=rightsum[i+1]+nums[i+1];
        }
        for(int i=0;i<n;i++){
            ans.push_back(abs(rightsum[i]-leftsum[i]));
        }
       return ans;

    }
};
