// Problem: 90. Subsets II
// URL: https://leetcode.com/problems/subsets-ii/
// Language: cpp
class Solution {
public:
    void printSubSet(int ind , vector<int> &tmp , set<vector<int>> &ans , int s , vector<int>& nums){
        if(ind == s){
            ans.insert(tmp);
            return;
        }

        // take
        tmp.push_back(nums[ind]);
        printSubSet(ind + 1 , tmp , ans , s , nums);

        // not take
        tmp.pop_back();
        printSubSet(ind + 1, tmp , ans , s , nums);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int s = nums.size();
        int ind = 0;
        set<vector<int>> ans;
        vector<int> tmp;
        sort(nums.begin() , nums.end());

        printSubSet(ind , tmp , ans , s , nums);
        return vector<vector<int>>(ans.begin() , ans.end());

    }
};
