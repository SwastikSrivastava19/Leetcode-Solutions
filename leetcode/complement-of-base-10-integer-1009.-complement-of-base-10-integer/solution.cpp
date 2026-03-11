// Problem: 1009. Complement of Base 10 Integer
// URL: https://leetcode.com/problems/complement-of-base-10-integer/
// Language: cpp
class Solution {
public:
    int bitwiseComplement(int n) {
        string bin = "";
        if(n == 0) return 1;

        while(n > 0){
            // bin += (n % 2) + '0';
            bin += to_string(n % 2);
            n/=2;
        }
        reverse(bin.begin() , bin.end());

        for(int i=0; i<bin.size(); i++){
            if(bin[i] == '0') bin[i] = '1';
            else bin[i] = '0';
        }
        int ans = 0;

        for(char c : bin){
            ans = ans * 2 + (c - '0');
        }
        return ans;
    }
};
