// Problem: 2114. Maximum Number of Words Found in Sentences
// URL: https://leetcode.com/problems/maximum-number-of-words-found-in-sentences/
// Language: cpp
class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int ans = 0;
        for(auto s : sentences){
            int count = 1;
            for(int i=0; i<s.size(); i++){
                if(s[i] == ' ') count++;
            }
            ans = max(ans , count);
        }
        return ans;
    }
};
