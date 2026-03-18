// Problem: 763. Partition Labels
// URL: https://leetcode.com/problems/partition-labels/
// Language: cpp
class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.size();

        vector<int> ans;

        vector<int> mp(26 , -1);
        for(int i=0; i<n; i++){
            int ind = s[i] - 'a';
            mp[ind] = i;
        }

        int r = 0;
        while(r < n){
            int end = mp[s[r] - 'a'];

            int l = r;
            while(l < end){
                end = max(end , mp[s[l] - 'a']);
                l++;
            }
            ans.push_back(l - r + 1);
            r = l + 1;
        }
        return ans;
    }
};
