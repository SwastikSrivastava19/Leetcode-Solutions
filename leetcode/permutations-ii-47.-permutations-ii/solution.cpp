// Problem: 47. Permutations II
// URL: https://leetcode.com/problems/permutations-ii/
// Language: cpp
// class Solution {
// public:
//     void f(vector<int>& nums , vector<int> &ds , vector<vector<int>> &ans , vector<int> &vis ){
//         if(ds.size() == nums.size()){
//             ans.push_back(ds);
//             return;
//         }

//         for(int i=0; i<nums.size(); i++){
//             if(i > 0 && nums[i] == nums[i-1] && vis[i-1] == 0)
//     continue;

//     if (vis[i] == 1) continue;

//             vis[i] = 1;
//             ds.push_back(nums[i]);
//             f(nums , ds , ans , vis);

//             vis[i] = 0;
//             ds.pop_back();
//         }
//     }
//     vector<vector<int>> permuteUnique(vector<int>& nums) {
//         vector<vector<int>> ans;
//         sort(nums.begin() , nums.end());
//         vector<int> ds;
//         vector<int> vis(nums.size() , 0);
//         f(nums , ds , ans , vis);
//         return ans;
//     }
// };

class Solution {
public:
    void f(vector<int>& nums , vector<int> &ds , set<vector<int>> &ans , vector<int> &vis ){
        if(ds.size() == nums.size()){
            ans.insert(ds);
            return;
        }

        for(int i=0; i<nums.size(); i++){
            if (vis[i] == 1) continue;

            vis[i] = 1;
            ds.push_back(nums[i]);
            f(nums , ds , ans , vis);

            vis[i] = 0;
            ds.pop_back();
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>> ans;
        vector<int> ds;
        vector<int> vis(nums.size() , 0);
        f(nums , ds , ans , vis);
        return vector<vector<int>>(ans.begin() , ans.end());
    }
};
