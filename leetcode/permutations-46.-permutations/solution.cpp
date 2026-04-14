// Problem: 46. Permutations
// URL: https://leetcode.com/problems/permutations/
// Language: cpp
class Solution {
public:
    void f(vector<int>& nums , vector<int> &ds , vector<vector<int>> &ans , vector<int> &vis){
        
        if(ds.size() == nums.size()){
            ans.push_back(ds);
            return;
        }

        for(int i=0; i<nums.size(); i++){
            if(vis[i] == 1) continue;

            vis[i] = 1;
            ds.push_back(nums[i]);
            f(nums , ds , ans , vis);

            vis[i] = 0;
            ds.pop_back();
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        vector<int> vis(nums.size(), 0);
        f(nums , ds , ans , vis);
        return ans;
    }
};
