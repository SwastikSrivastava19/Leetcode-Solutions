// Problem: 77. Combinations
// URL: https://leetcode.com/problems/combinations/
// Language: cpp
class Solution {
public:
    void f(int n , int k , vector<vector<int>> &ans , vector<int> &ds , int curr){
        // base case
        if(ds.size() == k){
            ans.push_back(ds);
            return;
        }
        if(curr > n) return;
        // take
        ds.push_back(curr);
        f(n , k , ans , ds , curr + 1);
        ds.pop_back();

        // not take
        f(n , k , ans , ds , curr + 1);
    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> ds;
        int curr;
        f(n , k , ans , ds , 1);
        return ans;
    }
};
