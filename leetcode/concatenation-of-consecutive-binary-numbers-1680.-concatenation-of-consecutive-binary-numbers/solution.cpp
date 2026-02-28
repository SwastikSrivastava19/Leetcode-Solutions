// Problem: 1680. Concatenation of Consecutive Binary Numbers
// URL: https://leetcode.com/problems/concatenation-of-consecutive-binary-numbers/
// Language: cpp
#define mod 1000000007
class Solution {
public:
    int concatenatedBinary(int n) {

        // stoi wali approach kaam nhi krri
        long long ans = 0;
        for(int i=1;i<=n;++i) {
            int shift = 0;
            int num = i;
            while(num){
                num>>=1;
                ++shift;
            }
            ans=((ans<<shift)%mod+i)%mod;
        }
        return (int)ans;
    }
};
