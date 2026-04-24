// Problem: 219. Contains Duplicate II
// URL: https://leetcode.com/problems/contains-duplicate-ii/
// Language: cpp
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        // unordered_map<int, int> mp;

        // for(int i = 0; i < min(n, k); i++){
        //     if(mp[nums[i]] > 0) return true; 
        //     mp[nums[i]]++;
        // }

        // for(int i = k; i < n; i++){
        //     if(mp[nums[i]] > 0) return true;

        //     mp[nums[i]]++;
        //     mp[nums[i - k]]--;

        //     if(mp[nums[i - k]] == 0) mp.erase(nums[i - k]);
        // }
        // return false;
        unordered_set<int> st;
        for(int i=0; i<n; i++){
            if(st.count(nums[i])) return true;

            st.insert(nums[i]);

            if(st.size() > k){
                st.erase(nums[i-k]);
            }
        }
        return false;
    }
};
