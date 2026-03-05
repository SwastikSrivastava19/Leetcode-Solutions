// Problem: 1758. Minimum Changes To Make Alternating Binary String
// URL: https://leetcode.com/problems/minimum-changes-to-make-alternating-binary-string/
// Language: cpp
class Solution {
public:
    int minOperations(string s) {
        int n = s.size();
        // jo final string hogi vo ya to 0 se hogi start ya to 1 se
        // bss yahi nikaal ke charc me diff cnt krna h
        // final string bnata hu
        string finalString0(n, '0');
        string finalString1(n, '0');
        for (int i = 0; i < s.size(); i++) {
            if (i % 2 == 0)
                finalString0[i] = '0';
            else
                finalString0[i] = '1';
        }

        for (int i = 0; i < s.size(); i++) {
            if (i % 2 == 0)
                finalString1[i] = '1';
            else
                finalString1[i] = '0';
        }
        int cnt0 = 0;
        int cnt1 = 0;

        int i = 0, j = 0 , k = 0 , l = 0;
        while (i < s.size() && j < s.size()) {
            if (s[i] != finalString0[j])
                cnt0++;
            i++;
            j++;
        }

        while (k < s.size() && l < s.size()) {
            if (s[k] != finalString1[l])
                cnt1++;
            k++;
            l++;
        }

        return min(cnt0 , cnt1);
    }
};
