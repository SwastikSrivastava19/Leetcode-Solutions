// Problem: 2011. Final Value of Variable After Performing Operations
// URL: https://leetcode.com/problems/final-value-of-variable-after-performing-operations/
// Language: cpp
class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int ans = 0;
        for (string x : operations) ans += (x[1] == '+' ? 1 : -1);
        return ans;
    }
};
