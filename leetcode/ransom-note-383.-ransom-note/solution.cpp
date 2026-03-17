// Problem: 383. Ransom Note
// URL: https://leetcode.com/problems/ransom-note/
// Language: cpp
class Solution {
public:
    bool canConstruct(string str1, string str2) {
        int freq[26] = {0};

        for(auto ch : str2){
            freq[ch - 'a']++;
        }

        for(auto ch : str1){
            if(freq[ch - 'a'] == 0) return false;
            freq[ch - 'a']--;
        }
        return true;
    }
};
