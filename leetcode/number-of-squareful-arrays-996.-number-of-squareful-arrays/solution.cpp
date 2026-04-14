// Problem: 996. Number of Squareful Arrays
// URL: https://leetcode.com/problems/number-of-squareful-arrays/
// Language: cpp
class Solution {
public:

    bool isPerfectSquare(int a , int b){
        int sum = a + b;
        int root = sqrt(sum);

        return sum == (root * root);
    }

    void f(vector<int> &ds , vector<int> &nums , vector<int> &vis , int &count){
        if(ds.size() == nums.size()){
            count++;
            return;
        }

        for(int i=0; i<nums.size(); i++){
            if(vis[i] == 1) continue;

            if(i > 0 && nums[i] == nums[i-1] && vis[i-1] == 0) continue;

            if((ds.empty()) || isPerfectSquare(ds.back() , nums[i])){
                ds.push_back(nums[i]);
                vis[i] = 1;

                f(ds , nums , vis , count);
                vis[i] = 0;
                ds.pop_back();
            }
        }
    }
    int numSquarefulPerms(vector<int>& nums) {
        // vector<vector<int>> ans;
        vector<int> ds;
        int count = 0;
        sort(nums.begin() , nums.end());
        vector<int> vis(nums.size() , 0);
        f(ds , nums , vis , count);
        return count;
    }
};
