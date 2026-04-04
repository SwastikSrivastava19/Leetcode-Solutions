// Problem: 2075. Decode the Slanted Ciphertext
// URL: https://leetcode.com/problems/decode-the-slanted-ciphertext/
// Language: cpp
class Solution {
public:
    //approach 2
    string decodeCiphertext(string encodedText, int rows) {
        int l = encodedText.size();
        if(l == 0) return "";
        
        int cols = l/rows;
        string ans = "";
        
        for(int j = 0; j < cols; j++){
            for(int r = 0, c = j; r < rows && c < cols; r++, c++){
                ans.push_back(encodedText[r * cols + c]);
            }
        }
        
        while(!ans.empty() && ans.back() == ' '){
            ans.pop_back();
        }
        return ans;
    }
};
