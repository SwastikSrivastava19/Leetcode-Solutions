// Problem: 476. Number Complement
// URL: https://leetcode.com/problems/number-complement/
// Language: cpp
class Solution {
public:
    int findComplement(int n) {
        string bin = "";
        if(n == 0) return 1;

        while(n > 0){
            bin += (n % 2) + '0';
            // bin += to_string(n % 2);
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
