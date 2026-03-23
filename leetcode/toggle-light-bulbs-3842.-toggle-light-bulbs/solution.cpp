// Problem: 3842. Toggle Light Bulbs
// URL: https://leetcode.com/problems/toggle-light-bulbs/
// Language: cpp
class Solution {
public:
    vector<int> toggleLightBulbs(vector<int>& bulbs) {
        unordered_map<int , int> freq;
        for(auto it : bulbs){
            freq[it]++;
        }
        // if(freq.size() == 1 && freq[0].second % 2 != 0) ans.push_back(bulbs[0]);
        set<int> ans;

        for(int i=0; i<bulbs.size(); i++){
            if(freq[bulbs[i]] % 2 != 0) ans.insert(bulbs[i]);
        }
        // sort(ans.begin() , ans.end());
        vector<int> ans1(ans.begin() , ans.end());
        sort(ans1.begin() , ans1.end());
        return ans1;
    }
};
