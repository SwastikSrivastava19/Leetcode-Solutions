// Problem: 17. Letter Combinations of a Phone Number
// URL: https://leetcode.com/problems/letter-combinations-of-a-phone-number/
// Language: cpp
class Solution {
public:
    void f(string& digits, string& curr, int ind , vector<string>& ans , vector<string> &mp){

        if(ind == digits.size()){
            ans.push_back(curr);
            return;
        }

        int num = digits[ind] - '0';
        string letters = mp[num];  //{a , b , c}

        for(auto it : letters){
            curr += it;
            f(digits , curr , ind + 1 , ans , mp);
            curr.pop_back();
        }

    }

    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        vector<string> mp = {
            "",     // 0
            "",     // 1
            "abc",  // 2
            "def",  // 3
            "ghi",  // 4
            "jkl",  // 5
            "mno",  // 6
            "pqrs", // 7
            "tuv",  // 8
            "wxyz"  // 9
        };
        string curr = "";
        f(digits, curr , 0 , ans , mp);
        return ans;
    }
};
