// Problem: 76. Minimum Window Substring
// URL: https://leetcode.com/problems/minimum-window-substring/
// Language: cpp
class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size(), ans = n+1, l = 0, r = 0, id = 0, cnt = t.size();
        vector<int> mp(130, 0);
        for(auto i : t) mp[i]++;
        while(r < n) {
            if(mp[s[r]] > 0) cnt--;
            mp[s[r++]]--;
            while(cnt == 0) {
                if(r - l < ans) ans = r - l, id = l;
                if(mp[s[l]] == 0) cnt++;
                mp[s[l++]]++;
            }
        }
        if(ans == n+1) return "";
        return s.substr(id, ans);
    }
};
