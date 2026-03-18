// Problem: 1004. Max Consecutive Ones III
// URL: https://leetcode.com/problems/max-consecutive-ones-iii/
// Language: cpp
// class Solution {
// public:
//     int longestOnes(vector<int>& nums, int k) {
//         // BRUTE FORCE APPROACH --->>>

//         int maxLen = 0;
//         for(int i=0;i<nums.size();i++){
//             int zeros = 0;
//             for(int j=i;j<nums.size();j++){
//                 if(nums[j] == 0) zeros++;

//                 if(zeros <= k){
//                     maxLen = max(maxLen , j-i+1);
//                 }
                
//             }
//         }
//         return maxLen;
        
//     }
// };




// class Solution {
//     public:
//         int longestOnes(vector<int>& nums, int k){

//             // BETTER APPROACH USING SLIDING WINDOW --->>>
//             int r=0;
//             int l=0;
//             int maxLen=0;
//             int zeros=0;

//             while(r < nums.size()){
//                 if(nums[r] == 0){
//                     zeros++;

//                 }

//                 while(zeros > k){
//                     if(nums[l] == 0){
//                         zeros--;
//                         // l++;
//                     }
//                     l++;
//                 }

//                 if(zeros <= k){
//                     maxLen = max(maxLen , r-l+1);
//                 }
//                 r++;
//             }
//             return maxLen;



//         }
// };


class Solution {
public:
    int longestOnes(vector<int>& nums, int k){

        // MOST OPTIMAL WITH O(N) TC --->>>
        int r=0;
        int l=0;
        int maxLen=0;
        int zeros=0;

        while(r < nums.size()){
            if(nums[r] == 0) zeros++;

            if(zeros > k){
                if(nums[l] == 0){
                    zeros--;
                    // l++;
                }
                l++;
                 
            }
            // if(zeros <= k){
                maxLen = max(maxLen , r-l+1);
            // }
            r++;
        }
        return maxLen;

    }
};











