// Problem: 2981. Find Longest Special Substring That Occurs Thrice I
// URL: https://leetcode.com/problems/find-longest-special-substring-that-occurs-thrice-i/
// Language: cpp
class Solution {
public:
    int maximumLength(string s) {
        int n = s.size();
        unordered_map<string , int> mp;
        for(int i=0; i<n; i++){
            string str = "";
            for(int j=i; j<n; j++){
                if(s[i] != s[j]) break;

                str += s[j];
                mp[str]++;
            }
        }
        int ans = -1;

        for(auto &it : mp){
            if(it.second >= 3){
                ans = max(ans , (int)it.first.size());
            }
        }
        return ans;
    }
};
