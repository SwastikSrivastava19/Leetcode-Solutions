// Problem: 1561. Maximum Number of Coins You Can Get
// URL: https://leetcode.com/problems/maximum-number-of-coins-you-can-get/
// Language: cpp
class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin() , piles.end());
        int ans = 0;
        int n = piles.size();

        for(int i=0; i<piles.size()/3; i++){
            ans += piles[n-2];
            n -= 2;
        }
        return ans;
    }
};
