// Problem: 1356. Sort Integers by The Number of 1 Bits
// URL: https://leetcode.com/problems/sort-integers-by-the-number-of-1-bits/
// Language: cpp
class Solution {
public:
    static bool compare(int a, int b) {
        int counta = __builtin_popcount(a);
        int countb = __builtin_popcount(b);
        
        if(counta == countb){
            return a < b;
        }
        return counta < countb;
    }

    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), compare);
        return arr;
    }
};
