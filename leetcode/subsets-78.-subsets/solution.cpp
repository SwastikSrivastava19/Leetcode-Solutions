// Problem: 78. Subsets
// URL: https://leetcode.com/problems/subsets/
// Language: cpp
class Solution {
public:
    void printSubSet(int ind , vector<int> &tmp , vector<vector<int>> &ans , int s , vector<int>& nums){
        if(ind == s){
            ans.push_back(tmp);
            return;
        }

        // take
        tmp.push_back(nums[ind]);
        printSubSet(ind + 1 , tmp , ans , s , nums);

        // not take
        tmp.pop_back();
        printSubSet(ind + 1, tmp , ans , s , nums);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        int ind = 0;
        int s = nums.size();
        vector<int> tmp;
        vector<vector<int>> ans;


        printSubSet(ind , tmp , ans , s , nums);
        return ans;
    }
};
