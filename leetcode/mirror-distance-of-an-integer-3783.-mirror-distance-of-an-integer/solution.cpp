// Problem: 3783. Mirror Distance of an Integer
// URL: https://leetcode.com/problems/mirror-distance-of-an-integer/
// Language: cpp
class Solution {
public:
    int rev(int a){
        int num = 0;
        while(a > 0){
            num = num * 10 + a % 10;
            a /= 10;
        }
        return num;
    }

    int mirrorDistance(int n) {
        return abs(n - rev(n));
    }
};
