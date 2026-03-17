// Problem: 1160. Find Words That Can Be Formed by Characters
// URL: https://leetcode.com/problems/find-words-that-can-be-formed-by-characters/
// Language: cpp
class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        int ans = 0;
        int freq[26] = {0};

        for(auto ch : chars) freq[ch - 'a']++;

        for(int i = 0; i < words.size(); i++){
            string a = words[i];
            int temp[26];
            for(int j = 0; j < 26; j++) temp[j] = freq[j];

            bool f = false;

            for(auto ch : a){
                if(temp[ch - 'a'] == 0){
                    f = true;
                    break;
                }
                temp[ch - 'a']--;
            }
            if (!f) ans += words[i].size();
        }
        return ans;
    }
};
