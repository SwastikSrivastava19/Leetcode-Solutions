// Problem: 1888. Minimum Number of Flips to Make the Binary String Alternating
// URL: https://leetcode.com/problems/minimum-number-of-flips-to-make-the-binary-string-alternating/
// Language: cpp
// class Solution {
// public:
//     int minFlips(string s) {
//          int n = s.size();
//         // jo final string hogi vo ya to 0 se hogi start ya to 1 se
//         // bss yahi nikaal ke charc me diff cnt krna h
//         // final string bnata hu
//         string finalString0(n, '0');
//         string finalString1(n, '0');
//         for (int i = 0; i < s.size(); i++) {
//             if (i % 2 == 0)
//                 finalString0[i] = '0';
//             else
//                 finalString0[i] = '1';
//         }

//         for (int i = 0; i < s.size(); i++) {
//             if (i % 2 == 0)
//                 finalString1[i] = '1';
//             else
//                 finalString1[i] = '0';
//         }
//         int cnt0 = 0;
//         int cnt1 = 0;

//         int i = 0, j = 0 , k = 0 , l = 0;
//         while (i < s.size() && j < s.size()) {
//             if (s[i] != finalString0[j])
//                 cnt0++;
//             i++;
//             j++;
//         }

//         while (k < s.size() && l < s.size()) {
//             if (s[k] != finalString1[l])
//                 cnt1++;
//             k++;
//             l++;
//         }

//         return min(cnt0 , cnt1);
//     }
// };









class Solution {
public:
    int minFlips(string s) {
        int n = s.size();
        string ss = s + s;

        string alt1 = "", alt2 = "";

        for(int i = 0; i < 2*n; i++){
            if(i % 2 == 0){
                alt1 += '0';
                alt2 += '1';
            }
            else{
                alt1 += '1';
                alt2 += '0';
            }
        }

        int diff1 = 0, diff2 = 0;
        int ans = 1e9;
        int l = 0;

        for(int r = 0; r < 2*n; r++){

            if(ss[r] != alt1[r]) diff1++;
            if(ss[r] != alt2[r]) diff2++;

            if(r - l + 1 > n){
                if(ss[l] != alt1[l]) diff1--;
                if(ss[l] != alt2[l]) diff2--;
                l++;
            }

            if(r - l + 1 == n){
                ans = min(ans, min(diff1, diff2));
            }
        }

        return ans;
    }
};
