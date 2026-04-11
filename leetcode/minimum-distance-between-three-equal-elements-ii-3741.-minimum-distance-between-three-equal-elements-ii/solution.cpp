// Problem: 3741. Minimum Distance Between Three Equal Elements II
// URL: https://leetcode.com/problems/minimum-distance-between-three-equal-elements-ii/
// Language: cpp
class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int, vector<int>> mp;

        for(int i = 0; i < nums.size(); i++){
            mp[nums[i]].push_back(i);
        }

        int ans = INT_MAX;

        for(auto &it : mp){
            vector<int> &ind = it.second;

            if (ind.size() < 3) continue;

            for(int i = 2; i < ind.size(); i++){
                int first = ind[i - 2];
                int last  = ind[i];

                int distance = 2 * (last - first);

                ans = min(ans, distance);
            }

        }
        return ans == INT_MAX ? -1 : ans;
    }
};
